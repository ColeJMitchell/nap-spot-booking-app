//
// Created by cojmi on 4/13/2024.
//

#include "Multiple_windows.h"
#include <gtkmm.h>
#include <thread>
#include "Button.h"
#include "Insert.h"
#include "Select.h"
#include "Update.h"
Gtk::Fixed *fix;
//signup & login
Button* b;
Button* b2;
//submit
Button* b3;
Button* b4;
//main menu buttons
Button* b5;
Button* b6;
Button* b7;
//entries for username and password
Gtk::Entry *e;
Gtk::Entry *e2;
Gtk::Entry *e3;
Gtk::Entry *e4;
Gtk::Entry *e5;
std::string username;
std::string password;
std::string nap_spot_name;
std::string attribute1;
std::string attribute2;
std::string attribute3;
std::string photo;
int book_id;
int num_minutes;
int favorite_id;
int num_nap_spots;
int current_user;
int remove_id;
int approve_id;
int deny_id;
//login/signup labels
Gtk::Label *l;
Gtk::Label *l2;
Gtk::Label *l3;
Gtk::Label *l4;
Gtk::Label *l5;
Gtk::Label *l6;
Gtk::Label *l7;
bool is_book_page;
bool is_favorite_page;
bool reserved;
std::vector<Gtk::Frame*> *f;
std::vector<Gtk::Frame*> *f2;
std::vector<Gtk::Frame*> *f3;
std::vector<std::vector<int>> * favorite_ids;
int offset = 0;
int offset_favorite = 0;
int offset_request = 0;
int offset2_request = 0;
//starts the gui and immediately sets page1
Multiple_windows::Multiple_windows() {
    Select s;
    Update u;
    fix = Gtk::manage(new Gtk::Fixed);
    f = new std::vector<Gtk::Frame*>();
    f2 = new std::vector<Gtk::Frame*>();
    f3 = new std::vector<Gtk::Frame*>();
    add(*fix);
    reserved = false;
    for(int i = 0; i < s.get_row_count("nap_spots"); i++){
        u.update_reservation(i, "Open");
    }
    change_to_page_open();
}
//displays first page which has two buttons which can take you either to sign up or log in
void Multiple_windows::change_to_page_open(){
    set_title("Naps");
    override_background_color(Gdk::RGBA("dark green"));
    set_border_width(10);
    set_default_size(1920, 1080);

    // Allocate memory for the Gtk::Box and Gtk::Button dynamically
    ;
    b = new Button("Sign Up",250,150);
    b2 = new Button("Log In",250,150);
    b->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_sign_up_clicked));
    b2->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_log_in_clicked));
    fix->put(*b,1920/2-550,1080/2-120);
    fix->put(*b2,1920/2+250,1080/2-120);

    // Show all widgets
    show_all_children();
}


//second page which has entry boxes for signing up for the first time
void Multiple_windows::change_to_signuppage(){
    override_background_color(Gdk::RGBA("light blue"));
    e = Gtk::manage(new Gtk::Entry);
    e2 = Gtk::manage(new Gtk::Entry);
    e->set_visibility(false);
    l = Gtk::manage(new Gtk::Label);
    l->set_label("Password");
    l2 = Gtk::manage(new Gtk::Label);
    l2->set_label("Username");
    b3 = new Button("Submit",170,100);
    b4 = new Button("Back",170,100);
    fix->put(*l,1920/2-110,1080/2+60);
    fix->put(*l2,1920/2-110,1080/2-80);
    fix ->put(*e,1920/2-120,1080/2+20);
    fix ->put(*e2,1920/2-120,1080/2-120);
    fix->put(*b3, 1920/2-400,1080/2+200);
    fix->put(*b4, 1920/2+160,1080/2+200);
    e->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_password_entered));
    e2->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_username_entered));
    b3->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_submit_signup));
    b4->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_back_clicked));
    show_all_children();
}

void Multiple_windows::change_to_loginpage(){
    override_background_color(Gdk::RGBA("orange"));
    e = Gtk::manage(new Gtk::Entry);
    e2 = Gtk::manage(new Gtk::Entry);
    e->set_visibility(false);
    l = Gtk::manage(new Gtk::Label);
    l->set_label("Password");
    l2 = Gtk::manage(new Gtk::Label);
    l2->set_label("Username");
    b3 = new Button("Submit",170,100);
    b4 = new Button("Back",170,100);
    fix->put(*l,1920/2-110,1080/2+60);
    fix->put(*l2,1920/2-110,1080/2-80);
    fix ->put(*e,1920/2-120,1080/2+20);
    fix ->put(*e2,1920/2-120,1080/2-120);
    fix->put(*b3, 1920/2-400,1080/2+200);
    fix->put(*b4, 1920/2+160,1080/2+200);
    e->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_password_entered));
    e2->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_username_entered));
    b3->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_submit_login));
    b4->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_back_clicked));
    show_all_children();
}

void Multiple_windows::change_to_home_page(){
    override_background_color(Gdk::RGBA("salmon"));
    b4 = new Button("Back to Login",170,100);
    b5 = new Button("Favorite Nap Spots",250,150);
    b6 = new Button("Book a Nap Spot",250,150);
    b7 = new Button("Submit a Location Request",250,150);
    fix->put(*b5,240,400);
    fix->put(*b6,820,400);
    fix->put(*b4,859, 800);
    fix ->put(*b7,1420,400);
    b4->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_back_clicked_home));
    b5->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_favorite_clicked));
    b6->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_book_clicked));
    b7->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_request_clicked));
    show_all_children();
}

void Multiple_windows::change_to_favorite_page(){
    is_favorite_page = true;
    Select s;
    override_background_color(Gdk::RGBA("white"));
    l6 = Gtk::manage(new Gtk::Label);
    b = new Button("Scroll up",170,100);
    b2 = new Button("Scroll down",170,100);
    b3 = new Button("Back to Home Page",170,100);
    b4 = new Button("Book",170,100);
    b5 = new Button("Remove",170,100);
    l6->set_markup("<span size = '30000'><b>Your Favorite Nap Spots</b></span>");
    l3 = Gtk::manage(new Gtk::Label);
    l4 = Gtk::manage(new Gtk::Label);
    e = Gtk::manage(new Gtk::Entry);
    e2 = Gtk::manage(new Gtk::Entry);
    e3 = Gtk::manage(new Gtk::Entry);
    l3->set_markup("<span size = '14000'><b>Enter the ID of the Nap Spot You Wish to Book:</b></span>");
    l4->set_markup("<span size = '14000'><b>Enter Number of Minutes:</b></span>");
    l5 = Gtk::manage(new Gtk::Label);
    l5->set_markup("<span size = '14000'><b>Enter the ID of the Nap Spot You Wish to Remove:</b></span>");
    fix->put(*l6,690,20);
    fix->put(*b , 200,350);
    fix->put(*b2, 200, 450);
    fix->put(*b3, 200, 150);
    fix->put(*l3 ,1350,160);
    fix->put(*l4 ,1350,260);
    fix->put(*e ,1350,200);
    fix->put(*e2 ,1350,300);
    fix->put(*b4 ,1350,370);
    fix->put(*b5 ,1350,640);
    fix->put(*l5 ,1350,530);
    fix->put(*e3 ,1350,570);
    std::vector<std::string> s3 = s.get_one_row_id_user("user_information",current_user);
    for(int i=4; i<9; i++){
        try{
            if(std::stoi(s3[i])!=-1){
                std::vector<std::string> s2 = s.get_one_row_id("nap_spots",std::stoi(s3[i]));
                add_nap_spot_frame(s2, 1);
            }
            else{
                continue;
            }
        }
        catch(const std::exception& e){

        }
    }
    for(Gtk::Frame *f3 : *f2){
        fix->put(*f3, 680,150+offset_favorite);
        offset_favorite+=600;
    }
    b->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_scroll_up_clicked_favorite));
    b2->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_scroll_down_clicked_favorite));
    b3->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_back_clicked_favorite));
    e->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_book_id_entered));
    e2->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_minutes_entered));
    e3->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_remove_id_entered));
    b4->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_book_nap_spot_clicked));
    b5->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_remove_clicked));
    show_all_children();
}

int offset2_favorite = 0;
void Multiple_windows::on_back_clicked_favorite(){
    fix->remove(*l6);
    fix->remove(*l5);
    fix->remove(*b);
    fix->remove(*b2);
    fix->remove(*b3);
    fix->remove(*b4);
    fix->remove(*b5);
    fix->remove(*l3);
    fix->remove(*l4);
    fix->remove(*e);
    fix->remove(*e2);
    fix->remove(*e3);
    for(Gtk::Frame *f3 : *f2){
        fix->remove(*f3);
    }
    f2->clear();
    offset_favorite = 0;
    offset2_favorite = 0;
    is_favorite_page = false;
    change_to_home_page();
}

void Multiple_windows::change_to_book_page(){
    is_book_page = true;
    Select s;
    override_background_color(Gdk::RGBA("white"));
    set_border_width(10);
    set_default_size(1920, 1080);
    b = new Button("Scroll up",170,100);
    b2 = new Button("Scroll down",170,100);
    b3 = new Button("Back to Home Page",170,100);
    b4 = new Button("Book",170,100);
    b5 = new Button("Favorite",170,100);
    e = Gtk::manage(new Gtk::Entry);
    e2 = Gtk::manage(new Gtk::Entry);
    e3 = Gtk::manage(new Gtk::Entry);
    l3 = Gtk::manage(new Gtk::Label);
    l4 = Gtk::manage(new Gtk::Label);
    l5 = Gtk::manage(new Gtk::Label);
    l3->set_markup("<span size = '14000'><b>Enter the ID of the Nap Spot You Wish to Book:</b></span>");
    l4->set_markup("<span size = '14000'><b>Enter Number of Minutes:</b></span>");
    l5->set_markup("<span size = '14000'><b>Enter the ID of the Nap Spot You Wish to Favorite:</b></span>");
    fix->put(*e ,1350,200);
    fix->put(*l3 ,1350,160);
    fix->put(*e2 ,1350,300);
    fix->put(*e3 ,1350,570);
    fix->put(*b5 ,1350,640);
    fix->put(*b4 ,1350,370);
    fix->put(*l5 ,1350,530);
    fix->put(*l4 ,1350,260);
    fix->put(*b , 200,350);
    fix->put(*b2, 200, 450);
    fix->put(*b3, 200, 150);
    l = Gtk::manage(new Gtk::Label);
    l->set_markup("<span size = '30000'><b>Available Nap Spots</b></span>");
    fix->put(*l,725,20);
    b3->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_back_clicked_book));
    b4->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_book_nap_spot_clicked));
    for(int i=0; i<s.get_row_count("nap_spots"); i++){
        std::vector<std::string> s2 = s.get_one_row_id("nap_spots",i);
        add_nap_spot_frame(s2, 0);
    }
    for(Gtk::Frame *f2 : *f){
        fix->put(*f2, 664,150+offset);
        offset+=600;
    }

    e->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_book_id_entered));
    e2->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_minutes_entered));
    e3->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_favorite_id_entered));
    b->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_scroll_up_clicked));
    b2->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_scroll_down_clicked));
    b5->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_favorite_clicked_book));
    show_all_children();
}

void Multiple_windows::change_to_request_page(){
    int privledge;
    Select s;
    std::vector<std::string> s2 = s.get_one_row_id_user("user_information",current_user);
    try{
        privledge = std::stoi(s2[3]);
    }
    catch(const std::exception& e){

    }
    if(privledge == 0) {
        override_background_color(Gdk::RGBA("grey"));
        l = Gtk::manage(new Gtk::Label);
        l2 = Gtk::manage(new Gtk::Label);
        l3 = Gtk::manage(new Gtk::Label);
        l4 = Gtk::manage(new Gtk::Label);
        l5 = Gtk::manage(new Gtk::Label);
        e = Gtk::manage(new Gtk::Entry);
        e2 = Gtk::manage(new Gtk::Entry);
        e3 = Gtk::manage(new Gtk::Entry);
        e4 = Gtk::manage(new Gtk::Entry);
        e5 = Gtk::manage(new Gtk::Entry);
        l->set_markup("<span size = '15000'><b>Enter Nap Spot Name:</b></span>");
        l2->set_markup("<span size = '15000'><b>Enter Attribute 1:</b></span>");
        l3->set_markup("<span size = '15000'><b>Enter Attribute 2:</b></span>");
        l4->set_markup("<span size = '15000'><b>Enter Attribute 3:</b></span>");
        l5->set_markup("<span size = '15000'><b>Enter Path to Photo:</b></span>");
        b3 = new Button("Submit", 170, 100);
        b4 = new Button("Back to Home Page",170,100);
        fix->put(*b3, 845, 850);
        fix->put(*b4, 200, 150);
        fix->put(*l, 845, 50);
        fix->put(*l2, 845, 200);
        fix->put(*l3, 845, 350);
        fix->put(*l4, 845, 500);
        fix->put(*l5, 845, 650);
        fix->put(*e, 845, 100);
        fix->put(*e2, 845, 250);
        fix->put(*e3, 845, 400);
        fix->put(*e4, 845, 550);
        fix->put(*e5, 845, 700);

        e->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_name_entered));
        e2->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_attribute1_entered));
        e3->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_attribute2_entered));
        e4->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_attribute3_entered));
        e5->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_photo_entered));
        b3->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_submit_nap_spot));
        b4->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_back_clicked_request));
        show_all_children();
    }
    else if(privledge == 1){
        override_background_color(Gdk::RGBA("white"));
        b = new Button("Scroll up",170,100);
        b2 = new Button("Scroll down",170,100);
        b3 = new Button("Approve",170,100);
        b4 = new Button("Back to Home Page",170,100);
        b5 = new Button("Deny",170,100);
        l = Gtk::manage(new Gtk::Label);
        l->set_markup("<span size = '30000'><b>New Nap Spots</b></span>");
        l3 = Gtk::manage(new Gtk::Label);
        l4 = Gtk::manage(new Gtk::Label);
        e = Gtk::manage(new Gtk::Entry);
        e3 = Gtk::manage(new Gtk::Entry);
        l3->set_markup("<span size = '14000'><b>Enter the ID of the Nap Spot You Wish to Approve:</b></span>");
        l4->set_markup("<span size = '14000'><b>Enter the ID of the Nap Spot You Wish to Deny:</b></span>");
        fix->put(*l,770,20);
        fix->put(*b4, 200, 150);
        fix->put(*b , 200,350);
        fix->put(*b2, 200, 450);
        fix->put(*b3 , 1350,300);
        fix->put(*b5, 1350, 670);
        fix->put(*l3 ,1350,160);
        fix->put(*l4 ,1350,530);
        fix->put(*e ,1350,200);;
        fix->put(*e3 ,1350,570);
        b4->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_back_clicked_request_admin));
        b->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_scroll_up_clicked_request));
        b2->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_scroll_down_clicked_request));
        b3->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_approval));
        b5->signal_clicked().connect(sigc::mem_fun(*this, &Multiple_windows::on_denial));
        e->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_approve_id_entered));
        e3->signal_changed().connect(sigc::mem_fun(*this, &Multiple_windows::on_deny_id_entered));
        for(int i=0; i<s.get_row_count("new_nap_spots"); i++){
            std::vector<std::string> s2 = s.get_one_row_id("new_nap_spots",i);
            try{
            if(std::stoi(s2[7])==0){
            add_nap_spot_frame(s2, 2);
            }
            }
            catch(std::exception &e){

            }
        }
        for(Gtk::Frame *f2 : *f3){
            fix->put(*f2, 664,150+offset_request);
            offset_request+=600;
        }
        show_all_children();
    }
}


void Multiple_windows :: on_submit_nap_spot(){
    Insert i;
    Select s;
    if(photo!="Error") {
        i.insert_new_nap_spot("new_nap_spots", s.get_row_count("new_nap_spots"), nap_spot_name, attribute1, attribute2,
                              attribute3, photo);
    }
    e->set_text("");
    e2->set_text("");
    e3->set_text("");
    e4->set_text("");
    e5->set_text("");
}

void Multiple_windows :: reload_request_page(){
    Select s;
    for(Gtk::Frame *f2 : *f3){
        fix->remove(*f2);
    }
    f3->clear();
    offset_request = 0;
    for(int i=0; i<s.get_row_count("new_nap_spots"); i++){
        std::vector<std::string> s2 = s.get_one_row_id("new_nap_spots",i);
        try{
            if(std::stoi(s2[7])==0){
                add_nap_spot_frame(s2, 2);
            }
        }
        catch(std::exception &e){

        }
    }
    for(Gtk::Frame *f2 : *f3){
        fix->put(*f2, 664,150+offset_request+offset2_request);
        offset_request+=600;
    }
    show_all_children();

}

void Multiple_windows :: on_approval(){
    Select s;
    Update u;
    Insert i;
    std::vector<std::string> s2 = s.get_one_row_id("new_nap_spots",approve_id);
    i.insert_nap_spot("nap_spots",s.get_row_count("nap_spots"),s2[1],s2[2],s2[3],s2[4],s2[5]);
    u.update_new_nap_spot(approve_id);
    e->set_text("");
    reload_request_page();

}

void Multiple_windows :: on_denial(){
    Update u;
    u.update_new_nap_spot(deny_id);
    e3->set_text("");
    reload_request_page();
}


void Multiple_windows :: on_back_clicked_request(){
    fix->remove(*b3);
    fix->remove(*b4);
    fix->remove(*e);
    fix->remove(*e2);
    fix->remove(*e3);
    fix->remove(*e4);
    fix->remove(*e5);
    fix->remove(*l);
    fix->remove(*l2);
    fix->remove(*l3);
    fix->remove(*l4);
    fix->remove(*l5);
    change_to_home_page();
}

void Multiple_windows :: on_back_clicked_request_admin(){
    fix->remove(*b4);
    fix->remove(*l);
    fix->remove(*l3);
    fix->remove(*l4);
    fix->remove(*e);
    fix->remove(*e3);
    fix->remove(*b);
    fix->remove(*b2);
    fix->remove(*b3);
    fix->remove(*b5);
    for(Gtk::Frame *f2 : *f3){
        fix->remove(*f2);
    }
    f3->clear();
    offset_request = 0;
    offset2_request = 0;
    change_to_home_page();
}

void Multiple_windows::on_request_clicked(){
    fix->remove(*b4);
    fix->remove(*b5);
    fix->remove(*b6);
    fix->remove(*b7);
    change_to_request_page();
}

void Multiple_windows::on_remove_clicked(){
    Select s;
    Update u;
    std::vector<std::string> s2 = s.get_one_row_id_user("user_information",current_user);
    if(remove_id >= 0) {
        for (int i = 4; i < 9; i++) {
            try {
                if (std::stoi(s2[i]) == remove_id) {
                    u.update_favorite(current_user,i,-1);
                }
            }
            catch (const std::exception &e) {

            }
        }
        for(Gtk::Frame *f3 : *f2){
            fix->remove(*f3);
        }
        f2->clear();
        offset_favorite = 0;
        std::vector<std::string> s3 = s.get_one_row_id_user("user_information",current_user);
        for(int i=4; i<9; i++){
            try{
                if(std::stoi(s3[i])!=-1){
                    std::vector<std::string> s2 = s.get_one_row_id("nap_spots",std::stoi(s3[i]));
                    add_nap_spot_frame(s2, 1);
                }
                else{
                    continue;
                }
            }
            catch(const std::exception& e){

            }
        }
        for(Gtk::Frame *f3 : *f2){
            fix->put(*f3, 680,150+offset_favorite+ offset2_favorite);
            offset_favorite+=600;
        }
        e3->set_text("");
        show_all_children();
    }

}

//callback for password input in entry widget
void Multiple_windows::on_password_entered(){
        password = e->get_text();
}

void Multiple_windows::on_username_entered(){
    username = e2->get_text();
}

void Multiple_windows::on_name_entered(){
    nap_spot_name = e->get_text();
}

void Multiple_windows::on_attribute1_entered(){
    attribute1 = e2->get_text();
}

void Multiple_windows::on_attribute2_entered(){
    attribute2 = e3->get_text();
}

void Multiple_windows::on_attribute3_entered(){
    attribute3 = e4->get_text();
}

void Multiple_windows::on_photo_entered(){
    if(e5->get_text() == "Good photo"){
        photo = "../photos/IMG_3326.jpg";
    }
    else if(e5->get_text() == "Bad photo"){
        photo = "../photos/IMG_3332.jpg";
    }
    else{
        photo = "Error";
    }
}


void Multiple_windows::on_book_id_entered(){
    Select s;
    try {
        book_id = std::stoi(e->get_text());
        if(book_id<0 || book_id > s.get_row_count("nap_spots") ){
            book_id = -1;
        }
    } catch(const std::exception& e){
        book_id = -1;
    }
}

void Multiple_windows::on_approve_id_entered(){
    Select s;
    try {
        approve_id = std::stoi(e->get_text());
        if(approve_id<0 || approve_id > s.get_row_count("new_nap_spots") ){
            approve_id = -1;
        }
    } catch(const std::exception& e){
        approve_id = -1;
    }
}

void Multiple_windows::on_deny_id_entered(){
    Select s;
    try {
        deny_id = std::stoi(e3->get_text());
        if(deny_id<0 || deny_id > s.get_row_count("new_nap_spots") ){
            deny_id = -1;
        }
    } catch(const std::exception& e){
        deny_id = -1;
    }
}

void Multiple_windows::on_remove_id_entered(){
    Select s;
    try {
        remove_id = std::stoi(e3->get_text());
        if(remove_id<0 || remove_id > s.get_row_count("nap_spots") ){
            remove_id = -1;
        }
    } catch(const std::exception& e){
        remove_id = -1;
    }
}

void Multiple_windows::on_minutes_entered(){
    try {
        num_minutes = std::stoi(e2->get_text());
        if (num_minutes<=0){
            num_minutes = -1;
        }
    } catch(const std::exception& e){
        num_minutes = -1;
    }
}

void Multiple_windows::on_favorite_id_entered(){
    Select s;
    Update u;
    try {
        favorite_id = std::stoi(e3->get_text());
    } catch(const std::exception& e){
        favorite_id = -1;
    }
}


void Multiple_windows::on_submit_login(){
    Select s;
    if(s.determine_if_user_exists("user_information",username, password)!=-1 && (password!="" || username!="")) {
        current_user = s.determine_if_user_exists("user_information",username, password);
        fix->remove(*e);
        fix->remove(*e2);
        fix->remove(*l);
        fix->remove(*l2);
        fix->remove(*b3);
        fix->remove(*b4);
        password = "";
        username = "";
        change_to_home_page();
    }
}

void Multiple_windows::on_submit_signup(){
    Insert i;
    Select s;
    if(s.determine_if_user_exists("user_information",username, password)==-1&&(password!="" || username!="")) {
        int count = s.get_row_count("user_information");
        i.insert_user(count,username,password,0);
        current_user = count;
        fix->remove(*e);
        fix->remove(*e2);
        fix->remove(*l);
        fix->remove(*l2);
        fix->remove(*b3);
        fix->remove(*b4);
        password = "";
        username = "";
        change_to_home_page();
    }
}


void Multiple_windows::on_favorite_clicked(){
    fix->remove(*b4);
    fix->remove(*b5);
    fix->remove(*b6);
    fix->remove(*b7);
    change_to_favorite_page();
}

void Multiple_windows::on_book_clicked(){
    fix->remove(*b4);
    fix->remove(*b5);
    fix->remove(*b6);
    fix->remove(*b7);
    change_to_book_page();
}

//checks if sign up button is clicked and switches page if it is
void Multiple_windows::on_sign_up_clicked() {
    // Change to page 2
    fix->remove(*b);
    fix->remove(*b2);
    change_to_signuppage();
}

void Multiple_windows::on_log_in_clicked() {
    // Change to page 2
    fix->remove(*b);
    fix->remove(*b2);
    change_to_loginpage();
}

void Multiple_windows::on_back_clicked() {
    fix->remove(*e);
    fix->remove(*e2);
    fix->remove(*l);
    fix->remove(*l2);
    fix->remove(*b3);
    fix->remove(*b4);
    change_to_page_open();
}

void Multiple_windows::on_back_clicked_home(){
    fix->remove(*b4);
    fix->remove(*b5);
    fix->remove(*b6);
    fix->remove(*b7);
    change_to_loginpage();
}

int offset2 = 0;
void Multiple_windows::on_back_clicked_book(){
    fix->remove(*b);
    fix->remove(*b2);
    fix->remove(*b3);
    fix->remove(*b4);
    fix->remove(*b5);
    fix->remove(*e);
    fix->remove(*e2);
    fix->remove(*e3);
    fix->remove(*l);
    fix->remove(*l3);
    fix->remove(*l4);
    fix->remove(*l5);
    for(Gtk::Frame *f2 : *f){
        fix->remove(*f2);
    }
    f->clear();
    offset = 0;
    offset2 = 0;
    is_book_page = false;
    change_to_home_page();
}

void Multiple_windows::on_favorite_clicked_book(){
Select s;
Update u;
if(favorite_id>=0 && favorite_id < s.get_row_count("nap_spots")){
    std::vector<std::string> s2 = s.get_one_row_id_user("user_information",current_user);
    for(int i = 4; i<9; i++){
        try{
            if(std::stoi(s2[i])==favorite_id){
                return;
            }
        }
        catch(const std::exception& e){

        }
    }
    for(int i = 4; i<9; i++){
        try{
        if(std::stoi(s2[i])!=-1){
            continue;
        }
        else{
            u.update_favorite(current_user,i,favorite_id);
            break;
            }
        }
        catch(const std::exception& e){

        }
    }
    }
e3->set_text("");
}

void Multiple_windows::on_scroll_up_clicked(){
    for(Gtk::Frame *f2 : *f){
        fix->remove(*f2);
    }
    offset = 0;
    fix->remove(*l);
    if(offset2!=0) {
        offset2 += 600;
    }
    for(Gtk::Frame *f2 : *f){
        fix->put(*f2, 664,150+offset+offset2);
        offset+=600;
    }
    l = Gtk::manage(new Gtk::Label);
    l->set_markup("<span size = '30000'><b>Available Nap Spots</b></span>");
    fix->put(*l,725,20+offset2);
    show_all_children();
}

void Multiple_windows::on_scroll_down_clicked(){
    for(Gtk::Frame *f2 : *f){
        fix->remove(*f2);
    }
    offset = 0;
    fix->remove(*l);
    offset2 -= 600;
    for(Gtk::Frame *f2 : *f){
        fix->put(*f2, 664,150+offset+offset2);
        offset+=600;
    }
    l = Gtk::manage(new Gtk::Label);
    l->set_markup("<span size = '30000'><b>Available Nap Spots</b></span>");
    fix->put(*l,725,20+offset2);
    show_all_children();
}

void Multiple_windows::on_scroll_up_clicked_favorite(){
    for(Gtk::Frame *f3 : *f2){
        fix->remove(*f3);
    }
    offset_favorite = 0;
    fix->remove(*l6);
    if(offset2_favorite!=0) {
        offset2_favorite += 600;
    }
    for(Gtk::Frame *f3 : *f2){
        fix->put(*f3, 680,150+offset_favorite+offset2_favorite);
        offset_favorite+=600;
    }
    l6= Gtk::manage(new Gtk::Label);
    l6->set_markup("<span size = '30000'><b>Your Favorite Nap Spots</b></span>");
    fix->put(*l6,690,20+offset2_favorite);
    show_all_children();
}

void Multiple_windows::on_scroll_down_clicked_favorite(){
    for(Gtk::Frame *f3 : *f2){
        fix->remove(*f3);
    }
    offset_favorite = 0;
    fix->remove(*l6);
    offset2_favorite -= 600;
    for(Gtk::Frame *f3 : *f2){
        fix->put(*f3, 680,150+offset_favorite+offset2_favorite);
        offset_favorite+=600;
    }
    l6 = Gtk::manage(new Gtk::Label);
    l6->set_markup("<span size = '30000'><b>Your Favorite Nap Spots</b></span>");
    fix->put(*l6,690,20+offset2_favorite);
    show_all_children();
}

void Multiple_windows::on_scroll_up_clicked_request(){
    for(Gtk::Frame *f2 : *f3){
        fix->remove(*f2);
    }
    offset_request = 0;
    fix->remove(*l);
    if(offset2_request!=0) {
        offset2_request += 600;
    }
    for(Gtk::Frame *f2 : *f3){
        fix->put(*f2, 664,150+offset_request+offset2_request);
        offset_request+=600;
    }
    l= Gtk::manage(new Gtk::Label);
    l->set_markup("<span size = '30000'><b>New Nap Spots</b></span>");
    fix->put(*l,790,20+offset2_request);
    show_all_children();
}

void Multiple_windows::on_scroll_down_clicked_request(){
    for(Gtk::Frame *f2 : *f3){
        fix->remove(*f2);
    }
    offset_request = 0;
    fix->remove(*l);
    offset2_request -= 600;
    for(Gtk::Frame *f2 : *f3){
        fix->put(*f2, 664,150+offset_request+offset2_request);
        offset_request+=600;
    }
    l = Gtk::manage(new Gtk::Label);
    l->set_markup("<span size = '30000'><b>New Nap Spots</b></span>");
    fix->put(*l,790,20+offset2_request);
    show_all_children();
}


int temp_num;
int temp_id;
void Multiple_windows::countdown() {
    Update u;
    Select s;
    int num = temp_num;
    int id = temp_id;
    std::this_thread::sleep_for(std::chrono::minutes(num));
    u.update_reservation(id, "Open");
    reserved = false;
    if(is_book_page){
    for(Gtk::Frame *f2 : *f){
        fix->remove(*f2);
    }
    f->clear();
    offset = 0;
    for(int i=0; i<s.get_row_count("nap_spots"); i++){
        std::vector<std::string> s2 = s.get_one_row_id("nap_spots",i);
        add_nap_spot_frame(s2, 0);
    }
    for(Gtk::Frame *f2 : *f){
        fix->put(*f2, 664,150+offset+offset2);
        offset+=600;
    }
    show_all_children();
    }
    else if(is_favorite_page){
        for(Gtk::Frame *f3 : *f2){
            fix->remove(*f3);
        }
        f2->clear();
        offset_favorite = 0;
        std::vector<std::string> s3 = s.get_one_row_id_user("user_information",current_user);
        for(int i=4; i<9; i++){
            try{
                if(std::stoi(s3[i])!=-1){
                    std::vector<std::string> s2 = s.get_one_row_id("nap_spots",std::stoi(s3[i]));
                    add_nap_spot_frame(s2, 1);
                }
                else{
                    continue;
                }
            }
            catch(const std::exception& e){

            }
        }
        for(Gtk::Frame *f3 : *f2){
            fix->put(*f3, 680,150+offset_favorite+ offset2_favorite);
            offset_favorite+=600;
        }
        show_all_children();
    }



}

void Multiple_windows::on_book_nap_spot_clicked(){
    Update u;
    temp_num = num_minutes;
    temp_id = book_id;
    Select s;
    if(book_id == -1 || num_minutes == -1 || reserved == true){
        e->set_text("");
        e2->set_text("");
        return;
    }
    else{
        u.update_reservation(temp_id,"Reserved");
        reserved = true;
    }
    if(is_book_page) {
        for (Gtk::Frame *f2: *f) {
            fix->remove(*f2);
        }
        f->clear();
        offset = 0;
        for (int i = 0; i < s.get_row_count("nap_spots"); i++) {
            std::vector<std::string> s2 = s.get_one_row_id("nap_spots", i);
            add_nap_spot_frame(s2, 0);
        }
        for (Gtk::Frame *f2: *f) {
            fix->put(*f2, 664, 150 + offset + offset2);
            offset += 600;
        }
        e->set_text("");
        e2->set_text("");
        try {
            std::thread countdown_thread(&Multiple_windows::countdown, this);
            countdown_thread.detach();
        } catch (const std::exception &e) {

        }
    }
    else if(is_favorite_page){
        for(Gtk::Frame *f3 : *f2){
            fix->remove(*f3);
        }
        f2->clear();
        offset_favorite = 0;
        std::vector<std::string> s3 = s.get_one_row_id_user("user_information",current_user);
        for(int i=4; i<9; i++){
            try{
                if(std::stoi(s3[i])!=-1){
                    std::vector<std::string> s2 = s.get_one_row_id("nap_spots",std::stoi(s3[i]));
                    add_nap_spot_frame(s2, 1);
                }
                else{
                    continue;
                }
            }
            catch(const std::exception& e){

            }
        }
        for(Gtk::Frame *f3 : *f2){
            fix->put(*f3, 680,150+offset_favorite+ offset2_favorite);
            offset_favorite+=600;
        }
        e->set_text("");
        e2->set_text("");
        try {
            std::thread countdown_thread(&Multiple_windows::countdown, this);
            countdown_thread.detach();
        } catch (const std::exception &e) {

        }
    }
    show_all_children();
}


void Multiple_windows::add_nap_spot_frame(std::vector<std::string> s, int i){
    Gtk::Frame *frame = Gtk::manage(new Gtk::Frame);
    frame->set_size_request(550, 500);

    Gtk::Box* box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
    std::string ID = "Nap Spot ID: " + s[0];
    std::string Name = "Nap Spot Name: " + s[1].substr(1, s[1].size() - 2);
    std::string Attribute1 = "Attribute 1: " + s[2].substr(1, s[2].size() - 2);
    std::string Attribute2 = "Attribute 2: " + s[3].substr(1, s[3].size() - 2);
    std::string Attribute3 = "Attribute 3: " + s[4].substr(1, s[4].size() - 2);
    std::string Availibility = "Availibility Status: " + s[6];

    Gtk::Label* label1 = Gtk::manage(new Gtk::Label());
    label1->set_markup("<b><span size='large'>" + ID + "</span></b>");
    Gtk::Label* label2 = Gtk::manage(new Gtk::Label());
    label2->set_markup("<span size='large'>" + Name + "</span>");
    Gtk::Label* label3 = Gtk::manage(new Gtk::Label());
    label3->set_markup("<span size='large'>" + Attribute1 + "</span>");
    Gtk::Label* label4 = Gtk::manage(new Gtk::Label());
    label4->set_markup("<span size='large'>" + Attribute2 + "</span>");
    Gtk::Label* label5 = Gtk::manage(new Gtk::Label());
    label5->set_markup("<span size='large'>" + Attribute3 + "</span>");
    Glib::RefPtr<Gdk::Pixbuf> p = Gdk::Pixbuf::create_from_file(s[5]);
    Glib::RefPtr<Gdk::Pixbuf> rp = p->scale_simple(400, 400, Gdk::INTERP_BILINEAR);
    Gtk::Image* image = Gtk::manage(new Gtk::Image(rp));
    box->pack_start(*label1);
    if(i!=2) {
        Gtk::Label *label6 = Gtk::manage(new Gtk::Label());
        label6->set_markup("<span size='large'>" + Availibility + "</span>");
        box->pack_start(*label6);
    }
    box->pack_start(*label2);
    box->pack_start(*label3);
    box->pack_start(*label4);
    box->pack_start(*label5);
    box->pack_start(*image);
    frame->add(*box);
    if(i == 0) {
        f->push_back(frame);
    }
    else if(i == 2){
        f3->push_back(frame);
    }
    else{
        f2->push_back(frame);
    }
}