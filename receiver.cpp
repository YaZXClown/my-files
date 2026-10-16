#include "ros/ros.h"
#include "std_msgs/String.h"
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Transmission received: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Receiver");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("radio", 1000, chatterCallback);
  ros::spin();

  return 0;
}
