//
// Created by cojmi on 3/18/2024.
//

#ifndef GOLD_INSERT_H
#define GOLD_INSERT_H
#include <string>
class Insert{
public:
    void insert_user(int id, std::string first_name, std::string last_name, std::string email, std::string username, std::string password);
    void insert_nap_spot_or_favorite(std::string table, int id, float latitude, float longitude, std::string name,
                                     std::string attribute1, std::string attribute2, std::string attribute3,
                                     int num_people,
                                     std::string description, int reserved);
};
#endif //GOLD_INSERT_H
