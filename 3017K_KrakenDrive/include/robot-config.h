using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor FrontRight;
extern motor FrontLeft;
extern motor BackRight;
extern motor BackLeft;
extern motor Roller;
extern motor Intake;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );