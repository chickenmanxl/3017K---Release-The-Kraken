using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern motor FrontRight;
extern motor FrontLeft;
extern motor BackRight;
extern motor BackLeft;
extern motor Roller;
extern motor Intake;
extern signature visionR__SIG_1;
extern signature visionR__SIG_2;
extern signature visionR__SIG_3;
extern signature visionR__SIG_4;
extern signature visionR__SIG_5;
extern signature visionR__SIG_6;
extern signature visionR__SIG_7;
extern vision visionR;
extern signature visionL__SIG_1;
extern signature visionL__SIG_2;
extern signature visionL__SIG_3;
extern signature visionL__SIG_4;
extern signature visionL__SIG_5;
extern signature visionL__SIG_6;
extern signature visionL__SIG_7;
extern vision visionL;
extern motor string2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );