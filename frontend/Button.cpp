//
// Created by cojmi on 4/2/2024.
//

#include "Button.h"
#include "Insert.h"
#include "gtkmm.h"
#include "Multiple_windows.h"

Button::Button(Glib::ustring s) {
    log = false;
    sign_up = false;
    page_num = 0;
    button_label = s;
    set_size_request(250,150);
// This function will add a label to the button using the passed value.
    add_label(s);
// This connects the button widget (referenced by this) to a pointer of
// the on_button_clicked method.
    if(s == "Favorite Nap Spots") {
        signal_clicked().connect(
                sigc::mem_fun(*this, &Button::on_button1_clicked));
    }
    else if(s == "Book a Nap Spot") {
        signal_clicked().connect(
                sigc::mem_fun(*this, &Button::on_button2_clicked));
    }
    else if(s == "Submit a Location Request") {
        signal_clicked().connect(
                sigc::mem_fun(*this, &Button::on_button3_clicked));
    }
}
// This is a destructor that does nothing in this case.
Button::~Button() { }
// A method that connected to the button by the command above.
void Button::on_button1_clicked()
{
    std::cout << "button 1 was clicked"<< std::endl;
}
void Button::on_button2_clicked()
{
    std::cout << "button 2 was clicked"<< std::endl;
}
void Button::on_button3_clicked()
{
    std::cout << "button 3 was clicked"<< std::endl;
}