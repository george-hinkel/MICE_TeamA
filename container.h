#ifndef container_h
#define container_h
#include <string>
#include <iostream>
#include <vector>
#include "item.h"

<<<<<<< HEAD
class Container
{
=======
class Container : public Item{
>>>>>>> b9c52d021dc5835ff2d8e89ca9c88bb79dcf2d10
  public:
    Container(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path="",int max_scoops=1);
    std::string to_string();
private:
    int _max_scoops;
};
#endif /* container.h */
