#!/usr/bin/env python 
# -*- coding: utf-8 -*-  
#导入包
from re import T
from turtle import pu
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys,select,termios,tty

speed = 0.0 
turn = 0.0
one_control_flag = 0

info_p = '''
  ********这个是控制终端，请确保光标在这个脚本内********
    这个例程是键盘控制KKSwarm运动的节点
    W前进
    S后退
    A左转
    D右转

    大写后提速
    c或者空格 暂停。
    e切换控制单车
    q切换集体控制
    z 退出
'''
key_control = {
    'w':(0.2,0.0),
    's':(-0.2,0.0),
    'a':(0.0,1.0),
    'd':(0.0,-1.0),

    'W':(0.5,0.0),
    'S':(-0.5,0.0),
    'A':(0.0,3.0),
    'D':(0.0,-3.0)
}

def check_keys():
    global speed, turn, one_control_flag
    key = ''
    while key ==  '':
        key = get_one_key()
    if key in key_control.keys():
        speed = key_control[key][0]
        turn = key_control[key][1]
    elif key == ' ' or key == 'c' :
        speed = 0.0
        turn = 0.0
    elif key == 'z':
        exit()
    elif key == 'e' :
        one_control_flag = 1
        print("现在是单车控制！")
    elif key == "q":
        one_control_flag = 0
        print("现在是集体控制！")

def get_one_key():
    global settings
    tty.setraw(sys.stdin.fileno()) #通过raw标准化输入
    rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
    if rlist:
        key = sys.stdin.read(1) #获取捕获的键盘值
    else:
        key = ''

    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings) #终端参数配置
    return key


def main(args=None):
    global speed, turn, one_control_flag
    rclpy.init(args=args)

    node = Node("cmd_pub")   
    rate = node.create_rate(2)
    global settings 
    settings = termios.tcgetattr(sys.stdin) 
    pub1 = node.create_publisher(Twist,"/robot_1/cmd_vel", 5) 
    pub2 = node.create_publisher(Twist,"/robot_2/cmd_vel", 5) 
    pub3 = node.create_publisher(Twist,"/robot_3/cmd_vel", 5) 
    pub4 = node.create_publisher(Twist,"/robot_4/cmd_vel", 5) 
    pub5 = node.create_publisher(Twist,"/robot_5/cmd_vel", 5) 
    pub6 = node.create_publisher(Twist,"/robot_6/cmd_vel", 5) 
    pub7 = node.create_publisher(Twist,"/robot_7/cmd_vel", 5) 
    pub8 = node.create_publisher(Twist,"/robot_8/cmd_vel", 5) 
    pub9 = node.create_publisher(Twist,"/robot_9/cmd_vel", 5) 
    pub10 = node.create_publisher(Twist,"/robot_10/cmd_vel", 5) 

    one_control_flag = 0
    print(info_p)
    while rclpy.ok():
        speed = 0.0
        turn = 0.0
        check_keys()

        if  one_control_flag == 0:
            twist = Twist()
            twist.linear.x = speed; twist.linear.y = 0.0; twist.linear.z = 0.0
            twist.angular.x = 0.0; twist.angular.y = 0.0; twist.angular.z = turn
            pub1.publish(twist)
            pub2.publish(twist)
            pub3.publish(twist)
            pub4.publish(twist)
            pub5.publish(twist)
            pub6.publish(twist)
            pub7.publish(twist)
            pub8.publish(twist)
            pub9.publish(twist)
            pub10.publish(twist)
        else:
            speed = 0.0
            turn = 0.0
            twist = Twist()
            twist.linear.x = speed; twist.linear.y = 0.0; twist.linear.z = 0.0
            twist.angular.x = 0.0; twist.angular.y = 0.0; twist.angular.z = turn
            pub1.publish(twist)
            pub2.publish(twist)
            pub3.publish(twist)
            pub4.publish(twist)
            pub5.publish(twist)
            pub6.publish(twist)
            pub7.publish(twist)
            pub8.publish(twist)
            pub9.publish(twist)
            pub10.publish(twist)
            key = input("你想要控制几号车？ >")
            while one_control_flag == 1:
                check_keys()
                # twist = Twist()
                twist.linear.x = speed; twist.linear.y = 0.0; twist.linear.z = 0.0
                twist.angular.x = 0.0; twist.angular.y = 0.0; twist.angular.z = turn
                if key == '1':
                    pub1.publish(twist)
                if key == '2':
                    pub2.publish(twist)
                if key == '3':
                    pub3.publish(twist)
                if key == '4':
                    pub4.publish(twist)
                if key == '5':
                    pub5.publish(twist)
                if key == '6':
                    pub6.publish(twist)
                if key == '7':
                    pub7.publish(twist)
                if key == '8':
                    pub8.publish(twist)
                if key == '9':
                    pub9.publish(twist)
                if key == '10':
                    pub10.publish(twist)
        rclpy.spin_once(node)
        rate.sleep()

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
