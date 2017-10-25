#include "main_window.h"
//#include "manager.h"

Main_window::Main_window(){

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(800, 400);

    // Put a vertical box container as the Window contents
    vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //		F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //				N E W   T E S T   D A T A
    // Append New to the File menu
    Gtk::MenuItem *menuitem_test = Gtk::manage(new Gtk::MenuItem("_Generate Test Data", true));
    menuitem_test->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_gen_test_click));
    filemenu->append(*menuitem_test);
    
    //				N E W   L I B R A R Y
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Library", true));
    menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_new_lib_click));
    filemenu->append(*menuitem_new);

    //				Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    filemenu->append(*menuitem_quit);

	//		P U B L I C A T I O N
	// Create a Publication menu and add to the menu bar
    Gtk::MenuItem *menuitem_publications = Gtk::manage(new Gtk::MenuItem("_Publications", true));
    menubar->append(*menuitem_publications);
    Gtk::Menu *publicationsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_publications->set_submenu(*publicationsmenu);
    
	//				A D D   P U B L I C A T I O N
	// Append add publication to the publications menu
    Gtk::MenuItem *menuitem_ap = Gtk::manage(new Gtk::MenuItem("_Add Publication", true));
    menuitem_ap->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_ap_click));
    publicationsmenu->append(*menuitem_ap);
    
	//				L I S T   P U B L I C A T I O N S
	// Append list publications to the publications menu
    Gtk::MenuItem *menuitem_lp = Gtk::manage(new Gtk::MenuItem("_List Publications", true));
    menuitem_lp->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_lp_click));
    publicationsmenu->append(*menuitem_lp);
    
	//		P A T R O N
	// Create a Patron menu and add to the menu bar
    Gtk::MenuItem *menuitem_patrons = Gtk::manage(new Gtk::MenuItem("_Patrons", true));
    menubar->append(*menuitem_patrons);
    Gtk::Menu *patronsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_patrons->set_submenu(*patronsmenu);
    
	//				A D D   P A T R O N
	// Append add patron to the patrons menu
    Gtk::MenuItem *menuitem_apa = Gtk::manage(new Gtk::MenuItem("_Add Patron", true));
    menuitem_apa->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_apa_click));
    patronsmenu->append(*menuitem_apa);
	
	//				L I S T   P A T R O N S
	// Append list patrons to the patrons menu
    Gtk::MenuItem *menuitem_lpa = Gtk::manage(new Gtk::MenuItem("_List Patrons", true));
    menuitem_lpa->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_lpa_click));
    patronsmenu->append(*menuitem_lpa);
	
    //		H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //				A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_about_click));
    helpmenu->append(*menuitem_about);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //     A D D   P U B L I C A T I O N
    // Add a icon for adding publications
    button_ap = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    button_ap->set_tooltip_markup("Add publication");
    button_ap->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_ap_click));
    toolbar->append(*button_ap);

    //     L I S T   P U B L I C A T I O N S
    // Add a icon for listing publications
    button_lp = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::PRINT));
    button_lp->set_tooltip_markup("List publications");
    button_lp->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_lp_click));
    toolbar->append(*button_lp);

    //TODO     C H E C K   O U T   P U B L I C A T I O N
    // Add a icon for checking out patrons
    button_cop = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::DISCONNECT));
    button_cop->set_tooltip_markup("Check out a publication");
    button_cop->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_cop_click));
    toolbar->append(*button_cop);

    //TODO    C H E C K   I N   P U B L I C A T I O N
    // Add a icon for checking in publications
    button_cip = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::CONNECT));
    button_cip->set_tooltip_markup("Check in a publication");
    button_cip->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_cip_click));
    toolbar->append(*button_cip);

	//TODO    A D D   P A T R O N
    // Add a icon for adding patrons
    button_apa = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
    button_apa->set_tooltip_markup("Add a patron");
    button_apa->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_apa_click));
    toolbar->append(*button_apa);

    //     L I S T   P A T R O N S
    // Add a button to list patrons
    button_lpa = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::DND));
    button_lpa->set_tooltip_markup("List patrons");
    button_lpa->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_lpa_click));
    toolbar->append(*button_lpa);

	//TODO     E N T E R
    // Add a button to advance prog
    button_e = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::APPLY));
    button_e->set_tooltip_markup("Enter");
    button_e->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_enter_click));
    toolbar->append(*button_e);

	//     Q U I T
    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit");
    quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);

    // D I S P L A Y
    // Provide a label to display things
    display = Gtk::manage(new Gtk::Label());
    // display->set_has_frame(false);
    display->set_hexpand(true);
    vbox->add(*display);
    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    msg->set_vexpand(true);
    vbox->add(*msg);
	
	// D I S P L A Y   B O X
	// Provide a display box for entries and comboboxtexts
	displayBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	displayBox->show_all();
    vbox->pack_start(*displayBox);
    // Make the box and everything in it visible
    vbox->show_all();

    
}


Main_window::~Main_window() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Main_window::on_ap_click() {
	delete displayBox;
	activeWindow=1;
	
	displayBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	
	//title entry
	Gtk::HBox *titleB = new Gtk::HBox();
    displayBox->pack_start(*titleB);
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

    entries.push_back(titleE);
    
    //author entry
    Gtk::HBox *authorB = new Gtk::HBox();
    displayBox->pack_start(*authorB);
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
    
    entries.push_back(authorE);
    
    //copyright entry
    Gtk::HBox *copyrightB = new Gtk::HBox();
    displayBox->pack_start(*copyrightB);
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
    
    entries.push_back(copyrightE);
    
    //genre entry
    Gtk::HBox *genreB = new Gtk::HBox();
    displayBox->pack_start(*genreB);
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
    
    cboxs.push_back(genreC);
    
    //media entry
    Gtk::HBox *mediaB = new Gtk::HBox();
    displayBox->pack_start(*mediaB);
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
    
    cboxs.push_back(mediaC);
    
    //target_age entry
    Gtk::HBox *target_ageB = new Gtk::HBox();
    displayBox->pack_start(*target_ageB);
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
    
    cboxs.push_back(target_ageC);
    
    //isbn entry
    Gtk::HBox *isbnB = new Gtk::HBox();
    displayBox->pack_start(*isbnB);
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
    
    entries.push_back(isbnE);
    
    displayBox->show_all();
    vbox->pack_start(*displayBox);
}

void Main_window::on_lp_click() {
	//activeWindow=2;
    tstring = "Listing all publications";
    //dstring=_manager.list_publications();
    update_display();
}

void Main_window::on_cop_click() {
	delete displayBox;
    activeWindow=3;
    
    entries.clear();
    displayBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    
    Gtk::HBox *titleB = new Gtk::HBox();
    displayBox->pack_start(*titleB);
    titleB->set_homogeneous();
    titleB->show();
    
    Gtk::Label *titleP = new Gtk::Label("Enter patron index:");
    titleB->pack_start(*titleP);
    titleP->show();
    
    Gtk::Entry *titleE = new Gtk::Entry{};
    titleE->set_text("0");
    titleE->set_max_length(50);
    titleE->show();
    titleB->pack_start(*titleE);
    
    entries.push_back(titleE);
    
    Gtk::HBox *authorB = new Gtk::HBox();
    displayBox->pack_start(*authorB);
    authorB->set_homogeneous();
    authorB->show();
    
    Gtk::Label *authorP = new Gtk::Label("Enter publication index to check out:");
    authorB->pack_start(*authorP);
    authorP->show();
    
    Gtk::Entry *authorE = new Gtk::Entry{};
    authorE->set_text("0");
    authorE->set_max_length(50);
    authorE->show();
    authorB->pack_start(*authorE);
    
    entries.push_back(authorE);
    
    displayBox->show_all();
    vbox->pack_start(*displayBox);
}

void Main_window::on_cip_click() {
	delete displayBox;
    activeWindow=4;
    
    on_lpa_click();
    
    entries.clear();
    displayBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    
    Gtk::HBox *titleB = new Gtk::HBox();
    displayBox->pack_start(*titleB);
    titleB->set_homogeneous();
    titleB->show();
    
    Gtk::Label *titleP = new Gtk::Label("Enter publication index:");
    titleB->pack_start(*titleP);
    titleP->show();
    
    Gtk::Entry *titleE = new Gtk::Entry{};
    titleE->set_text("0");
    titleE->set_max_length(50);
    titleE->show();
    titleB->pack_start(*titleE);
    
    entries.push_back(titleE);
    
    displayBox->show_all();
    vbox->pack_start(*displayBox);
}

void Main_window::on_apa_click() {
    delete displayBox;
    activeWindow=5;
    
    entries.clear();
    displayBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    
    Gtk::HBox *titleB = new Gtk::HBox();
    displayBox->pack_start(*titleB);
    titleB->set_homogeneous();
    titleB->show();
    
    Gtk::Label *titleP = new Gtk::Label("Enter patron name:");
    titleB->pack_start(*titleP);
    titleP->show();
    
    Gtk::Entry *titleE = new Gtk::Entry{};
    titleE->set_text("John Doe");
    titleE->set_max_length(50);
    titleE->show();
    titleB->pack_start(*titleE);
    
    entries.push_back(titleE);
    
    Gtk::HBox *authorB = new Gtk::HBox();
    displayBox->pack_start(*authorB);
    authorB->set_homogeneous();
    authorB->show();
    
    Gtk::Label *authorP = new Gtk::Label("Enter patron phone:");
    authorB->pack_start(*authorP);
    authorP->show();
    
    Gtk::Entry *authorE = new Gtk::Entry{};
    authorE->set_text("888-888-8888");
    authorE->set_max_length(50);
    authorE->show();
    authorB->pack_start(*authorE);
    
    entries.push_back(authorE);
    
    displayBox->show_all();
    vbox->pack_start(*displayBox);
}

void Main_window::on_lpa_click() {
	//activeWindow=6;
    tstring = "Listing all patrons";
    //dstring=_manager.list_patrons();
    update_display();
}

void Main_window::on_enter_click() {
	vector<string> output;
	int a,b;
    switch(activeWindow){
    	case 0: break;
    	case 1:	
    		output.push_back(entries[0]->get_text());
   			output.push_back(entries[1]->get_text());
    		output.push_back(entries[2]->get_text());
    		output.push_back(cboxs[0]->get_active_id());
    		output.push_back(cboxs[1]->get_active_id());
    		output.push_back(cboxs[2]->get_active_id());
    		output.push_back(entries[3]->get_text());
    		
    		delete displayBox;
    		entries.clear();
    		cboxs.clear();
    		//_manager.create_publication(output);
    		break;
    	case 2: break;
    	case 3:
    		delete displayBox;
    		a=stoi(entries[0]->get_text());
    		b=stoi(entries[1]->get_text());
    		//_manager.check_out_publication(a,b);
    		entries.clear();
    		break;
    	case 4:
    		delete displayBox;
    		a=stoi(entries[0]->get_text());
    		//_manager.check_in_publication(a);
    		entries.clear();
    		break;
    	case 5:
    		delete displayBox;
    		//_manager.add_patron(entries[0]->get_text(),entries[1]->get_text());
    		entries.clear();
    		break;
    }
    activeWindow=0;
}

void Main_window::on_quit_click() {
    hide();
}

void Main_window::on_gen_test_click() {
    //_manager.generate_test_data();
}

void Main_window::on_new_lib_click() {
    //_manager.clear_library();
}

void Main_window::on_about_click() {
    Glib::ustring s = "<span size='24000' weight='bold'>Help</span>\n<span size='large'>Library Management System 2000</span>\n<span>To generate test data click File->New Test Library\n\nTo add a publication, click the add publication button, fill it out, then click the check icon which is the enter button</span>";
    Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dlg.run();
}

// /////////////////
// U T I L I T I E S
// /////////////////

void Main_window::update_display() {
    // s collects the status message
    display->set_markup(tstring);
    msg->set_markup(dstring);
}

