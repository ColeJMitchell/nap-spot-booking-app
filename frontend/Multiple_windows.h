//
// Created by cojmi on 4/13/2024.
//

#ifndef GOLD_MULTIPLE_WINDOWS_H
#define GOLD_MULTIPLE_WINDOWS_H
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/fixed.h>
#include "Button.h"
class Multiple_windows : public Gtk:: Window{
public:
    Multiple_windows();
    void change_to_page_open();

    void change_to_signuppage();

    void change_to_loginpage();

    void on_sign_up_clicked();

    void on_log_in_clicked();

    void on_back_clicked();

    void on_password_entered();

    void on_username_entered();

    void on_submit();

    void change_to_sign_up();

    void change_to_home_page();

    void on_favorite_clicked();

    void change_to_favorite_page();

    void on_request_clicked();

    void on_book_clicked();

    void change_to_book_page();

    void change_to_request_page();

    void on_submit_login();

    void on_submit_signup();

    void on_back_clicked_home();

    void on_scroll_up_clicked();

    void on_scroll_down_clicked();

    void on_back_clicked_book();

    void on_back_clicked_favorite();

    void on_book_id_entered();

    void on_minutes_entered();

    void on_favorite_id_entered();

    void on_book_nap_spot_clicked();

    void add_nap_spot_frame(std::vector<std::string> s, int i);

    void countdown();

    void on_favorite_clicked_book();

    void on_scroll_up_clicked_favorite();

    void on_scroll_down_clicked_favorite();

    void on_remove_id_entered();

    void on_remove_clicked();

    void on_back_clicked_request();
};


#endif //GOLD_MULTIPLE_WINDOWS_H
