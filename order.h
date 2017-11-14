#ifndef order_h
#define order_h
#include <string>
#include <iostream>
#include "serving.h"
class Order
{
	public:
		Order(std::string order_id,std::string status="unfilled") : _order_id{order_id},_status{status} { }
		class Invalid_status_change : public std::exception{
			public:
				Invalid_status_change(std::string initial_status,std::string final_status) : _initial_status{initial_status},_final_status{final_status} { }
				virtual const char* what() const throw(){
    				std::string output= "Invalid status change from: '";
    				output+= _initial_status;
    				output+= "' to '";
    				output+= _final_status;
    				output+= "'!";
    				return output.c_str();
    			}
    		private:
    			std::string _initial_status;
    			std::string _final_status;
		};
		void add_serving(Serving* serving);
		Serving* get_serving(std::string serving_id);
		void remove_serving(Serving* serving);
		std::string to_string(int op);//0=full;1=short
		double get_wholesale_cost();
		double get_retail_price();
		std::string get_id();
		std::string get_status();
		void fill();
		void cancel();
		double pay();
		std::string to_file_string();
		std::string order_summary();
	private:
		std::vector<Serving*> _servings;
		std::string _status;
		std::string _order_id;
};
#endif
