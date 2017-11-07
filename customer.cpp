#include "customer.h"
Customer::Customer(std::string username,std::string password,std::string name,std::string phone_number) : User(username,password,name),_phone_number{phone_number} {
	static int _next_id=0;
	_privilege=0;
	_id=std::to_string(_next_id);
	_next_id++;
}
std::string Customer::to_string(){
	return "Customer ID: "+_id+"\tUsername: "+_username+"\tName: "+_name+"\tPhone number: "+_phone_number+"\n";
}
std::string Customer::to_file_string(){
	return User::to_file_string()+_phone_number+"\n";
}

