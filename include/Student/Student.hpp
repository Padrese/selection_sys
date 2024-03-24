#pragma once

#ifndef DEF_STUDENT
#define DEF_STUDENT

#include <unordered_map>
#include <map>

#include "../Behavior/Behavior.hpp"
#include "../Preference/Preference.hpp"

using namespace std;

class Student{
    private:
    long id;
    Behavior behavior;
    unordered_map<string, int> grades;
    map<int, Preference> preferences;
    bool has_training;

    public:

    //Constructor
    Student();
    Student(long id);

    //Destructor
    ~Student();

    bool operator==(Student &other) const;

    long get_id() const;
    Behavior get_behavior() const;
    void add_grade(string id_grade, int grade);
    void remove_grade(string id_grade);
    void clear_all_grades();
    int get_grade(string id_grade) const;
    Preference get_preference(int order_preference) const;
    map<int, Preference> get_preferences() const;
    void set_behavior(Behavior behavior);
    void push_grade(string id_grade, int grade);
    void add_preference(int order_preference, Preference preference);
    void remove_preference(int order_preference);
    void switch_preferences(int order_pref_1, int order_pref_2);
    void remove_all_preferences();
    bool get_has_training() const;
    void set_has_training(bool status);
};

#endif