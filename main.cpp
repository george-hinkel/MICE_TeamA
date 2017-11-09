#include "main_window.h"
#include "gtkmm.h"

int main(int argc,char *argv[]){
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc,argv,"edu.uta.MICE_TeamA");
    Emporium* emporium=(Emporium*)malloc(sizeof(Emporium));
    emporium = new Emporium("mice.dat");
    User* user = new Customer("JoeSchmo","passw0rd","Joe Schmo","555-666-0101");
    Main_window win(emporium,user);
    return app->run(win,argc,argv);
}
