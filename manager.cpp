#include "manager.h"
Manager::Manager(std::string username,std::string password,std::string name) : User(username,password,name) {
	static int _next_id=0;
	_privilege=2;
	_id=std::to_string(_next_id);
	_next_id++;
}

