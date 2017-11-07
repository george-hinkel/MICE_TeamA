#ifndef scoop_h
#define scoop_h
#include <string>
#include <iostream>
#include <vector>
#include "item.h"

class Scoop : public Item{
	public:
	    Scoop(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path="file-path");
};
#endif /* scoop_h */
