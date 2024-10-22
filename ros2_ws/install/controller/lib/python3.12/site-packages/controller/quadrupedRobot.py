# * File: quadrupedRobot.py
# * Author: ROBOT_DOG_TEAM
# * Creation Date: October 17, 2024
# * Last Modified: October 17, 2024
# * Description: the program to control all operations of robot
# * Status: developing (Done, brainStorm, developing):


from controller.kinematicRobot import coordinatePoint, kinematicEachLeg
from controller.convertGlobal2LocalCoordinate import leg
import sys
sys.path.append("../../can_node/can_node")
from can_node.canController import CanNode
import time
from math import pi, atan2

# for gamepad
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import String
import subprocess
import time


#---------------------------------------------------------------------------------------------------------------------#
# Class quadrupedRobot: the main class to control all operations of quadruped robot
# Parameters:
#    - globalCoordinateFL: global coordinate of FL leg
#    - globalCoordinateFR: global coordinate of FR leg
#    - globalCoordinateRR: global coordinate of RR leg
#    - globalCoordinateRL: global coordinate of RL leg
#    - legFL: the object is on behalf of leg front left 
#    - legFR: the object is on behalf of leg front right
#    - legRR: the object is on behalf of leg rear right
#    - legRL: the object is on behalf of leg rear left   
class quadrupedRobot:
  
  def __init__(self):
    # may be modified x and z, not y
    globalCoordinateFL = coordinatePoint(-330, 161.12, -187)    
    globalCoordinateFR = coordinatePoint(-330, -161.12, -187) 
    globalCoordinateRL = coordinatePoint(-330, 161.12, 187) 
    globalCoordinateRR = coordinatePoint(-330, -161.12, 187)
    
    self.legFL = kinematicEachLeg(globalCoordinateFL, leg.FL.value)
    self.legRR = kinematicEachLeg(globalCoordinateRR, leg.RR.value)
    self.legRL = kinematicEachLeg(globalCoordinateRL, leg.RL.value)
    self.legFR = kinematicEachLeg(globalCoordinateFR, leg.FR.value)
    
  def updateTrajectoryAllLegs(self, vectorAngle):
    self.trajectoryRROriginal = self.legRR.updateTrajectoryLeg(deviation = 35, angleVector= vectorAngle)
    self.trajectoryRLOriginal = self.legRL.updateTrajectoryLeg(deviation = 35, angleVector= vectorAngle)
    self.trajectoryFROriginal = self.legFR.updateTrajectoryLeg(deviation = 35, angleVector= vectorAngle)
    self.trajectoryFLOriginal = self.legFL.updateTrajectoryLeg(deviation = 35, angleVector= vectorAngle)
    
    # if abs(vectorAngle) <= atan2(161.12, 187):
    #   self.trajectoryRRTemp = trajectoryRROriginal      
    #   self.trajectoryRLTemp = trajectoryRLOriginal
    #   self.trajectoryFRTemp = trajectoryFROriginal
    #   self.trajectoryFLTemp = trajectoryFLOriginal
    
    # else:
    #   if abs(vectorAngle) <= (pi - atan2(161.12, 187)):
    #     if vectorAngle < 0:
    #       self.trajectoryRRTemp = trajectoryFROriginal
    #       self.trajectoryRLTemp = trajectoryRROriginal
    #       self.trajectoryFRTemp = trajectoryFLOriginal
    #       self.trajectoryFLTemp = trajectoryRLOriginal
    #     else:
    #       self.trajectoryRRTemp = trajectoryRLOriginal
    #       self.trajectoryRLTemp = trajectoryFLOriginal
    #       self.trajectoryFRTemp = trajectoryRROriginal
    #       self.trajectoryFLTemp = trajectoryFROriginal
    #   else:
    #     self.trajectoryRRTemp = trajectoryFLOriginal
    #     self.trajectoryRLTemp = trajectoryFROriginal
    #     self.trajectoryFRTemp = trajectoryRLOriginal
    #     self.trajectoryFLTemp = trajectoryRROriginal
        
  def getTrajectory(self):
    return self.trajectoryRROriginal, self.trajectoryRLOriginal, self.trajectoryFROriginal, self.trajectoryFLOriginal
    # return self.trajectoryRRTemp, self.trajectoryRLTemp, self.trajectoryFRTemp, self.trajectoryFLTemp
#---------------------------------------------------------------------------------------------------------------------#

class GamepadRecorder(Node):
    def __init__(self):
        super().__init__('gamepad_recorder')
        self.subscription = self.create_subscription(
            Joy, # message type
            'joy', # topic
            self.joy_callback, # callback function
            10 # queue size
        )
        self.publisher_ = self.create_publisher(String, 'topic', 10)
        self.gamepad_values = []  # Danh sách lưu giá trị gamepad
        self.prev_time = time.time()
        self.count = 0
    
    # function to send the message to the node control
    def publishMessage(self):
        msg = String()
        self.publisher_.publish(msg)

    # function process input get from the teleop
    def joy_callback(self, msg):
        self.current_time = time.time()
        
        if self.current_time - self.prev_time > 1:
            self.prev_time = self.current_time
            print("Value save: ", msg.buttons, msg.axes)

            print("joy1 value X: ", msg.axes[0])
            print("joy1 value Y: ", msg.axes[1])
            print("joy1 type X: ", type(msg.axes[0]))
            print("joy1 type Y: ", type(msg.axes[1]))

            print("print count: ", self.count)
            self.count += 1

            angleVector = atan2(-msg.axes[0], msg.axes[1])   # updated from the gamePad
            robotDogTeam = quadrupedRobot()
              
            robotDogTeam.updateTrajectoryAllLegs(angleVector)
            trajectoryRR, trajectoryRL, trajectoryFR, trajectoryFL = robotDogTeam.getTrajectory()
            print("----------------TRAJECTORY-----------------")
            for i in range(len(trajectoryFL)):
              print("-------------point", i+ 1, "------------------")
              print("FL:", trajectoryFL[i])
              # print("RL:", trajectoryRL[i])
              # print("FR:", trajectoryFR[i])
              # print("FL:", trajectoryFL[i])
            print("#############################################")

def main():
  # angleVector = atan2(-x, y)   # updated from the gamePad
  # robotDogTeam = quadrupedRobot()
    
  # robotDogTeam.updateTrajectoryAllLegs(angleVector)
  # trajectoryRR, trajectoryRL, trajectoryFR, trajectoryFL = robotDogTeam.getTrajectory()
  # print("----------------TRAJECTORY-----------------")
  # for i in range(len(trajectoryRR)):
  #   print("-------------point", i+ 1, "------------------")
  #   print("RR:", trajectoryRR[i])
  #   # print("RL:", trajectoryRL[i])
  #   # print("FR:", trajectoryFR[i])
  #   # print("FL:", trajectoryFL[i])
  # print("#############################################")
      
    rclpy.init()
    # use teleop to get the input of xbox gamepad
    teleop_node = subprocess.Popen(['ros2', 'launch', 'teleop_twist_joy', 'teleop-launch.py', "joy_config:='xbox'"])
    time.sleep(1)  # wait for teleop run

    gamepad_recorder = GamepadRecorder()

    rclpy.spin(gamepad_recorder)
    teleop_node.terminate()
    gamepad_recorder.destroy_node()
    rclpy.shutdown()
    
  # CAN = CanNode()
  # CAN.sendClosedLoop(5)
  # time.sleep(1)
  # CAN.sendClosedLoop(4)
  # time.sleep(1)
  # CAN.sendClosedLoop(1)
  # time.sleep(1)
  # CAN.sendClosedLoop(2)
  # time.sleep(1)
  # try:
  #   idxRR = 4
  #   idxFR = 6
  #   while True:
      
  #     CAN.sendPos(5, trajectoryFR[idxFR][2])
  #     time.sleep(1)
  #     CAN.sendPos(4, trajectoryFR[idxFR][1])
  #     time.sleep(1)
  #     CAN.sendPos(2, trajectoryRR[idxRR][1])
  #     time.sleep(1)
  #     CAN.sendPos(1, trajectoryRR[idxRR][2])
  #     time.sleep(1)
  #     idxRR -= 1
  #     idxFR -= 1
  #     if idxRR < 0:
  #       idxRR = 7
  #     if idxFR < 0:
  #       idxFR = 7

  # except KeyboardInterrupt:
  #   CAN.sendIdle(5)
  #   time.sleep(1)
  #   CAN.sendIdle(4)
  #   time.sleep(1)
  #   CAN.sendIdle(1)
  #   time.sleep(1)
  #   CAN.sendIdle(2)
  #   time.sleep(1)
  #   CAN.bus.shutdown()
  


if __name__ == "__main__":
  main()
  