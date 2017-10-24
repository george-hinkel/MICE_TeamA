#include <string>
#include <iostream>
#include <vector>

class scoop
{
  public:
    std::vector<std::string> flavors = {"Chocolate", "Vanilla", "Strawberry"};
    void addFlavor();
    void setPrice();
    double getPrice();

  private:
    double price;

};
