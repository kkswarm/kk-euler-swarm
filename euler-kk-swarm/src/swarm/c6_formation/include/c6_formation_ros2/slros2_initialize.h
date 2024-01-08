// Copyright 2022 The MathWorks, Inc.
// Generated 21-Oct-2023 12:55:14
#ifndef _SLROS2_INITIALIZE_H_
#define _SLROS2_INITIALIZE_H_
#include "c6_formation_ros2_types.h"
// Generic pub-sub header
#include "slros2_generic_pubsub.h"
// Generic service header
#include "slros2_generic_service.h"
extern rclcpp::Node::SharedPtr SLROSNodePtr;
#ifndef SET_QOS_VALUES
#define SET_QOS_VALUES(qosStruct, hist, dep, dur, rel)  \
    {                                                   \
        qosStruct.history = hist;                       \
        qosStruct.depth = dep;                          \
        qosStruct.durability = dur;                     \
        qosStruct.reliability = rel;                    \
    }
#endif
inline rclcpp::QoS getQOSSettingsFromRMW(const rmw_qos_profile_t& qosProfile) {
    rclcpp::QoS qos(rclcpp::QoSInitialization::from_rmw(qosProfile));
    if (RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL == qosProfile.durability) {
        qos.transient_local();
    } else {
        qos.durability_volatile();
    }
    if (RMW_QOS_POLICY_RELIABILITY_RELIABLE == qosProfile.reliability) {
        qos.reliable();
    } else {
        qos.best_effort();
    }
    return qos;
}
// c6_formation_ros2/Subsystem/Command Velocity Publisher/Publish
extern SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_c6_formation_ros2_16722;
// c6_formation_ros2/Subsystem/Command Velocity Publisher1/Publish
extern SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_c6_formation_ros2_16728;
// c6_formation_ros2/Subsystem/Command Velocity Publisher2/Publish
extern SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_c6_formation_ros2_16734;
// c6_formation_ros2/Subsystem/Command Velocity Publisher3/Publish
extern SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_c6_formation_ros2_16740;
// c6_formation_ros2/Subsystem/Command Velocity Publisher4/Publish
extern SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_c6_formation_ros2_16746;
// c6_formation_ros2/Subsystem/Command Velocity Publisher5/Publish
extern SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_c6_formation_ros2_16752;
// c6_formation_ros2/Subsystem/Car Pose Listener/Subscribe2
extern SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_c6_formation_ros2_16753;
// c6_formation_ros2/Subsystem/Car Pose Listener/Subscribe3
extern SimulinkSubscriber<kkswarm_msgs::msg::KKSwarmState,SL_Bus_kkswarm_msgs_KKSwarmState> Sub_c6_formation_ros2_16754;
// c6_formation_ros2/Subsystem/Car Pose Listener1/Subscribe2
extern SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_c6_formation_ros2_16981;
// c6_formation_ros2/Subsystem/Car Pose Listener1/Subscribe3
extern SimulinkSubscriber<kkswarm_msgs::msg::KKSwarmState,SL_Bus_kkswarm_msgs_KKSwarmState> Sub_c6_formation_ros2_16982;
// c6_formation_ros2/Subsystem/Car Pose Listener2/Subscribe2
extern SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_c6_formation_ros2_17026;
// c6_formation_ros2/Subsystem/Car Pose Listener2/Subscribe3
extern SimulinkSubscriber<kkswarm_msgs::msg::KKSwarmState,SL_Bus_kkswarm_msgs_KKSwarmState> Sub_c6_formation_ros2_17027;
// c6_formation_ros2/Subsystem/Car Pose Listener3/Subscribe2
extern SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_c6_formation_ros2_17071;
// c6_formation_ros2/Subsystem/Car Pose Listener3/Subscribe3
extern SimulinkSubscriber<kkswarm_msgs::msg::KKSwarmState,SL_Bus_kkswarm_msgs_KKSwarmState> Sub_c6_formation_ros2_17072;
// c6_formation_ros2/Subsystem/Car Pose Listener4/Subscribe2
extern SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_c6_formation_ros2_17116;
// c6_formation_ros2/Subsystem/Car Pose Listener4/Subscribe3
extern SimulinkSubscriber<kkswarm_msgs::msg::KKSwarmState,SL_Bus_kkswarm_msgs_KKSwarmState> Sub_c6_formation_ros2_17117;
// c6_formation_ros2/Subsystem/Car Pose Listener5/Subscribe2
extern SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_c6_formation_ros2_17161;
// c6_formation_ros2/Subsystem/Car Pose Listener5/Subscribe3
extern SimulinkSubscriber<kkswarm_msgs::msg::KKSwarmState,SL_Bus_kkswarm_msgs_KKSwarmState> Sub_c6_formation_ros2_17162;
#endif
