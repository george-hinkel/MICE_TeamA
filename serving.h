#ifndef serving_h
#define serving_h
#include <string>
#include <iostream>
#include <vector>
#include "mice.h"

class Serving
{
	public:
	    void getMessage(std::string mess);
		void add_item(Item* item);
		Item* get_item(std::string name);
		void remove_item(Item* item);
		std::string to_string();
	private:
    	std::vector<Item*> _items;
    	std::string serving_id;
};
#endif
