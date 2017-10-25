#ifndef container_h
#define container_h
#include "item.h"
#include <string>
#include <iostream>
#include <vector>

class Container : public Item
{
  public:
    Container(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path="",int max_scoops=1);
    std::string to_string();
    //std::vector<std::string> containers = {"Cone", "Cup", "Bowl"}; //replaced with constructor
    //void addContainer();
private:
    int _max_scoops;
};
#endif
