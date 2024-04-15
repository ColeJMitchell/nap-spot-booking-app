//
// Created by cojmi on 4/13/2024.
//

#include "Multiple_windows.h"
#include <gtkmm.h>
#include "Button.h"
Gtk::Fixed *fix;
Button* b;
Button* b2;
Gtk::Entry *e;
Gtk::Entry *e2;
//starts the gui and immediately sets page1
Multiple_windows::Multiple_windows() {
    change_to_pageopen();
}
//displays first page which has two buttons which can take you either to sign up or log in
void Multiple_windows::change_to_pageopen(){
    set_title("Naps");
    override_background_color(Gdk::RGBA("dark green"));
    set_border_width(10);
    set_default_size(1920, 1080);

    // Allocate memory for the Gtk::Box and Gtk::Button dynamically
    fix = Gtk::manage(new Gtk::Fixed);;
    b = new Button("Sign Up");
    b2 = new Button("Log In");
    b->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_sign_up_clicked));
    b2->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_log_in_clicked));
    fix->put(*b,1920/2-550,1080/2-120);
    fix->put(*b2,1920/2+250,1080/2-120);

    add(*fix);
    // Show all widgets
    show_all_children();
}

//second page which has entry boxes for signing up for the first time
void Multiple_windows::change_to_signuppage(){
    override_background_color(Gdk::RGBA("light blue"));
    e = Gtk::manage(new Gtk::Entry);
    Gtk::Label *l = Gtk::manage(new Gtk::Label);
    l->set_label("Password");
    fix->put(*l,1920/2-90,1080/2-140);
    fix ->put(*e,1920/2-100,1080/2-100);
    e->signal_activate().connect(sigc::mem_fun(*this, &Multiple_windows::on_password_entered));
    add(*fix);
    show_all_children();
}

void Multiple_windows::change_to_loginpage(){
    override_background_color(Gdk::RGBA("light blue"));
    e = Gtk::manage(new Gtk::Entry);
    e2 = Gtk::manage(new Gtk::Entry);
    Gtk::Label *l = Gtk::manage(new Gtk::Label);
    Gtk::Label *l2 = Gtk::manage(new Gtk::Label);
    l->set_label("Password");
    l2->set_label("Username");
    fix->put(*l,1920/2-90,1080/2-140);
    fix->put(*l2,1920/2-90,1080/2-240);
    fix ->put(*e,1920/2-100,1080/2-100);
    fix ->put(*e2,1920/2-100,1080/2-200);
    e->signal_activate().connect(sigc::mem_fun(*this, &Multiple_windows::on_password_entered));
    e2->signal_activate().connect(sigc::mem_fun(*this, &Multiple_windows::on_username_entered));
    add(*fix);
    show_all_children();
}
//checks if sign up button is clicked and switches page if it is
void Multiple_windows::on_sign_up_clicked() {
    // Change to page 2
    change_to_signuppage();
    fix->remove(*b);
    fix->remove(*b2);
}

void Multiple_windows::on_log_in_clicked() {
    // Change to page 2
    change_to_loginpage();
    fix->remove(*b);
    fix->remove(*b2);
}

//callback for password input in entry widget
void Multiple_windows::on_password_entered(){
    std::cout << e->get_text() << std::endl;
}

void Multiple_windows::on_username_entered(){
    std::cout << e2->get_text() << std::endl;
}

