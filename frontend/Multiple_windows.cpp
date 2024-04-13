//
// Created by cojmi on 4/13/2024.
//

#include "Multiple_windows.h"
#include <gtkmm.h>

Multiple_windows::Multiple_windows() {
    set_title("Naps");
    set_border_width(10);
    set_default_size(400, 200);
    show_all_children();
}