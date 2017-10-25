#ifndef __login_h
#define __login_h
#include <string>
#include <iostream>
#include <vector>

<<<<<<< HEAD
class Login
{
=======
class Login{
>>>>>>> b9c52d021dc5835ff2d8e89ca9c88bb79dcf2d10
  public:
    void verify();
    std::string userName = "manager";
    std::string password = "password";

  private:
    
    std::string attemptUser;
    std::string attemptPass;
};
#endif
