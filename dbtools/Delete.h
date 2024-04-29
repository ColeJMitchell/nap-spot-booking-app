//
// Created by cojmi on 3/18/2024.
//

#ifndef GOLD_DELETE_H
#define GOLD_DELETE_H
#include <string>
class Delete{
public:
    //removes information from the database
    void delete_from_table(std::string table, int id);
};
#endif //GOLD_DELETE_H
