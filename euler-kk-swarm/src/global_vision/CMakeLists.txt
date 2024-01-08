cmake_minimum_required(VERSION 3.5)
project(global_vision)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(kkswarm_msgs REQUIRED)

## System dependencies are found with CMake's conventions
set(Boost_NO_WARN_NEW_VERSIONS 1)
find_package(Boost REQUIRED COMPONENTS thread)
find_package(OpenCV REQUIRED)
# message( "version: ${OpenCV_VERSION}")
# message( "---Boost_INCLUDE_DIRS=${Boost_INCLUDE_DIRS}---")
# message( "---Boost_LIBRARIES=${Boost_LIBRARIES}---")
# message( "---Boost_VERSION=${Boost_VERSION}---")

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
)

set(THIRD_PARTY_LIBS
    ${OpenCV_LIBS}
  	#MvCameraControl
)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(odometryPub src/odomPub.cpp)
target_include_directories(odometryPub PUBLIC
  include
  ${OpenCV_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)
target_link_libraries(odometryPub
  -lpthread
  ${OpenCV_LIBS}
  ${Boost_LIBRARIES}
  ${geometry_msgs_TARGETS}
  ${tf2_geometry_msgs_TARGETS}
)

ament_target_dependencies(odometryPub 
  rclcpp
  geometry_msgs
  kkswarm_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
  nav_msgs
  std_msgs
)

add_executable(stop src/stop.cpp)
target_link_libraries(stop)
ament_target_dependencies(stop 
  rclcpp
  geometry_msgs
)

install(TARGETS odometryPub stop
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
)

install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
