//
// Created by cojmi on 4/2/2024.
//
#include <gtkmm.h>
#include "Button.h"
int main(int argc, char *argv[])
{


    auto app =
            Gtk::Application::create(argc, argv,
                                     "hi.more");

    Gtk::Window window;
    //number of pixels for a full screen
    window.set_default_size(1920, 1080);

    Gtk::Button button1("Favorite Nap Spots");
    Gtk::Button button2("Book a Nap Spot");
    Gtk::Button button3("Submit a Location Request");

    Gtk::Box hbox(Gtk::ORIENTATION_HORIZONTAL);
    hbox.set_spacing(0);
    hbox.pack_start(button1);
    hbox.pack_start(button2);
    hbox.pack_end(button3);

    window.add(hbox);
    window.show_all_children();

    return app->run(window);
}
