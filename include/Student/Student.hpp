#ifndef DEF_STUDENT
#define DEF_STUDENT

#include <string>
#include <unordered_map>
#include <map>
using namespace std;

class Student{
    private:
    string name;
    Behavior behavior;
    unordered_map<string, int> grades;
    map<string, Training> preferences;

    public:
    string get_name();
    Behavior get_behavior();
    int get_grade(int grade);
    map<string, Training> get_preferences();
    void set_name(string name);
    void set_behavior(Behavior behavior);
    void push_grade(int grade);
    void remove_grade(int grade);
    void set_preference(Training training);
    void remove_preference(Training training);
    void remove_all_preferences();
        
};

#endif