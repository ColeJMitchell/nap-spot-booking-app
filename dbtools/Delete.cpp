//
// Created by cojmi on 3/18/2024.
//
#include "Delete.h"
#include <sqlite3.h>
#include <iostream>

//deletes a user if they violated rules or client wants to delete their account / removes a nap spot from favorites list
void Delete::delete_from_table(std::string table, int id) {
    sqlite3 *curr_db;
    int rc = sqlite3_open("../database/database.sqlite", &curr_db);
    int retCode = 0;
    char *zErrMsg = 0;
    std::string sql = "DELETE FROM ";
    sql += table;
    sql += " WHERE id = \"";
    sql += std::to_string(id);
    sql += "\";";
    retCode = sqlite3_exec(curr_db,
                           sql.c_str(),
                           0, // no call back needed for Delete
                           0, // no data structure needed
                           &zErrMsg);
    if( retCode != SQLITE_OK ){
        std::cerr << sql
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(curr_db);
}



