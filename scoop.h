#ifndef scoop_h
#define scoop_h
#include <string>
#include <iostream>
#include <vector>
#include "item.h"

<<<<<<< HEAD
class Scoop
{
=======
class Scoop : public Item{
>>>>>>> b9c52d021dc5835ff2d8e89ca9c88bb79dcf2d10
  public:
    Scoop(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path="");

  private:

}; 
#endif /* scppp.h */
