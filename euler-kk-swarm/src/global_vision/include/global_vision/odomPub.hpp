/*
 * @Author: Chaozheng Zhu && Loren
 * @Date: 2022-05-07 09:33:11
 * @LastEditTime: 2022-05-17 17:09:58
 * @FilePath:
 * /kk-robot-swarm/src/global_vision/include/global_vision/odomPub.hpp
 * @Description:
 *
 * Copyright (c) 2022 by AmovLab, All Rights Reserved.
 */
#pragma once

#include <geometry_msgs/msg/pose_stamped.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/transform_listener.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include "tf2/time.h"
#include "tf2/time_cache.h"
#include "tf2/convert.h"
#include "tf2/impl/convert.h"
#include "tf2_ros/buffer.h"
#include "tf2/buffer_core.h"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2/LinearMath/Vector3.h"
#include "tf2_ros/buffer_interface.h"
#include "geometry_msgs/msg/point_stamped.hpp"
#include "geometry_msgs/msg/quaternion_stamped.hpp"
#include "geometry_msgs/msg/transform.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs/msg/vector3_stamped.hpp"

#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "geometry_msgs/msg/pose_with_covariance.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include "geometry_msgs/msg/wrench.hpp"
#include "geometry_msgs/msg/wrench_stamped.hpp"

#include <iostream>
#include <map>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <sys/time.h>

#include "kkswarm_msgs/msg/kk_swarm_pose.hpp"
#include "kkswarm_msgs/msg/kk_swarm_state.hpp"

class odomPub {
 public:
  std::shared_ptr<rclcpp::Node> nh_;
  std::vector<rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr> odom_pub_set_;
  rclcpp::Subscription<kkswarm_msgs::msg::KKSwarmState>::SharedPtr communication_sub_;

  // car_odom_[1] means No.1 car's odom data.
  nav_msgs::msg::Odometry car_odom_[11];

  // car_pose_[1] means No.1 car's pose data.
  kkswarm_msgs::msg::KKSwarmPose car_pose_[11];

  std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
  //tf2_ros::TransformListener car_tf_listener_;
  std::shared_ptr<tf2_ros::TransformListener> car_tf_listener_;

  geometry_msgs::msg::TransformStamped transform_;
  tf2::Quaternion quat_;

  int car_total_num_ = 6;
  odomPub();
  ~odomPub() = default;

  /**
   * \brief: Subscribe TF data form camera.
   * \param: {*}
   * \return: {*}
   */
  void subFromTf();

  /**
   * \brief: Subscribe /comm topic from tcpDriverNode.cpp
   * \param: {*}
   * \return: {*}
   */
  void subFromTcp();

  /**
   * \brief: This callback save the car's id and linear speed and angular speed.
   * \param: {const kkswarm_msgs::kkSwarmState::ConstPtr: Custom msgs.
   *          See /kk-robot-swarm/src/kkswarm_msgs/msg/kkSwarmState.msg
   *          for more information.}
   * \return: {*}
   */
  void communicationCallBack(const kkswarm_msgs::msg::KKSwarmState::SharedPtr msgs);

  /**
   * \brief: Creates robot_x/base_link tf frame. x is car's id.
   * \param: {int mark: Car's id.}
   * \return: {std::string: robot_x/base_link tf frame}
   */
  std::string tfNameGenerate(int mark) {
    std::string front_str = "robot_";
    std::stringstream ss_base;
    std::string end_str_base = "/base_link";
    ss_base << front_str << mark << end_str_base;
    std::string tf_base = ss_base.str();
    return tf_base;
  }

  /**
   * \brief: Creates robot_x/pose topic. x is car's id.
   * \param: {int mark: Car's id.}
   * \return: {std::string: robot_x/pose topic name.}
   */
  std::string topicNameGenerate(int mark) {
    std::string front_str = "robot_";
    std::string end_str = "/pose";
    std::stringstream ssss;
    ssss << front_str << mark << end_str;
    std::string topic = ssss.str();
    return topic;
  }

  /**
   * \brief: Convert rad to degree.
   * \param: {double yaw: car's yaw in degree.}
   * \return: {double, car's yaw in rad.}
   */
  double convertDegree(double yaw) {
    if (yaw < 0) yaw = yaw + 2 * 3.1415926;
    return 180 * yaw / 3.1415926;
  }

  /** The code below is a simplified version of getEulerRPY that only
   * returns the yaw. It is mostly useful in navigation where only yaw
   * matters
   * \param q a tf2::Quaternion
   * \return the computed yaw
   */
  inline
  double getYaw(const tf2::Quaternion & q)
  {
    double yaw;

    double sqw;
    double sqx;
    double sqy;
    double sqz;

    sqx = q.x() * q.x();
    sqy = q.y() * q.y();
    sqz = q.z() * q.z();
    sqw = q.w() * q.w();

    // Cases derived from https://orbitalstation.wordpress.com/tag/quaternion/
    // normalization added from urdfom_headers
    double sarg = -2 * (q.x() * q.z() - q.w() * q.y()) / (sqx + sqy + sqz + sqw);

    if (sarg <= -0.99999) {
      yaw = -2 * atan2(q.y(), q.x());
    } else if (sarg >= 0.99999) {
      yaw = 2 * atan2(q.y(), q.x());
    } else {
      yaw = atan2(2 * (q.x() * q.y() + q.w() * q.z()), sqw + sqx - sqy - sqz);
    }
    return yaw;
  }
};