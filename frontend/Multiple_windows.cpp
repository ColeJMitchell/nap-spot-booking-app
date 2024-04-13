//
// Created by cojmi on 4/13/2024.
//

#include "Multiple_windows.h"
#include <gtkmm.h>
#include "Button.h"

Multiple_windows::Multiple_windows() {
    change_to_page1();
}

void Multiple_windows::change_to_page1(){
    set_title("Naps");
    set_border_width(10);
    set_default_size(1920, 1080);
    Gtk::Box hbox1;
    Button b("Favorite Nap Spots");
    hbox1.pack_start(b, Gtk::PACK_EXPAND_PADDING, 5);
    add(hbox1);
    show_all_children();
    /*
     * if(next page)
     * remove all packed buttons
     * call next change_to_page3
     */
}

void Multiple_windows::change_to_page2(){
    set_title("Naps");
    set_border_width(10);
    set_default_size(1920, 1080);
    show_all_children();
    /*
     * if(next page)
     * remove all packed buttons
     * call next change_to_page3
     */
}