#include "data_library.h"
#include <string>
Data_library::Data_library(std::string library_file_location) : _library_file_location{library_file_location} {
	_next_serving_id=0;
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
Item* Data_library::get_item(std::string name){
	for(int i=0;i<_items.size();i++){
		if(_items[i]->get_name()==name){
			return _items[i];
		}
	}
	Item* null_item = (Item*)malloc(sizeof(Item));
	null_item = new Item("NULL","NULL",0,0,0,"NULL");
	return null_item;
}
std::string Data_library::list_items(int op){
	std::string output="";
	if(op==0){
		for(int i=0;i<_items.size();i++){
			output+=_items[i]->to_string();
		}
	}else if(op==1){
		for(int i=0;i<_items.size();i++){
			if(_items[i]->get_type()=="container"){
				output+=_items[i]->to_string();
			}
		}
	}else if(op==2){
		for(int i=0;i<_items.size();i++){
			if(_items[i]->get_type()=="scoop"){
				output+=_items[i]->to_string();
			}
		}
	}else if(op==3){
		for(int i=0;i<_items.size();i++){
			if(_items[i]->get_type()=="topping"){
				output+=_items[i]->to_string();
			}
		}
	}
	return output;
}
std::vector<Item*> Data_library::get_items_vector(int op){
	std::vector<Item*> output;
	if(op==0){
		for(int i=0;i<_items.size();i++){
			output.push_back(_items[i]);
		}
	}else if(op==1){
		for(int i=0;i<_items.size();i++){
			if(_items[i]->get_type()=="container"){
				output.push_back(_items[i]);
			}
		}
	}else if(op==2){
		for(int i=0;i<_items.size();i++){
			if(_items[i]->get_type()=="scoop"){
				output.push_back(_items[i]);
			}
		}
	}else if(op==3){
		for(int i=0;i<_items.size();i++){
			if(_items[i]->get_type()=="topping"){
				output.push_back(_items[i]);
			}
		}
	}
	return output;
}
std::vector<std::string> Data_library::get_item_names_vector(int op){
	std::vector<std::string> output;
	if(op==0){
		for(int i=0;i<_items.size();i++){
			output.push_back(_items[i]->get_name());
		}
	}else if(op==1){
		for(int i=0;i<_items.size();i++){
			if(_items[i]->get_type()=="container"){
				output.push_back(_items[i]->get_name());
			}
		}
	}else if(op==2){
		for(int i=0;i<_items.size();i++){
			if(_items[i]->get_type()=="scoop"){
				output.push_back(_items[i]->get_name());
			}
		}
	}else if(op==3){
		for(int i=0;i<_items.size();i++){
			if(_items[i]->get_type()=="topping"){
				output.push_back(_items[i]->get_name());
			}
		}
	}
	return output;
}
Item* Data_library::create_item_instance(Item* item){
	Item* instance;
	if(item->get_type()=="container"){
		instance = (Mice::Container*)malloc(sizeof(Mice::Container));
		Mice::Container* container = (Mice::Container*)item;
		instance=new Mice::Container(*container);
	}else if(item->get_type()=="scoop"){
		instance = (Scoop*)malloc(sizeof(Scoop));
		Scoop* scoop = (Scoop*)item;
		instance=new Scoop(*scoop);
	}else if(item->get_type()=="topping"){
		instance = (Topping*)malloc(sizeof(Topping));
		Topping* topping = (Topping*)item;
		instance=new Topping(*topping);
	}else{
		instance = (Item*)malloc(sizeof(Item));
		instance = new Item(*item);
	}
	_item_instances.push_back(instance);
	return instance;
}
Serving* Data_library::create_unassigned_serving(){
	Serving* serving = (Serving*)malloc(sizeof(Serving));
	serving = new Serving(std::to_string(_next_serving_id));
	_unassigned_servings.push_back(serving);
	_next_serving_id++;
	return serving;
}
std::string Data_library::list_servings(){
	std::string output="";
	for(int i=0;i<_unassigned_servings.size();i++){
		output+=_unassigned_servings[i]->to_string();
	}
	return output;
}
Serving* Data_library::get_serving(std::string serving_id){
	for(int i=0;i<_unassigned_servings.size();i++){
		if(_unassigned_servings[i]->get_id()==serving_id){
			return _unassigned_servings[i];
		}
	}
	Serving* null_serving = (Serving*)malloc(sizeof(Serving));
	null_serving = new Serving("NULL");
	return null_serving;
}
void Data_library::assemble_serving(){
	Serving* serving = (Serving*)malloc(sizeof(Serving));
	serving = new Serving(std::to_string(_next_serving_id));
	_unassigned_servings.push_back(serving);
	_next_serving_id++;
	for(int i=0;i<_item_instances.size();i++){
		serving->add_item(_item_instances[i]);
		//free(_item_instances[i]);
	}
	_item_instances.clear();
}
void Data_library::assemble_order(std::vector<int> serving_indexes){}
