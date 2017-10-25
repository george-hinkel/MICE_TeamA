#ifndef scoop_h
#define scoop_h
#include <string>
#include <iostream>
#include <vector>

class Scoop
{
  public:
    std::vector<std::string> flavors = {"Chocolate", "Vanilla", "Strawberry"};
    void addFlavor();
    void setPrice();
    double getPrice();

  private:
    double price;

}; 
#endif /* scppp.h */
