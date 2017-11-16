#include "main_window.h"
using std::vector;
using std::string;

Main_window::Main_window(Emporium* emporium,User* user) : _emporium{emporium},_user{user} {
	
    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(1080, 720);

    // Put a vertical box container as the Window contents
    vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //		M A N A G E R
    menuitem_manager = Gtk::manage(new Gtk::MenuItem("_Manager", true));
    menubar->append(*menuitem_manager);
    Gtk::Menu *menu_manager = Gtk::manage(new Gtk::Menu());
    menuitem_manager->set_submenu(*menu_manager);

	// 		A D D  M A N A G E R
    menuitem_add_manager = Gtk::manage(new Gtk::MenuItem("_Add Manager", true));
    menuitem_add_manager->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_manager_click));
    menu_manager->append(*menuitem_add_manager);

    //				A D D   I T E M
    menuitem_add_item = Gtk::manage(new Gtk::MenuItem("_Add Item", true));
    menuitem_add_item->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_item_click));
    menu_manager->append(*menuitem_add_item);
    
    //				H I R E   S E R V E R
    menuitem_hire_server = Gtk::manage(new Gtk::MenuItem("_Hire Server", true));
    menuitem_hire_server->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_hire_server_click));
    menu_manager->append(*menuitem_hire_server);

	//				C H A N G E   S E R V E R   S A L A R Y
    menuitem_change_server_salary = Gtk::manage(new Gtk::MenuItem("_Change Server Salary", true));
    menuitem_change_server_salary->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_change_server_salary_click));
    menu_manager->append(*menuitem_change_server_salary);
    
    //				R E P O R T S
    menuitem_reports = Gtk::manage(new Gtk::MenuItem("_Reports", true));
    menu_manager->append(*menuitem_reports);
    menu_reports = Gtk::manage(new Gtk::Menu());
    menuitem_reports->set_submenu(*menu_reports);

	//						S E R V E R   R E P O R T
    menuitem_server_report = Gtk::manage(new Gtk::MenuItem("_Server Report", true));
    menuitem_server_report->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_server_report_click));
    menu_reports->append(*menuitem_server_report);

	//						C U S T O M E R   R E P O R T
    menuitem_customer_report = Gtk::manage(new Gtk::MenuItem("_Customer Report", true));
    menuitem_customer_report->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_customer_report_click));
    menu_reports->append(*menuitem_customer_report);
    
    //						I N V E N T O R Y   R E P O R T
    menuitem_inventory_report = Gtk::manage(new Gtk::MenuItem("_Inventory Report", true));
    menuitem_inventory_report->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_inventory_report_click));
    menu_reports->append(*menuitem_inventory_report);
    
    //						O R D E R   R E P O R T
    menuitem_order_report = Gtk::manage(new Gtk::MenuItem("_Order Report", true));
    menuitem_order_report->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_order_report_click));
    menu_reports->append(*menuitem_order_report);
    
    //						P R O F I T   L O S S   S T A T E M E N T
    menuitem_profit_loss_statement = Gtk::manage(new Gtk::MenuItem("_Profit and Loss Statement", true));
    menuitem_profit_loss_statement->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_profit_loss_statement_click));
    menu_reports->append(*menuitem_profit_loss_statement);

	//		S E R V E R
    menuitem_server = Gtk::manage(new Gtk::MenuItem("_Server", true));
    menubar->append(*menuitem_server);
    menu_server = Gtk::manage(new Gtk::Menu());
    menuitem_server->set_submenu(*menu_server);
    
    //				R E G I S T E R   C U S T O M E R
    menuitem_register_customer = Gtk::manage(new Gtk::MenuItem("_Register New Customer", true));
    menuitem_register_customer->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_register_customer_click));
    menu_server->append(*menuitem_register_customer);
    
	//				C R E A T E   S E R V I N G
    menuitem_s_create_serving = Gtk::manage(new Gtk::MenuItem("_Create Serving", true));
    menuitem_s_create_serving->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_create_serving_click));
    menu_server->append(*menuitem_s_create_serving);
     
        //                    V I E W  S E R V I N G
    menuitem_s_view_serving = Gtk::manage(new Gtk::MenuItem("_View Serving", true));
    menuitem_s_view_serving->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_view_serving_click));
    menu_server->append(*menuitem_s_view_serving);
    
	//				A S S E M B L E   O R D E R
    menuitem_s_assemble_order = Gtk::manage(new Gtk::MenuItem("_Assemble Order", true));
    menuitem_s_assemble_order->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_assemble_order_click));
    menu_server->append(*menuitem_s_assemble_order);
    
    //				F I L L   O R D E R
    menuitem_fill_order = Gtk::manage(new Gtk::MenuItem("_Fill Order", true));
    menuitem_fill_order->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_fill_order_click));
    menu_server->append(*menuitem_fill_order);
   
    //				C H E C K O U T   O R D E R
    menuitem_checkout_order = Gtk::manage(new Gtk::MenuItem("_Checkout Order", true));
    menuitem_checkout_order->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_checkout_order_click));
    menu_server->append(*menuitem_checkout_order);
    
	//		C U S T O M E R
    menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menubar->append(*menuitem_customer);
    menu_customer = Gtk::manage(new Gtk::Menu());
    menuitem_customer->set_submenu(*menu_customer);
    
	//				C R E A T E   S E R V I N G
    menuitem_c_create_serving = Gtk::manage(new Gtk::MenuItem("_Create Serving", true));
    menuitem_c_create_serving->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_create_serving_click));
    menu_customer->append(*menuitem_c_create_serving);

	//			 C U S T O M E R  V I E W  O R D E R
    menuitem_c_view_order = Gtk::manage(new Gtk::MenuItem("_View Order", true));
    menuitem_c_view_order->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_view_order_click));
    menu_customer->append(*menuitem_c_view_order);
    
    //				V E R I F Y   S E R V I N G
    menuitem_verify_serving = Gtk::manage(new Gtk::MenuItem("_Verify Serving", true));
    menuitem_verify_serving->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_verify_serving_click));
    menu_customer->append(*menuitem_verify_serving);
	
	//				A S S E M B L E   O R D E R
    menuitem_c_assemble_order = Gtk::manage(new Gtk::MenuItem("_Assemble Order", true));
    menuitem_c_assemble_order->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_assemble_order_click));
    menu_customer->append(*menuitem_c_assemble_order);
	
	//				C A N C E L   O R D E R
    menuitem_cancel_order = Gtk::manage(new Gtk::MenuItem("_Cancel Order", true));
    menuitem_cancel_order->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_cancel_order_click));
    menu_customer->append(*menuitem_cancel_order);
	
    //		T E S T
    menuitem_test = Gtk::manage(new Gtk::MenuItem("_Test", true));
    menubar->append(*menuitem_test);
    menu_test = Gtk::manage(new Gtk::Menu());
    menuitem_test->set_submenu(*menu_test);

	//				R U N   T E S T
    menuitem_run_test = Gtk::manage(new Gtk::MenuItem("_Run Test", true));
    menuitem_run_test->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_run_test_click));
    menu_test->append(*menuitem_run_test);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //     A D D   I T E M
    button_add_item = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
    button_add_item->set_tooltip_markup("Add item");
    button_add_item->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_add_item_click));
    toolbar->append(*button_add_item);

    //		H I R E   S E R V E R
    button_hire_server = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
    button_hire_server->set_tooltip_markup("Hire Server");
    button_hire_server->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_hire_server_click));
    toolbar->append(*button_hire_server);

    //		S E R V E R   R E P O R T
    button_server_report = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::DND));
    button_server_report->set_tooltip_markup("Server Report");
    button_server_report->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_server_report_click));
    toolbar->append(*button_server_report);

    //		C U S T O M E R   R E P O R T
    button_customer_report = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::DND));
    button_customer_report->set_tooltip_markup("Customer Report");
    button_customer_report->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_customer_report_click));
    toolbar->append(*button_customer_report);

	//		I N V E N T O R Y   R E P O R T
    button_inventory_report = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::DND));
    button_inventory_report->set_tooltip_markup("Inventory Report");
    button_inventory_report->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_inventory_report_click));
    toolbar->append(*button_inventory_report);

    //		O R D E R   R E P O R T
    button_order_report = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::DND));
    button_order_report->set_tooltip_markup("Order Report");
    button_order_report->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_order_report_click));
    toolbar->append(*button_order_report);
    
    //		O R D E R   R E P O R T
    button_profit_loss_statement = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::DND));
    button_profit_loss_statement->set_tooltip_markup("Profit and Loss Statement");
    button_profit_loss_statement->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_profit_loss_statement_click));
    toolbar->append(*button_profit_loss_statement);

	//		C R E A T E   S E R V I N G
    button_create_serving = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    button_create_serving->set_tooltip_markup("Create Serving");
    button_create_serving->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_create_serving_click));
    toolbar->append(*button_create_serving);
    
    //		A S S E M B L E   O R D E R
    button_assemble_order = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    button_assemble_order->set_tooltip_markup("Assemble Order");
    button_assemble_order->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_assemble_order_click));
    toolbar->append(*button_assemble_order);

	//		F I L L   O R D E R
    button_fill_order = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::CONNECT));
    button_fill_order->set_tooltip_markup("Fill Order");
    button_fill_order->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_fill_order_click));
    toolbar->append(*button_fill_order);

	//		C H E C K O U T   O R D E R
    button_checkout_order = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::APPLY));
    button_checkout_order->set_tooltip_markup("Checkout Order");
    button_checkout_order->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_checkout_order_click));
    toolbar->append(*button_checkout_order);

	//		C A N C E L   O R D E R
    button_cancel_order = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::CANCEL));
    button_cancel_order->set_tooltip_markup("Cancel Order");
    button_cancel_order->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_cancel_order_click));
    toolbar->append(*button_cancel_order);
    
    //		R U N   T E S T
    button_run_test = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::EXECUTE));
    button_run_test->set_tooltip_markup("Run Test");
    button_run_test->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_run_test_click));
    toolbar->append(*button_run_test);

	//     Q U I T
    // Add a icon for quitting
    quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit");
    quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);

    // D I S P L A Y
    // Provide a label to display things
    displayWindow = Gtk::manage(new Gtk::ScrolledWindow());
    displayWindow->set_border_width(10);
    displayWindow->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);
    vbox->pack_start(*displayWindow);
    display = Gtk::manage(new Gtk::Label());
    // display->set_has_frame(false);
    display->set_hexpand(true);
    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    //msg->set_vexpand(true);
	
	// D I S P L A Y   B O X
	// Provide a display box for entries and comboboxtexts
	displayBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	
    displayWindow->add(*displayBox);
    displayBox->pack_start(*display);
    displayBox->pack_start(*msg);
    displayBox->show_all();
    // Make the box and everything in it visible
    vbox->show_all();
	if(user->get_privilege()<2){
		menuitem_manager->hide();
		button_server_report->hide();
        button_customer_report->hide();
        button_inventory_report->hide();
        button_order_report->hide();
        button_profit_loss_statement->hide();
        button_add_item->hide();
        button_hire_server->hide();
	}
	if(user->get_privilege()<1){
		menuitem_server->hide();
		button_fill_order->hide();
        button_checkout_order->hide();
	}
    if(_user->get_username()=="admin"){
    	_emporium->delete_user("admin");
    }
}


Main_window::~Main_window() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Main_window::on_add_manager_click(){
	User* user = Dialogs::create_user(2);
	if(user->get_username()!="NULL") _emporium->add_user(user);
	dstring=_emporium->list_users(3);
	update_display(0);
}
void Main_window::on_add_item_click(){
	Item* item=Dialogs::create_item(*this);
	if(item->get_name()!="NULL") _emporium->add_item(item);
	update_display(1);
}
void Main_window::on_hire_server_click(){
	User* user = Dialogs::create_user(1);
	if(user->get_username()!="NULL") _emporium->add_user(user);
	dstring=_emporium->list_users(2);
	update_display(0);
}
void Main_window::on_server_report_click(){
	tstring = "Server Report...";
	dstring = _emporium->get_server_report();
	update_display(0);
}
void Main_window::on_customer_report_click(){}
void Main_window::on_inventory_report_click(){
	// words go here
	tstring = "Inventory Report...";
	dstring = _emporium->get_inventory_report();
	update_display(0);
}
void Main_window::on_order_report_click(){}
void Main_window::on_profit_loss_statement_click(){
	tstring = "Profit and Loss Statement...";
	dstring = _emporium->get_profit_loss_statement();
	update_display(0);
}
void Main_window::on_create_serving_click(){
	std::vector<Item*> temp;
	std::vector<std::string> temps;
	int index;
	int number;
	std::vector<std::string> qualifiers = {"light","normal","extra","drenched"};
	Item* tempitem;
	
	//add a container
	temp = _emporium->get_items_vector(1);
	temps= _emporium->get_item_names_vector(1);
	index = Dialogs::question(_emporium->list_items(1),"Choose a container",temps,*this);
	_emporium->create_item_instance(temp[index]);
	
	//add 1-N scoops
	temp = _emporium->get_items_vector(2);
	temps= _emporium->get_item_names_vector(2);
	number=stoi(Dialogs::input("How many scoops would you like?","Choose number of scoops","1","1"));
	for(int i=0;i<number;i++){
		index = Dialogs::question(_emporium->list_items(2),"Choose a scoop",temps,*this);
		_emporium->create_item_instance(temp[index]);
	}
	
	//add 0-N toppings
	temp = _emporium->get_items_vector(3);
	temps= _emporium->get_item_names_vector(3);
	number=stoi(Dialogs::input("How many toppings would you like?","Choose number of toppings","0","0"));
	for(int i=0;i<number;i++){
		index = Dialogs::question(_emporium->list_items(2),"Choose a topping",temps,*this);
		tempitem=_emporium->create_item_instance(temp[index]);
		static_cast<Topping*>(tempitem)->change_quantifier(Dialogs::question("Choose topping intensity","Choose a topping",qualifiers,*this));
	}
	
	_emporium->assemble_serving();
	
	dstring=_emporium->list_servings();
	update_display(0);
}
void Main_window::on_view_serving_click(){
        std::string serving_id = Dialogs::input(_emporium->list_servings(),"Input serving id of your serving...","serving id #","");
	Serving* serving = _emporium->get_serving(serving_id);
	int done_view = Dialogs::question(serving->to_string(), "Ready to fill order?",{"Yes","No"},*this);
	dstring = std::to_string(done_view);
	if(done_view==0){
		on_assemble_order_click();
	}
}
void Main_window::on_assemble_order_click(){
	int number=0;
	std::vector<int> serving_indexes;
	std::string servings=_emporium->get_serving_listing();
	int index=0;
	
	number=stoi(Dialogs::input("How many servings are in this order?","Choose number of servings","1","1"));
	for(int i=0;i<number;i++){
		index=stoi(Dialogs::input(servings,"Choose serving index","0","0"));
		serving_indexes.push_back(index);
	}
	
	_emporium->assemble_order(serving_indexes);
	tstring = "Orders...";
	dstring = _emporium->list_orders(0,0);
	update_display(0);
}
void Main_window::on_view_order_click(){
	std::string orders = _emporium->list_orders(0,1);
	std::string order_id=Dialogs::input(orders,"Choose order id","0","0");
	Order* order = _emporium->get_order(order_id);
	int done_view = Dialogs::question(order->to_string(0), "Click when done viewing",{"Okay"},*this);
	tstring = "";
	dstring = "";
	update_display(0);
}
void Main_window::on_fill_order_click(){
	std::string orders = _emporium->list_orders(1,1);
	std::string order_id=Dialogs::input(orders,"Choose order id","0","0");
	try{
		_emporium->fill_order(order_id);
	}catch(Order::Invalid_status_change e){
		Dialogs::message(e.what(),"Error!");
	}
	tstring = "Orders...";
	dstring = _emporium->list_orders(0,1);
	update_display(0);
}
void Main_window::on_checkout_order_click(){
	std::string orders = _emporium->list_orders(2,1);
	std::string order_id=Dialogs::input(orders,"Choose order id","0","0");
	try{
		_emporium->pay_order(order_id);
	}catch(Order::Invalid_status_change e){
		Dialogs::message(e.what(),"Error!");
	}
	tstring = "Orders...";
	dstring = _emporium->list_orders(0,1);
	update_display(0);
}
void Main_window::on_cancel_order_click(){
	std::string orders = _emporium->list_orders(1,1);
	std::string order_id=Dialogs::input(orders,"Choose order id","0","0");
	try{
		_emporium->cancel_order(order_id);
	}catch(Order::Invalid_status_change e){
		Dialogs::message(e.what(),"Error!");
	}
	tstring = "Orders...";
	dstring = _emporium->list_orders(0,1);
	update_display(0);
}
void Main_window::on_run_test_click(){
    update_display(1);
}
void Main_window::on_quit_click(){
	_emporium->write_out_data();
	hide();
}
void Main_window::on_verify_serving_click(){
	std::string serving_id = Dialogs::input(_emporium->list_servings(),"Input serving id of your serving...","serving id #","");
	Serving* serving = _emporium->get_serving(serving_id);
	int op = Dialogs::question(serving->to_string(),"Is your serving correct?",{"Yes","No"},*this);
	dstring = std::to_string(op);
	update_display(0);
	if(op==1){
		_emporium->delete_serving(serving);
		on_create_serving_click();
	}
}
void Main_window::on_register_customer_click(){
	User* user = Dialogs::create_user(0);
	if(user->get_username()!="NULL") _emporium->add_user(user);
	dstring=_emporium->list_users(1);
	update_display(0);
}
void Main_window::on_change_server_salary_click(){
	Server* server;
	std::vector<User*> servers = _emporium->get_users_vector(2);
	std::vector<std::string> servers_names = _emporium->get_users_name_vector(2);
	int server_index = Dialogs::question("Choose whose salary to change.","Changing Server Salary...",servers_names,*this);
	server=(Server*)servers[server_index];
	std::string msg = "Old salary: "+std::to_string(server->get_hourly_wage())+"\nChoose a new salary!";
	double new_salary = stod(Dialogs::input(msg,"Set New Salary...","0.00",std::to_string(server->get_hourly_wage())));
	if(new_salary!=server->get_hourly_wage()){
		server->set_hourly_wage(new_salary);
	}
}

// /////////////////
// U T I L I T I E S
// /////////////////

void Main_window::update_display(int op) {
    // s collects the status message
    if(op==1){
		display_items();
	}else{
		for(Gtk::Box* box : item_boxes){
			box->hide();
			delete box;
		}
		item_boxes.clear();
	}
    if(op>=0){
    	display->set_markup(tstring);
    	msg->set_markup(dstring);
	}
	
}
void Main_window::display_items(){
	std::vector<Item*> items = _emporium->get_items_vector(0);
	tstring = "Items...";
	dstring = "";
	Gtk::Box* item_box;
	Gtk::Image *item_image;
	for(Item* item : items){
		item_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
		item_image = new Gtk::Image{item->get_image_file_path()};
		item_box->pack_start(*item_image);
		Gtk::Label *item_label = Gtk::manage(new Gtk::Label(item->to_string()));
		item_box->pack_start(*item_label);
		item_boxes.push_back(item_box);
		displayBox->pack_start(*item_box);
	}
	displayBox->show_all();
}

