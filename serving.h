#ifndef serving_h
#define serving_h
#include <string>
#include <iostream>
#include <vector>
#include "mice.h"

class Serving
{
	public:
		Serving(std::string serving_id) : _serving_id{serving_id} { }
	    void getMessage(std::string mess);
		void add_item(Item* item);
		Item* get_item(std::string name);
		void remove_item(Item* item);
		std::string to_string();
		std::string get_id();
	private:
    	std::vector<Item*> _items;
    	std::string _serving_id;
};
#endif
