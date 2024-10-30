import sys

import rclpy
from rclpy.node import Node
from custom_interfaces.srv import IMU

class AdditionClientAsync(Node):
    def __init__(self):
        super().__init__("addition_client_async")
        self.client = self.create_client(IMU, "imu")
        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("service not available, waiting again...")

    def send_request(self):
        request = IMU.Request()
        # request.a = int(sys.argv[1])
        # request.b = int(sys.argv[2])
        self.future = self.client.call_async(request)

def main(args=None):
    rclpy.init(args=args)

    # create node
    addition_client= AdditionClientAsync()

    addition_client.send_request()
    # use/spin node
    while rclpy.ok():
        rclpy.spin_once(addition_client)
        if addition_client.future.done():
            try:
                response = addition_client.future.result()
            except Exception as e:
                addition_client.get_logger().info(
                    f"Service call failed {e}"
                )
            else:
                addition_client.get_logger().info(
                    f"Result of addition is {response.angle}"
                )
                break
                

    # destroy node and shutdown
    addition_client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()