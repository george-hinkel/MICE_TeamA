#include "emporium.h"
#include <string>
Emporium::Emporium(std::string library_file_location) : _library_file_location{library_file_location} {
	_next_serving_id=0;
	_next_order_id=0;
    read_in_data();
}
void Emporium::read_in_data(){}
void Emporium::write_out_data(){}
void Emporium::add_user(User* user){
	_users.push_back(user);
}
User* Emporium::get_user(std::string username){
	for(int i=0;i<_users.size();i++){
		if(_users[i]->get_username()==username){
			return _users[i];
		}
	}
	User* null_user = (User*)malloc(sizeof(User));
	null_user = new User("NULL","NULL","NULL");
	return null_user;
}
std::string Emporium::list_users(){
	std::string output="";
	for(int i=0;i<_users.size();i++){
		output+=_users[i]->to_string();
	}
	return output;
}
void Emporium::add_item(Item* item){
	_items.push_back(item);
}
Item* Emporium::get_item(std::string name){
	for(int i=0;i<_items.size();i++){
		if(_items[i]->get_name()==name){
			return _items[i];
		}
	}
	Item* null_item = (Item*)malloc(sizeof(Item));
	null_item = new Item("NULL","NULL",0,0,0,"NULL");
	return null_item;
}
std::string Emporium::list_items(int op){
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
std::vector<Item*> Emporium::get_items_vector(int op){
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
std::vector<std::string> Emporium::get_item_names_vector(int op){
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
Item* Emporium::create_item_instance(Item* item){
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
std::string Emporium::list_servings(){
	std::string output="";
	for(int i=0;i<_unassigned_servings.size();i++){
		output+=_unassigned_servings[i]->to_string();
	}
	return output;
}
Serving* Emporium::get_serving(std::string serving_id){
	for(int i=0;i<_unassigned_servings.size();i++){
		if(_unassigned_servings[i]->get_id()==serving_id){
			return _unassigned_servings[i];
		}
	}
	Serving* null_serving = (Serving*)malloc(sizeof(Serving));
	null_serving = new Serving("NULL");
	return null_serving;
}
void Emporium::assemble_serving(){
	Serving* serving = (Serving*)malloc(sizeof(Serving));
	serving = new Serving(std::to_string(_next_serving_id));
	_unassigned_servings.push_back(serving);
	_next_serving_id++;
	for(int i=0;i<_item_instances.size();i++){
		serving->add_item(_item_instances[i]);
	}
	_item_instances.clear();
}
void Emporium::delete_serving(Serving* serving){
	int index=-1;
	for(int i=0;i<_unassigned_servings.size();i++){
		if(_unassigned_servings[i]==serving){
			index=i;
		}
	}
	if(index!=-1){
		_unassigned_servings.erase(_unassigned_servings.begin()+index);
		//free(serving);
	}
}
void Emporium::assemble_order(std::vector<int> serving_indexes){
	Order* order = (Order*)malloc(sizeof(Order));
	std::vector<Serving*> assigned_servings;
	order = new Order(std::to_string(_next_order_id));
	_next_order_id++;
	for(int& i : serving_indexes){
		order->add_serving(_unassigned_servings[i]);
		assigned_servings.push_back(_unassigned_servings[i]);
	}
	for(int i=0;i<assigned_servings.size();i++){
		delete_serving(assigned_servings[i]);
	}
	_active_orders.push_back(order);
}
std::string Emporium::list_orders(int op,int op2){
	std::string output="";
	if(op==0){
		for(int i=0;i<_active_orders.size();i++){
			output+=_active_orders[i]->to_string(op2);
		}
	}else if(op==1){
		for(int i=0;i<_active_orders.size();i++){
			if(_active_orders[i]->get_status()=="unfilled"){
				output+=_active_orders[i]->to_string(op2);
			}
		}
	}else if(op==2){
		for(int i=0;i<_active_orders.size();i++){
			if(_active_orders[i]->get_status()=="filled"){
				output+=_active_orders[i]->to_string(op2);
			}
		}
	}else if(op==3){
		for(int i=0;i<_active_orders.size();i++){
			if(_active_orders[i]->get_status()=="cancelled"){
				output+=_active_orders[i]->to_string(op2);
			}
		}
	}else if(op==4){
		for(int i=0;i<_active_orders.size();i++){
			if(_active_orders[i]->get_status()=="paid"){
				output+=_active_orders[i]->to_string(op2);
			}
		}
	}
	return output;
}
std::string Emporium::get_serving_listing(){
	std::string output="";
	for(int i=0;i<_unassigned_servings.size();i++){
		output+= std::to_string(i);
		output+= ": ";
		output+= _unassigned_servings[i]->to_short_string();
	}
	return output;
}
void Emporium::fill_order(std::string order_id){
	for(int i=0;i<_active_orders.size();i++){
		if(_active_orders[i]->get_id()==order_id){
			_active_orders[i]->fill();
		}
	}
}
void Emporium::pay_order(std::string order_id){
	for(int i=0;i<_active_orders.size();i++){
		if(_active_orders[i]->get_id()==order_id){
			_active_orders[i]->pay();
		}
	}
}
void Emporium::cancel_order(std::string order_id){
	for(int i=0;i<_active_orders.size();i++){
		if(_active_orders[i]->get_id()==order_id){
			_active_orders[i]->cancel();
		}
	}
}
