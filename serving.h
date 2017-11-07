#ifndef serving_h
#define serving_h
#include <string>
#include <vector>
#include "mice.h"
class Serving
{
	public:
		Serving(std::string serving_id) : _serving_id{serving_id} { }
		void add_item(Item* item);
		Item* get_item(std::string name);
		void remove_item(Item* item);
		std::string to_string();
		std::string get_id();
		double get_retail_price();
		double get_wholesale_cost();
		std::string to_short_string();
		std::string to_file_string();
	private:
    	std::vector<Item*> _items;
    	std::string _serving_id;
};
#endif
