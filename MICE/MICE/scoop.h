#ifndef scoop_h
#define scoop_h
#include "item.h"
#include <string>
#include <iostream>
#include <vector>

class Scoop : public Item
{
  public:
    std::vector<std::string> flavors = {"Chocolate", "Vanilla", "Strawberry"};
    void addFlavor();
    void setPrice();
    double getPrice();

  private:
    //double price; //replaced with inherited retail_price variable

};
#endif
