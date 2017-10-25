#include <iostream>
#include "container.h"

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
}
