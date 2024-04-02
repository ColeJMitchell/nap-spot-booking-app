//
// Created by cojmi on 4/2/2024.
//
#include <gtkmm.h>
#include "Button.h"
int main(int argc, char *argv[])
{
    Button button11("Button 11 -- PACK_EXPAND_PADDING");
    Button button12("Button 12 -- PACK_EXPAND_WIDGET");
    Button button13("Button 13 -- EXPAND");

    auto app =
            Gtk::Application::create(argc, argv,
                                     "something.more");

    Gtk::Window window;
    //number of pixels for a full screen
    window.set_default_size(1920, 1080);

    return app->run(window);
}
