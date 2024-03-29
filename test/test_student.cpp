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
 * @brief Tests number of preferences.
 * 
 */
TEST(TestStudent, StudentNumberOfPreferences){
    Student student(1234);
    Preference preference_1("Harvard");
    student.add_preference(1, preference_1);
    Preference preference_2("Yale");
    student.add_preference(2, preference_2);
    Preference preference_3("New York University");
    student.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    EXPECT_EQ(student.get_nb_preferences(), 3);
}

/**
 * @brief Tests adding and getting a preference.
 * 
 */
TEST(TestStudent, StudentPreferenceAddGetTrue){
    Student student(1234);
    Preference preference("Harvard");
    student.add_preference(1, preference);
    EXPECT_EQ(student.get_preference(1).get_training_name(), "Harvard");
}

/**
 * @brief Tests order update in list of preferences.
 * 
 */
TEST(TestStudent, StudentPreferenceAddandCheckOrder){
    Student student(1234);

    Preference preference_1("Harvard");
    student.add_preference(1, preference_1);
    Preference preference_2("Yale");
    student.add_preference(2, preference_2);
    Preference preference_3("New York University");
    student.add_preference(3, preference_3);
    Preference preference_fr("Grenoble INP - ENSIMAG");
    student.add_preference(2, preference_fr);
    EXPECT_EQ(student.get_preference(2).get_training_name(), "Grenoble INP - ENSIMAG");
    EXPECT_EQ(student.get_preference(3).get_training_name(), "Yale");
    EXPECT_EQ(student.get_preference(4).get_training_name(), "New York University");
}

/**
 * @brief Tests a wrong added preference order, above the updated
 * size of the preferences list.
 *
 */
TEST(TestStudent, StudentAddPreferenceWrongOversize){
    Student student(1234);
    Preference preference("Harvard");
    EXPECT_ANY_THROW(student.add_preference(2, preference));
}

/**
 * @brief Tests a wrong added preference negative order.
 *
 */
TEST(TestStudent, StudentAddPreferenceWrongNegative){
    Student student(1234);
    Preference preference("Harvard");
    EXPECT_ANY_THROW(student.add_preference(-1, preference));
}

/**
 * @brief Tests removing a preference and check that it is not here anymore.
 */
TEST(TestStudent, StudentRemovePreference){
    Student student(1234);
    Preference preference("Harvard");
    student.add_preference(1, preference);
    student.remove_preference(1);
    EXPECT_ANY_THROW(student.get_preference(1));
}

/**
 * @brief Tests removing all preferences.
 * 
 */
TEST(TestStudent, StudentRemoveAllPreferences){
    Student student(1234);
    Preference preference_1("Harvard");
    student.add_preference(1, preference_1);
    Preference preference_2("Yale");
    student.add_preference(2, preference_2);
    Preference preference_3("New York University");
    student.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    student.add_preference(4, preference_4);
    student.remove_all_preferences();

    EXPECT_EQ(student.get_nb_preferences(), 0);
}

/**
 * @brief Tests removing a preference in a preference list (not at the end).
 * If preference k has been removed and k is not the size of the list, 
 * preference order indexes k' for k' >= k should be 
 * adapted to the new context.
 */
TEST(TestStudent, StudentPreferenceRemoveandCheckOrderMiddle){
    Student student(1234);
    Preference preference_1("Harvard");
    student.add_preference(1, preference_1);
    Preference preference_2("Yale");
    student.add_preference(2, preference_2);
    Preference preference_3("New York University");
    student.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    student.add_preference(4, preference_4);
    student.remove_preference(2);
    EXPECT_EQ(student.get_preference(2).get_training_name(), "New York University");
    EXPECT_EQ(student.get_preference(3).get_training_name(), "Grenoble INP - ENSIMAG");
}

/**
 * @brief Tests removing a wrong preference order number above
 * the size of the preferences list.
 * 
 */
TEST(TestStudent, StudentRemovePreferenceWrongOversize){
    Student student(1234);
    Preference preference_1("Harvard");
    student.add_preference(1, preference_1);
    Preference preference_2("Yale");
    student.add_preference(2, preference_2);
    Preference preference_3("New York University");
    student.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    student.add_preference(4, preference_4);
    EXPECT_ANY_THROW(student.remove_preference(5));  
}

/**
 * @brief Tests removing a wrong preference negative order number
 * 
 */
TEST(TestStudent, StudentRemovePreferenceWrongNegative){
    Student student(1234);
    Preference preference_1("Harvard");
    student.add_preference(1, preference_1);
    Preference preference_2("Yale");
    student.add_preference(2, preference_2);
    Preference preference_3("New York University");
    student.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    student.add_preference(4, preference_4);
    EXPECT_ANY_THROW(student.remove_preference(-1));  
}

/**
 * @brief Tests removing a preference in a preference list (at the end).
 * If the last preference is removed, we do not touch the preference order.
 */
TEST(TestStudent, StudentPreferenceRemoveandCheckOrderEnd){
    Student student(1234);
    Preference preference_1("Harvard");
    student.add_preference(1, preference_1);
    Preference preference_2("Yale");
    student.add_preference(2, preference_2);
    Preference preference_3("New York University");
    student.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    student.add_preference(4, preference_4);
    student.remove_preference(4);
    EXPECT_EQ(student.get_preference(1).get_training_name(), "Harvard");
    EXPECT_EQ(student.get_preference(2).get_training_name(), "Yale");
    EXPECT_EQ(student.get_preference(3).get_training_name(), "New York University");
}

/**
 * @brief Tests switching preferences.
 * 
 */
TEST(TestStudent, StudentSwitchPreferences){
    Student student(1234);
    Preference preference_1("Harvard");
    student.add_preference(1, preference_1);
    Preference preference_2("Yale");
    student.add_preference(2, preference_2);
    Preference preference_3("New York University");
    student.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    student.add_preference(4, preference_4);
    student.switch_preferences(2,4);
    EXPECT_EQ(student.get_preference(2).get_training_name(), "Grenoble INP - ENSIMAG");
    EXPECT_EQ(student.get_preference(4).get_training_name(), "Yale");
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

