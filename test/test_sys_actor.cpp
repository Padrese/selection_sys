/**
 * @file test_sys_actor.cpp
 * @author alan
 * @brief 
 * @date 2024-03-30
 * 
 * @copyright Copyright (c) 2024
 * 
*/

#include <iostream>

#include <gtest/gtest.h>
#include "../include/SystemActor/SystemActor.hpp"


/**
 * @brief Tests number of preferences.
 * 
 */
TEST(TestActor, ActorNumberOfPreferences){
    SystemActor actor;
    Preference preference_1("Harvard");
    actor.add_preference(1, preference_1);
    Preference preference_2("Yale");
    actor.add_preference(2, preference_2);
    Preference preference_3("New York University");
    actor.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    EXPECT_EQ(actor.get_nb_preferences(), 3);
}

/**
 * @brief Tests adding and getting a preference.
 * 
 */
TEST(Testactor, ActorPreferenceAddGetTrue){
    SystemActor actor;
    Preference preference("Harvard");
    actor.add_preference(1, preference);
    EXPECT_EQ(actor.get_preference(1).get_training_name(), "Harvard");
}

/**
 * @brief Tests order update in list of preferences.
 * 
 */
TEST(Testactor, ActorPreferenceAddandCheckOrder){
    SystemActor actor;

    Preference preference_1("Harvard");
    actor.add_preference(1, preference_1);
    Preference preference_2("Yale");
    actor.add_preference(2, preference_2);
    Preference preference_3("New York University");
    actor.add_preference(3, preference_3);
    Preference preference_fr("Grenoble INP - ENSIMAG");
    actor.add_preference(2, preference_fr);
    EXPECT_EQ(actor.get_preference(2).get_training_name(), "Grenoble INP - ENSIMAG");
    EXPECT_EQ(actor.get_preference(3).get_training_name(), "Yale");
    EXPECT_EQ(actor.get_preference(4).get_training_name(), "New York University");
}

/**
 * @brief Tests a wrong added preference order, above the updated
 * size of the preferences list.
 *
 */
TEST(Testactor, ActorAddPreferenceWrongOversize){
    SystemActor actor;
    Preference preference("Harvard");
    EXPECT_ANY_THROW(actor.add_preference(2, preference));
}

/**
 * @brief Tests a wrong added preference negative order.
 *
 */
TEST(Testactor, ActorAddPreferenceWrongNegative){
    SystemActor actor;
    Preference preference("Harvard");
    EXPECT_ANY_THROW(actor.add_preference(-1, preference));
}

/**
 * @brief Tests removing a preference and check that it is not here anymore.
 */
TEST(Testactor, ActorRemovePreference){
    SystemActor actor;
    Preference preference("Harvard");
    actor.add_preference(1, preference);
    actor.remove_preference(1);
    EXPECT_ANY_THROW(actor.get_preference(1));
}

/**
 * @brief Tests removing all preferences.
 * 
 */
TEST(Testactor, ActorRemoveAllPreferences){
    SystemActor actor;
    Preference preference_1("Harvard");
    actor.add_preference(1, preference_1);
    Preference preference_2("Yale");
    actor.add_preference(2, preference_2);
    Preference preference_3("New York University");
    actor.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    actor.add_preference(4, preference_4);
    actor.remove_all_preferences();

    EXPECT_EQ(actor.get_nb_preferences(), 0);
}

/**
 * @brief Tests removing a preference in a preference list (not at the end).
 * If preference k has been removed and k is not the size of the list, 
 * preference order indexes k' for k' >= k should be 
 * adapted to the new context.
 */
TEST(Testactor, ActorPreferenceRemoveandCheckOrderMiddle){
    SystemActor actor;
    Preference preference_1("Harvard");
    actor.add_preference(1, preference_1);
    Preference preference_2("Yale");
    actor.add_preference(2, preference_2);
    Preference preference_3("New York University");
    actor.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    actor.add_preference(4, preference_4);
    actor.remove_preference(2);
    EXPECT_EQ(actor.get_preference(2).get_training_name(), "New York University");
    EXPECT_EQ(actor.get_preference(3).get_training_name(), "Grenoble INP - ENSIMAG");
}

/**
 * @brief Tests removing a wrong preference order number above
 * the size of the preferences list.
 * 
 */
TEST(Testactor, ActorRemovePreferenceWrongOversize){
    SystemActor actor;
    Preference preference_1("Harvard");
    actor.add_preference(1, preference_1);
    Preference preference_2("Yale");
    actor.add_preference(2, preference_2);
    Preference preference_3("New York University");
    actor.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    actor.add_preference(4, preference_4);
    EXPECT_ANY_THROW(actor.remove_preference(5));  
}

/**
 * @brief Tests removing a wrong preference negative order number
 * 
 */
TEST(Testactor, ActorRemovePreferenceWrongNegative){
    SystemActor actor;
    Preference preference_1("Harvard");
    actor.add_preference(1, preference_1);
    Preference preference_2("Yale");
    actor.add_preference(2, preference_2);
    Preference preference_3("New York University");
    actor.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    actor.add_preference(4, preference_4);
    EXPECT_ANY_THROW(actor.remove_preference(-1));  
}

/**
 * @brief Tests removing a preference in a preference list (at the end).
 * If the last preference is removed, we do not touch the preference order.
 */
TEST(Testactor, ActorPreferenceRemoveandCheckOrderEnd){
    SystemActor actor;
    Preference preference_1("Harvard");
    actor.add_preference(1, preference_1);
    Preference preference_2("Yale");
    actor.add_preference(2, preference_2);
    Preference preference_3("New York University");
    actor.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    actor.add_preference(4, preference_4);
    actor.remove_preference(4);
    EXPECT_EQ(actor.get_preference(1).get_training_name(), "Harvard");
    EXPECT_EQ(actor.get_preference(2).get_training_name(), "Yale");
    EXPECT_EQ(actor.get_preference(3).get_training_name(), "New York University");
}

/**
 * @brief Tests switching preferences.
 * 
 */
TEST(Testactor, ActorSwitchPreferences){
    SystemActor actor;
    Preference preference_1("Harvard");
    actor.add_preference(1, preference_1);
    Preference preference_2("Yale");
    actor.add_preference(2, preference_2);
    Preference preference_3("New York University");
    actor.add_preference(3, preference_3);
    Preference preference_4("Grenoble INP - ENSIMAG");
    actor.add_preference(4, preference_4);
    actor.switch_preferences(2,4);
    EXPECT_EQ(actor.get_preference(2).get_training_name(), "Grenoble INP - ENSIMAG");
    EXPECT_EQ(actor.get_preference(4).get_training_name(), "Yale");
}
