#include "item.h"
#include <string>
#include <cstdio>
#include <iostream>
Item::Item(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path) : _name{name},_description{description},_wholesale_cost{wholesale_cost},_retail_price{retail_price},_stock_remaining{initial_stock},_image_file_path{image_file_path} {
	_type="item";
}
int Item::get_stock_remaining(){
    return _stock_remaining;
}
void Item::modify_stock(int quantity_to_Add){
    _stock_remaining=_stock_remaining+quantity_to_Add;
}
std::string Item::to_string(){
    char output[_name.length()+_description.length()+100];
    std::sprintf(output,"Name: %s\tWholesale Cost: %0.2lf\tRetail Price: %0.2lf\tStock Remaining: %d\nDescription: %s\n",_name.c_str(),_wholesale_cost,_retail_price,_stock_remaining,_description.c_str());
    return output;
}
std::string Item::get_name(){
	return _name;
}
std::string Item::get_type(){
	return _type;
}
double Item::get_retail_price(){
	return _retail_price;
}
double Item::get_wholesale_cost(){
	return _wholesale_cost;
}
std::string Item::to_file_string(int op){
	if(op==0){
		return _type+"\n"+_name+"\n"+_description+"\n"+std::to_string(_wholesale_cost)+"\n"+std::to_string(_retail_price)+"\n"+std::to_string(_stock_remaining)+"\n"+_image_file_path+"\n";
	}else if(op==1){
		return _name+"\n";
	}
}
