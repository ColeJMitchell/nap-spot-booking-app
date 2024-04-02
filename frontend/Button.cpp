//
// Created by cojmi on 4/2/2024.
//

#include "Button.h"
Button::Button(Glib::ustring s) {
    button_label = s;
// This function will add a label to the button using the passed value.
    add_label(s);
// This connects the button widget (referenced by this) to a pointer of
// the on_button_clicked method.
    signal_clicked().connect(
            sigc::mem_fun(*this, &Button::on_button_clicked) );
}
Button::Button()
{
    button_label = "test Button";
// This function will add a label to the button using a default value.
    add_label(button_label);
// This connects the button widget (referenced by this) to a pointer of
// the on_button_clicked method.
    signal_clicked().connect(
            sigc::mem_fun(*this, &Button::on_button_clicked) );
}
// This is a destructor that does nothing in this case.
Button::~Button() { }
// A method that connected to the button by the command above.
void Button::on_button_clicked()
{
    std::cout << button_label << " was clicked." << std::endl;
}
