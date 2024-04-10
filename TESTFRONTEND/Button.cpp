//
// Created by Joe Skap on 4/8/24.
//

#include "Button.h"

Button::Button(Glib::ustring s)
{
    button_label = s;
    page_name = s;
    add_label(s);
    signal_clicked().connect(sigc::mem_fun(*this, &Button::on_button_clicked));
}

Button::Button()
{
    button_label = "test Button";
    page_name = button_label;
    add_label(button_label);
    signal_clicked().connect(sigc::mem_fun(*this, &Button::on_button_clicked));
}

Button::~Button()
{
}

void Button::set_main_window(Gtk::Window* window)
{
    main_window = window;
}

void Button::set_main_stack(Gtk::Stack* stack)
{
    main_stack = stack;
}

void Button::on_button_clicked()
{
    if (main_stack)
    {
        main_stack->set_visible_child(page_name);
    }
}

