# malu_robot
This package is used to control malu mobile base through Local Area Network (LAN).

To control the malu mobile based by this ROS package, we need:
1. Connecting to "malu" with setting the address, netmask and gateway as 192.168.10.101, 255.255.255.0 and 192.168.10.254 respectively.
2. Running "roscore" command.
3. Running ros node "malu_robot_node".

Notes: 
1. All the available functions are defined in [robot.h](https://github.com/jiaweimeng/malu_robot/blob/master/include/malu_robot/robot.h) head file.
2. QR code needs to be pasted on each waypoint of the path.
3. After using [robot.SetOrientation()](https://github.com/jiaweimeng/malu_robot/blob/master/include/malu_robot/robot.h), the robot should wait for 15 s to calibrate the orientation.
