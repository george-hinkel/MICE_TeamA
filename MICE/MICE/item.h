#ifndef item_h
#define item_h
#include <string>
class Item{
public:
    
protected:
    std::string name;
    std::string description;
    double wholesale_cost;
    double retail_price;
    int stock_remaining;
    std::string picture_location;
};
#endif /* item_h */
