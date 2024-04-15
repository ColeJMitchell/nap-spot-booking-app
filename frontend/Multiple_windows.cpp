//
// Created by cojmi on 4/13/2024.
//

#include "Multiple_windows.h"
#include <gtkmm.h>
#include "Button.h"
#include "Insert.h"
Gtk::Fixed *fix;
Button* b;
Button* b2;
Button* b3;
Gtk::Entry *e;
Gtk::Entry *e2;
std::string username;
std::string password;
Gtk::Label *l;
Gtk::Label *l2;
//starts the gui and immediately sets page1
Multiple_windows::Multiple_windows() {
    change_to_page1();
}
//displays first page which has two buttons which can take you either to sign up or log in
void Multiple_windows::change_to_page1(){
    set_title("Naps");
    override_background_color(Gdk::RGBA("dark green"));
    set_border_width(10);
    set_default_size(1920, 1080);

    // Allocate memory for the Gtk::Box and Gtk::Button dynamically
    fix = Gtk::manage(new Gtk::Fixed);;
    b = new Button("Sign Up",250,150);
    b2 = new Button("Log In",250,150);
    b->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_sign_up_clicked));
    fix->put(*b,1920/2-550,1080/2-120);
    fix->put(*b2,1920/2+250,1080/2-120);

    add(*fix);
    // Show all widgets
    show_all_children();
}

//second page which has entry boxes for signing up for the first time
void Multiple_windows::change_to_sign_up(){
    override_background_color(Gdk::RGBA("light blue"));
    e = Gtk::manage(new Gtk::Entry);
    e2 = Gtk::manage(new Gtk::Entry);
    l = Gtk::manage(new Gtk::Label);
    l->set_label("Password");
    l2 = Gtk::manage(new Gtk::Label);
    l2->set_label("Username");
    b3 = new Button("Submit",170,100);
    fix->put(*l,1920/2-110,1080/2+60);
    fix->put(*l2,1920/2-110,1080/2-80);
    fix ->put(*e,1920/2-120,1080/2+20);
    fix ->put(*e2,1920/2-120,1080/2-120);
    fix->put(*b3, 1920/2-120,1080/2+200);
    e->signal_activate().connect(sigc::mem_fun(*this, &Multiple_windows::on_password_entered));
    e2->signal_activate().connect(sigc::mem_fun(*this, &Multiple_windows::on_username_entered));
    b3->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_submit));
    show_all_children();

}

//checks if sign up button is clicked and switches page if it is
void Multiple_windows::on_sign_up_clicked() {
    // Change to page 2
    fix->remove(*b);
    fix->remove(*b2);
    change_to_sign_up();
}

//callback for password input in entry widget
void Multiple_windows::on_password_entered(){
    password = e->get_text();
    std::cout<<password;
}
void Multiple_windows::on_username_entered(){
    username = e2->get_text();
    std::cout<<username;
}

void Multiple_windows::on_submit(){
    Insert i;
    i.insert_user(username,password);
    fix->remove(*e);
    fix->remove(*e2);
    fix->remove(*l);
    fix->remove(*l2);
    fix->remove(*b3);
}