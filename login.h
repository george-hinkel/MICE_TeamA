#ifndef __login_h
#define __login_h
#include <string>
#include <iostream>
#include <vector>

class login
{
  public:
    void verify();
    std::string userName = "manager";
    std::string password = "password";

  private:
    
    std::string attemptUser;
    std::string attemptPass;
};
#endif
