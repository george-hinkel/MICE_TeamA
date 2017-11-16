#include "server.h"
Server::Server(std::string username,std::string password,std::string name,int all_time_orders_filled,double hourly_wage) : User(username,password,name),_all_time_orders_filled{all_time_orders_filled},_hourly_wage{hourly_wage} {
	static int _next_id=0;
	_privilege=1;
	_id=std::to_string(_next_id);
	_next_id++;
}
std::string Server::to_string(){
	return "Server ID: "+_id+"\tUsername: "+_username+"\tName: "+_name+"\tAll time total orders filled: "+std::to_string(_all_time_orders_filled)+"Hourly wage: "+std::to_string(_hourly_wage)+"\n";
}
std::string Server::to_file_string(){
	return User::to_file_string()+std::to_string(_all_time_orders_filled)+"\n"+std::to_string(_hourly_wage)+"\n";
}
void Server::set_hourly_wage(double new_wage){
	_hourly_wage=new_wage;
}
double Server::get_hourly_wage(){
	return _hourly_wage;
}
