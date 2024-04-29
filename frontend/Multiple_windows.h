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
    //change page to opening page (login/signup)
    void change_to_page_open();
    //change page to sign up page
    void change_to_signuppage();
    //change page to login page
    void change_to_loginpage();
    //checks if signup button is clicked
    void on_sign_up_clicked();
    //checks if login button is clicked
    void on_log_in_clicked();
    //checks if back button is clicked
    void on_back_clicked();
    //checks if password is entered
    void on_password_entered();
    //checks if username is entered
    void on_username_entered();
    //if submit button is clicked
    void on_submit();
    //changes to signup page
    void change_to_sign_up();
    //changes to home page
    void change_to_home_page();
    //checks if favorites list page button is clicked
    void on_favorite_clicked();
    //change page to favorites list page
    void change_to_favorite_page();
    //checks if request nap spot page button is clicked
    void on_request_clicked();
    //checks if book nap spot page button is clicked
    void on_book_clicked();
    //change page to booking page
    void change_to_book_page();
    //change page to request spot page
    void change_to_request_page();
    //checks if submit login button is clicked in login page
    void on_submit_login();
    //checks if submit signup button is clicked in signup page
    void on_submit_signup();
    //checks if back button is clicked in home page
    void on_back_clicked_home();
    //checks if scroll up button is clicked in booking page
    void on_scroll_up_clicked();
    //checks if scroll down button is clicked in booking page
    void on_scroll_down_clicked();
    //checks if back button is clicked in booking page
    void on_back_clicked_book();
    //checks if back button is clicked in favorites page
    void on_back_clicked_favorite();
    //checks if nap spot id is entered in booking page
    void on_book_id_entered();
    //checks if minutes reserved is entered in booking page
    void on_minutes_entered();
    //checks if favorite id is entered in booking page
    void on_favorite_id_entered();
    //checks if book nap spot page button is clicked
    void on_book_nap_spot_clicked();
    //nap spot frame
    void add_nap_spot_frame(std::vector<std::string> s, int i);
    //nap spot reservation countdown method
    void countdown();
    //checks if favorite nap spot is clicked in booking page
    void on_favorite_clicked_book();
    //checks if scroll up button is clicked in favorites page
    void on_scroll_up_clicked_favorite();
    //checks if scroll down button is clicked in favorites page
    void on_scroll_down_clicked_favorite();
    //when nap spot id is entered to be removed in favorites list
    void on_remove_id_entered();
    //checks if remove button is clicked on favorites list
    void on_remove_clicked();
    //checks if back button is clicked in request page
    void on_back_clicked_request();
    //checks name entered in nap spot request
    void on_name_entered();
    //checks attribute 1 entered in nap spot request
    void on_attribute1_entered();
    //checks attribute 2 entered in nap spot request
    void on_attribute2_entered();
    //checks attribute 3 entered in nap spot request
    void on_attribute3_entered();
    //checks photo entered in nap spot request
    void on_photo_entered();
    //checks if approve nap spot button is clicked by admin
    void on_approve_id_entered();
    //checks if deny nap spot button is clicked by admin
    void on_deny_id_entered();
    //checks if submit nap spot page button is clicked in request page
    void on_submit_nap_spot();
    //checks if back button is clicked in request page by admin
    void on_back_clicked_request_admin();
    //checks if scroll up button is clicked in request page
    void on_scroll_up_clicked_request();
    //checks if scroll down button is clicked in request page
    void on_scroll_down_clicked_request();
    //checks if a nap spot is approved by an admin
    void on_approval();
    //checks if a nap spot is denied by an admin
    void on_denial();
    //reloads the request page for admin to view requested spots
    void reload_request_page();
};


#endif //GOLD_MULTIPLE_WINDOWS_H
