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
// FrontLeft            motor         9               
// BackRight            motor         1               
// BackLeft             motor         11              
// Roller               motor         2               
// Intake               motor         3               
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

void drive(int dist, char dir)
{
 switch(dir)
 {
    case 'f':
    {
      FrontLeft.setVelocity(90, pct);
      FrontRight.setVelocity(90, pct);
      BackLeft.setVelocity(90, pct);
      BackRight.setVelocity(90, pct);
    break;
    }
    case 'a':
    {
      FrontLeft.setVelocity(90, pct);
      FrontRight.setVelocity(90, pct);
      BackLeft.setVelocity(90, pct);
      BackRight.setVelocity(90, pct);

      FrontLeft.spinFor(reverse, 1, rev, false);
      FrontRight.spinFor(reverse, 1, rev, false);
      BackLeft.spinFor(reverse, 1, rev, false);
      BackRight.spinFor(reverse, 1, rev, true);
      break;
    }
    case 'p':
    {
      FrontLeft.setVelocity(90, pct);
      FrontRight.setVelocity(90, pct);
      BackLeft.setVelocity(90, pct);
      BackRight.setVelocity(90, pct);      
      break;
    }
    case 's':
    {
      FrontLeft.setVelocity(90, pct);
      FrontRight.setVelocity(90, pct);
      BackLeft.setVelocity(90, pct);
      BackRight.setVelocity(90, pct);      
      break;
    }
    case 'l':
    {
      FrontLeft.setVelocity(90, pct);
      FrontRight.setVelocity(90, pct);
      BackLeft.setVelocity(90, pct);
      BackRight.setVelocity(90, pct);

      FrontLeft.spinFor(reverse, 1, rev, false);
      FrontRight.spinFor(fwd, 1, rev, false);
      BackLeft.spinFor(fwd, 1, rev, false);
      BackRight.spinFor(reverse, 1, rev, true);      
      break;
    }
    case 'r':
    {
      FrontLeft.setVelocity(90, pct);
      FrontRight.setVelocity(90, pct);
      BackLeft.setVelocity(90, pct);
      BackRight.setVelocity(90, pct);
            
      FrontLeft.spinFor(fwd, 1, rev, false);
      FrontRight.spinFor(reverse, 1, rev, false);
      BackLeft.spinFor(reverse, 1, rev, false);
      BackRight.spinFor(fwd, 1, rev, true);      
      break;
    }
 } 
  

}

void autonomous(void) {

  
  FrontLeft.setVelocity(100, pct);
  FrontRight.setVelocity(100, pct);
  BackLeft.setVelocity(100, pct);
  BackRight.setVelocity(100, pct);

  FrontLeft.spinFor(fwd, .5, rev, false);
  FrontRight.spinFor(fwd, .5, rev, false);
  BackLeft.spinFor(fwd, .5, rev, false);
  BackRight.spinFor(fwd, .5, rev, true);

wait(5, msec);

  FrontLeft.spinFor(reverse, 1, rev, false);
  FrontRight.spinFor(reverse, 1, rev, false);
  BackLeft.spinFor(reverse, 1, rev, false);
  BackRight.spinFor(reverse, 1, rev, true);

wait(5, msec);

  FrontLeft.spinFor(fwd, 1, rev, false);
  FrontRight.spinFor(reverse, 1, rev, false);
  BackLeft.spinFor(reverse, 1, rev, false);
  BackRight.spinFor(fwd, 1, rev, true);

wait(5, msec);
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
  FrontLeft.setVelocity(90, pct);
  FrontRight.setVelocity(90, pct);
  BackLeft.setVelocity(90, pct);
  BackRight.setVelocity(90, pct);
 
  int forward = Controller1.Axis3.position(percent); //reads controller stick input
  int sideways = Controller1.Axis4.position(percent); //reads controller stick input
  int rot = Controller1.Axis1.position(percent); //reads controller stick input
  

    FrontRight.spin(vex::forward, forward/1.1 - sideways/1.1 + rot/1.5, vex::percent); //front right motor drive
    FrontLeft.spin(vex::forward,  forward/1.1 + sideways/1.1 - rot/1.5, vex::percent); //front left motor drive
    BackRight.spin(vex::forward,  forward/1.1 + sideways/1.1 + rot/1.5, vex::percent); //back right motor drive
    BackLeft.spin(vex::forward,   forward/1.1 - sideways/1.1 - rot/1.5, vex::percent); //back left motor drive

  while(Controller1.ButtonUp.pressing())
  {
    FrontLeft.setVelocity(20, pct);
    FrontRight.setVelocity(20, pct);
    BackLeft.setVelocity(20, pct);
    BackRight.setVelocity(20, pct);

    FrontLeft.spinFor(fwd, .25, rev, false);
    FrontRight.spinFor(fwd, .25, rev, false);
    BackLeft.spinFor(fwd, .25, rev, false);
    BackRight.spinFor(fwd, .25, rev, true);
  }

  while(Controller1.ButtonDown.pressing())
  {
    FrontLeft.setVelocity(20, pct);
    FrontRight.setVelocity(20, pct);
    BackLeft.setVelocity(20, pct);
    BackRight.setVelocity(20, pct);

    FrontLeft.spinFor(reverse, .25, rev, false);
    FrontRight.spinFor(reverse, .25, rev, false);
    BackLeft.spinFor(reverse, .25, rev, false);
    BackRight.spinFor(reverse, .25, rev, true);
  }

  while(Controller1.ButtonLeft.pressing())
  {
    FrontLeft.setVelocity(20, pct);
    FrontRight.setVelocity(20, pct);
    BackLeft.setVelocity(20, pct);
    BackRight.setVelocity(20, pct);    
    
    FrontLeft.spinFor(reverse, .25, rev, false);
    FrontRight.spinFor(fwd, .25, rev, false);
    BackLeft.spinFor(fwd, .25, rev, false);
    BackRight.spinFor(reverse, .25, rev, true);
  }

  while(Controller1.ButtonRight.pressing())
  {
    FrontLeft.setVelocity(20, pct);
    FrontRight.setVelocity(20, pct);
    BackLeft.setVelocity(20, pct);
    BackRight.setVelocity(20, pct);

    FrontLeft.spinFor(fwd, .25, rev, false);
    FrontRight.spinFor(reverse, .25, rev, false);
    BackLeft.spinFor(reverse, .25, rev, false);
    BackRight.spinFor(fwd, .25, rev, true);
  }
  
  while(Controller1.ButtonR1.pressing())
    {
      Roller.spin(fwd);
      }
 
  while(Controller1.ButtonR2.pressing())
    {
      Roller.spin(reverse);
    }

        Roller.stop();

 
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
