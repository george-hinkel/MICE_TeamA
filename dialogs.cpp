#include "dialogs.h"

// A message is like cout, simply displaying information to the user
void Dialogs::message(string msg, string title) {
    Gtk::MessageDialog *dialog = new Gtk::MessageDialog(title);
    dialog->set_secondary_text(msg, true);
    dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete dialog;
}

// A question is a message that allows the user to respond with a button
int Dialogs::question(string msg, string title,
             vector<string> buttons) {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);

    //Gtk::Label *label = new Gtk::Label(msg);
    Gtk::Label *label = new Gtk::Label();
    label->set_markup(msg);
    dialog->get_content_area()->pack_start(*label);
    label->show();

    for(int i=0; i<buttons.size(); ++i) dialog->add_button(buttons[i], i);

    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete label;
    delete dialog;

    return result;
}

// A request for a line of text input
string Dialogs::input(string msg, string title, string default_text, 
             string cancel_text) {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);

    Gtk::Label *label = new Gtk::Label(msg);
    dialog->get_content_area()->pack_start(*label);
    label->show();

    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->set_default_response(1);

    Gtk::Entry *entry = new Gtk::Entry{};
    entry->set_text(default_text);
    entry->set_max_length(50);
    entry->show();
    dialog->get_vbox()->pack_start(*entry);

    int result = dialog->run();
    string text = entry->get_text();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete entry;
    delete label;
    delete dialog;

    if (result == 1)
        return text;
    else
        return cancel_text;
}

// Display an image from a disk file
void Dialogs::image(string filename, string title, string msg) {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);

    Gtk::Label *label = new Gtk::Label(msg);
    dialog->get_content_area()->pack_start(*label);
    label->show();

    dialog->add_button("Close", 0);
    dialog->set_default_response(0);

    Gtk::Image *image = new Gtk::Image{filename};
    image->show();
    dialog->get_vbox()->pack_start(*image);

    int result = dialog->run();

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete image;
    delete label;
    delete dialog;

    return;
}

Item* Dialogs::create_item(){
	int item_type=-1;
	item_type = question("Creating an item...","Decide which kind of item to create!",{"Scoop","Container","Topping"});
	Item* item = (Item*)malloc(sizeof(Item));
	vector<string> output;
	Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Creating a new item...");
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->set_default_response(1);
    
    //name entry
    Gtk::HBox *nameB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*nameB);
    nameB->set_homogeneous();
    nameB->show();
    
    Gtk::Label *nameP = new Gtk::Label("Name:");
    nameB->pack_start(*nameP);
    nameP->show();
    
    Gtk::Entry *nameE = new Gtk::Entry{};
    nameE->set_text("name");
    nameE->set_max_length(50);
    nameE->show();
    nameB->pack_start(*nameE);
    
    //description entry
    Gtk::HBox *descriptionB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*descriptionB);
    descriptionB->set_homogeneous();
    descriptionB->show();
    
    Gtk::Label *descriptionP = new Gtk::Label("Description:");
    descriptionB->pack_start(*descriptionP);
    descriptionP->show();
    
    Gtk::Entry *descriptionE = new Gtk::Entry{};
    descriptionE->set_text("description (max 300 characters)");
    descriptionE->set_max_length(300);
    descriptionE->show();
    descriptionB->pack_start(*descriptionE);
    
    //wholesale cost entry
    Gtk::HBox *wholesale_costB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*wholesale_costB);
    wholesale_costB->set_homogeneous();
    wholesale_costB->show();
    
    Gtk::Label *wholesale_costP = new Gtk::Label("Wholesale Cost:");
    wholesale_costB->pack_start(*wholesale_costP);
    wholesale_costP->show();
    
    Gtk::Entry *wholesale_costE = new Gtk::Entry{};
    wholesale_costE->set_text("00.00");
    wholesale_costE->set_max_length(50);
    wholesale_costE->show();
    wholesale_costB->pack_start(*wholesale_costE);
    
    //retail price entry
    Gtk::HBox *retail_priceB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*retail_priceB);
    retail_priceB->set_homogeneous();
    retail_priceB->show();
    
    Gtk::Label *retail_priceP = new Gtk::Label("Retail Price:");
    retail_priceB->pack_start(*retail_priceP);
    retail_priceP->show();
    
    Gtk::Entry *retail_priceE = new Gtk::Entry{};
    retail_priceE->set_text("00.00");
    retail_priceE->set_max_length(50);
    retail_priceE->show();
    retail_priceB->pack_start(*retail_priceE);
    
    //initial stock entry
    Gtk::HBox *initial_stockB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*initial_stockB);
    initial_stockB->set_homogeneous();
    initial_stockB->show();
    
    Gtk::Label *initial_stockP = new Gtk::Label("Initial Stock:");
    initial_stockB->pack_start(*initial_stockP);
    initial_stockP->show();
    
    Gtk::Entry *initial_stockE = new Gtk::Entry{};
    initial_stockE->set_text("00");
    initial_stockE->set_max_length(50);
    initial_stockE->show();
    initial_stockB->pack_start(*initial_stockE);
    
    //max scoops entry
    Gtk::HBox *max_scoopsB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*max_scoopsB);
    max_scoopsB->set_homogeneous();
    
    Gtk::Label *max_scoopsP = new Gtk::Label("Max Scoops:");
    max_scoopsB->pack_start(*max_scoopsP);
    
    Gtk::Entry *max_scoopsE = new Gtk::Entry{};
    max_scoopsE->set_text("0");
    max_scoopsE->set_max_length(50);
    max_scoopsB->pack_start(*max_scoopsE);
    
    if(item_type==1){
    	max_scoopsB->show();
    	max_scoopsP->show();
    	max_scoopsE->show();
    }
    
    //quantifier entry
    Gtk::HBox *quantifierB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*quantifierB);
    quantifierB->set_homogeneous();
    
    Gtk::Label *quantifierP = new Gtk::Label("Amount Qualifier:");
    quantifierB->pack_start(*quantifierP);
    
    Gtk::ComboBoxText *quantifierC = new Gtk::ComboBoxText();
    quantifierC->append("0","light");
    quantifierC->append("1","normal");
    quantifierC->append("2","extra");
    quantifierC->append("3","drenched");
    quantifierB->pack_start(*quantifierC);
    
    if(item_type==2){    
    	quantifierB->show();
    	quantifierP->show();
    	quantifierC->show();
    }
    
    int result = dialog->run();
    output.push_back(nameE->get_text());
    output.push_back(descriptionE->get_text());
    output.push_back(wholesale_costE->get_text());
    output.push_back(retail_priceE->get_text());
    output.push_back(initial_stockE->get_text());
    if(item_type==1)
    output.push_back(max_scoopsE->get_text());
    if(item_type==2)
    output.push_back(quantifierC->get_active_id());
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete nameP;
    delete nameE;
    delete nameB;
    delete descriptionP;
    delete descriptionE;
    delete descriptionB;
    delete wholesale_costP;
    delete wholesale_costE;
    delete wholesale_costB;
    delete retail_priceP;
    delete retail_priceE;
    delete retail_priceB;
    delete initial_stockP;
    delete initial_stockE;
    delete initial_stockB;
    delete max_scoopsP;
    delete max_scoopsE;
    delete max_scoopsB;
    delete quantifierP;
    delete quantifierC;
    delete quantifierB;
    delete dialog;
	
	switch(item_type){
		case 0: item = new Scoop(output[0],output[1],stod(output[2]),stod(output[3]),stoi(output[4]));
			break;
		case 1: item = new Mice::Container(output[0],output[1],stod(output[2]),stod(output[3]),stoi(output[4]),"",stoi(output[5]));
			break;
		case 2: item = new Topping(output[0],output[1],stod(output[2]),stod(output[3]),stoi(output[4]),"",stoi(output[5]));
			break;
		default: item = new Item("NULL","NULL",0,0,0);
			break;
	}
	
    if (result == 1)
        return item;
    else
        return item;
}
