#ifndef emporium_h
#define emporium_h
#include "mice.h"
#include "order.h"
#include "serving.h"

class Emporium{
public:
    Emporium(std::string library_file_location="");
    void read_in_data();
    void write_out_data();
    
    void add_user(User* user);
    User* get_user(std::string username);
    std::string list_users();
    
    void add_item(Item* item);
    Item* get_item(std::string name);
    std::string list_items(int op);//0=all;1=containers;2=scoops;3=toppings
    std::vector<Item*> get_items_vector(int op);//same as above
    std::vector<std::string> get_item_names_vector(int op);//same as above
    Item* create_item_instance(Item* item);
    
    std::string list_servings();
    Serving* get_serving(std::string serving_id);
    void assemble_serving();
    void delete_serving(Serving* serving);
    
    void assemble_order(std::vector<int> serving_indexes);
private:
    std::vector<Item*> _items;
    std::vector<User*> _users;
    std::vector<Item*> _item_instances;
    std::vector<Serving*> _unassigned_servings;
    std::vector<Order*> _active_orders;
    std::string _library_file_location;
    int _next_serving_id;
};
#endif /* emporium_h */
