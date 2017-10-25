#ifndef item_h
#define item_h
#include <string>
class Item{
public:
    Item(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path="") : _name{name},_description{description},_wholesale_cost{wholesale_cost},_retail_price{retail_price},_stock_remaining{initial_stock},_image_file_path{image_file_path} { }
    virtual std::string to_string();
    int get_stock_remaining();
    void modify_stock(int quantity_to_add);
protected:
    std::string _name;
    std::string _description;
    double _wholesale_cost;
    double _retail_price;
    int _stock_remaining;
    std::string _image_file_path;
};
#endif /* item_h */
