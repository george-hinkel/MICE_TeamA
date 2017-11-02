#include "user.h"
User::User(std::string username,std::string password,std::string name) : _username{username},_password{password},_name{name} { }
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
std::string User::get_id(){
	return _id;
}
int User::get_privilege(){
	return _privilege;
}
std::string User::to_string(){
	return "Username: "+_username+"\tName: "+_name+"\tID: "+_id+"\n";
}
