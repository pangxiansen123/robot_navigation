#!/usr/bin/env python
# coding:utf-8
import sys
import time
import signal
import rospy
from get_coordinate.msg import position #导入位置消息
from nav_msgs.msg import Odometry#导入里程计消息
from sensor_msgs.msg import Imu#导入陀螺仪数据
from multisensor_information_fusion.msg import pose  #发布滤波后的消息
import numpy as np
from extended_kalman_filter import EKF
import threading
import matplotlib.pyplot as plt
import multiprocessing
from show_trajectory import show_traject

def quit(signum, frame):
    print ''
    print 'stop fusion'
    sys.exit()

class Fusion:
    def __init__(self):
        signal.signal(signal.SIGINT, quit)
        signal.signal(signal.SIGTERM, quit)        
        self.raw_x = 0.1
        self.raw_y = 0.1
        self.raw_yaw = 0.001
        self.raw_v = 0.001
        self.raw_yaw_v = 0.001
        #ros initial
        rospy.init_node('listener', anonymous=True)
        #subscriber sensor topic
        rospy.Subscriber("position", position, self.callback_position)
        rospy.Subscriber("/odom", Odometry, self.callback_odom)
        rospy.Subscriber("/mobile_base/sensors/imu_data", Imu, self.callback_imu)
        #publish result to pose
        self.pub = rospy.Publisher("pose",pose,queue_size = 1)
        #extended kalman filter parameter setting
        num_states = 5
        dt = 1.0/50.0
        rate = 1 / dt
        self.r = rospy.Rate(rate)
        #use EKF
        time.sleep(1)
        initial_state = [self.raw_x,self.raw_y,0.1,
                         self.raw_v,self.raw_yaw_v]
        self.ekf = EKF(initial_state)
        self.optimal_estimate = [0.1,0.1,0.1,0.1,0.1]
    
    def publish_ros_topic(self,optimal_estimate):
        pos = pose()
        pos.x = optimal_estimate[0]
        pos.y = optimal_estimate[1]
        pos.psi = optimal_estimate[2]
        pos.dx = optimal_estimate[3]
        pos.dpsi = optimal_estimate[4]
        self.pub.publish(pos)

    def fusion_thread(self):
        while True:
            measurement = [self.raw_x,self.raw_y,
                           self.raw_v,self.raw_yaw_v]
            self.optimal_estimate = self.ekf.extended_kalman_filter(measurement)
            self.r.sleep()
            print self.optimal_estimate
            self.publish_ros_topic(self.optimal_estimate)
    
    #callback function get position x , y
    def callback_position(self, data):
        self.raw_x = data.positionX / 1000.0
        self.raw_y = data.positionY / 1000.0
        #print "from sensor: %f %f" %(self.raw_x,self.raw_y)

    #callback function get speed
    def callback_odom(self, data):
        self.raw_v = data.twist.twist.linear.x
        #print "from sensor : %f" %self.raw_v
    
    #callback function get angle speed
    def callback_imu(self,data):
        self.raw_yaw_v = data.angular_velocity.z
        #print self.raw_yaw_v
    
if __name__ == '__main__':
    fusion = Fusion()
    fusion.fusion_thread()
    #p1 = multiprocessing.Process(target = fusion.fusion_thread)
    #p2 = multiprocessing.Process(target = show_traject)
    #p1.daemon = True
    #p2.daemon = True
    #p1.start()
    #p2.start()


