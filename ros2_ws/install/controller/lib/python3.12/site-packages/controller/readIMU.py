#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
import tf_transformations

class IMUListener(Node):
    def __init__(self):
        super().__init__('imu_listener')
        # Đăng ký lắng nghe topic /wit/raw_data
        self.subscription = self.create_subscription(
            Imu,
            '/wit/raw_data',
            self.listener_callback,
            10)
        self.subscription  # Tránh cảnh báo về biến không sử dụng

    def listener_callback(self, data):
        # Chuyển đổi quaternion thành góc Euler
        (roll, pitch, yaw) = tf_transformations.euler_from_quaternion(
            [data.orientation.x, data.orientation.y, data.orientation.z, data.orientation.w]
        )

        # Xuất ra kết quả ở dạng độ
        self.get_logger().info(
            f'Roll: {roll * 180 / 3.1415926:.3f}, Pitch: {pitch * 180 / 3.1415926:.3f}, Yaw: {yaw * 180 / 3.1415926:.3f}'
        )

def main(args=None):
    rclpy.init(args=args)
    imu_listener = IMUListener()
    rclpy.spin(imu_listener)  # Giữ cho nút nghe các tin nhắn đến
    imu_listener.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()