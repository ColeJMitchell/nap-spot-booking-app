//
// Created by cojmi on 3/18/2024.
//

#include "Insert.h"
#include <sqlite3.h>
#include <iostream>
#include <iomanip>

void Insert::insert_user(int id, std::string first_name, std::string last_name, std::string email, std::string username, std::string password) {
    sqlite3 *curr_db;
    int rc = sqlite3_open("../database/database.sqlite", &curr_db);
    int retCode = 0;
    char *zErrMsg = 0;
    std::string sql = "INSERT INTO user_information";
    sql += " ( id, first_name, last_name, email, username, password) ";
    sql += "VALUES (";
    sql += std::to_string(id);
    sql += ", \"";
    sql += first_name;
    sql += "\", ";
    sql += "\"";
    sql += last_name;
    sql += "\",";
    sql += "\"";
    sql += email;
    sql += "\",";
    sql += "\"";
    sql += username;
    sql += "\",";
    sql += "\"";
    sql += password;
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

void Insert::insert_nap_spot_or_favorite(std::string table, int id, float latitude, float longitude, std::string name,
                                         std::string attribute1, std::string attribute2, std::string attribute3,
                                         int num_people, std::string description){
    sqlite3 *curr_db;
    int rc = sqlite3_open("../database/database.sqlite", &curr_db);
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << latitude;
    std::string strValue = ss.str();
    int retCode = 0;
    char *zErrMsg = 0;
    std::string sql = "INSERT INTO ";
    sql += table;
    sql += " ( id, latitude, longitude, name, attribute_1, attribute_2, attribute_3, num_people, description) ";
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