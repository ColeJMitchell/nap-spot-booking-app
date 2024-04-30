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
        i1->insert_user(100,"Generic", "Password",0);
        i1->insert_nap_spot("nap_spots",100,"'test'","'na'","'na'","'na'","na");
    }

    virtual void TearDown() {
        delete i1;
        delete s1;
        d1->delete_from_table("user_information","user_id", 100);
        d1->delete_from_table("nap_spots","id",100);
        delete d1;
    }

    Insert* i1;
    Select* s1;
    Delete* d1;
};

TEST_F(SelectTest, TESTFIXTURE) {
    std::vector<std::string> expected_user = {"100", "Generic", "Password", "0", "-1", "-1", "-1", "-1", "-1"};
    std::vector<std::string> expected_nap_spot = {"100", "'test'", "'na'", "'na'", "'na'", "na", "Open"};
    std::vector<std::string> test_user = s1->get_one_row_id_user("user_information", 100);
    std::vector<std::string> test_nap_spot = s1->get_one_row_id("nap_spots", 100);
    for(int i =0; i< 9; i++) {
        ASSERT_EQ(test_user[i],expected_user[i]);
    }
    for(int i =0; i< 7; i++) {
        ASSERT_EQ(test_nap_spot[i],expected_nap_spot[i]);
    }
    ASSERT_EQ(s1->get_row_count("user_information"),3);
    ASSERT_EQ(s1->determine_if_user_exists("user_information","Generic","Password"),100);
}
/*
class InsertTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        i1 = new Insert;
        s1 = new Select;
        d1 = new Delete;
    }

    virtual void TearDown() {
        delete i1;
        delete s1;
        delete d1;
    }

    Insert* i1;
    Select* s1;
    Delete* d1;
};

TEST_F(InsertTest, InsertUserTest) {
    i1->insert_user(1, "TestUser", "TestPassword", 0);
    std::vector<std::string> expected = {"1", "TestUser", "TestPassword", "0", "-1", "-1", "-1", "-1", "-1"};
    ASSERT_EQ(s1->get_one_row_id("user_information", 1), expected);
    d1->delete_from_table("user_information", 1);
}

TEST_F(InsertTest, InsertNewNapSpotTest) {
    i1->insert_new_nap_spot("nap_spots", 9, "Test Spot", "Test Attr1", "Test Attr2", "Test Attr3", "../photos/test.jpg");
    std::vector<std::string> expected = {"9", "Test Spot", "Test Attr1", "Test Attr2", "Test Attr3", "../photos/test.jpg", "Open", "0"};
    ASSERT_EQ(s1->get_one_row_id("nap_spots", 9), expected);
    d1->delete_from_table("nap_spots", 9);
}

TEST_F(InsertTest, InsertNapSpotTest) {
    i1->insert_nap_spot("nap_spots", 10, "Test Spot", "Test Attr1", "Test Attr2", "Test Attr3", "../photos/test.jpg");
    std::vector<std::string> expected = {"10", "Test Spot", "Test Attr1", "Test Attr2", "Test Attr3", "../photos/test.jpg", "Open"};
    ASSERT_EQ(s1->get_one_row_id("nap_spots", 10), expected);
    d1->delete_from_table("nap_spots", 10);
}

class UpdateTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        i1 = new Insert;
        s1 = new Select;
        d1 = new Delete;
        u1 = new Update;

        // Insert test data
        i1->insert_user(1, "TestUser", "TestPassword", 0);
        i1->insert_nap_spot("nap_spots", 1, "Test Spot", "Test Attr1", "Test Attr2", "Test Attr3", "../photos/test.jpg");
        i1->insert_new_nap_spot("new_nap_spots", 2, "New Test Spot", "Test Attr1", "Test Attr2", "Test Attr3", "../photos/test.jpg");
    }

    virtual void TearDown() {
        d1->delete_from_table("user_information", 1);
        d1->delete_from_table("nap_spots", 1);
        d1->delete_from_table("new_nap_spots", 2);
        delete i1;
        delete s1;
        delete d1;
        delete u1;
    }

    Insert* i1;
    Select* s1;
    Delete* d1;
    Update* u1;
};

TEST_F(UpdateTest, UpdateReservationTest) {
    u1->update_reservation(1, "Reserved");
    std::vector<std::string> expected = {"1", "Test Spot", "Test Attr1", "Test Attr2", "Test Attr3", "../photos/test.jpg", "Reserved"};
    ASSERT_EQ(s1->get_one_row_id("nap_spots", 1), expected);
}

TEST_F(UpdateTest, UpdateNewNapSpotTest) {
    u1->update_new_nap_spot(2);
    std::vector<std::string> expected = {"2", "New Test Spot", "Test Attr1", "Test Attr2", "Test Attr3", "../photos/test.jpg", "Open", "1"};
    ASSERT_EQ(s1->get_one_row_id("new_nap_spots", 2), expected);
}

TEST_F(UpdateTest, UpdateFavoriteTest) {
    u1->update_favorite(1, 4, 1);
    std::vector<std::string> expected = {"1", "TestUser", "TestPassword", "0", "1", "-1", "-1", "-1", "-1"};
    ASSERT_EQ(s1->get_one_row_id_user("user_information", 1), expected);
}
class DeleteTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        i1 = new Insert;
        s1 = new Select;
        d1 = new Delete;

        // Insert test data
        i1->insert_user(1, "TestUser", "TestPassword", 0);
        i1->insert_nap_spot("nap_spots", 1, "Test Spot", "Test Attr1", "Test Attr2", "Test Attr3", "../photos/test.jpg");
    }

    virtual void TearDown() {
        delete i1;
        delete s1;
        delete d1;
    }

    Insert* i1;
    Select* s1;
    Delete* d1;
};

TEST_F(DeleteTest, DeleteFromUserTableTest) {
    int initialCount = s1->get_row_count("user_information");
    d1->delete_from_table("user_information", 1);
    int finalCount = s1->get_row_count("user_information");
    ASSERT_EQ(finalCount, initialCount - 1);
}

TEST_F(DeleteTest, DeleteFromNapSpotsTableTest) {
    int initialCount = s1->get_row_count("nap_spots");
    d1->delete_from_table("nap_spots", 1);
    int finalCount = s1->get_row_count("nap_spots");
    ASSERT_EQ(finalCount, initialCount - 1);
}
 */
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
