#ifndef server_h
#define server_h
#include "user.h"
class Server : public User{
	public:
		Server(std::string username,std::string password,std::string name,int all_time_orders_filled,double hourly_wage);
		std::string to_string();
	private:
		int _all_time_orders_filled;
		double _hourly_wage;
};
#endif
