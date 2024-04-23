//
// Created by cojmi on 3/18/2024.
//

#ifndef GOLD_SELECT_H
#define GOLD_SELECT_H
class Select{
public:
    static int cb_select_row(void *data, int argc, char **argv, char **azColName);
    std::vector<std::string> get_one_row_id(std::string table, int id);

    int get_row_count(std::string table);

    static int cb_size(void *data, int argc, char **argv, char **azColName);

    int determine_if_user_exists(std::string table, std::string username);
};
#endif //GOLD_SELECT_H
