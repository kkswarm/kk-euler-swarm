#ifndef C6_FORMATION_ROS2__VISIBILITY_CONTROL_H_
#define C6_FORMATION_ROS2__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define C6_FORMATION_ROS2_EXPORT __attribute__ ((dllexport))
    #define C6_FORMATION_ROS2_IMPORT __attribute__ ((dllimport))
  #else
    #define C6_FORMATION_ROS2_EXPORT __declspec(dllexport)
    #define C6_FORMATION_ROS2_IMPORT __declspec(dllimport)
  #endif
  #ifdef C6_FORMATION_ROS2_BUILDING_LIBRARY
    #define C6_FORMATION_ROS2_PUBLIC C6_FORMATION_ROS2_EXPORT
  #else
    #define C6_FORMATION_ROS2_PUBLIC C6_FORMATION_ROS2_IMPORT
  #endif
  #define C6_FORMATION_ROS2_PUBLIC_TYPE C6_FORMATION_ROS2_PUBLIC
  #define C6_FORMATION_ROS2_LOCAL
#else
  #define C6_FORMATION_ROS2_EXPORT __attribute__ ((visibility("default")))
  #define C6_FORMATION_ROS2_IMPORT
  #if __GNUC__ >= 4
    #define C6_FORMATION_ROS2_PUBLIC __attribute__ ((visibility("default")))
    #define C6_FORMATION_ROS2_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define C6_FORMATION_ROS2_PUBLIC
    #define C6_FORMATION_ROS2_LOCAL
  #endif
  #define C6_FORMATION_ROS2_PUBLIC_TYPE
#endif
#endif  // C6_FORMATION_ROS2__VISIBILITY_CONTROL_H_
// Generated 21-Oct-2023 12:55:21
 