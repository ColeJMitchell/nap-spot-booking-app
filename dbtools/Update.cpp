//
// Created by cojmi on 3/18/2024.
//

#include "Update.h"
#include <sqlite3.h>
#include <iostream>

//update user information such as a password, email, or username.
void Update::update_reservation(int id, std::string reserve) {
    sqlite3 *curr_db;
    int rc = sqlite3_open("../database/database.sqlite", &curr_db);
    int retCode = 0;
    char *zErrMsg = 0;
    std::string sql = "UPDATE nap_spots";
    sql += " SET reserve = \"";
    sql += reserve;
    sql += "\" WHERE id = ";
    sql += std::to_string(id);
    sql += ";";
    retCode = sqlite3_exec(curr_db,
                           sql.c_str(),
                           0,
                           0,
                           &zErrMsg);
    if( retCode != SQLITE_OK ){
        std::cerr << sql
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;
        sqlite3_free(zErrMsg);
    }
    }

void Update::update_new_nap_spot(int id) {
    sqlite3 *curr_db;
    int rc = sqlite3_open("../database/database.sqlite", &curr_db);
    int retCode = 0;
    char *zErrMsg = 0;
    std::string sql = "UPDATE new_nap_spots";
    sql += " SET remove = ";
    sql += std::to_string(1);
    sql += " WHERE id = ";
    sql += std::to_string(id);
    sql += ";";
    retCode = sqlite3_exec(curr_db,
                           sql.c_str(),
                           0,
                           0,
                           &zErrMsg);
    if( retCode != SQLITE_OK ){
        std::cerr << sql
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;
        sqlite3_free(zErrMsg);
    }
}

    void Update::update_favorite(int id, int favorite, int value) {
        sqlite3 *curr_db;
        int rc = sqlite3_open("../database/database.sqlite", &curr_db);
        int retCode = 0;
        char *zErrMsg = 0;
        std::string change;
        switch(favorite){
            case 4:
                change = "spot1";
                break;
            case 5:
                change = "spot2";
                break;
            case 6:
                change = "spot3";
                break;
            case 7:
                change = "spot4";
                break;
            case 8:
                change = "spot5";
                break;
        }
        std::string sql = "UPDATE user_information SET ";
        sql += change;
        sql += " = ";
        sql += std::to_string(value);
        sql += " WHERE user_id = ";
        sql += std::to_string(id);
        sql += " ;";
        retCode = sqlite3_exec(curr_db,
                               sql.c_str(),
                               0,
                               0,
                               &zErrMsg);
        if (retCode != SQLITE_OK) {
            std::cerr << sql
                      << std::endl
                      << "SQL error: "
                      << zErrMsg;
            sqlite3_free(zErrMsg);
        }
    }