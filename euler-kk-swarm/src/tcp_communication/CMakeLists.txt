cmake_minimum_required(VERSION 3.8)
project(tcp_communication)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(kkswarm_msgs REQUIRED)

## System dependencies are found with CMake's conventions
set(Boost_NO_WARN_NEW_VERSIONS 1)
find_package(Boost REQUIRED COMPONENTS thread)
find_package(OpenCV REQUIRED)
message(STATUS "version: ${OpenCV_VERSION}")

message(STATUS "---OpenCV_INCLUDE_DIRS=${OpenCV_INCLUDE_DIRS}---")
message(STATUS "---OpenCV_LIBS=${OpenCV_LIBS}---")

message(STATUS "---Boost_INCLUDE_DIRS=${Boost_INCLUDE_DIRS}---")
message(STATUS "---Boost_LIBRARIES=${Boost_LIBRARIES}---")
message(STATUS "---Boost_VERSION=${Boost_VERSION}---")

message(STATUS "---kkswarm_msgs_INCLUDE_DIRS=${kkswarm_msgs_INCLUDE_DIRS}---")
message(STATUS "---kkswarm_msgs_LIBRARIES=${kkswarm_msgs_LIBRARIES}---")

message(STATUS "---rclcpp_INCLUDE_DIRS=${rclcpp_INCLUDE_DIRS}---")
message(STATUS "---rclcpp_LIBRARIES=${rclcpp_LIBRARIES}---")

set(dependencies
  rclcpp
  kkswarm_msgs
)

add_executable(tcpDriverNode src/tcpDriverNode.cpp)
target_include_directories(tcpDriverNode PUBLIC
  include
  ${OpenCV_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)
target_link_libraries(tcpDriverNode 
  -lpthread
  ${OpenCV_LIBS}
  ${Boost_LIBRARIES}
)
ament_target_dependencies(tcpDriverNode ${dependencies})

install(TARGETS tcpDriverNode
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
)

ament_export_include_directories(include)
ament_export_dependencies(${dependencies})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
