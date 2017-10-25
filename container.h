#ifndef container_h
#define container_h
#include <string>
#include <iostream>
#include <vector>

class Container
{
  public:
    std::vector<std::string> containers = {"Cone", "Cup", "Bowl"};
    double price;
    int howMany;
    void addContainer();
};
#endif /* container.h */
