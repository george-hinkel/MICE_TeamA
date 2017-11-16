#ifndef server_h
#define server_h
#include "user.h"
class Server : public User{
	public:
		Server(std::string username,std::string password,std::string name,int all_time_orders_filled,double hourly_wage);
		std::string to_string();
		std::string to_file_string();
		double get_hourly_wage();
		void set_hourly_wage(double new_wage);
	private:
		int _all_time_orders_filled;
		double _hourly_wage;
};
#endif
