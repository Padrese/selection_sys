#ifndef DEF_STUDENT
#define DEF_STUDENT

#include <unordered_map>
#include <map>

#include "../include/Training/Training.hpp"
#include "../include/Behavior/Behavior.hpp"

using namespace std;

class Student{
    private:
    long id;
    Behavior behavior;
    unordered_map<string, int> grades;
    map<int, Training> preferences;
    bool has_training;

    public:

    //Constructor
    Student();
    Student(long id);

    //Destructor
    ~Student();

    long get_id() const;
    Behavior get_behavior() const;
    int get_grade(string id_grade) const;
    Training get_preference(int order_preference) const;
    map<int, Training> get_preferences() const;
    void set_behavior(Behavior behavior);
    void push_grade(string id_grade, int grade);
    void remove_grade(string id_grade);
    void set_preference(int order_preference, Training training);
    void remove_preference(int order_preference);
    void switch_preferences(int order_pref_1, int order_pref_2);
    void remove_all_preferences();
    bool get_has_training() const;
    void set_has_training(bool status);
};

#endif