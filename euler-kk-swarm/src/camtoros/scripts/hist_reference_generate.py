#!/usr/bin/env python

#import roslib
import sys
import rclpy
from rclpy.node import Node
import cv2 as cv
from matplotlib import pyplot as plt
#import numpy as np


from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

class hist_reference_generate(Node):

  def __init__(self):
    super().__init__('hist_reference_generate')
    self.bridge = CvBridge()
    self.image_sub = self.create_subscription(Image, "/hik_camera/image_raw", self.callback, 1)

  def callback(self,data):
    # plt.clf()
    try:
      image = self.bridge.imgmsg_to_cv2(data, "bgr8")
    except CvBridgeError as e:
      print(e)
    plt.hist(image.ravel(), 256, [0, 256]) 
    plt.savefig("1.png")
    # plt.show()
    print("saving...")
    sys.exit(0)


def main(args=None):
  rclpy.init(args=args)
  node = hist_reference_generate()
  # plt.ion()
  try:
    rclpy.spin(node)
  except KeyboardInterrupt:
    print("Shutting down")
  
  cv.destroyAllWindows()
#   rclpy.shutdown()

if __name__ == '__main__':
    main()