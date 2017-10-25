#include "item.h"
#include <string>
#include <cstdio>
int Item::get_stock_remaining(){
    return _stock_remaining;
}
void Item::modify_stock(int quantity_to_Add){
    _stock_remaining=_stock_remaining+quantity_to_Add;
}
std::string Item::to_string(){
    char output[_name.length()+_description.length()+100];
    std::sprintf(output,"Name: %s\tWholesale Cost: %0.2lf\tRetail Price: %0.2lf\tStock Remaining: %d\nDescription: %s",_name.c_str(),_wholesale_cost,_retail_price,_stock_remaining,_description.c_str());
    return output;
}