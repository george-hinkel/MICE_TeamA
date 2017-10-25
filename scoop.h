#ifndef scoop_h
#define scoop_h
#include "item.h"
#include <string>
#include <iostream>
#include <vector>

class Scoop : public Item{
  public:
    Scoop(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path="");
    double getPrice();

  private:
    //double price; //replaced with inherited retail_price variable

};
#endif
