//
// Created by Joe Skap on 4/8/24.
//

#ifndef GTKMMEXMPLESJSKAP_BUTTON_H
#define GTKMMEXMPLESJSKAP_BUTTON_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/stack.h>
#include <gtkmm/stackswitcher.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/entry.h>

class Button : public Gtk::Button
{
public:
    Button();
    Button(Glib::ustring s);
    virtual ~Button();

    void set_main_window(Gtk::Window* window);
    void set_main_stack(Gtk::Stack* stack);

protected:
    // Signal handlers:
    void on_button_clicked();

    // Child widgets:
    Glib::ustring button_label;
    Gtk::Window* main_window;
    Gtk::Stack* main_stack;
    Glib::ustring page_name;
};

#endif //GTKMMEXMPLESJSKAP_BUTTON_H
