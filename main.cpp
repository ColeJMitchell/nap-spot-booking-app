//
// Created by cojmi on 3/18/2024.
//
#include <vector>
#include <iostream>
#include "Delete.h"
#include "Insert.h"
#include "Update.h"
#include "Select.h"
int main(int argc, char **argv) {
    Insert i;
    i.insert_nap_spot_or_favorite("nap_spots",1,76.28,23.10,"spot","w","w","w",2,"d");
   // Update u;
    //u.update_user_information("first_name",2,"Cole");
    //Delete d;
    //d.delete_user_table("user_information",1);
    Select s;
    //std::vector<std::string> res = s.get_one_row_id("user_information",2);
    //for(int i =0; i<6; i++){
      //  std::cout<<res[i];
   // }
}
