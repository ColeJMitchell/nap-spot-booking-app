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