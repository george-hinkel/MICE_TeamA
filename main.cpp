#include "main_window.h"
#include "gtkmm.h"

int main(int argc,char *argv[]){
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc,argv,"edu.uta.MICE_TeamA");
    Emporium* emporium=(Emporium*)malloc(sizeof(Emporium));
    emporium = new Emporium("");
    Main_window win(emporium);
    return app->run(win,argc,argv);
}
