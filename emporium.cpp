#include "emporium.h"
#include <string>
#include <iostream>
Emporium::Emporium(std::string library_file_location) : _library_file_location{library_file_location} {
    read_in_data();
    if(_users.size()==0){
    	User* default_manager = new Manager("admin","admin","admin");
    	add_user(default_manager);
    }
}
void Emporium::read_in_data(){
	std::ifstream file;
	file.open(_library_file_location);
	file.seekg(0);
	std::string line;
	std::vector<std::string> reads;
	std::vector<Serving*> temp_servings;
	std::vector<Item*> temp_items;
	int serving_count;
	int max_order_id=-1;
	int max_serving_id=-1;
	while(getline(file,line)){
		if(line=="items"){
			while(line!="end items"){
				getline(file,line);
				if(line=="container"){
					for(int i=0;i<7;i++){
						getline(file,line);
						reads.push_back(line);
					}
					Mice::Container* container = (Mice::Container*)malloc(sizeof(Mice::Container));
					container = new Mice::Container(reads[0],reads[1],stod(reads[2]),stod(reads[3]),stoi(reads[4]),reads[5],stoi(reads[6]));
					_items.push_back(container);
					reads.clear();
				}else if(line=="scoop"){
					for(int i=0;i<6;i++){
						getline(file,line);
						reads.push_back(line);
					}
					Scoop* scoop = (Scoop*)malloc(sizeof(Scoop));
					scoop = new Scoop(reads[0],reads[1],stod(reads[2]),stod(reads[3]),stoi(reads[4]),reads[5]);
					_items.push_back(scoop);
					reads.clear();
				}else if(line=="topping"){
					for(int i=0;i<7;i++){
						getline(file,line);
						reads.push_back(line);
					}
					Topping* topping = (Topping*)malloc(sizeof(Topping));
					topping = new Topping(reads[0],reads[1],stod(reads[2]),stod(reads[3]),stoi(reads[4]),reads[5],stoi(reads[6]));
					_items.push_back(topping);
					reads.clear();
				}
			}
		}else if(line=="users"){
			while(line!="end users"){
				getline(file,line);
				if(line=="0"){//customer
					for(int i=0;i<4;i++){
						getline(file,line);
						reads.push_back(line);
					}
					Customer* customer = (Customer*)malloc(sizeof(Customer));
					customer = new Customer(reads[0],reads[1],reads[2],reads[3]);
					_users.push_back(customer);
					reads.clear();
				}else if(line=="1"){//server
					for(int i=0;i<5;i++){
						getline(file,line);
						reads.push_back(line);
					}
					Server* server = (Server*)malloc(sizeof(Server));
					server = new Server(reads[0],reads[1],reads[2],stoi(reads[3]),stod(reads[4]));
					_users.push_back(server);
					reads.clear();
				}else if(line=="2"){//manager
					for(int i=0;i<3;i++){
						getline(file,line);
						reads.push_back(line);
					}
					Manager* manager = (Manager*)malloc(sizeof(Manager));
					manager = new Manager(reads[0],reads[1],reads[2]);
					_users.push_back(manager);
					reads.clear();
				}
			}
		}else if(line=="orders"){
			while(line!="end orders"){
				getline(file,line);
				if(line=="order"){
					serving_count=0;
					for(int i=0;i<2;i++){
						getline(file,line);
						reads.push_back(line);
					}
					Order* order = (Order*)malloc(sizeof(Order));
					order = new Order(reads[0],reads[1]);
					if(stoi(reads[0])>max_order_id) max_order_id = stoi(reads[0]);
					reads.clear();
					while(line!="end order"){
						getline(file,line);
						if(line=="serving"){
							getline(file,line);
							Serving* serving = (Serving*)malloc(sizeof(Serving));
							serving = new Serving(line);
							if(stoi(line)>max_serving_id) max_serving_id = stoi(line);
							getline(file,line);
							while(line!="end serving"){
								Item* item = create_item_instance(get_item(line));
								if(item->get_type()=="topping"){
									getline(file,line);
									static_cast<Topping*>(item)->change_quantifier(stoi(line));
								}
								temp_items.push_back(item);
								getline(file,line);
							}
							for(int i=0;i<temp_items.size();i++){
								serving->add_item(temp_items[i]);
							}
							temp_items.clear();
							temp_servings.push_back(serving);
						}
					}
					for(int i=0;i<temp_servings.size();i++){
						order->add_serving(temp_servings[i]);
					}
					temp_servings.clear();
					_item_instances.clear();
					_orders.push_back(order);
				}
			}
		}else if(line=="transactions"){
			while(line!="end transactions"){
				getline(file,line);
				if(line=="wh"){
					for(int i=0;i<2;i++){
						getline(file,line);
						reads.push_back(line);
					}
					_cash_register.make_transaction(stod(reads[0]),reads[1]);
					reads.clear();
				}else if(line=="nh"){
					getline(file,line);
					_cash_register.make_transaction(stod(line),"n/a");
				}
			}
		}
	}
	_next_serving_id = max_serving_id+1;
	_next_order_id   = max_order_id+1;
	file.close();
}
void Emporium::write_out_data(){
	std::ofstream file;
	file.open(_library_file_location);
	file.seekp(0);
	if(_items.size()>0){ file << "items" << std::endl;}
	for(int i=0;i<_items.size();i++){
		file << _items[i]->to_file_string(0);
	}
	if(_items.size()>0){ file << "end items" << std::endl;}
	if(_users.size()!=0) file << "users" << std::endl;
	for(int i=0;i<_users.size();i++){
		file << _users[i]->to_file_string();
	}
	if(_users.size()!=0) file << "end users" << std::endl;
	if(_orders.size()!=0) file << "orders" << std::endl;
	for(int i=0;i<_orders.size();i++){
		file << _orders[i]->to_file_string();
	}
	if(_orders.size()!=0) file << "end orders" << std::endl;
	if(_cash_register.size()!=0){
		file << "transactions" << std::endl;
		file << _cash_register.to_file_string();
		file << "end transactions" << std::endl;
	}
	file.close();
}
void Emporium::add_user(User* user){
	_users.push_back(user);
}
User* Emporium::get_user(std::string username){
	for(int i=0;i<_users.size();i++){
		if(_users[i]->get_username()==username){
			return _users[i];
		}
	}
	User* null_user = new User("NULL","NULL","NULL");
	return null_user;
}
void Emporium::delete_user(std::string username){
	int index=-1;
	for(int i=0;i<_users.size();i++){
		if(_users[i]->get_username()==username){
			index=i;
		}
	}
	if(index!=-1){
		_users.erase(_users.begin()+index);
	}
}
std::string Emporium::list_users(int op){
	std::string output="";
	for(User* user : _users){
		if(op==0){
			output+= user->to_string();
		}else if(user->get_privilege()==op-1){
			output+= user->to_string();	
		}
	}
	return output;
}
std::vector<User*> Emporium::get_users_vector(int op){
	std::vector<User*> users;
	for(User* user : _users){
		if(op==0){
			users.push_back(user);
		}else if(user->get_privilege()==op-1){
			users.push_back(user);
		}
	}
	return users;
}
std::vector<std::string> Emporium::get_users_name_vector(int op){
	std::vector<std::string> users_names;
	for(User* user : _users){
		if(op==0){
			users_names.push_back(user->get_name());
		}else if(user->get_privilege()==op-1){
			users_names.push_back(user->get_name());
		}
	}
	return users_names;
}
void Emporium::add_item(Item* item){
	_items.push_back(item);
	double num = -1*item->get_stock_wholesale_cost();
	std::string message = std::to_string(item->get_stock_remaining())+" x "+item->get_name()+" purchased and stocked.";
	_cash_register.make_transaction(num,message);
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
		item->modify_stock(-1);
		instance = (Mice::Container*)malloc(sizeof(Mice::Container));
		Mice::Container* container = (Mice::Container*)item;
		instance=new Mice::Container(*container);
	}else if(item->get_type()=="scoop"){
		item->modify_stock(-1);
		instance = (Scoop*)malloc(sizeof(Scoop));
		Scoop* scoop = (Scoop*)item;
		instance=new Scoop(*scoop);
	}else if(item->get_type()=="topping"){
		item->modify_stock(-1*static_cast<Topping*>(item)->get_quantifier());
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
	_orders.push_back(order);
}
std::string Emporium::list_orders(int op,int op2){
	std::string output="";
	if(op==0){
		for(int i=0;i<_orders.size();i++){
			output+=_orders[i]->to_string(op2);
		}
	}else if(op==1){
		for(int i=0;i<_orders.size();i++){
			if(_orders[i]->get_status()=="unfilled"){
				output+=_orders[i]->to_string(op2);
			}
		}
	}else if(op==2){
		for(int i=0;i<_orders.size();i++){
			if(_orders[i]->get_status()=="filled"){
				output+=_orders[i]->to_string(op2);
			}
		}
	}else if(op==3){
		for(int i=0;i<_orders.size();i++){
			if(_orders[i]->get_status()=="cancelled"){
				output+=_orders[i]->to_string(op2);
			}
		}
	}else if(op==4){
		for(int i=0;i<_orders.size();i++){
			if(_orders[i]->get_status()=="paid"){
				output+=_orders[i]->to_string(op2);
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
	for(int i=0;i<_orders.size();i++){
		if(_orders[i]->get_id()==order_id){
			_orders[i]->fill();
		}
	}
}
void Emporium::pay_order(std::string order_id){
	Order* order;
	for(int i=0;i<_orders.size();i++){
		if(_orders[i]->get_id()==order_id){
			order=_orders[i];
		}
	}
	order->pay();
	_cash_register.make_transaction(order->get_retail_price(),order->order_summary());
}
void Emporium::cancel_order(std::string order_id){
	for(Order* order : _orders){
		if(order->get_id()==order_id){
			order->cancel();
		}
	}
}
Order* Emporium::get_order(std::string order_id){
	for(Order* order : _orders){
		if(order->get_id()==order_id){
			return order;
		}
	}
}
std::string Emporium::get_order_report(){
	//std::vector<std::string> all_orders;
	//int order_id=0;
	std::string all_orders = "All Pending Orders:\n";
	for(Order* order : _orders){
		if (order->get_status() != "paid"){
			all_orders += order->to_string(0);
			all_orders += "\n";
		}
	}
	return all_orders;
}
std::string Emporium::get_profit_loss_statement(){
	return _cash_register.statement();
}
std::string Emporium::get_inventory_report(){
	std::string output="Item Name\tStock Remaining\n";
	for(Item* item : _items){
		output+= item->get_name()+": "+std::to_string(item->get_stock_remaining())+"\n";
	}
	return output;
}
void Emporium::restock_item(int how_much){
	for(Item* item : _items){
		item->modify_stock(how_much);
	}
	
}
std::string Emporium::get_server_report(){
	return list_users(2);
}

std::string Emporium::get_customer_report(){
	return list_users(1);
}
