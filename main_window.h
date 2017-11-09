#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <vector>
#include <gtkmm.h>
#include "emporium.h"
#include "mice.h"
#include "login.h"
#include "dialogs.h"
class Main_window : public Gtk::Window{
    public:
        Main_window(Emporium* emporium,User* user);
        virtual ~Main_window();
    protected:
	void on_add_manager_click();
        void on_add_item_click();  
        void on_hire_server_click(); 
        void on_server_report_click();
        void on_customer_report_click();
        void on_inventory_report_click();
        void on_order_report_click();
        void on_create_serving_click();
        void on_view_serving_click();
        void on_assemble_order_click();
        void on_fill_order_click();
        void on_checkout_order_click();
        void on_cancel_order_click();
        void on_run_test_click();
        void on_quit_click();
        void on_verify_serving_click();
        void on_register_customer_click();
	void on_view_order_click();
    private:
    	Emporium* _emporium;
    	User* _user;
    	
    	int activeWindow=0;
    	std::vector<Gtk::Entry *> entries;
    	std::vector<Gtk::ComboBoxText *> cboxs;
        void update_display();                    // Update display
        Gtk::Box *vbox;
        Gtk::Box *displayBox;
        Glib::ustring tstring;
        Glib::ustring dstring;
        Gtk::Label *display;  	// Display
        Gtk::Label *msg;  		// Status message display
        
        Gtk::ToolButton *button_add_item;
        Gtk::ToolButton *button_hire_server;
        Gtk::ToolButton *button_server_report;
        Gtk::ToolButton *button_customer_report;
        Gtk::ToolButton *button_inventory_report;
        Gtk::ToolButton *button_order_report;
        Gtk::ToolButton *button_create_serving;
        Gtk::ToolButton *button_assemble_order;
        Gtk::ToolButton *button_fill_order;
        Gtk::ToolButton *button_checkout_order;
        Gtk::ToolButton *button_cancel_order;
        Gtk::ToolButton *button_run_test;
        Gtk::ToolButton *quit_button;
    
    //menubar design
    	Gtk::MenuBar *menubar;
    		Gtk::MenuItem *menuitem_manager;
    		Gtk::Menu *menu_manager;
			Gtk::MenuItem *menuitem_add_manager;
    			Gtk::MenuItem *menuitem_add_item;
    			Gtk::MenuItem *menuitem_hire_server;
    			Gtk::MenuItem *menuitem_reports;
    			Gtk::Menu *menu_reports;
    				Gtk::MenuItem *menuitem_server_report;
    				Gtk::MenuItem *menuitem_customer_report;
    				Gtk::MenuItem *menuitem_inventory_report;
    				Gtk::MenuItem *menuitem_order_report;
			Gtk::MenuItem *menuitem_server;
			Gtk::Menu *menu_server;
				Gtk::MenuItem *menuitem_register_customer;
				Gtk::MenuItem *menuitem_s_create_serving;
                                Gtk::MenuItem *menuitem_s_view_serving;
				Gtk::MenuItem *menuitem_s_assemble_order;
				Gtk::MenuItem *menuitem_fill_order;
				Gtk::MenuItem *menuitem_checkout_order;
			Gtk::MenuItem *menuitem_customer;
			Gtk::Menu *menu_customer;
				Gtk::MenuItem *menuitem_c_create_serving;
				Gtk::MenuItem *menuitem_c_view_order;
				Gtk::MenuItem *menuitem_verify_serving;
				Gtk::MenuItem *menuitem_c_assemble_order;
				Gtk::MenuItem *menuitem_cancel_order;
			Gtk::MenuItem *menuitem_test;
			Gtk::Menu *menu_test;
				Gtk::MenuItem *menuitem_run_test;
};
#endif 

