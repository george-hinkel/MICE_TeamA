#include <string>
#include <iostream>
#include <vector>
#include "item.h"
namespace Mice{
class Container : public Item{
  public:
    Container(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path="",int max_scoops=1);
    std::string to_string();
private:
    int _max_scoops;
};
}
