#ifndef data_library_h
#define data_library_h
#include "mice.h"
class Data_library{
public:
    Data_library(std::string library_file_location);
    void read_in_data();
    void write_out_data();
    void add_user(User *user);
    void add_item(Item *item);
    User* get_user(std::string username);
    Item* get_item(std::string name);
private:
    std::vector<Item*> _items;
    std::vector<User*> _users;
    std::string _library_file_location;
};
#endif /* data_library_h */
