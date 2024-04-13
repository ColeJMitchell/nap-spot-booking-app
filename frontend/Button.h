//
// Created by cojmi on 4/2/2024.
//

#ifndef GOLD_BUTTON_H
#define GOLD_BUTTON_H
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <iostream>
#include "Multiple_windows.h"
class Button : public Gtk::Button
{
public:
    Button();
    Button(Glib::ustring s);
    virtual ~Button();
    int page_num;
protected:
//Signal handlers:
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
//Child widgets:
    Glib::ustring button_label;

};

#endif //GOLD_BUTTON_H
