#include "ros/ros.h"
#include "std_msgs/String.h"
#include "osrf_gear/Order.h"
#include <vector>
#include "osrf_gear/GetMaterialLocations.h"
#include "osrf_gear/LogicalCameraImage.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
std::vector<osrf_gear::Order> order_vector;
osrf_gear::GetMaterialLocations location;
ros::ServiceClient location_client;
bool found_part = false;

//osrf_gear::GetMaterialLocation::Request req;
  //   osrf_gear::GetMaterialLocation::Response resp;
void chatterCallback(const osrf_gear::Order msg)
{
  found_part = false; // if new order, have not found part yet
  ROS_INFO("I heard order number: [%s]", msg.order_id.c_str());
  order_vector.push_back(msg);
  ROS_INFO("Order vector size is: [%lu]", order_vector.size());
  ROS_INFO("First product type is: [%s]", msg.shipments[0].products[0].type.c_str());
  //ros::service::waitForService("/ariac/material_locations"); 
  //req = msg.shipments[0].products[0].type;
location.request.material_type = msg.shipments[0].products[0].type;
   location_client.call(location);
ROS_INFO("Location is [%s]", location.response.storage_units[0].unit_id.c_str());
  //location_client.call(location);
  //service_call_succeeded = begin_client.call(begin_comp);
}

/** Logical Camera Callbacks **/
void bin1Callback(const osrf_gear::LogicalCameraImage img)
{
  if(!found_part)
	{
		ROS_INFO("Checking bin 1");
		for(int i = 0; i<img.models.size(); i++){
			if(!found_part & img.models[i].type == location.request.material_type){
				ROS_WARN("Found in bin 1");
				ROS_WARN("Product type: [%s]", img.models[i].type.c_str()); 
				ROS_WARN("The pose is:");
				ROS_WARN("Position");
				ROS_WARN("x: [%f]", img.models[i].pose.position.x);
				ROS_WARN("y: [%f]", img.models[i].pose.position.y);
				ROS_WARN("z: [%f]", img.models[i].pose.position.z);
				ROS_WARN("Orientation");
				ROS_WARN("x: [%f]", img.models[i].pose.orientation.x);
				ROS_WARN("y: [%f]", img.models[i].pose.orientation.y);
				ROS_WARN("z: [%f]", img.models[i].pose.orientation.z);
				ROS_WARN("w: [%f]", img.models[i].pose.orientation.w);
				found_part = true;
			}
		}
		
	}  

}
void bin2Callback(const osrf_gear::LogicalCameraImage img)
{
  if(!found_part)
	{
		ROS_INFO("Checking bin 2");
		for(int i = 0; i<img.models.size(); i++){
			if(!found_part & img.models[i].type == location.request.material_type){
				ROS_WARN("Found in bin 2");
				ROS_WARN("Product type: [%s]", img.models[i].type.c_str()); 
				ROS_WARN("The pose is:");
				ROS_WARN("Position");
				ROS_WARN("x: [%f]", img.models[i].pose.position.x);
				ROS_WARN("y: [%f]", img.models[i].pose.position.y);
				ROS_WARN("z: [%f]", img.models[i].pose.position.z);
				ROS_WARN("Orientation");
				ROS_WARN("x: [%f]", img.models[i].pose.orientation.x);
				ROS_WARN("y: [%f]", img.models[i].pose.orientation.y);
				ROS_WARN("z: [%f]", img.models[i].pose.orientation.z);
				ROS_WARN("w: [%f]", img.models[i].pose.orientation.w);
				found_part = true;
			}
		}
		
	}  

}
void bin3Callback(const osrf_gear::LogicalCameraImage img)
{
  if(!found_part)
	{
		ROS_INFO("Checking bin 3");
		for(int i = 0; i<img.models.size(); i++){
			if(!found_part & img.models[i].type == location.request.material_type){
				ROS_WARN("Found in bin 3");
				ROS_WARN("Product type: [%s]", img.models[i].type.c_str()); 
				ROS_WARN("The pose is:");
				ROS_WARN("Position");
				ROS_WARN("x: [%f]", img.models[i].pose.position.x);
				ROS_WARN("y: [%f]", img.models[i].pose.position.y);
				ROS_WARN("z: [%f]", img.models[i].pose.position.z);
				ROS_WARN("Orientation");
				ROS_WARN("x: [%f]", img.models[i].pose.orientation.x);
				ROS_WARN("y: [%f]", img.models[i].pose.orientation.y);
				ROS_WARN("z: [%f]", img.models[i].pose.orientation.z);
				ROS_WARN("w: [%f]", img.models[i].pose.orientation.w);
				found_part = true;
			}
		}
		
	}  

}
void bin4Callback(const osrf_gear::LogicalCameraImage img)
{
  if(!found_part)
	{
		ROS_INFO("Checking bin 4");
		for(int i = 0; i<img.models.size(); i++){
			if(!found_part & img.models[i].type == location.request.material_type){
				ROS_WARN("Found in bin 4"); 
				ROS_WARN("Product type: [%s]", img.models[i].type.c_str()); 
				ROS_WARN("The pose is:");
				ROS_WARN("Position");
				ROS_WARN("x: [%f]", img.models[i].pose.position.x);
				ROS_WARN("y: [%f]", img.models[i].pose.position.y);
				ROS_WARN("z: [%f]", img.models[i].pose.position.z);
				ROS_WARN("Orientation");
				ROS_WARN("x: [%f]", img.models[i].pose.orientation.x);
				ROS_WARN("y: [%f]", img.models[i].pose.orientation.y);
				ROS_WARN("z: [%f]", img.models[i].pose.orientation.z);
				ROS_WARN("w: [%f]", img.models[i].pose.orientation.w);
				found_part = true;
			}
		}
		
	}  

}
void bin5Callback(const osrf_gear::LogicalCameraImage img)
{
  if(!found_part)
	{
		ROS_INFO("Checking bin 5");
		for(int i = 0; i<img.models.size(); i++){
			if(!found_part & img.models[i].type == location.request.material_type){
				ROS_WARN("Found in bin 5");
				ROS_WARN("Product type: [%s]", img.models[i].type.c_str()); 
				ROS_WARN("The pose is:");
				ROS_WARN("Position");
				ROS_WARN("x: [%f]", img.models[i].pose.position.x);
				ROS_WARN("y: [%f]", img.models[i].pose.position.y);
				ROS_WARN("z: [%f]", img.models[i].pose.position.z);
				ROS_WARN("Orientation");
				ROS_WARN("x: [%f]", img.models[i].pose.orientation.x);
				ROS_WARN("y: [%f]", img.models[i].pose.orientation.y);
				ROS_WARN("z: [%f]", img.models[i].pose.orientation.z);
				ROS_WARN("w: [%f]", img.models[i].pose.orientation.w);
				found_part = true;
			}
		}
		
	}  

}
void bin6Callback(const osrf_gear::LogicalCameraImage img)
{
  if(!found_part)
	{
		ROS_INFO("Checking bin 6");
		for(int i = 0; i<img.models.size(); i++){
			if(!found_part & img.models[i].type == location.request.material_type){
				ROS_WARN("Found in bin 6");
				ROS_WARN("Product type: [%s]", img.models[i].type.c_str()); 
				ROS_WARN("The pose is:");
				ROS_WARN("Position");
				ROS_WARN("x: [%f]", img.models[i].pose.position.x);
				ROS_WARN("y: [%f]", img.models[i].pose.position.y);
				ROS_WARN("z: [%f]", img.models[i].pose.position.z);
				ROS_WARN("Orientation");
				ROS_WARN("x: [%f]", img.models[i].pose.orientation.x);
				ROS_WARN("y: [%f]", img.models[i].pose.orientation.y);
				ROS_WARN("z: [%f]", img.models[i].pose.orientation.z);
				ROS_WARN("w: [%f]", img.models[i].pose.orientation.w);
				found_part = true;
			}
		}
		
	}  

}
void agv1Callback(const osrf_gear::LogicalCameraImage img)
{
  if(!found_part)
	{
		ROS_INFO("Checking agv bin 1");
		for(int i = 0; i<img.models.size(); i++){
			if(!found_part & img.models[i].type == location.request.material_type){
				ROS_WARN("Found in agv bin 1");
				ROS_WARN("Product type: [%s]", img.models[i].type.c_str()); 
				ROS_WARN("The pose is:");
				ROS_WARN("Position");
				ROS_WARN("x: [%f]", img.models[i].pose.position.x);
				ROS_WARN("y: [%f]", img.models[i].pose.position.y);
				ROS_WARN("z: [%f]", img.models[i].pose.position.z);
				ROS_WARN("Orientation");
				ROS_WARN("x: [%f]", img.models[i].pose.orientation.x);
				ROS_WARN("y: [%f]", img.models[i].pose.orientation.y);
				ROS_WARN("z: [%f]", img.models[i].pose.orientation.z);
				ROS_WARN("w: [%f]", img.models[i].pose.orientation.w);
				found_part = true;
			}
		}
		
	}  

}
void agv2Callback(const osrf_gear::LogicalCameraImage img)
{
  if(!found_part)
	{
		ROS_INFO("Checking agv bin 2");
		for(int i = 0; i<img.models.size(); i++){
			if(!found_part & img.models[i].type == location.request.material_type){
				ROS_WARN("Found in agv bin 2");
				ROS_WARN("Product type: [%s]", img.models[i].type.c_str()); 
				ROS_WARN("The pose is:");
				ROS_WARN("Position");
				ROS_WARN("x: [%f]", img.models[i].pose.position.x);
				ROS_WARN("y: [%f]", img.models[i].pose.position.y);
				ROS_WARN("z: [%f]", img.models[i].pose.position.z);
				ROS_WARN("Orientation");
				ROS_WARN("x: [%f]", img.models[i].pose.orientation.x);
				ROS_WARN("y: [%f]", img.models[i].pose.orientation.y);
				ROS_WARN("z: [%f]", img.models[i].pose.orientation.z);
				ROS_WARN("w: [%f]", img.models[i].pose.orientation.w);
				found_part = true;
			}
		}
		
	}  

}
void qual1Callback(const osrf_gear::LogicalCameraImage img)
{
  if(!found_part)
	{
		ROS_INFO("Checking qual 1");
		for(int i = 0; i<img.models.size(); i++){
			if(!found_part & img.models[i].type == location.request.material_type){
				ROS_WARN("Found in qual 1");
				ROS_WARN("Product type: [%s]", img.models[i].type.c_str()); 
				ROS_WARN("The pose is:");
				ROS_WARN("Position");
				ROS_WARN("x: [%f]", img.models[i].pose.position.x);
				ROS_WARN("y: [%f]", img.models[i].pose.position.y);
				ROS_WARN("z: [%f]", img.models[i].pose.position.z);
				ROS_WARN("Orientation");
				ROS_WARN("x: [%f]", img.models[i].pose.orientation.x);
				ROS_WARN("y: [%f]", img.models[i].pose.orientation.y);
				ROS_WARN("z: [%f]", img.models[i].pose.orientation.z);
				ROS_WARN("w: [%f]", img.models[i].pose.orientation.w);
				found_part = true;
			}
		}
		
	}  

}
void qual2Callback(const osrf_gear::LogicalCameraImage img)
{
  if(!found_part)
	{
		ROS_INFO("Checking qual 2");
		for(int i = 0; i<img.models.size(); i++){
			if(!found_part & img.models[i].type == location.request.material_type){
				ROS_WARN("Found in qual 2");
				ROS_WARN("Product type: [%s]", img.models[i].type.c_str()); 
				ROS_WARN("The pose is:");
				ROS_WARN("Position");
				ROS_WARN("x: [%f]", img.models[i].pose.position.x);
				ROS_WARN("y: [%f]", img.models[i].pose.position.y);
				ROS_WARN("z: [%f]", img.models[i].pose.position.z);
				ROS_WARN("Orientation");
				ROS_WARN("x: [%f]", img.models[i].pose.orientation.x);
				ROS_WARN("y: [%f]", img.models[i].pose.orientation.y);
				ROS_WARN("z: [%f]", img.models[i].pose.orientation.z);
				ROS_WARN("w: [%f]", img.models[i].pose.orientation.w);
				found_part = true;
			}
		}
		
	}  

}

int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "listener");
order_vector.clear();
  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages
   * on a given topic.  This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing.  Messages are passed to a callback function, here
   * called chatterCallback.  subscribe() returns a Subscriber object that you
   * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
   * object go out of scope, this callback will automatically be unsubscribed from
   * this topic.
   *
   * The second parameter to the subscribe() function is the size of the message
   * queue.  If messages are arriving faster than they are being processed, this
   * is the number of messages that will be buffered up before beginning to throw
   * away the oldest ones.
   */
  ros::Subscriber sub = n.subscribe("/ariac/orders", 1000, chatterCallback);
  ros::Subscriber sub_bin_1 = n.subscribe("/ariac/logical_camera_bin1", 1000, bin1Callback);
  ros::Subscriber sub_bin_2 = n.subscribe("/ariac/logical_camera_bin2", 1000, bin2Callback);
  ros::Subscriber sub_bin_3 = n.subscribe("/ariac/logical_camera_bin3", 1000, bin3Callback);
  ros::Subscriber sub_bin_4 = n.subscribe("/ariac/logical_camera_bin4", 1000, bin4Callback);
  ros::Subscriber sub_bin_5 = n.subscribe("/ariac/logical_camera_bin5", 1000, bin5Callback);
  ros::Subscriber sub_bin_6 = n.subscribe("/ariac/logical_camera_bin6", 1000, bin6Callback);
  ros::Subscriber sub_agv_1 = n.subscribe("/ariac/logical_camera_agv1", 1000, agv1Callback);
  ros::Subscriber sub_agv_2 = n.subscribe("/ariac/logical_camera_agv2", 1000, agv2Callback);
  ros::Subscriber sub_qual_1 = n.subscribe("/ariac/quality_control_sensor_1", 1000, qual1Callback);
  ros::Subscriber sub_qual_2 = n.subscribe("/ariac/quality_control_sensor_2", 1000, qual2Callback);

  location_client = n.serviceClient<osrf_gear::GetMaterialLocations>("/ariac/material_locations");

    

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();

  return 0;
}
