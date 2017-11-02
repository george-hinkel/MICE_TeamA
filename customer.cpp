#include "customer.h"
Customer::Customer(std::string username,std::string password,std::string name,std::string id,std::string phone_number) : User(username,password,name,id),_phone_number{phone_number} {
	_privilege=0;
}
std::string Customer::to_string(){
	return "Username: "+_username+"\tName: "+_name+"\tID: "+_id+"\tPhone number: "+_phone_number+"\n";
}
