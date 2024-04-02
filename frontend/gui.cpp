//
// Created by cojmi on 4/2/2024.
//
#include <gtkmm.h>
int main(int argc, char *argv[])
{
    auto app =
            Gtk::Application::create(argc, argv,
                                     "something.more");

    Gtk::Window window;
    //number of pixels for a full screen
    window.set_default_size(1920, 1080);

    return app->run(window);
}
