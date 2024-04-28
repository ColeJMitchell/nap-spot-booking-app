//
// Created by cojmi on 3/18/2024.
//

#ifndef GOLD_INSERT_H
#define GOLD_INSERT_H
#include <string>
class Insert{
public:

    void insert_user(int user_id, std::string username, std::string password, int privledge);


    void insert_new_nap_spot(std::string table, int id, std::string name, std::string attribute1, std::string attribute2,
                         std::string attribute3, std::string photo);

    void insert_nap_spot(std::string table, int id, std::string name, std::string attribute1, std::string attribute2,
                         std::string attribute3, std::string photo);
};
#endif //GOLD_INSERT_H
