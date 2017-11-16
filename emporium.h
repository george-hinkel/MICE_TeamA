#ifndef emporium_h
#define emporium_h
#include <iostream>
#include <fstream>
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
    void delete_user(std::string username);
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
    std::string list_orders(int op,int op2);//0=all;1=unfilled;2=filled;3=cancelled;4=paid;;;0=full;1=short
    std::string get_serving_listing();
    void fill_order(std::string order_id);
    void pay_order(std::string order_id);
    void cancel_order(std::string order_id);
    Order* get_order(std::string order_id);
    
    std::string get_profit_loss_statement();
private:
    std::vector<Item*> _items; //stock of items
    std::vector<User*> _users; //users i.e. servers, customers etc
    
    std::vector<Item*> _item_instances;//instances of items used in servings, list of those not in a serving
    std::vector<Serving*> _unassigned_servings;//servings not in an order
    std::vector<Order*> _orders;//active orders
    
    std::string _library_file_location;
    
    int _next_serving_id;
    int _next_order_id;
    
    class Cash_register{
    	public://O P E R A T O R   O V E R L O A D I N G   ! ! !
    		void operator+=(double num){
    			_balance = _balance + num;
    			_book.push_back(num);
    		}
    		void make_transaction(double num,std::string message){
    			(*this)+=num;
    			_history.push_back(message);
    		}
    		void annotate_transaction(std::string message){
    			_history.push_back(message);
    		}
    		std::string to_file_string(){
    			std::string output="";
    			for(int i=0;i<_book.size();i++){
    				if(_history[i]!=""){
    					output+= "wh\n"+std::to_string(_book[i])+"\n"+_history[i]+"\n";	 
    				}else{
    					output+= "nh\n"+std::to_string(_book[i])+"\n";
    				}
    			}
    			return output;
    		}
    		int size(){
    			return _book.size();
    		}
    		std::string statement(){
    			std::string output="Total profit = $"+std::to_string(_balance)+"\n";
    			for(int i=0;i<_book.size();i++){
    				output+= std::to_string(_book[i])+"\t"+_history[i]+"\n";
    			}
    			return output;
    		}
    	private:
    		double _balance;
    		std::vector<double> _book;
    		std::vector<std::string> _history;
    }_cash_register;
};
#endif /* emporium_h */
