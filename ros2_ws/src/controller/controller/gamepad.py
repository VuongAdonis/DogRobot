import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import subprocess
import time

class GamepadRecorder(Node):
    def __init__(self):
        super().__init__('gamepad_recorder')
        self.subscription = self.create_subscription(
            Joy,
            'joy',
            self.joy_callback,
            10
        )
        self.gamepad_values = []  # Danh sách lưu giá trị gamepad
        self.prev_time = time.time()
        self.count = 0
        
    def joy_callback(self, msg):
        # Lưu các giá trị buttons và axes
        # self.gamepad_values.append((msg.buttons, msg.axes))
        # self.get_logger().info(f'Buttons: {msg.buttons}, Axes: {msg.axes}')
        self.current_time = time.time()
        
        if self.current_time - self.prev_time > 5:
            self.prev_time = self.current_time
            print("Value save: ", msg.buttons, msg.axes)
            print("print count: ", self.count)
            self.count += 1

def main():
    rclpy.init()
    
    # Khởi động các nút ROS 2
    # joy_node = subprocess.Popen(['ros2', 'run', 'joy', 'joy_node'])
    # time.sleep(1)  # Đợi để đảm bảo rằng nút joy đã khởi động

    teleop_node = subprocess.Popen(['ros2', 'launch', 'teleop_twist_joy', 'teleop-launch.py', "joy_config:='xbox'"])
    time.sleep(1)  # Đợi để đảm bảo rằng teleop đã khởi động

    gamepad_recorder = GamepadRecorder()
    # Khởi động một tệp Python (joy.py) nếu cần thiết
    # joy_script = subprocess.Popen(['python3', 'joy.py'])
    # time.sleep(1)  # Đợi vui lòng

    # Khởi động echo
    # echo_process = subprocess.Popen(['ros2', 'topic', 'echo', '/joy'])

    try:
        # Chạy rclpy.spin để xử lý các sự kiện
        rclpy.spin(gamepad_recorder)
    except KeyboardInterrupt:
        # joy_node.terminate()
        teleop_node.terminate()
        # joy_script.terminate()
        # echo_process.terminate()
        gamepad_recorder.destroy_node()
        rclpy.shutdown()
        print("Đã dừng lại.")
        
if __name__ == '__main__':
    main()
