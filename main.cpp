#include <iostream>
#include "order.h"
#include <string>
#include "serving.h"
#include "scoop.h"
#include "container.h"
#include "login.h"

int main()
{
/*  std::cout << "This works now" << std::endl;
  std::string testing = "Container works";
  container newOne;
  newOne.addContainer();
  scoop scoop;
  container container;
  scoop.addFlavor();
  scoop.setPrice();
  std::cout << "$" << scoop.getPrice() << std::endl;
*/  login login;
  login.verify();
}
