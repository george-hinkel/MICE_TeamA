#include "main_window.h"
#include "gtkmm.h"
#include <iostream>
int main(int argc,char *argv[]){
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc,argv,"edu.uta.MICE_TeamA");
    Emporium* emporium = new Emporium("mice.dat");
    Login* login = new Login(emporium);
    User* current_user=login->get_current_user();
    delete login;
    if(current_user->get_username()!="NULL"){
    	Main_window win(emporium,current_user);
    	return app->run(win,argc,argv);
    }else{
    	std::cout << current_user->get_name()+"Login Attempt" << std::endl;
    	return 0;
    }
}
