#include "manager.h"
Manager::Manager(std::string username,std::string password,std::string name,std::string id) : User(username,password,name,id) {
	_privilege=2;
}
