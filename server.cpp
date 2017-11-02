#include "server.h"
Server::Server(std::string username,std::string password,std::string name,std::string id,int all_time_orders_filled,double hourly_wage) : User(username,password,name,id),_all_time_orders_filled{all_time_orders_filled},_hourly_wage{hourly_wage} {
	_privilege=1;
}
std::string Server::to_string(){
	return "Username: "+_username+"\tName: "+_name+"\tID: "+_id+"\tAll time total orders filled: "+std::to_string(_all_time_orders_filled)+"Hourly wage: "+std::to_string(_hourly_wage)+"\n";
}
