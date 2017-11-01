#include "main_window.h"
#include "gtkmm.h"

int main(int argc,char *argv[]){
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc,argv,"edu.uta.MICE_TeamA");
    Data_library* data_library=(Data_library*)malloc(sizeof(Data_library));
    data_library = new Data_library("");
    Main_window win(data_library);
    return app->run(win,argc,argv);
}
