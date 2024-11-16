/**
 * @file test_preference.cpp
 * @author alan
 * @brief
 * @date 2024-03-30
 * 
 * @copyright Copyright (c) 2024
 * 
*/

#include <iostream>

#include <gtest/gtest.h>
#include "../include/Preference/Preference.hpp"

/**
 * @brief Tests initialization of a Preference instance (student).
 * 
 */
TEST(TestPreference, PreferenceInstantiationStudent){
    Preference preference(1234);
    EXPECT_EQ(preference.get_student_id(), 1234);
    EXPECT_EQ(preference.get_training_name(), "");
}

/**
 * @brief Tests initialization of a Preference instance (training).
 * 
 */
TEST(TestPreference, PreferenceInstantiationTraining){
    Preference preference("Aalto University");
    EXPECT_EQ(preference.get_student_id(), -1);
    EXPECT_EQ(preference.get_training_name(), "Aalto University");
}

/**
 * @brief Tests setters for a Preference instance.
 * 
 */
TEST(TestPreference, PreferenceSetters){
    Preference preference(1234);
    preference.set_student_id(4567);
    preference.set_training_name("Harvard");
    EXPECT_EQ(preference.get_student_id(), 4567);
    EXPECT_EQ(preference.get_training_name(), "Harvard");
}



