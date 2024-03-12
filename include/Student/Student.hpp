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
    map<string, Training> preferences;

    public:

    //Constructor
    Student(long id);

    //Destructor
    ~Student();

    long get_id() const;
    Behavior get_behavior() const;
    int get_grade(string id_grade) const;
    map<string, Training> get_preferences() const;
    void set_behavior(Behavior behavior);
    void push_grade(string id_grade, int grade);
    void remove_grade(string id_grade);
    void set_preference(Training training);
    void remove_preference(Training training);
    void remove_all_preferences();
        
};

#endif