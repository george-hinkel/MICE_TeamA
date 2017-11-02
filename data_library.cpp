#include "data_library.h"
#include <string>
Data_library::Data_library(std::string library_file_location) : _library_file_location{library_file_location} {
    read_in_data();
}
void Data_library::read_in_data(){}
void Data_library::write_out_data(){}
void Data_library::add_user(User* user){
	_users.push_back(user);
}
void Data_library::add_item(Item* item){
	_items.push_back(item);
}
User* Data_library::get_user(std::string username){}
Item* Data_library::get_item(std::string name){}
void Data_library::add_unassigned_serving(Serving* serving){
	_unassigned_servings.push_back(serving);
}
void Data_library::assemble_order(std::vector<int> serving_indexes){}
