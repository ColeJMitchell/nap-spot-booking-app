//
// Created by cojmi on 4/2/2024.
//
#include <gtkmm.h>
#include "Button.h"
#include "Multiple_windows.h"
int main(int argc, char *argv[])
{
    auto app =
            Gtk::Application::create(argc, argv,
                                     "hi.more");

    Multiple_windows window;
    return app->run(window);
}
