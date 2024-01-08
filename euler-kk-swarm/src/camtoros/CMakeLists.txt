cmake_minimum_required(VERSION 3.8)
project(camtoros)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_compile_options(-Wno-missing-field-initializers)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(image_transport REQUIRED)
find_package(camera_info_manager REQUIRED)

set(MVS_INCLUDE_DIRS "/opt/MVS/include/")
if (${CMAKE_SYSTEM_PROCESSOR} MATCHES "x86_64")
  set(MVS_LINK_INCLUDE_DIRS "/opt/MVS/lib/64/")
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "aarch64")
  set(MVS_LINK_INCLUDE_DIRS "/opt/MVS/lib/aarch64/")
else()
  set(MVS_LINK_INCLUDE_DIRS "")
endif()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/include
  ${MVS_INCLUDE_DIRS}
)

link_directories(
  ${PROJECT_SOURCE_DIR}/libs
  ${MVS_LINK_INCLUDE_DIRS}
)

set(THIRD_PARTY_LIBS
  ${OpenCV_LIBS}
  MvCameraControl
)

add_library(GlobalVisionROSLibrary SHARED 
  init/init_camera.cc
)
target_link_libraries(GlobalVisionROSLibrary ${THIRD_PARTY_LIBS})

add_executable(camtoros src/camtoros.cpp)
target_link_libraries(camtoros ${THIRD_PARTY_LIBS} GlobalVisionROSLibrary)
ament_target_dependencies(camtoros rclcpp cv_bridge image_transport camera_info_manager)

# install
install(TARGETS 
  camtoros
  GlobalVisionROSLibrary
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

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
