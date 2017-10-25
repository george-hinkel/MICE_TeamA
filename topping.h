#ifndef topping_h
#define topping_h
#include <vector>
#include <string>
#include "item.h"
class Topping : public Item{
public:
    Topping(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path="",int quantifier=1);
    std::string to_string();
private:
    int _quantifier;
    std::string _qualifiers[4] = {"light","normal","extra","drenched"};
};
#endif /* topping_h */
