#!/usr/bin/env python

import sys
import rclpy
from rclpy.node import Node
import cv2 as cv
import matplotlib.pyplot as plt
#import numpy as np


from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

class calibrator_reference(Node):

  def __init__(self):
    super().__init__('calibrator_reference')
    self.image_pub = self.create_publisher(Image, "/reference_rectangle/image_raw", 1)
    
    self.bridge = CvBridge()
    self.image_sub = self.create_subscription(Image, "/hik_camera/image_raw", self.callback, 1)

  def callback(self,data):
    try:
      image = self.bridge.imgmsg_to_cv2(data, "bgr8")
    except CvBridgeError as e:
      print(e)

    size = image.shape
    # draw reference rectangle
    first_point = (210, 150)
    last_point = (1010, 950)

    cv.rectangle(image, first_point, last_point, (0, 255, 0), 2)
    # cv.imshow("output", image)
    # cv.waitKey(1)

    try:
      msg = self.bridge.cv2_to_imgmsg(image, "bgr8")
      msg.header.stamp = self.get_clock().now().to_msg()
      msg.header.frame_id = 'hik_camera'
      self.image_pub.publish(msg)
    except CvBridgeError as e:
      print(e)


def main(args=None):
  rclpy.init(args=args)
  node = calibrator_reference()

  plt.ion()
  print('calibrator reference running...')
  try:
    rclpy.spin(node)
  except KeyboardInterrupt:
    print("Shutting down")
  
  cv.destroyAllWindows()
#   rclpy.shutdown()

if __name__ == '__main__':
    main()