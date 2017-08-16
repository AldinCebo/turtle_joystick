#include <iostream>

// ROS related
#include "ros/ros.h"
#include <std_msgs/Float64.h>
#include <std_msgs/Bool.h>

class templateClass
{
public:
    templateClass();
    ~templateClass();
    void run();
    
private:
    // Node handle, publishers and subscribers
    ros::NodeHandle nh;
    ros::Subscriber sub;
    ros::Publisher pub;
    
    // subscriber callback function
    void callback(const std_msgs::Bool& msg);
    
};