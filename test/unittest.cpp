//
// Created by cojmi on 3/18/2024.
//
#include "gtest/gtest.h"
#include "Update.h"
#include "Select.h"
#include "Delete.h"
#include "Insert.h"

//Test fixture class for testing the Select Class
class SelectTest : public ::testing::Test {
protected:
    /*
     * SetUp function to initialize the Insert,Select,Delete objects
     * Inserts a user and nap spot into respective tables
     */
    virtual void SetUp() {
        i1 = new Insert;
        s1 = new Select;
        d1 = new Delete;
        i1->insert_user(100,"Generic", "Password",0);
        i1->insert_nap_spot("nap_spots",100,"'test'","'na'","'na'","'na'","na");
    }
    /*
     * TearDoen function deletes inserted user and nap spot from their tables
     * Cleans up objects after test is run
     */
    virtual void TearDown() {
        delete i1;
        delete s1;
        d1->delete_from_table("user_information","user_id", 100);
        d1->delete_from_table("nap_spots","id",100);
        delete d1;
    }

    Insert* i1; //Insert object pointer
    Select* s1; //Select object pointer
    Delete* d1; //Delete object pointer
};

/*
 * Test case for testing Select class
 * Verifies the correctness of the class' functions
 */
TEST_F(SelectTest, TESTFIXTURE) {
    std::vector<std::string> expected_user = {"100", "Generic", "Password", "0", "-1", "-1", "-1", "-1", "-1"};
    std::vector<std::string> expected_nap_spot = {"100", "'test'", "'na'", "'na'", "'na'", "na", "Open"};
    std::vector<std::string> test_user = s1->get_one_row_id_user("user_information", 100);
    std::vector<std::string> test_nap_spot = s1->get_one_row_id("nap_spots", 100);
    // Check if the user data matches the expected values
    for(int i =0; i< 9; i++) {
        ASSERT_EQ(test_user[i],expected_user[i]);
    }
    // Check if the nap spot data matches the expected values
    for(int i =0; i< 7; i++) {
        ASSERT_EQ(test_nap_spot[i],expected_nap_spot[i]);
    }
    // Check if the function returns the expected number of rows
    ASSERT_EQ(s1->get_row_count("user_information"),3);
    // Check if the function returns the expected user information
    ASSERT_EQ(s1->determine_if_user_exists("user_information","Generic","Password"),100);
}
/*
 * Test fixture class for testing the Update class
 */
class UpdateTest : public ::testing::Test {
protected:
    /*
     * SetUp function initializes the Insert, Update, Select, and Delete objects
     * Inserts test data into the user_information, nap_spots, and new_nap_spots tables
     */
    virtual void SetUp() {
        i1 = new Insert;
        u1 = new Update;
        s1 = new Select;
        d1 = new Delete;

        // Insert test data
        i1->insert_user(100, "TestUser", "TestPassword", 0);
        i1->insert_nap_spot("nap_spots", 100, "'test'", "'na'", "'na'", "'na'", "na");
        i1->insert_new_nap_spot("new_nap_spots", 200, "'new_test'", "'new_attr1'", "'new_attr2'", "'new_attr3'", "'new_image'");
    }
    /*
     * TearDown function cleans up the inserted test data from the tables
     * Deletes the objects
     */
    virtual void TearDown() {
        // Clean up test data
        d1->delete_from_table("user_information", "user_id", 100);
        d1->delete_from_table("nap_spots", "id", 100);
        d1->delete_from_table("new_nap_spots", "id", 200);

        delete i1;
        delete u1;
        delete s1;
        delete d1;
    }

    Insert* i1; // Pointer to the Insert object
    Update* u1; // Pointer to the Update object
    Select* s1; // Pointer to the Select object
    Delete* d1; // Pointer to the Delete object
};
/*
 * Test case for testing the update_reservation function of the Update class
 * Verifies that the reservation status of a nap spot is updated correctly
 */
TEST_F(UpdateTest, UpdateReservationTest) {
    u1->update_reservation(100, "Closed");
    std::vector<std::string> expected = {"100", "'test'", "'na'", "'na'", "'na'", "na", "Closed"};
    std::vector<std::string> test_nap_spot = s1->get_one_row_id("nap_spots", 100);
    ASSERT_EQ(test_nap_spot, expected);
}
/*
 * Test case for testing the update_new_nap_spot function of the Update class
 * Verifies that the details of a new nap spot are updated correctly
 */
TEST_F(UpdateTest, UpdateNewNapSpotTest) {
    u1->update_new_nap_spot(200);
    std::vector<std::string> expected = {"200", "'new_test'", "'new_attr1'", "'new_attr2'", "'new_attr3'", "'new_image'", "Open", "1"};
    std::vector<std::string> test_new_nap_spot = s1->get_one_row_id("new_nap_spots", 200);
    ASSERT_EQ(test_new_nap_spot, expected);
}
/*
 * Test case for testing the update_favorite function of the Update class
 * Verifies that a user's favorite nap spot is updated correctly
 */
TEST_F(UpdateTest, UpdateFavoriteTest) {
    u1->update_favorite(100, 4, 200);
    std::vector<std::string> expected = {"100", "TestUser", "TestPassword", "0", "200", "-1", "-1", "-1", "-1"};
    std::vector<std::string> test_user = s1->get_one_row_id_user("user_information", 100);
    ASSERT_EQ(test_user, expected);
}
/*
 * Test fixture class for testing the Insert class
 */
class InsertTest : public ::testing::Test {
protected:
    /*
    * SetUp function initializes the Insert, Select, and Delete objects
    */
    virtual void SetUp() {
        i1 = new Insert;
        s1 = new Select;
        d1 = new Delete;
    }
    /*
     * TearDown function cleans up the objects
     */
    virtual void TearDown() {
        delete i1;
        delete s1;
        delete d1;
    }

    Insert* i1; // Pointer to the Insert object
    Select* s1; // Pointer to the Select object
    Delete* d1; // Pointer to the Delete object
};
/*
 * Test case for testing the insert_user function of the Insert class
 * Verifies that a user is correctly inserted into the user_information table
 */
TEST_F(InsertTest, InsertUserTest) {
    i1->insert_user(100, "TestUser", "TestPassword", 0);
    std::vector<std::string> expected = {"100", "TestUser", "TestPassword", "0", "-1", "-1", "-1", "-1", "-1"};
    std::vector<std::string> test_user = s1->get_one_row_id_user("user_information", 100);
    ASSERT_EQ(test_user, expected);
    d1->delete_from_table("user_information", "user_id", 100);
}
/*
 * Test case for testing the insert_new_nap_spot function of the Insert class
 * Verifies that a new nap spot is correctly inserted into the new_nap_spots table
 */
TEST_F(InsertTest, InsertNewNapSpotTest) {
    i1->insert_new_nap_spot("new_nap_spots", 200, "'test_spot'", "'attr1'", "'attr2'", "'attr3'", "'image'");
    std::vector<std::string> expected = {"200", "test_spot", "'attr1'", "'attr2'", "'attr3'", "'image'", "Open", "0"};
    std::vector<std::string> test_new_nap_spot = s1->get_one_row_id("new_nap_spots", 200);
    ASSERT_EQ(test_new_nap_spot, expected);
    d1->delete_from_table("new_nap_spots", "id", 200);
}
/*
 * Test case for testing the insert_nap_spot function of the Insert class
 * Verifies that a nap spot is correctly inserted into the nap_spots table
 */
TEST_F(InsertTest, InsertNapSpotTest) {
    i1->insert_nap_spot("nap_spots", 300, "'test_spot'", "'attr1'", "'attr2'", "'attr3'", "'image'");
    std::vector<std::string> expected = {"300", "'test_spot'", "'attr1'", "'attr2'", "'attr3'", "'image'", "Open"};
    std::vector<std::string> test_nap_spot = s1->get_one_row_id("nap_spots", 300);
    ASSERT_EQ(test_nap_spot, expected);
    d1->delete_from_table("nap_spots", "id", 300);
}
/*
 * Test fixture class for testing the Delete class
 */
class DeleteTest : public ::testing::Test {
protected:
    /*
    * SetUp function initializes the Insert, Delete, and Select objects
    * Inserts test data into the user_information, nap_spots, and new_nap_spots tables
    */
    virtual void SetUp() {
        i1 = new Insert;
        d1 = new Delete;
        s1 = new Select;

        // Insert test data
        i1->insert_user(100, "TestUser", "TestPassword", 0);
        i1->insert_nap_spot("nap_spots", 200, "'test_spot'", "'attr1'", "'attr2'", "'attr3'", "'image'");
        i1->insert_new_nap_spot("new_nap_spots", 300, "'new_test_spot'", "'new_attr1'", "'new_attr2'", "'new_attr3'", "'new_image'");
    }
    /*
    * TearDown function cleans up the objects
     */
    virtual void TearDown() {
        delete i1;
        delete d1;
        delete s1;
    }

    Insert* i1; // Pointer to the Insert object
    Delete* d1; // Pointer to the Delete object
    Select* s1; // Pointer to the Select object
};
/*
 * Test case for testing the delete_from_table function of the Delete class
 * Verifies that a user is correctly deleted from the user_information table
 */
TEST_F(DeleteTest, DeleteUserTest) {
    d1->delete_from_table("user_information", "id",100);
    ASSERT_EQ(s1->get_row_count("user_information"), 3); // Assuming 2 other users in the database
}
/*
 * Test case for testing the delete_from_table function of the Delete class
 * Verifies that a nap spot is correctly deleted from the nap_spots table
 */
TEST_F(DeleteTest, DeleteNapSpotTest) {
    d1->delete_from_table("nap_spots", "id",200);
    ASSERT_EQ(s1->get_row_count("nap_spots"), 9); // Assuming 5 other nap spots in the database
}
/*
 * Test case for testing the delete_from_table function of the Delete class
 * Verifies that a new nap spot is correctly deleted from the new_nap_spots table
 */
TEST_F(DeleteTest, DeleteNewNapSpotTest) {
    d1->delete_from_table("new_nap_spots", "id",300);
    ASSERT_EQ(s1->get_row_count("new_nap_spots"), 0); // Assuming no other new nap spots in the database
}
//main argument function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
