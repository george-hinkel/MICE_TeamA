#include <iostream>
#include "order.h"
#include <string>
#include "serving.h"
#include "scoop.h"
#include "container.h"

int main()
{
  std::cout << "This works now" << std::endl;
  std::string testing = "Container works";
  Container newOne;
  newOne.addContainer();
  Scoop other;
  other.addFlavor();
  other.setPrice();
  std::cout << other.getPrice();
}
