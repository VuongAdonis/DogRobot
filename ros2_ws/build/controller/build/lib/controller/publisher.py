#!/user/bin/env/python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class PublishNode(Node):

    def __init__(self):
        super().__init__("Publish_Node")
        self.counter = 0
        self.publisher_ = self.create_publisher(String, 'topic', 10)
        timer_period = 1 # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = String()
        msg.data = 'Hello world: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info("Publishing: '%s'" % msg.data)
        self.i += 1

def main(args=None):
    rclpy.init(args=args)

    Publish_node = PublishNode()
    rclpy.spin(Publish_node)
    Publish_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()