#include <iostream>
#include "order.h"
#include <string>
#include "serving.h"
#include "scoop.h"
#include "container.h"
#include "topping.h"

int main(){
    Container container("Waffle Cone","Delicious freshly made waffle cone",0.25,0.9,10);
    Scoop scoop("Vanilla","Delicious homemade vanilla ice cream scoop",0.8,1.5,10);
    Topping topping("Chocolate Syrup","Rich 100% milk chocolate syrup",0.1,0.25,10);
    std::cout << container.to_string() << std::endl;
    std::cout << scoop.to_string() << std::endl;
    std::cout << topping.to_string() << std::endl;
}
