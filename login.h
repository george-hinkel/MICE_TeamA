#ifndef __login_h
#define __login_h
#include <vector>
#include "emporium.h"
#include "dialogs.h"
class Login{
  public:
  	Login(Emporium* emporium);
  	User* get_current_user();

  private:
    User* _current_user;
};
#endif
