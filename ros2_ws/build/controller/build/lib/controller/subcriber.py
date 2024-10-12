#!/user/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import can

class SubscriberNode(Node):
    def __init__(self):
        super().__init__("Subcriber_Node")
        self.subscription = self.create_subscription(
            String,
            'topic',
            self.listener_callback,
            10
        )
        self.count = 0
        self.subscription #prevent unsued variable warning

    def listener_callback(self, msg):
        self.get_logger().info("I heard: '%s'" % msg.data)
        self.count += 1
        if self.count == 10:
            bus = can.interface.Bus(bustype='slcan', channel='/dev/ttyACM0', bitrate=500000)
            # CLOSED LOOP
            try:
                id_ = 0x1<< 5 | 0x07
                msg = can.Message(arbitration_id=0x27,
                            data=[0x08, 0x00, 0x00, 0x00],
                            dlc= 4,
                            is_extended_id=False
                            )
                
                bus.send(msg)
            except can.CanError:
                print("Message NOT sent")
            #shutdown slcan
            bus.shutdown()  # Hoặc sử dụng 'bus.close()' nếu có phương thức này
            print("SLCAN bus đã được tắt đúng cách.")


def main(args=None):
    rclpy.init(args=args)
    subscriber_node = SubscriberNode()
    rclpy.spin(subscriber_node)
    subscriber_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()