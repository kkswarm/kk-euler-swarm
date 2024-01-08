#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto nh = rclcpp::Node::make_shared("stop");
  geometry_msgs::msg::Twist vel;
  vel.linear.x = 0.0;
  vel.angular.z = 0.0;
  vector<rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr> stop_pub;
  rclcpp::Rate rate(20);

  string front_str = "/robot_";
  string end_str = "/cmd_vel";

  for (int i = 1; i <= 10; i++) {
    stringstream ss;
    ss << front_str << i << end_str;
    string topic = ss.str();
    auto pub = nh->create_publisher<geometry_msgs::msg::Twist>(topic, 10);
    stop_pub.push_back(pub);
  }

  while (rclcpp::ok()) {

    for (int j = 1; j <= 10; j++) {
      stringstream ss;
      ss << front_str << j << end_str;
      string topic = ss.str();
      if (stop_pub[j - 1]->get_topic_name() == topic) {
        stop_pub[j - 1]->publish(vel);
        RCLCPP_INFO(nh->get_logger(), "Publishing %s ...\n", stop_pub[j - 1]->get_topic_name());
      }
    }
    rclcpp::spin_some(nh);
    rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}