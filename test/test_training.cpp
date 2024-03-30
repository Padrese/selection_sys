/**
 * @file test_training.cpp
 * @author alan
 * @brief 
 * @date 2024-03-30
 * 
 * @copyright Copyright (c) 2024
 * 
*/

#include <iostream>

#include <gtest/gtest.h>
#include "../include/Training/Training.hpp"

/**
 * @brief Tests initialization of a Training instance.
 * 
 */
TEST(TestTraining, TrainingInstantiation){
    Training training("Aalto University", "Math", "Espoo, Finland", 1);
    EXPECT_EQ(training.get_name(), "Aalto University");
    EXPECT_EQ(training.get_theme(), "Math");
    EXPECT_EQ(training.get_location(), "Espoo, Finland");
    EXPECT_EQ(training.get_ranking(), 1);
    EXPECT_EQ(training.get_has_student(), false);
}

/**
 * @brief Tests setters for a Training instance.
 * 
 */
TEST(TestTraining, TrainingSetters){
    Training training("Aalto University", "Math", "Espoo, Finland", 1);
    training.set_ranking(2);
    training.set_has_student(true);
    EXPECT_EQ(training.get_ranking(), 2);
    EXPECT_EQ(training.get_has_student(), true);
}



