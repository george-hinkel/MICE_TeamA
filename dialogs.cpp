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

vector<string> Dialogs::input_publication(){
	vector<string> output;
	Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Creating a publication...");
    
    dialog->add_button("Cancel", 0);
    dialog->add_button("OK", 1);
    dialog->set_default_response(1);
    
    //title entry
    Gtk::HBox *titleB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*titleB);
    titleB->set_homogeneous();
    titleB->show();
    
    Gtk::Label *titleP = new Gtk::Label("Title:");
    titleB->pack_start(*titleP);
    titleP->show();
    
    Gtk::Entry *titleE = new Gtk::Entry{};
    titleE->set_text("title");
    titleE->set_max_length(50);
    titleE->show();
    titleB->pack_start(*titleE);
    
    //author entry
    Gtk::HBox *authorB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*authorB);
    authorB->set_homogeneous();
    authorB->show();
    
    Gtk::Label *authorP = new Gtk::Label("Author:");
    authorB->pack_start(*authorP);
    authorP->show();
    
    Gtk::Entry *authorE = new Gtk::Entry{};
    authorE->set_text("author");
    authorE->set_max_length(50);
    authorE->show();
    authorB->pack_start(*authorE);
    
    //copyright entry
    Gtk::HBox *copyrightB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*copyrightB);
    copyrightB->set_homogeneous();
    copyrightB->show();
    
    Gtk::Label *copyrightP = new Gtk::Label("Copyright:");
    copyrightB->pack_start(*copyrightP);
    copyrightP->show();
    
    Gtk::Entry *copyrightE = new Gtk::Entry{};
    copyrightE->set_text("copyright");
    copyrightE->set_max_length(50);
    copyrightE->show();
    copyrightB->pack_start(*copyrightE);
    
    //genre entry
    Gtk::HBox *genreB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*genreB);
    genreB->set_homogeneous();
    genreB->show();
    
    Gtk::Label *genreP = new Gtk::Label("Genre:");
    genreB->pack_start(*genreP);
    genreP->show();
    
    Gtk::ComboBoxText *genreC = new Gtk::ComboBoxText();
    genreC->append("0","Fiction");
    genreC->append("1","Non-Fiction");
    genreC->append("2","Self-Help");
    genreC->append("3","Performance");
    genreC->show();
    genreB->pack_start(*genreC);
    
    //media entry
    Gtk::HBox *mediaB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*mediaB);
    mediaB->set_homogeneous();
    mediaB->show();
    
    Gtk::Label *mediaP = new Gtk::Label("Media:");
    mediaB->pack_start(*mediaP);
    mediaP->show();
    
    Gtk::ComboBoxText *mediaC = new Gtk::ComboBoxText();
    mediaC->append("0","Book");
    mediaC->append("1","Periodical");
    mediaC->append("2","Newspaper");
    mediaC->append("3","Audio");
    mediaC->append("4","Video");
    mediaC->show();
    mediaB->pack_start(*mediaC);
    
    //target_age entry
    Gtk::HBox *target_ageB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*target_ageB);
    target_ageB->set_homogeneous();
    target_ageB->show();
    
    Gtk::Label *target_ageP = new Gtk::Label("Target Age:");
    target_ageB->pack_start(*target_ageP);
    target_ageP->show();
    
    Gtk::ComboBoxText *target_ageC = new Gtk::ComboBoxText();
    target_ageC->append("0","Children");
    target_ageC->append("1","Teen");
    target_ageC->append("2","Adult");
    target_ageC->append("3","Restricted");
    target_ageC->show();
    target_ageB->pack_start(*target_ageC);
    
    //isbn entry
    Gtk::HBox *isbnB = new Gtk::HBox();
    dialog->get_vbox()->pack_start(*isbnB);
    isbnB->set_homogeneous();
    isbnB->show();
    
    Gtk::Label *isbnP = new Gtk::Label("ISBN: ");
    isbnB->pack_start(*isbnP);
    isbnP->show();
    
    Gtk::Entry *isbnE = new Gtk::Entry{};
    isbnE->set_text("isbn");
    isbnE->set_max_length(50);
    isbnE->show();
    isbnB->pack_start(*isbnE);
    
    
    int result = dialog->run();
    output.push_back(titleE->get_text());
    output.push_back(authorE->get_text());
    output.push_back(copyrightE->get_text());
    output.push_back(genreC->get_active_id());
    output.push_back(mediaC->get_active_id());
    output.push_back(target_ageC->get_active_id());
    output.push_back(isbnE->get_text());
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();

    delete titleP;
    delete titleE;
    delete titleB;
    delete authorP;
    delete authorE;
    delete authorB;
    delete copyrightP;
    delete copyrightE;
    delete copyrightB;
    delete genreP;
    delete genreC;
    delete genreB;
    delete mediaP;
    delete mediaC;
    delete mediaB;
    delete target_ageP;
    delete target_ageC;
    delete target_ageB;
    delete isbnP;
    delete isbnE;
    delete isbnB;
    delete dialog;

    if (result == 1)
        return output;
    else
        return output;
}
