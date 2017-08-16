#include <template_package/templateClass.h>

templateClass::templateClass() {
    
    // define a publisher (one or more)
    pub = nh.advertise<std_msgs::Float64>("template_output", 1);
    
    // define a subscriber (one or more)
    sub = nh.subscribe("template_input", 1, &templateClass::callback, this);
    
}

templateClass::~templateClass(){
}

void templateClass::callback(const std_msgs::Bool& msg){
    
    if (!msg.data) {
        std::cout << "In a callback function, publishing nothing!" << std::endl;  
    }
    else {
        std_msgs::Float64 moveWrist;
        
        std::cout << "Publish to a topic!";
        
        moveWrist.data = 0.1;
        pub.publish(moveWrist);       
    }
}

void templateClass::run(){
    
    ros::Rate r(1); // 1 hz
    
    while (ros::ok()) {
        // do something
        ros::spinOnce();
        r.sleep();
    }

    // or use just
    // ros::spin();
    
}