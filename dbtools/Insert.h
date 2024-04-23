//
// Created by cojmi on 3/18/2024.
//

#ifndef GOLD_INSERT_H
#define GOLD_INSERT_H
#include <string>
class Insert{
public:
    void insert_nap_spot_or_favorite(std::string table, int id, float latitude, float longitude, std::string name,
                                     std::string attribute1, std::string attribute2, std::string attribute3,
                                     int num_people,
                                     std::string description, int reserved);


    void insert_user(int user_id, std::string username, std::string password, int privledge);
};
#endif //GOLD_INSERT_H
