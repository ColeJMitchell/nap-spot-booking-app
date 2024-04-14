//
// Created by cojmi on 4/13/2024.
//

#include "Multiple_windows.h"
#include <gtkmm.h>
#include "Button.h"
Gtk::Fixed *fix;
Button* b;
Button* b2;
Multiple_windows::Multiple_windows() {
    change_to_page1();
}
void Multiple_windows::change_to_page1(){
    set_title("Naps");
    override_background_color(Gdk::RGBA("dark green"));
    set_border_width(10);
    set_default_size(1920, 1080);

    // Allocate memory for the Gtk::Box and Gtk::Button dynamically
    fix = Gtk::manage(new Gtk::Fixed);;
    b = new Button("Sign Up");
    b2 = new Button("Log In");
    b->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_sign_up_clicked));
    fix->put(*b,1920/2-550,1080/2-120);
    fix->put(*b2,1920/2+250,1080/2-120);

    add(*fix);
    // Show all widgets
    show_all_children();
}

void Multiple_windows::change_to_page2(){
    override_background_color(Gdk::RGBA("light blue"));
    Gtk::Entry *e = Gtk::manage(new Gtk::Entry);;
    fix ->put(*e,1920/2-100,1080/2-100);
    add(*fix);
    show_all_children();

}
void Multiple_windows::on_sign_up_clicked() {
    // Change to page 2
    change_to_page2();
    fix->remove(*b);
    fix->remove(*b2);
}
