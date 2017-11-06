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
std::string Order::to_string(){
	std::string output="";
	for(int i=0;i<_servings.size();i++){
		output+="Serving # ";
		output+=i;
		output+="\t";
		output+=_servings[i]->to_string();
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
