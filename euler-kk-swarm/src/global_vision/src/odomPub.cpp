/*
 * @Author: Chaozheng Zhu && Loren
 * @Date: 2022-04-20 14:29:58
 * @LastEditTime: 2022-05-17 16:52:42
 * @FilePath: /kk-robot-swarm/src/global_vision/src/odomPub.cpp
 * @Description: Combine the car raw datas and the Tf datas, and put odom datas.
 *
 * Copyright (c) 2022 by AmovLab, All Rights Reserved.
 */

#include "global_vision/odomPub.hpp"

#include <boost/thread.hpp>

#include "kkswarm_msgs/msg/kk_swarm_pose.hpp"
#include "kkswarm_msgs/msg/kk_swarm_state.hpp"

using namespace std;

// Constructor
odomPub::odomPub() {
  // subFromTcp();
  nh_ = rclcpp::Node::make_shared("odomPub_node");
  tf_buffer_ = std::make_unique<tf2_ros::Buffer>(nh_->get_clock());
  car_tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
  boost::thread commThread(&odomPub::subFromTcp, this);
  commThread.detach();

  boost::thread tfThread(&odomPub::subFromTf, this);
  tfThread.detach();

  for (int i = 1; i <= car_total_num_; i++) {
    string topic = odomPub::topicNameGenerate(i);
    auto pub = nh_->create_publisher<nav_msgs::msg::Odometry>(topic, 10);
    odom_pub_set_.push_back(pub);
  }

  RCLCPP_INFO(nh_->get_logger(), "odomPub initialized.");
}

void odomPub::subFromTcp() {
  RCLCPP_INFO(nh_->get_logger(), "subFromTcp. \n");
  communication_sub_ = nh_->create_subscription<kkswarm_msgs::msg::KKSwarmState>(
      "/comm",
      1000,
      [this](const kkswarm_msgs::msg::KKSwarmState::SharedPtr msgs) {
        this->communicationCallBack(msgs);
      });
}

void odomPub::communicationCallBack(
    const kkswarm_msgs::msg::KKSwarmState::SharedPtr msgs) {
  car_pose_[msgs->mark].mark = msgs->mark;
  car_pose_[msgs->mark].linear_vel = msgs->linear_speed;
  car_pose_[msgs->mark].angular_vel = msgs->angular_speed;

  // Debug only.
  RCLCPP_INFO(nh_->get_logger(), "car_pose_[msgs->mark].mark = %d", car_pose_[msgs->mark].mark);
  RCLCPP_INFO(nh_->get_logger(), "car_pose_[msgs->mark].linear_vel = %f",
           car_pose_[msgs->mark].linear_vel);
}

void odomPub::subFromTf() {
  rclcpp::Rate pub_rate(10);
  while (rclcpp::ok()) {
    for (int i = 1; i <= car_total_num_; i++) {
      try {
        // generate tf fream: /robot_i/base_link
        string tf_base = odomPub::tfNameGenerate(i);
        RCLCPP_INFO(nh_->get_logger(), "---tf_base: %s----", tf_base.c_str());

        transform_ = tf_buffer_->lookupTransform("map", tf_base, tf2::TimePointZero);
        tf2::Transform tf_from_msg;
        tf2::convert(transform_.transform, tf_from_msg);
        
        double quat_x = tf_from_msg.getRotation().getX();
        double quat_y = tf_from_msg.getRotation().getY();
        double quat_z = tf_from_msg.getRotation().getZ();
        double quat_w = tf_from_msg.getRotation().getW();
        RCLCPP_INFO(nh_->get_logger(), "-----quat_x=%f-----", quat_x);
        //tf::Quaternion quat = tf::Quaternion(quat_x, quat_y, quat_z, quat_w);
        tf2::Quaternion quat(quat_x, quat_y, quat_z, quat_w);
        double angle = getYaw(quat);
        // cout << "angle" << angle << endl;
        car_pose_[i].yaw = convertDegree(angle);
        car_pose_[i].quat.w = quat.w();
        car_pose_[i].quat.x = quat.x();
        car_pose_[i].quat.y = quat.y();
        car_pose_[i].quat.z = quat.z();

        car_pose_[i].car_center_point[0] = tf_from_msg.getOrigin().getX();
        car_pose_[i].car_center_point[1] = tf_from_msg.getOrigin().getY();

        // odom msgs.
        car_odom_[i].header.stamp = nh_->now();
        car_odom_[i].header.frame_id = "map";
        car_odom_[i].child_frame_id = tf_base;
        car_odom_[i].pose.pose.position.x = car_pose_[i].car_center_point[0];
        car_odom_[i].pose.pose.position.y = car_pose_[i].car_center_point[1];
        car_odom_[i].pose.pose.position.z = 0.0;
        car_odom_[i].pose.pose.orientation = car_pose_[i].quat;
        car_odom_[i].twist.twist.linear.x = car_pose_[i].linear_vel;
        car_odom_[i].twist.twist.angular.z = car_pose_[i].angular_vel;

        string topic = odomPub::topicNameGenerate(i);
        if (odom_pub_set_[i - 1]->get_topic_name() == topic) {
          odom_pub_set_[i - 1]->publish(car_odom_[i]);
        }

        // Debug Only.
        cout << "No." << i << "Car's linear_vel is " <<
        car_pose_[i].linear_vel
             << endl;
        cout << "No." << i << "Car's angular_vel is "
             << car_pose_[i].angular_vel << endl;
        cout << "No." << i << "Car's x position is "
             << car_pose_[i].car_center_point[0] << endl;
        cout << "No." << i << "Car's y position is "
             << car_pose_[i].car_center_point[1] << endl;
        cout << "No." << i << "car's yaw is " << car_pose_[i].yaw << endl;
      } catch (tf2::TransformException & ex) {
        RCLCPP_ERROR(nh_->get_logger(), "------%s------", ex.what());
        rclcpp::sleep_for(1s);
        continue;
      }
    }
    pub_rate.sleep();
  }
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  //auto nh = rclcpp::Node::make_shared("odomPub_node");

  odomPub OP;

  RCLCPP_INFO(OP.nh_->get_logger(), "\033[1;32m----> OdomPub Node Started.\033[0m");

  // ros::MultiThreadedSpinner spinner(2);
  // spinner.spin();
  rclcpp::spin(OP.nh_);
  rclcpp::shutdown();
  return 0;
}
