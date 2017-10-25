#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
//#include "manager.h"

class Main_window : public Gtk::Window{
    public:
        Main_window();
        virtual ~Main_window();
    protected:
        void on_ap_click();  
        void on_lp_click(); 
        void on_cop_click();
        void on_cip_click();
        void on_apa_click();
        void on_lpa_click();
        void on_about_click();
        void on_quit_click();
        void on_gen_test_click();
        void on_new_lib_click();
        void on_enter_click();
    private:
    	int activeWindow=0;
    	vector<Gtk::Entry *> entries;
    	vector<Gtk::ComboBoxText *> cboxs;
        void update_display();                    // Update display, robot move
        //Manager _manager;                      // Current manager board
        Gtk::Box *vbox;
        Gtk::Box *displayBox;
        Glib::ustring tstring;
        Glib::ustring dstring;
        Gtk::Label *display;                   // Display
        Gtk::Label *msg;                      // Status message display
        Gtk::ToolButton *button_ap;
        
        Gtk::ToolButton *button_lp;             // Button to list publication
        Gtk::ToolButton *button_cop;             // Button to check out publication
        Gtk::ToolButton *button_cip;             // Button to check in publication
        Gtk::ToolButton *button_apa;             // Button to add patron
        Gtk::ToolButton *button_lpa;  // Button to list patrons
        Gtk::ToolButton *button_e;  // Button to cont prog
};
#endif 

