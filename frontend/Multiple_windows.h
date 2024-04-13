//
// Created by cojmi on 4/13/2024.
//

#ifndef GOLD_MULTIPLE_WINDOWS_H
#define GOLD_MULTIPLE_WINDOWS_H
#include <gtkmm/window.h>
#include <gtkmm/button.h>
class Multiple_windows : public Gtk:: Window{
public:
    Multiple_windows();
    void change_to_page1();

    void change_to_page2();
};


#endif //GOLD_MULTIPLE_WINDOWS_H
