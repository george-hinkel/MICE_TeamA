#include "topping.h"
Topping::Topping(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path,int quantifier) : Item(name,description,wholesale_cost,retail_price,initial_stock,image_file_path), _quantifier{quantifier} {
	_type="topping";
}
std::string Topping::to_string(){
    char output[_name.length()+_description.length()+100];
    std::sprintf(output,"Name: %s\tQualifier: %s\tWholesale Cost: %0.2lf\tRetail Price: %0.2lf\tStock Remaining: %d\nDescription: %s\n",_name.c_str(),_qualifiers[_quantifier].c_str(),_wholesale_cost,_retail_price,_stock_remaining,_description.c_str());
    return output;
}
