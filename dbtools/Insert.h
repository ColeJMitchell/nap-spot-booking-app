//
// Created by cojmi on 3/18/2024.
//

#ifndef GOLD_INSERT_H
#define GOLD_INSERT_H
#include <string>
class Insert{
public:
    //inserts a created user into the database with a set privledge
    void insert_user(int user_id, std::string username, std::string password, int privledge);

    //inserts a new nap spot into the database with name, attributes and photo
    void insert_new_nap_spot(std::string table, int id, std::string name, std::string attribute1, std::string attribute2,
                         std::string attribute3, std::string photo);
    //inserts a nap spot from the database with its name, attributes and photo into different pages
    void insert_nap_spot(std::string table, int id, std::string name, std::string attribute1, std::string attribute2,
                         std::string attribute3, std::string photo);
};
#endif //GOLD_INSERT_H
