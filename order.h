#ifndef order_h
#define order_h
#include <string>
#include <iostream>
#include "serving.h"
class Order
{
	public:
		void add_serving(Serving* serving);
		Serving* get_serving(std::string serving_id);
		void remove_serving(Serving* serving);
		std::string to_string();
	private:
		std::vector<Serving*> _servings;
};
#endif
