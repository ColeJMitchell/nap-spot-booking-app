//
// Created by cojmi on 4/13/2024.
//

#include "Multiple_windows.h"
#include <gtkmm.h>
#include "Button.h"
#include "Insert.h"
#include "Select.h"
Gtk::Fixed *fix;
//signup & login
Button* b;
Button* b2;
//submit
Button* b3;
Button* b4;
//main menu buttons
Button* b5;
Button* b6;
Button* b7;
//entries for username and password
Gtk::Entry *e;
Gtk::Entry *e2;
std::string username;
std::string password;
//login/signup labels
Gtk::Label *l;
Gtk::Label *l2;
std::vector<Gtk::Frame> *f;
//starts the gui and immediately sets page1
Multiple_windows::Multiple_windows() {
    fix = Gtk::manage(new Gtk::Fixed);
    add(*fix);
    change_to_pageopen();
}
//displays first page which has two buttons which can take you either to sign up or log in
void Multiple_windows::change_to_pageopen(){
    set_title("Naps");
    override_background_color(Gdk::RGBA("dark green"));
    set_border_width(10);
    set_default_size(1920, 1080);

    // Allocate memory for the Gtk::Box and Gtk::Button dynamically
    ;
    b = new Button("Sign Up",250,150);
    b2 = new Button("Log In",250,150);
    b->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_sign_up_clicked));
    b2->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_log_in_clicked));
    fix->put(*b,1920/2-550,1080/2-120);
    fix->put(*b2,1920/2+250,1080/2-120);

    // Show all widgets
    show_all_children();
}


//second page which has entry boxes for signing up for the first time
void Multiple_windows::change_to_signuppage(){
    override_background_color(Gdk::RGBA("light blue"));
    e = Gtk::manage(new Gtk::Entry);
    e2 = Gtk::manage(new Gtk::Entry);
    l = Gtk::manage(new Gtk::Label);
    l->set_label("Password");
    l2 = Gtk::manage(new Gtk::Label);
    l2->set_label("Username");
    b3 = new Button("Submit",170,100);
    b4 = new Button("Back",170,100);
    fix->put(*l,1920/2-110,1080/2+60);
    fix->put(*l2,1920/2-110,1080/2-80);
    fix ->put(*e,1920/2-120,1080/2+20);
    fix ->put(*e2,1920/2-120,1080/2-120);
    fix->put(*b3, 1920/2-400,1080/2+200);
    fix->put(*b4, 1920/2+160,1080/2+200);
    e->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_password_entered));
    e2->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_username_entered));
    b3->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_submit_signup));
    b4->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_back_clicked));
    show_all_children();

}
void Multiple_windows::change_to_loginpage(){
    override_background_color(Gdk::RGBA("orange"));
    e = Gtk::manage(new Gtk::Entry);
    e2 = Gtk::manage(new Gtk::Entry);
    l = Gtk::manage(new Gtk::Label);
    l->set_label("Password");
    l2 = Gtk::manage(new Gtk::Label);
    l2->set_label("Username");
    b3 = new Button("Submit",170,100);
    b4 = new Button("Back",170,100);
    fix->put(*l,1920/2-110,1080/2+60);
    fix->put(*l2,1920/2-110,1080/2-80);
    fix ->put(*e,1920/2-120,1080/2+20);
    fix ->put(*e2,1920/2-120,1080/2-120);
    fix->put(*b3, 1920/2-400,1080/2+200);
    fix->put(*b4, 1920/2+160,1080/2+200);
    e->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_password_entered));
    e2->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_username_entered));
    b3->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_submit_login));
    b4->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_back_clicked));
    show_all_children();
}

void Multiple_windows::change_to_home_page(){
    override_background_color(Gdk::RGBA("salmon"));
    b4 = new Button("Back to Login",170,100);
    b5 = new Button("Favorite Nap Spots",250,150);
    b6 = new Button("Book a Nap Spot",250,150);
    b7 = new Button("Submit a Location Request",250,150);
    fix->put(*b5,240,400);
    fix->put(*b6,820,400);
    fix->put(*b4,859, 800);
    fix ->put(*b7,1420,400);
    b4->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_back_clicked_home));
    b5->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_favorite_clicked));
    b6->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_book_clicked));
    b7->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_request_clicked));
    show_all_children();
}

void Multiple_windows::change_to_favorite_page(){
    override_background_color(Gdk::RGBA("white"));
    show_all_children();
}

void Multiple_windows::change_to_book_page(){
    override_background_color(Gdk::RGBA("white"));
    set_border_width(10);
    set_default_size(1920, 1080);
    l = Gtk::manage(new Gtk::Label);
    l->set_markup("<span size = '30000'><b>Available Nap Spots</b></span>");
    fix->put(*l,720,20);
    Gtk::Frame *frame = Gtk::manage(new Gtk::Frame);
    frame->set_size_request(200, 150);

    Gtk::Box* vertical_box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));

    Gtk::Label* label1 = Gtk::manage(new Gtk::Label("Attribute 1"));
    Gtk::Label* label2 = Gtk::manage(new Gtk::Label("Attribute 2"));
    Gtk::Label* label3 = Gtk::manage(new Gtk::Label("Attribute 2"));
    vertical_box->pack_start(*label1);
    vertical_box->pack_start(*label2);
    vertical_box->pack_start(*label3);
    frame->add(*vertical_box);
    fix->put(*frame, 100, 100);
    show_all_children();
}

void Multiple_windows::change_to_request_page(){
    override_background_color(Gdk::RGBA("white"));
    show_all_children();
}




void Multiple_windows::on_request_clicked(){
    fix->remove(*b5);
    fix->remove(*b6);
    fix->remove(*b7);
    change_to_request_page();
}



//callback for password input in entry widget
void Multiple_windows::on_password_entered(){
    password = e->get_text();
}

void Multiple_windows::on_username_entered(){
    username = e2->get_text();
}

void Multiple_windows::on_submit_login(){
    Select s;
    if(s.determine_if_user_exists("user_information",username, password)!=-1) {
        fix->remove(*e);
        fix->remove(*e2);
        fix->remove(*l);
        fix->remove(*l2);
        fix->remove(*b3);
        fix->remove(*b4);
        password = "";
        username = "";
        change_to_home_page();
    }
}

void Multiple_windows::on_submit_signup(){
    Insert i;
    Select s;
    if(s.determine_if_user_exists("user_information",username, password)==-1) {
        int count = s.get_row_count("user_information");
        i.insert_user(count,username,password,0);
        fix->remove(*e);
        fix->remove(*e2);
        fix->remove(*l);
        fix->remove(*l2);
        fix->remove(*b3);
        fix->remove(*b4);
        password = "";
        username = "";
        change_to_home_page();
    }
}


void Multiple_windows::on_favorite_clicked(){
    fix->remove(*b4);
    fix->remove(*b5);
    fix->remove(*b6);
    fix->remove(*b7);
    change_to_favorite_page();
}

void Multiple_windows::on_book_clicked(){
    fix->remove(*b4);
    fix->remove(*b5);
    fix->remove(*b6);
    fix->remove(*b7);
    change_to_book_page();
}

//checks if sign up button is clicked and switches page if it is
void Multiple_windows::on_sign_up_clicked() {
    // Change to page 2
    fix->remove(*b);
    fix->remove(*b2);
    change_to_signuppage();
}

void Multiple_windows::on_log_in_clicked() {
    // Change to page 2
    fix->remove(*b);
    fix->remove(*b2);
    change_to_loginpage();
}

void Multiple_windows::on_back_clicked() {
    fix->remove(*e);
    fix->remove(*e2);
    fix->remove(*l);
    fix->remove(*l2);
    fix->remove(*b3);
    fix->remove(*b4);
    change_to_pageopen();
}

void Multiple_windows::on_back_clicked_home(){
    fix->remove(*b4);
    fix->remove(*b5);
    fix->remove(*b6);
    fix->remove(*b7);
    change_to_loginpage();
}