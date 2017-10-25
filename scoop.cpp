#include <iostream>
#include "scoop.h"

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
