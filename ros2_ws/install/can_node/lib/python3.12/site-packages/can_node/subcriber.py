#!/user/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from custom_interfaces.msg import CANmessage
import can

class SubscriberNode(Node):
    def __init__(self):
        super().__init__("Subcriber_Node")
        self.subscription = self.create_subscription(
            CANmessage,
            'CAN_topic',
            self.listener_callback,
            10
        )
        self.count = 0
        self.subscription #prevent unsued variable warning

    def listener_callback(self, msg):
        self.get_logger().info("I heard data: '%s'" % msg)
        self.get_logger().info("I heard type data: '%s'" % type(msg))
        self.get_logger().info("#################")
        self.count += 1
        


def main(args=None):
    rclpy.init(args=args)
    subscriber_node = SubscriberNode()
    try:
        # run rclpy.spin to process the event
        rclpy.spin(subscriber_node)
    except KeyboardInterrupt:
        subscriber_node.destroy_node()
        rclpy.shutdown()
        print("Stop completed")

if __name__ == '__main__':
    main()