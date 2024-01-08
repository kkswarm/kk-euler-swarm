#include <camera_info_manager/camera_info_manager.hpp>
#include <ctype.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.hpp>
#include <rclcpp/rclcpp.hpp>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include <cmath>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "camtoros/init_camera.h"

int main(int argc, char** argv) {
  // boost::shared_ptr<camera_info_manager::CameraInfoManager> caminfo;
  rclcpp::init(argc, argv);
  rclcpp::Node::SharedPtr nh = rclcpp::Node::make_shared("image_pub");
  image_transport::ImageTransport main_cam_image(nh);
  image_transport::CameraPublisher cam_pub =
      main_cam_image.advertiseCamera("/hik_camera/image_raw", 100);

  sensor_msgs::msg::CameraInfo camerainfo_msg;
  sensor_msgs::msg::Image image_msg;

  cv_bridge::CvImagePtr cv_ptr = std::make_shared<cv_bridge::CvImage>();
  cv_ptr->encoding = sensor_msgs::image_encodings::MONO8;
  camera_info_manager::CameraInfoManager caminfo(
      nh.get(), "hik_camera",
      "file:///home/root/kk-robot-swarm/src/camtoros/config/caminfo.yaml");

  EnumDevice();
  InitCamera();

  // struct timeval lastTime, currentTime;
  // float consumeTime;
  // gettimeofday(&lastTime, NULL);

  cv::Mat src;

  rclcpp::Rate loop_rate(10);
  double consumeTime;
  rclcpp::Time currentTime, lastTime;
  lastTime = nh->now();

  while (rclcpp::ok()) {
    StartGrabStream(src);

    cv_ptr->image = src;
    image_msg = *(cv_ptr->toImageMsg());
    camerainfo_msg = caminfo.getCameraInfo();
    image_msg.header.stamp = nh->now();
    image_msg.header.frame_id = "hik_camera";
    camerainfo_msg.header.frame_id = image_msg.header.frame_id;
    camerainfo_msg.header.stamp = image_msg.header.stamp;
    cam_pub.publish(image_msg, camerainfo_msg);
    rclcpp::spin_some(nh);
    // calculate time
    currentTime = nh->now();
    consumeTime = currentTime.seconds() - lastTime.seconds();
    cout << "image fps: " << 1 / consumeTime << "Hz" << endl;
    lastTime = currentTime;
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}
