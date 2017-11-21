#include <sstream>
#include "scoop.h"

Scoop::Scoop(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path) : Item(name,description,wholesale_cost,retail_price,initial_stock,image_file_path){
	_type="scoop";
}
std::string Scoop::to_string(){
	std::string t="        ";
	std::stringstream ss;
    ss << Item::to_string() << std::endl;
    ss << t << _description;
    return ss.str();
}
