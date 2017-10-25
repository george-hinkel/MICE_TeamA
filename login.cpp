#include <iostream>
#include "order.h"
#include "serving.h"
#include "scoop.h"
#include "container.h"
#include "login.h"

void login::verify()
{
 do {
  std::cout << "Enter username (manager): ";
  std::cin >> attemptUser;
  int choice;
  scoop scoop;
  container container;
  
  if (attemptUser == userName)
  {
    std::cout << "Enter password (password): ";
    std::cin >> attemptPass;
    if (attemptPass == password)
    {
      do {
        std::cout << "Would you like to \n1) Add flavor\n2) Add container\n3) Add toppings" << std::endl;
        std::cin >> choice;
        switch(choice)
        {
          case 1: scoop.addFlavor();
  		break;
          case 2: container.addContainer();
	  	break;
          default: std::cout << "Invalid" << std::endl;
        }
      }while(choice != 0);
    }
    else
      std::cout << "Invalid password" << std::endl;
  }
  else
  {
    std::cout << "Invalid username" << std::endl;
  }
 } while(attemptUser != "0" && attemptPass != "0");
}