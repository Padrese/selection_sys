#pragma once

#ifndef DEF_STUDENT
#define DEF_STUDENT

#include <unordered_map>
#include <map>

#include "../Behavior/Behavior.hpp"
#include "../SystemActor/SystemActor.hpp"

using namespace std;

class Student : public SystemActor{
    private:
    long id;
    Behavior behavior;
    unordered_map<string, int> grades;
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
    unordered_map<string, int> get_grades() const;
    int get_grade(string id_grade) const;
    void set_behavior(Behavior behavior);
    void push_grade(string id_grade, int grade);
    bool get_has_training() const;
    void set_has_training(bool status);
};

#endif