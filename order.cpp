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
std::string Order::to_string(){}
