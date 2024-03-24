//
// Created by cojmi on 3/18/2024.
//
#include "gtest/gtest.h"
#include "Update.h"
#include "Select.h"
#include "Delete.h"
#include "Insert.h"

class SelectTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        i1 = new Insert;
        s1 = new Select;
        d1 = new Delete;
        i1->insert_user(1,"Cole","Mitchell","mitchecj@lafayette.edu","Cedrien","Password");
    }
    virtual void TearDown() {
        delete i1;
        delete s1;
        d1->delete_from_table("user_information",1);
        delete d1;
    }
    Insert *i1;
    Select *s1;
    Delete *d1;
};
TEST_F(SelectTest, TESTFIXTURE) {
    std::vector<std::string> me = {"1","Cole", "Mitchell", "mitchecj@lafayette.edu", "Cedrien", "Password"};

    for (int i=0; i<6; i++) {
        ASSERT_EQ(s1->get_one_row_id("user_information",1)[i], me[i]) << "These should match!";
    }
}

class UpdateTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        i1 = new Insert;
        s1 = new Select;
        d1 = new Delete;
        u1 = new Update;
        i1->insert_user(1,"Cole","Mitchell","mitchecj@lafayette.edu","Cedrien","Password");
        u1->update_user_information("Password",1,"Password2");
    }
    virtual void TearDown() {
        delete i1;
        delete s1;
        d1->delete_from_table("user_information",1);
        delete d1;
    }
    Update *u1;
    Insert *i1;
    Select *s1;
    Delete *d1;
};
TEST_F(UpdateTest, TESTFIXTURE) {
    std::vector<std::string> me = {"1","Cole", "Mitchell", "mitchecj@lafayette.edu", "Cedrien", "Password2"};

    for (int i=0; i<6; i++) {
        ASSERT_EQ(s1->get_one_row_id("user_information",1)[i], me[i]) << "These should match!";
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
