#include <iostream>

// ROS related
#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include "turtle_joystick/gljiva.h"

class turtle_joystickClass
{
public:
    turtle_joystickClass();
    ~turtle_joystickClass();
    void run();
    
private:
    // Node handle, publishers and subscribers
    ros::NodeHandle nh;
    ros::Subscriber sub;
    ros::Publisher turtlebot_vel;
    
    // subscriber callback function
    void gljiva_Callback(const turtle_joystick::gljiva::ConstPtr& msg);
    
};
