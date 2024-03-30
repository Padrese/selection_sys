/**
 * @file test_selection_system.cpp
 * @author alan
 * @brief 
 * @date 2024-03-30
 * 
 * @copyright Copyright (c) 2024
 * 
*/

#include <iostream>

#include <gtest/gtest.h>
#include "../include/SelectionSystem/SelectionSystem.hpp"

/**
 * @brief Tests the instantiation of a SelectionSystem instance.
 * 
 */
TEST(TestSelectionSystem, SelectionSystemInstantiation){
    SelectionSystem sys("Parcoursup");
    EXPECT_EQ(sys.get_system_name(), "Parcoursup");
}

/**
 * @brief Tests adding students and trainings to the selection system.
 * 
 */
TEST(TestSelectionSystem, SelectionSystemAddGet){
    SelectionSystem sys("Parcoursup");
    Student student(1234);
    sys.add_student(student);
    Training training("Yale", "Physics", "America", 2);
    sys.add_training(training);
    EXPECT_EQ(sys.get_student(1234).get_id(), 1234);
    EXPECT_EQ(sys.get_training("Yale").get_name(), "Yale");
}

/**
 * @brief GS algorithm test with three students and three trainings.
 * Students: 1,2,3  Trainings: X,Y,Z
 * 1 : YXZ, 2 : ZYX, 3 : XZY, X : 213, Y : 321, Z: 132 
 * Expected return: 1Y, 2Z, 3X
 */
TEST(TestSelectionSystem, SelectionSystemGSThree){
    SelectionSystem sys("Parcoursup");

    Student stud_one(1);
    Student stud_two(2);
    Student stud_three(3);

    Training train_x("X", "", "", 124);
    Training train_y("Y", "", "", 241);
    Training train_z("Z", "", "", 14);

    Preference pref_one(1);
    Preference pref_two(2);
    Preference pref_three(3);
    Preference pref_x("X");
    Preference pref_y("Y");
    Preference pref_z("Z");

    //Preferences of 1
    stud_one.add_preference(1,pref_y);
    stud_one.add_preference(2,pref_x);
    stud_one.add_preference(3,pref_z);

    //Preferences of 2
    stud_two.add_preference(1,pref_z);
    stud_two.add_preference(2,pref_y);
    stud_two.add_preference(3,pref_x);

    //Preferences of 3
    stud_three.add_preference(1,pref_x);
    stud_three.add_preference(2,pref_z);
    stud_three.add_preference(3,pref_y);

    //Preferences of X
    train_x.add_preference(1,2);
    train_x.add_preference(2,1);
    train_x.add_preference(3,3);

    //Preferences of Y
    train_y.add_preference(1,3);
    train_y.add_preference(2,2);
    train_y.add_preference(3,1);

    //Preferences of Z
    train_z.add_preference(1,1);
    train_z.add_preference(2,3);
    train_z.add_preference(3,2);

    sys.add_student(stud_one);
    sys.add_student(stud_two);
    sys.add_student(stud_three);
    sys.add_training(train_x);
    sys.add_training(train_y);
    sys.add_training(train_z);

    map<string, long> results = sys.gale_shapley();

    EXPECT_EQ(results["X"], 3);
    EXPECT_EQ(results["Y"], 1);
    EXPECT_EQ(results["Z"], 2);

}


