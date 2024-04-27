//
// Created by cojmi on 3/18/2024.
//

#include "Insert.h"
#include <sqlite3.h>
#include <iostream>
#include <iomanip>


//adds a user to the database when they sign up
void Insert::insert_user(int user_id, std::string username, std::string password, int privledge) {
    sqlite3 *curr_db;
    int rc = sqlite3_open("../database/database.sqlite", &curr_db);
    int retCode = 0;
    char *zErrMsg = 0;
    std::string sql = "INSERT INTO user_information";
    sql += " ( user_id, username, password, privledge, spot1, spot2, spot3, spot4, spot5) ";
    sql += "VALUES ( ";
    sql += std::to_string(user_id);
    sql += ", \"";
    sql += username;
    sql += "\", ";
    sql += "\"";
    sql += password;
    sql += "\", ";
    sql += std::to_string(privledge);
    sql += ", -1, -1, -1, -1, -1";
    sql += ");";
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
    sqlite3_close(curr_db);
}


//adds a nap spot if administrator approved a request or the user adds a new favorite nap spot
void Insert::insert_nap_spot_or_favorite(std::string table, int id, float latitude, float longitude, std::string name,
                                         std::string attribute1, std::string attribute2, std::string attribute3,
                                         int num_people, std::string description ,int reserved){
    sqlite3 *curr_db;
    int rc = sqlite3_open("../database/database.sqlite", &curr_db);
    int retCode = 0;
    char *zErrMsg = 0;
    std::string sql = "INSERT INTO ";
    sql += table;
    sql += " ( id, latitude, longitude, name, attribute_1, attribute_2, attribute_3, num_people, description, reserved) ";
    sql += "VALUES (";
    sql += std::to_string(id);
    sql += ",";
    sql += std::to_string(latitude);
    sql += ",";
    sql += std::to_string(longitude);
    sql += ",";
    sql += "\"";
    sql += name;
    sql += "\",";
    sql += "\"";
    sql += attribute1;
    sql += "\",";
    sql += "\"";
    sql += attribute2;
    sql += "\",";
    sql += "\"";
    sql += attribute3;
    sql += "\"";
    sql += ",";
    sql += std::to_string(num_people);
    sql += ",";
    sql += "\"";
    sql += description;
    sql += " ";
    sql += std::to_string(reserved);
    sql += "\");";
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
    sqlite3_close(curr_db);
}