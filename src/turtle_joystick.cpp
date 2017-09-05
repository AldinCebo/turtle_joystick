#include <turtle_joystick/turtle_joystickClass.h>

int main (int argc, char** argv) {
    
    ros::init(argc, argv, "turtle_joystick");
    
    turtle_joystickClass turtle_joystickObj;
    
    turtle_joystickObj.run();
    
}
