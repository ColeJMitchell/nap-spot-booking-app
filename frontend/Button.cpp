//
// Created by cojmi on 4/2/2024.
//

#include "Button.h"
#include "Insert.h"
#include "gtkmm.h"
#include "Multiple_windows.h"

Button::Button(Glib::ustring s, int x, int y) {
    log = false;
    sign_up = false;
    page_num = 0;
    button_label = s;
    set_size_request(x,y);
// This function will add a label to the button using the passed value.
    add_label(s);
// This connects the button widget (referenced by this) to a pointer of
// the on_button_clicked method.
}
// This is a destructor that does nothing in this case.
Button::~Button() { };
