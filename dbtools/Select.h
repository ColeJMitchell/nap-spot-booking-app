//
// Created by cojmi on 3/18/2024.
//

#ifndef GOLD_SELECT_H
#define GOLD_SELECT_H
class Select{
public:
    static int cb_select_row(void *data, int argc, char **argv, char **azColName);
    std::vector<std::string> get_one_row_id(std::string table, int id);
};
#endif //GOLD_SELECT_H
