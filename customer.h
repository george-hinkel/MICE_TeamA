#ifndef customer_h
#define customer_h
#include "user.h"
class Customer : public User{
	public:
		Customer(std::string username,std::string password,std::string name,std::string id,std::string phone_number);
		std::string to_string();
	private:
		std::string _phone_number;
};
#endif
