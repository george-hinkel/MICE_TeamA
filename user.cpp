#include "user.h"
User::User(std::string username,std::string password) : _username{username},_password{password} { }
bool User::is_password(std::string password_attempt){
    if(password_attempt==_password){
        return true;
    }else{
        return false;
    }
}
std::string User::get_username(){
    return _username;
}
