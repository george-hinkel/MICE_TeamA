#include <sstream>
#include "container.h"
namespace Mice{
Container::Container(std::string name,std::string description,double wholesale_cost,double retail_price,int initial_stock,std::string image_file_path,int max_scoops) : Item(name,description,wholesale_cost,retail_price,initial_stock,image_file_path), _max_scoops{max_scoops} {
	_type="container";
}
std::string Container::to_string(){
	std::string t="        ";
	std::stringstream ss;
    ss << Item::to_string() << t;
    ss << "Max Scoops: " << _max_scoops << std::endl;
    ss << t << _description;
    return ss.str();
}
std::string Container::to_file_string(int op){
	if(op==0){
		return Item::to_file_string(op)+std::to_string(_max_scoops)+"\n";
	}else if(op==1){
		return Item::to_file_string(op);
	}
}
}
