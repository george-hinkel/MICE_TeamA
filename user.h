#ifndef user_h
#define user_h
#include <string>
class User{
public:
    User(std::string username,std::string password,std::string name);
    bool is_password(std::string password_attempt);
    std::string get_username();
    void change_username(User &admin,std::string username);
    void change_password(User &admin,std::string password);
    std::string get_id();
    int get_privilege();
    virtual std::string to_string();
protected:
    std::string _username;
    std::string _password;
    std::string _name;
    std::string _id;
    int _privilege;
};
#endif /* user_h */
