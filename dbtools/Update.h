//
// Created by cojmi on 3/18/2024.
//

#ifndef GOLD_UPDATE_H
#define GOLD_UPDATE_H
#include <string>
class Update{
public:
    void update_reservation(int id, std::string reserve);

    void update_favorite(int id, int favorite);

    void update_favorite(int id, int favorite, int value);
};
#endif //GOLD_UPDATE_H
