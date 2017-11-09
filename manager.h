#ifndef manager_h
#define manager_h
#include "user.h"
class Manager : public User{
	public:
		Manager(std::string username,std::string password,std::string name);
		std::string get_name();
};
#endif
