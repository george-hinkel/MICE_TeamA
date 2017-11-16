#include <iostream>
#include "order.h"

void Order::add_serving(Serving* serving){
	_servings.push_back(serving);
}
Serving* Order::get_serving(std::string serving_id){
	for(int i=0;i<_servings.size();i++){
		if(_servings[i]->get_id()==serving_id){
			return _servings[i];
		}
	}
	Serving* null_serving = (Serving*)malloc(sizeof(Serving));
	null_serving = new Serving("NULL");
	return null_serving;
}
void Order::remove_serving(Serving* serving){
	int index=-1;
	for(int i=0;i<_servings.size();i++){
		if(_servings[i]==serving){
			index=i;
		}
	}
	if(index!=-1){
		_servings.erase(_servings.begin()+index);
	}
}
std::string Order::to_string(int op){
	std::string output="Order ";
	output+=_order_id;
	output+="\tStatus: '";
	output+=_status;
	output+="'\tPrice: $";
	output+=std::to_string(get_retail_price());
	output+="\n";
	for(int i=0;i<_servings.size();i++){
		output+="Serving # ";
		output+=std::to_string(i+1);
		output+="\t";
		if(op==0){
			output+=_servings[i]->to_string();
		}else if(op==1){
			output+=_servings[i]->to_short_string();
		}
	}
	return output;
}
double Order::get_retail_price(){
	double price=0;
	for(int i=0;i<_servings.size();i++){
		price+=_servings[i]->get_retail_price();
	}
	return price;
}
double Order::get_wholesale_cost(){
	double cost=0;
	for(int i=0;i<_servings.size();i++){
		cost+=_servings[i]->get_wholesale_cost();
	}
	return cost;
}
std::string Order::get_id(){
	return _order_id;
}
std::string Order::get_status(){
	return _status;
}
void Order::fill(){
	if(_status=="unfilled"){
		_status="filled";
	}else{
		throw Invalid_status_change(_status,"filled");
	}
}
void Order::cancel(){
	if(_status=="unfilled"){
		_status="cancelled";
	}else{
		throw Invalid_status_change(_status,"cancelled");
	}
}
double Order::pay(){
	if(_status=="filled"){
		_status="paid";
	}else{
	//STATE MACHINE implemented with exceptions and handled in Main_window
		throw Invalid_status_change(_status,"paid");
	}
}
std::string Order::to_file_string(){
	std::string output = "order\n"+_order_id+"\n"+_status+"\n";
	for(int i=0;i<_servings.size();i++){
		output+= _servings[i]->to_file_string();
	}
	output+= "end order\n";
	return output;
}
std::string Order::order_summary(){
	std::string output="sold: ";
	for(int i=0;i<_servings.size();i++){
		output+= "serving "+std::to_string(i)+" "+_servings[i]->serving_summary()+"; ";
	}
	return output;
}
