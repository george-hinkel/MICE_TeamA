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
<<<<<<< HEAD
>>>>>>> b9c52d021dc5835ff2d8e89ca9c88bb79dcf2d10
  public:
    Scoop(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path="");

  private:

}; 
#endif /* scppp.h */
=======
	public:
	    Scoop(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path="");
};
#endif /* scoop_h */
>>>>>>> 740686e9ff67c62723118b7e02f893295703e68b
