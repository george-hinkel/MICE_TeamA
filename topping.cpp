#include "topping.h"
#include <sstream>

Topping::Topping(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path,int quantifier) : Item(name,description,wholesale_cost,retail_price,initial_stock,image_file_path), _quantifier{quantifier} {
	_type="topping";
}
std::string Topping::to_string(){
    std::string t="        ";
	std::stringstream ss;
    ss << Item::to_string() << t;
    ss << "Qualifier: " << _qualifiers[_quantifier] << std::endl;
    ss << t << _description;
    return ss.str();
}
void Topping::change_quantifier(int quantifier){
	_quantifier=quantifier;
}
double Topping::get_retail_price(){
	return _retail_price*_quantifier;
}
double Topping::get_wholesale_cost(){
	return _wholesale_cost*_quantifier;
}
std::string Topping::to_file_string(int op){
	return Item::to_file_string(op)+std::to_string(_quantifier)+"\n";
}
int Topping::get_quantifier(){
	return _quantifier;
}
