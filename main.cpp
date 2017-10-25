#include <iostream>
#include "order.h"
#include <string>
#include "serving.h"
#include "scoop.h"
#include "container.h"
#include "topping.h"
#include "login.h"
#include "main_window.h"
#include "gtkmm.h"

<<<<<<< HEAD
<<<<<<< HEAD
int main()
{
/*  std::cout << "This works now" << std::endl;
  std::string testing = "Container works";
  container newOne;
  newOne.addContainer();
  scoop scoop;
  container container;
  scoop.addFlavor();
  scoop.setPrice();
  std::cout << "$" << scoop.getPrice() << std::endl;
*/  Login login;
  login.verify();
=======
int main(){
=======
int main(int argc,char *argv[]){
    /*
>>>>>>> 67ff7da3c729250d9584f99ee07cf0afef6d2f54
    Container container("Waffle Cone","Delicious freshly made waffle cone",0.25,0.9,10);
    Scoop scoop("Vanilla","Delicious homemade vanilla ice cream scoop",0.8,1.5,10);
    Topping topping("Chocolate Syrup","Rich 100% milk chocolate syrup",0.1,0.25,10);
    std::cout << container.to_string() << std::endl;
    std::cout << scoop.to_string() << std::endl;
    std::cout << topping.to_string() << std::endl;
    Login login;
    login.verify();
<<<<<<< HEAD
    return 0;
>>>>>>> b9c52d021dc5835ff2d8e89ca9c88bb79dcf2d10
=======
     */
    
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc,argv,"edu.uta.homework_06_glh");
    Main_window win;
    return app->run(win,argc,argv);
>>>>>>> 67ff7da3c729250d9584f99ee07cf0afef6d2f54
}
