#include <iostream>
#include "serving.h"

void Serving::getMessage(std::string mess)
{
  std::cout << mess << std::endl;
}
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
std::string Serving::to_string(){}
