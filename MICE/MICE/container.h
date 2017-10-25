#ifndef container_h
#define container_h
#include "item.h"
#include <string>
#include <iostream>
#include <vector>

class Container : public Item
{
  public:
    std::vector<std::string> containers = {"Cone", "Cup", "Bowl"};
    void addContainer();
private:
    int max_scoops;
};
#endif
