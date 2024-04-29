//
// Created by cojmi on 3/18/2024.
//

#ifndef GOLD_UPDATE_H
#define GOLD_UPDATE_H
#include <string>
class Update{
public:
    //updates reservation status
    void update_reservation(int id, std::string reserve);
    //updates favorite nap spots
    void update_favorite(int id, int favorite);
    //updates favorite nap spots
    void update_favorite(int id, int favorite, int value);
    //updates if new nap spot is created
    void update_new_nap_spot(int id);
};
#endif //GOLD_UPDATE_H
