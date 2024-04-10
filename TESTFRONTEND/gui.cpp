//
// Created by Joe Skap on 4/8/24.
//
#include <gtkmm.h>
#include "Button.h"

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "hi.more");
    Gtk::Window window;
    window.set_default_size(1920, 1080);

    Gtk::Stack* main_stack = Gtk::manage(new Gtk::Stack());
    Gtk::StackSwitcher* stack_switcher = Gtk::manage(new Gtk::StackSwitcher());
    stack_switcher->set_stack(*main_stack);

    Gtk::Button* button1 = Gtk::manage(new Button("Favorite Nap Spots"));
    Gtk::Button* button2 = Gtk::manage(new Button("Book a Nap Spot"));
    Gtk::Button* button3 = Gtk::manage(new Button("Submit a Location Request"));

    button1->set_main_window(&window);
    button1->set_main_stack(main_stack);
    button2->set_main_window(&window);
    button2->set_main_stack(main_stack);
    button3->set_main_window(&window);
    button3->set_main_stack(main_stack);

    Gtk::Box hbox(Gtk::ORIENTATION_HORIZONTAL);
    hbox.set_spacing(10);
    hbox.pack_start(*button1);
    hbox.pack_start(*button2);
    hbox.pack_end(*button3);

    Gtk::Box vbox(Gtk::ORIENTATION_VERTICAL);
    vbox.pack_start(*stack_switcher, Gtk::PACK_SHRINK);
    vbox.pack_start(*main_stack);

    window.add(vbox);
    window.show_all_children();

    return app->run(window);
}