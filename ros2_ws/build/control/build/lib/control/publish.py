import rclpy
from rclpy.node import Node
import tf2_ros
import geometry_msgs.msg
from sensor_msgs.msg import JointState
from custom_interfaces.srv import CANsrv

class TFPublisher(Node):
    def __init__(self):
        super().__init__('joint_state_publisher')
        self.tf_broadcaster = tf2_ros.TransformBroadcaster(self)
        self.publisher_ = self.create_publisher(JointState, '/joint_states', 10)
        # self.timer = self.create_timer(1.0, self.publish_joint_states)
        self.service = self.create_service(
            CANsrv,
            "cansrv",
            self.CAN_listen_callback
        )

    def CAN_listen_callback(self, request, response):
        self.get_logger().info(f"Incoming request\n")
        posRR = request.positionrr
        posRL = request.positionrl
        posFR = request.positionfr
        posFL = request.positionfl
        self.publish_joint_states(posRR, posRL, posFR, posFL)
        response.can_done = True
        return response

        

    def publish_joint_states(self, posRR, posRL, posFR, posFL):
        joint_state = JointState()
        joint_state.header.stamp = self.get_clock().now().to_msg()
        joint_state.name = ['shoulder_joint_rr_to_base', 'thigh_joint_rr_to_shoulder_rr', 'shank_joint_rr_to_thigh_rr',
                            'shoulder_joint_rl_to_base', 'thigh_joint_rl_to_shoulder_rl', 'shank_joint_rl_to_thigh_rl',
                            'shoulder_joint_fr_to_base', 'thigh_joint_fr_to_shoulder_fr', 'shank_joint_fr_to_thigh_fr',
                            'shoulder_joint_fl_to_base', 'thigh_joint_fl_to_shoulder_fl', 'shank_joint_fl_to_thigh_fl'
                            ]
        joint_state.position = [posRR[0], posRR[1], posRR[2],
                                posRL[0], posRL[1], posRL[2],
                                posFR[0], posFR[1], posFR[2],
                                posFL[0], posFL[1], posFL[2]
                                ]
        self.publisher_.publish(joint_state)

        # Cập nhật phép biến đổi cho các khớp
        self.publisher_.publish(joint_state)
        print("publish value......")
        # self.publish_transforms(joint_state.position)

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
        transform.transform.rotation.x = 0.0
        transform.transform.rotation.y = 0.0
        transform.transform.rotation.z = 0.0
        transform.transform.rotation.w = 1.0  # Giả sử không có quay

        self.tf_broadcaster.sendTransform(transform)
        print("send information to TF...")

def main(args=None):
    rclpy.init(args=args)
    print("start")
    node = TFPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
