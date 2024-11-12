import rclpy
from rclpy.node import Node
import tf2_ros
import geometry_msgs.msg
from sensor_msgs.msg import JointState

class TFPublisher(Node):
    def __init__(self):
        super().__init__('joint_state_publisher')
        self.tf_broadcaster = tf2_ros.TransformBroadcaster(self)
        self.publisher_ = self.create_publisher(JointState, '/joint_states', 10)
        self.timer = self.create_timer(1, self.publish_joint_states)

    def publish_joint_states(self):
        joint_state = JointState()
        joint_state.header.stamp = self.get_clock().now().to_msg()
        joint_state.name = ['shoulder_joint_fr_to_base', 'thigh_joint_fr_to_shoulder_fr', 'shank_joint_fr_to_thigh_fr']
        joint_state.position = [0.5, 0.0, 0.0]
        self.publisher_.publish(joint_state)

        # Cập nhật phép biến đổi cho các khớp
        self.publisher_.publish(joint_state)
        print("publish value......")
        self.publish_transforms(joint_state.position)

    def publish_transforms(self, positions):
        # Publisher transform cho mỗi khớp
        transform = geometry_msgs.msg.TransformStamped()
        transform.header.stamp = self.get_clock().now().to_msg()
        transform.header.frame_id = 'base_link'  # Khung cơ sở
        transform.child_frame_id = 'shoulder_joint_fr_to_base'  # Khung con
        
        # Tính toán vị trí dựa trên vị trí góc
        transform.transform.translation.x = 0.0  # Cần tính toán x từ góc
        transform.transform.translation.y = 0.0  # Cần tính toán y từ góc
        transform.transform.translation.z = 0.0
        
        # Cập nhật quaternion cho hướng
        transform.transform.rotation.x = 0.5
        transform.transform.rotation.y = 0.0
        transform.transform.rotation.z = 0.0
        transform.transform.rotation.w = 1.0  # Giả sử không có quay

        self.tf_broadcaster.sendTransform(transform)
        print("send information to TF...")

def main(args=None):
    rclpy.init(args=args)
    node = TFPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
