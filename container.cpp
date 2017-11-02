#include <iostream>
#include "container.h"
namespace Mice{
Container::Container(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path,int max_scoops) : Item(name,description,wholesale_cost,retail_price,initial_stock,image_file_path), _max_scoops{max_scoops} {
	_type="container";
}
std::string Container::to_string(){
    char output[_name.length()+_description.length()+100];
    std::sprintf(output,"Name: %s\tMax Scoops: %d\tWholesale Cost: %0.2lf\tRetail Price: %0.2lf\tStock Remaining: %d\nDescription: %s\n",_name.c_str(),_max_scoops,_wholesale_cost,_retail_price,_stock_remaining,_description.c_str());
    return output;
}
}
