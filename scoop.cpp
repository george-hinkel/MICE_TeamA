#include <iostream>
#include "scoop.h"
<<<<<<< HEAD

void Scoop::addFlavor()
{
  std::string temp = "";
  std::cout << "Enter new flavor: ";
  std::cin >> temp;
  flavors.push_back(temp);
  for (int i=0; i<flavors.size(); i++)
  {
    std::cout << flavors[i] << " ";
  }
  std::cout << std::endl;
}

void Scoop::setPrice()
{
  std::cout << "Enter price per scoop: $";
  std::cin >> price;
}

double Scoop::getPrice(){return price;}
=======
Scoop::Scoop(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path) : Item(name,description,wholesale_cost,retail_price,initial_stock,image_file_path){ }
>>>>>>> b9c52d021dc5835ff2d8e89ca9c88bb79dcf2d10
