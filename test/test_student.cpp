/**
 * @file test_student.cpp
 * @author alan
 * @brief 
 * @date 2024-03-30
 * 
 * @copyright Copyright (c) 2024
 * 
*/

#include <iostream>

#include <gtest/gtest.h>
#include "../include/Student/Student.hpp"

/**
 * @brief Tests the instantiation of a Student instance.
 */
TEST(TestStudent, StudentInstantiation){
    Student student(1234);
    EXPECT_EQ(student.get_id(), 1234);
    EXPECT_EQ(student.get_has_training(), false);
}

/**
 * @brief Tests the comparison operator (false test).
 * 
 */
TEST(TestStudent, StudentCompFalse){
    Student student_1(1234);
    Student student_2(5678);
    bool test_comp_student = (student_1 == student_2);
    EXPECT_EQ(test_comp_student, false);
}

/**
 * @brief Tests the comparison operator (true test).
 * 
 */
TEST(TestStudent, StudentCompTrue){
    Student student_1(1234);
    Student student_2(1234);
    bool test_comp_student = (student_1 == student_2);
    EXPECT_EQ(test_comp_student, true);
}

/**
 * @brief Tests adding and getting a student's grade.
 * 
 */
TEST(TestStudent, StudentGradeAddGetTrue){
    Student student(1234);
    student.add_grade("0001", 16);
    EXPECT_EQ(student.get_grade("0001"), 16);
}

/**
 * @brief Tests removing a student's grade and checking 
 * that it is not present anymore.
 */
TEST(TestStudent, StudentGradeAddGetFalse){
    Student student(1234);
    student.add_grade("0001", 16);   
    student.add_grade("0002", 6);   
    student.add_grade("0003", 11);
    student.remove_grade("0002");   
    EXPECT_EQ(student.get_grade("0002"),-1);
}

/**
 * @brief Tests clearing grades for a student.
 * 
 */
TEST(TestStudent, StudentGradeClear){
    Student student(1234);
    student.add_grade("0001", 16);   
    student.add_grade("0002", 6);   
    student.add_grade("0003", 11);
    student.clear_all_grades();
    EXPECT_EQ(student.get_grades().size(), 0);
}

/**
 * @brief Tests if a student has a training (false case).
 * 
 */
TEST(TestStudent, StudentHasTrainingFalse){
    Student student(1234);
    EXPECT_EQ(student.get_has_training(), false);
}

/**
 * @brief Tests if a student has a training (true case).
 * 
 */
TEST(TestStudent, StudentHasTrainingTrue){
    Student student(1234);
    student.set_has_training(true);
    EXPECT_EQ(student.get_has_training(), true);
}

