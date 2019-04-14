#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensors/z_vector.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "lidar");
  ros::NodeHandle nh;

  ros::Publisher chatter_pub = nh.advertise<sensors::z_vector>("raw_measurement", 1000);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    sensors::z_vector msg;
    msg.type='L';
//fack sensor

    msg.px=5;
    msg.py=9;


    chatter_pub.publish(msg);

   // ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
