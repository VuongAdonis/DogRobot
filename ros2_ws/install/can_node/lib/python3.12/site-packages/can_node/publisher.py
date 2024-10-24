#!/user/bin/env/python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from custom_interfaces.msg import CANmessage

class PublishNode(Node):

    def __init__(self):
        super().__init__("Publish_Node")
        self.counter = 0
        self.publisher_ = self.create_publisher(CANmessage, 'topic', 10)
        timer_period = 1 # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = CANmessage()
        msg.name1 = "a"
        msg.name2 = "b"
        msg.name3 = "c"
        msg.name4 = "d"
        msg.positionrr = [1.0, 2.0, 3.0]
        msg.positionrl = [1.0, 2.0, 3.0]
        msg.positionfr = [1.0, 2.0, 3.0]
        msg.positionfl = [1.0, 2.0, 3.0]

        self.publisher_.publish(msg)
        self.get_logger().info("Publishing: '%s' " % msg)
        self.i += 1

def main(args=None):
    rclpy.init(args=args)

    Publish_node = PublishNode()
    rclpy.spin(Publish_node)
    Publish_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()