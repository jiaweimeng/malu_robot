#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>
#include <deque>

struct Robot
{
  std::string id; //robot id exp: R001
  float position[3]; // robot position (in x,y,z order)
  float orientation;
  float acceleration;
  float velocity;
  float voltage;
  bool is_connect; // is connecting to server or not
  bool online; // robot online or offline
  int status;  // -1 free  0 working  >0 in error

  Robot();
  ~Robot();
  void Handle(void);// handle in or out Message
  void Init(float x,float y,float z);// init robot in x y z exp: x = 1000mm y = 1000mm z = 0;
  void Kill(void);// shut down robot process
  void GetDetial(void);//get the robot position orientation voltage velocity acceleration
  bool SetPosition(float x,float y,float z);//set Robot target position  Robot move in a straight line to the destination the destination must have a qr code
  bool SetPosition(std::deque<float*> path);//the qr code point must be an element of the path! Otherwise, robot will not detect this qr code
  bool SetAcceleration(int Acceleration); // set Robot acceleration exp: Acceleration = 800(mm/s^2)
  bool SetVelocity(int Velocity); // set Robot Velocity exp: Velocity = 1000(mm/s)
  bool SetOrientation(float orientation);//set Robot target orientation -PI ~ PI
  std::string DebugString();// show all the info with robot

};
#endif

