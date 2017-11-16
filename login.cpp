#include "login.h"
Login::Login(Emporium* emporium){
	_current_user=Dialogs::login(emporium);
}
User* Login::get_current_user(){
	return _current_user;
}
