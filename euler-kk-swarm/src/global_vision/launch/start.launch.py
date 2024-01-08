from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='global_vision',
            executable='odometryPub',
            name='odometryPub',
            output='screen',
            emulate_tty=True
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='map_hik_broadcaster',
            arguments=['0', '2', '4', '1', '0', '0', '0', 'map', 'hik_camera']
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='odom_broadcaster_1',
            arguments=['0', '0', '0', '0', '0', '0', 'map', 'robot_1/odom']
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='tag_base_broadcaster_1',
            arguments=['0', '0', '0', '1', '0', '0', '0', 'tag_1', 'robot_1/base_link']
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='odom_broadcaster_2',
            arguments=['0', '0', '0', '0', '0', '0', 'map', 'robot_2/odom']
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='tag_base_broadcaster_2',
            arguments=['0', '0', '0', '1', '0', '0', '0', 'tag_2', 'robot_2/base_link']
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='odom_broadcaster_3',
            arguments=['0', '0', '0', '0', '0', '0', 'map', 'robot_3/odom']
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='tag_base_broadcaster_3',
            arguments=['0', '0', '0', '1', '0', '0', '0', 'tag_3', 'robot_3/base_link']
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='odom_broadcaster_4',
            arguments=['0', '0', '0', '0', '0', '0', 'map', 'robot_4/odom']
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='tag_base_broadcaster_4',
            arguments=['0', '0', '0', '1', '0', '0', '0', 'tag_4', 'robot_4/base_link']
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='odom_broadcaster_5',
            arguments=['0', '0', '0', '0', '0', '0', 'map', 'robot_5/odom']
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='tag_base_broadcaster_5',
            arguments=['0', '0', '0', '1', '0', '0', '0', 'tag_5', 'robot_5/base_link']
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='odom_broadcaster_6',
            arguments=['0', '0', '0', '0', '0', '0', 'map', 'robot_6/odom']
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='tag_base_broadcaster_6',
            arguments=['0', '0', '0', '1', '0', '0', '0', 'tag_6', 'robot_6/base_link']
        ),
    ])
