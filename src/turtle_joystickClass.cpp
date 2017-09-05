#include <turtle_joystick/turtle_joystickClass.h>

turtle_joystickClass::turtle_joystickClass() {
    
    // define a publisher (one or more)
    turtlebot_vel = nh.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1);

    // define a subscriber (one or more)
    sub = nh.subscribe("gljiva", 1, &turtle_joystickClass::gljiva_Callback, this);
    
}

turtle_joystickClass::~turtle_joystickClass(){
}

void turtle_joystickClass::gljiva_Callback(const turtle_joystick::gljiva::ConstPtr& msg){
    geometry_msgs::Twist vel_msg;
    //ROS_INFO("X: %d", msg->x);
    //ROS_INFO("Y: %d", msg->y);
    int x = msg->x;
    int y = msg->y;
    if (x > 500 && x < 550 && y > 500 && y < 550){
        //sredina
        vel_msg.linear.x=0;
        vel_msg.linear.y=0;
        vel_msg.linear.z=0;
        vel_msg.angular.x=0;
        vel_msg.angular.y=0;
        vel_msg.angular.z=0;
    }else if(x > 500 && x < 550 && y < 300){
        //Gore
        vel_msg.linear.x=2;
    }else if(x > 500 && x < 550 && y > 600){
        //Dolje
        vel_msg.linear.x=-2;
    }else if(x > 600 && y > 500 && y < 550){
        //Lijevo
        vel_msg.angular.z=1;
    }else if(x < 300 && y > 500 && y < 550){
        //Desno
        vel_msg.angular.z=-1;
    }
    turtlebot_vel.publish(vel_msg);
}

void turtle_joystickClass::run(){
    
    // or use just
    ros::spin();
    
}
