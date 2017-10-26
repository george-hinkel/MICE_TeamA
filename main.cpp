#include "main_window.h"
#include "gtkmm.h"

int main(int argc,char *argv[]){
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc,argv,"edu.uta.homework_06_glh");
    Main_window win;
    return app->run(win,argc,argv);
}
