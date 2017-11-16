#ifndef item_h
#define item_h
#include <string>

class Item{
public:
    Item(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path="file-path");
    virtual std::string to_string();
    int get_stock_remaining();
    void modify_stock(int quantity_to_add);
    std::string get_name();
    std::string get_type();
    virtual double get_retail_price();
    virtual double get_wholesale_cost();
    virtual std::string to_file_string(int op);
    double get_stock_wholesale_cost();
    std::string get_image_file_path();
protected:
    std::string _type;
    std::string _name;
    std::string _description;
    double _wholesale_cost;
    double _retail_price;
    int _stock_remaining;
    std::string _image_file_path;
};
#endif /* item_h */
