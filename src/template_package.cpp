#include <template_package/templateClass.h>

int main (int argc, char** argv) {
    
    ros::init(argc, argv, "template_package");
    
    templateClass templateObj;
    
    templateObj.run();
    
}