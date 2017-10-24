#include <iostream>
#include "scoop.h"

void scoop::addFlavor()
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

void scoop::setPrice()
{
  std::cout << "Enter price per scoop: $";
  std::cin >> price;
}

double scoop::getPrice(){return price;}
