#include <iostream>
#include "container.h"
<<<<<<< HEAD
<<<<<<< HEAD

void Container::addContainer()
{
  std::string temp = "";
  std::cout << "Enter new container: ";
  std::cin >> temp;
  containers.push_back(temp);
  for (int i=0; i<containers.size(); i++)
  {
    std::cout << containers[i] << " ";
  }
  std::cout << std::endl;
=======
=======
namespace Mice{
<<<<<<< HEAD
>>>>>>> 3a36f28d739b85a8f20a070d6bab977a52c6e2eb
Container::Container(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path,int max_scoops) : Item(name,description,wholesale_cost,retail_price,initial_stock,image_file_path), _max_scoops{max_scoops} { }
=======
Container::Container(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path,int max_scoops) : Item(name,description,wholesale_cost,retail_price,initial_stock,image_file_path), _max_scoops{max_scoops} {
	_type="container";
}
>>>>>>> 99485964cefeba60fd572ae72b616c706c9cf755
std::string Container::to_string(){
    char output[_name.length()+_description.length()+100];
    std::sprintf(output,"Name: %s\tMax Scoops: %d\tWholesale Cost: %0.2lf\tRetail Price: %0.2lf\tStock Remaining: %d\nDescription: %s\n",_name.c_str(),_max_scoops,_wholesale_cost,_retail_price,_stock_remaining,_description.c_str());
    return output;
>>>>>>> b9c52d021dc5835ff2d8e89ca9c88bb79dcf2d10
}
}
