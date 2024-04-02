//
// Created by cojmi on 4/2/2024.
//

#ifndef GOLD_BUTTON_H
#define GOLD_BUTTON_H
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <iostream>
class Button : public Gtk::Button
{
public:
    Button();
    Button(Glib::ustring s);
    virtual ~Button();
protected:
//Signal handlers:
    void on_button_clicked();
//Child widgets:
    Glib::ustring button_label;
};

#endif //GOLD_BUTTON_H
