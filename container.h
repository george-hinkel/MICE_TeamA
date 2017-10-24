#include <string>
#include <iostream>
#include <vector>

class container
{
  public:
    std::vector<std::string> containers = {"Cone", "Cup", "Bowl"};
    double price;
    int howMany;
    void addContainer();
};
