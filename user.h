#ifndef user_h
#define user_h
#include <string>
class User{
public:
    User(std::string username,std::string password);
    bool is_password(std::string password_attempt);
    std::string get_username();
    void change_username(User &admin,std::string username);
    void change_password(User &admin,std::string password);
protected:
    std::string _username;
    std::string _password;
};
#endif /* user_h */
