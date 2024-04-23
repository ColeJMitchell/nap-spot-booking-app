//
// Created by cojmi on 3/18/2024.
//

#include <iostream>
#include <vector>
#include <sqlite3.h>
#include "Select.h"

//callback necessary for selecting row from table as a vector of strings, needs to be static to work
int Select::cb_select_row(void *data, int argc, char **argv, char **azColName)
{
    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }
    std::vector<std::string> *dv = (std::vector<std::string> *) data;
    for (int i = 0; i < argc; i++) {
        dv->push_back((argv[i] ? std::string(argv[i]) : "NULL"));
    }
    return 0;
}

int Select::cb_size(void *data, int argc, char **argv, char **azColName) {
    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    } else {
// Store size in passed integer variable.
        int *obj = (int *) data;
        *obj = atoi(argv[0]);
    }
    return 0;
}



//returns a vector of string correlating to a row based on its id.
std::vector<std::string> Select::get_one_row_id(std::string table, int id) {
    sqlite3 *curr_db;
    int rc = sqlite3_open("../database/database.sqlite", &curr_db);
    int retCode = 0;
    char *zErrMsg = 0;
    std::string sql = "SELECT ";
    sql += "*";
    sql += " FROM ";
    sql += table;
    sql += " WHERE id=";
    sql += std::to_string(id);
    sql += ";";
    std::vector<std::string> result;
    retCode = sqlite3_exec(curr_db,
                           sql.c_str(),
                           cb_select_row,
                           (void *) &result,
                           &zErrMsg);
    if (retCode != SQLITE_OK) {
        std::cerr << sql
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(curr_db);
    return result;
}

int Select::get_row_count(std::string table){
    sqlite3 *curr_db;
    int rc = sqlite3_open("../database/database.sqlite", &curr_db);
    int retCode = 0;
    char *zErrMsg = 0;
    std::string sql = "SELECT COUNT(*)";
    sql += " FROM ";
    sql += table;
    sql += " ;";
    int result=0;
    retCode = sqlite3_exec(curr_db,
                           sql.c_str(),
                           cb_size,
                           (void *) &result,
                           &zErrMsg);
    if (retCode != SQLITE_OK) {
        std::cerr << sql
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(curr_db);
    return result;
}

int Select::determine_if_user_exists(std::string table, std::string username, std::string password){
    sqlite3 *curr_db;
    int rc = sqlite3_open("../database/database.sqlite", &curr_db);
    int retCode = 0;
    char *zErrMsg = 0;
    std::string sql = "SELECT user_id";
    sql += " FROM ";
    sql += table;
    sql += " WHERE username = \"";
    sql += username;
    sql += "\" and password = \"";
    sql += password;
    sql += "\" ;";
    int result=0;
    retCode = sqlite3_exec(curr_db,
                           sql.c_str(),
                           cb_size,
                           (void *) &result,
                           &zErrMsg);
    if (retCode != SQLITE_OK) {
        result = -1;
    }
    sqlite3_close(curr_db);
    return result;


}