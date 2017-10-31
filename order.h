#ifndef order_h
#define order_h
#include <string>
#include <iostream>
#include "mice.h"
class Order
{
	public:
    //std::vector<std::string> flavors;
    	void getMessage(std::string mess);
  //  void addFlavor();
		void add_serving(Serving* serving);
		Serving* get_serving(std::string serving_id);
		void remove_serving(Serving* serving);
		std::string to_string();
	private:
		std::vector<Serving*> _servings;
};
#endif
