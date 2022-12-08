#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor FrontRight = motor(PORT10, ratio18_1, false);
motor FrontLeft = motor(PORT12, ratio18_1, true);
motor BackRight = motor(PORT9, ratio18_1, false);
motor BackLeft = motor(PORT11, ratio18_1, true);
motor Roller = motor(PORT1, ratio18_1, false);
motor Intake = motor(PORT3, ratio18_1, false);
/*vex-vision-config:begin*/
vision visionR = vision (PORT18, 50);
/*vex-vision-config:end*/
/*vex-vision-config:begin*/
vision visionL = vision (PORT17, 50);
/*vex-vision-config:end*/
motor string2 = motor(PORT7, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}