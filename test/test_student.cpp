#include <iostream>

#include <gtest/gtest.h>
#include "../include/Student/Student.hpp"

/**
 * @brief Tests the instantiation of a Student.
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
TEST(TestStudent, StudentGradeTrue){
    Student student(1234);
    student.add_grade("0001", 16);
    EXPECT_EQ(student.get_grade("0001"), 16);
}

/**
 * @brief Tests removing a student's grade and checking 
 * that it is not present anymore.
 */
TEST(TestStudent, StudentGradeFalse){
    Student student(1234);
    student.add_grade("0001", 16);   
    student.add_grade("0002", 6);   
    student.add_grade("0003", 11);
    student.remove_grade("0002");   
    EXPECT_EQ(student.get_grade("0002"),-1);
}