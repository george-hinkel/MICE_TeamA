#ifndef _DIALOGS_H
#define _DIALOGS_H

#include <iostream>
#include <gtkmm.h>
#include "mice.h"
#include "emporium.h"
using namespace std;

class Dialogs {
  public:

    // A message is like cout, simply displaying information to the user
    static void message(string msg, string title = "Info");

    // A question is a message that allows the user to respond with a button
    static int question(string msg, string title,
                 vector<string> buttons,Gtk::Window& parent);

    // A request for a line of text input
    static string input(Gtk::Window& parent,string msg, string title = "Input", string default_text = "", 
                 string cancel_text = "CANCEL");

    // Display an image from a disk file
    static void image(string filename, string title = "Image", string msg = "");
    
    static Item* create_item(Gtk::Window& parent);
    
    static User* create_user(int user_type); 
    	//0=customer;1=server;2=manager
    static User* login(Gtk::Window& parent,Emporium* emporium);
    
    static Item* edit_item(Gtk::Window& parent,Item* item);
};
#endif
