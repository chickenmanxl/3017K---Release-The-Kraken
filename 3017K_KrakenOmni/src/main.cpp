/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// FrontRight           motor         10              
// FrontLeft            motor         12              
// BackRight            motor         9               
// BackLeft             motor         11              
// Roller               motor         1               
// Intake               motor         3               
// visionR              vision        18              
// visionL              vision        17              
// string2              motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <string>

using namespace vex;
using namespace std;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}
int D = 1;

struct Pos
{
  double valueX;
  double valueY;
  double rot;
};

Pos SLAM()
{
  double X = 0;
  double Y = 0;
  double R = 0;

  Pos result = {X,Y,R};
  return result;
}

void drive(int dist, char dir, int vel){
  float turns = dist/12.566;
 switch(dir)
 {
    case 'f':
    {
      FrontLeft.setVelocity(vel, pct);
      FrontRight.setVelocity(vel, pct);
      BackLeft.setVelocity(vel, pct);
      BackRight.setVelocity(vel, pct);

      FrontLeft.spinFor(fwd, turns, rev, false);
      FrontRight.spinFor(fwd, turns, rev, false);
      BackLeft.spinFor(fwd, turns, rev, false);
      BackRight.spinFor(fwd, turns, rev, true);
    break;
    }
    case 'b':
    {
      FrontLeft.setVelocity(vel, pct);
      FrontRight.setVelocity(vel, pct);
      BackLeft.setVelocity(vel, pct);
      BackRight.setVelocity(vel, pct);

      FrontLeft.spinFor(reverse, turns, rev, false);
      FrontRight.spinFor(reverse, turns, rev, false);
      BackLeft.spinFor(reverse, turns, rev, false);
      BackRight.spinFor(reverse, turns, rev, true);
      break;
    }
    case 'l':
    {
      FrontLeft.setVelocity(vel, pct);
      FrontRight.setVelocity(vel, pct);
      BackLeft.setVelocity(vel, pct);
      BackRight.setVelocity(vel, pct);

      FrontLeft.spinFor(reverse, turns, rev, false);
      FrontRight.spinFor(fwd, turns, rev, false);
      BackLeft.spinFor(reverse, turns, rev, false);
      BackRight.spinFor(fwd, turns, rev, true);      
      break;
    }
    case 'r':
    {
      FrontLeft.setVelocity(vel, pct);
      FrontRight.setVelocity(vel, pct);
      BackLeft.setVelocity(vel, pct);
      BackRight.setVelocity(vel, pct);
            
      FrontLeft.spinFor(fwd, turns, rev, false);
      FrontRight.spinFor(reverse, turns, rev, false);
      BackLeft.spinFor(fwd, turns, rev, false);
      BackRight.spinFor(reverse, turns, rev, true);      
      break;
    }
 } 


}

int reverseB(void)
{
return D*-1;
}
void autonomous(void) {

  
drive(6,'f',80);//drives forward 6 inches
wait(5, msec);//waits 5 msec

drive(12,'b',80);//drives backward 12 inches
wait(5, msec);//waits 5 msec

drive(2,'r',80);
wait(5, msec);//waits 5 msec
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
  FrontLeft.setStopping(hold);
  FrontRight.setStopping(hold);
  BackLeft.setStopping(hold);
  BackRight.setStopping(hold);
  string2.setVelocity(90,pct); 
 
  int forward = Controller1.Axis3.position(percent)/1.5; //reads controller stick input
  int rot = Controller1.Axis4.position(percent)/2.2; //reads controller stick input
  

    FrontRight.spin(vex::forward, forward/1.1 - rot/1.5, vex::percent); //front right motor drive
    FrontLeft.spin(vex::forward,  forward/1.1 + rot/1.5, vex::percent); //front left motor drive
    BackRight.spin(vex::forward,  forward/1.1 - rot/1.5, vex::percent); //back right motor drive
    BackLeft.spin(vex::forward,   forward/1.1 + rot/1.5, vex::percent); //back left motor drive

 Controller1.ButtonA.pressedI(reverseB());
  if(Controller1.ButtonUp.pressing())
    {
      drive(2,'f',20);
    }

  if(Controller1.ButtonDown.pressing())
  {
   drive(2,'b',20);
  }

  if(Controller1.ButtonLeft.pressing())
  {
    drive(2,'l',20);
  }

  if(Controller1.ButtonRight.pressing())
  {
    drive(2,'r',20);
  }
 
  while(Controller1.ButtonL1.pressing())
    {
      Roller.spin(fwd);

    }
 
  while(Controller1.ButtonL2.pressing())
    {
      Roller.spin(reverse);
    }

        Roller.stop();

  while(Controller1.ButtonX.pressing())
    {
      Intake.spin(fwd);
      }
 
  while(Controller1.ButtonB.pressing())
    {
      Intake.spin(reverse);
    }

        Intake.stop();        

    wait(10, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
