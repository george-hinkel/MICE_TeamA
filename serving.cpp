#include "serving.h"
#include <iostream>
void Serving::add_item(Item* item){
	_items.push_back(item);
}
Item* Serving::get_item(std::string name){
	for(int i=0;i<_items.size();i++){
		if(_items[i]->get_name()==name){
			return _items[i];
		}
	}
	Item* null_item = (Item*)malloc(sizeof(Item));
	null_item = new Item("NULL","NULL",0,0,0,"NULL");
	return null_item;
}
void Serving::remove_item(Item* item){
	int index=-1;
	for(int i=0;i<_items.size();i++){
		if(_items[i]==item){
			index=i;
		}
	}
	if(index!=-1){
		_items.erase(_items.begin()+index);
	}
}
std::string Serving::get_id(){
	return _serving_id;
}
std::string Serving::to_string(){
	std::string output="Serving ID:";
	output+= _serving_id;
	output+= "\n";
	for(int i=0;i<_items.size();i++){
		output+= "item #";
		output+= std::to_string(i+1);
		output+= "\t";
		output+= _items[i]->to_string();
	}
	return output;
}
double Serving::get_retail_price(){
	double price=0;
	for(int i=0;i<_items.size();i++){
		price+=_items[i]->get_retail_price();
	}
	return price;
}
double Serving::get_wholesale_cost(){
	double cost=0;
	for(int i=0;i<_items.size();i++){
		cost+=_items[i]->get_wholesale_cost();
	}
	return cost;
}
std::string Serving::to_short_string(){
	std::string output="";
	for(int i=0;i<_items.size();i++){
		output+= "Item ";
		output+= std::to_string(i+1);
		output+= ": ";
		output+= _items[i]->get_name();
		output+= ";  ";
	}
	output+="\n";
	return output;
}
