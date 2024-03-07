#ifndef DEF_STUDENT
#define DEF_STUDENT

#include <string>
#include <unordered_map>
using namespace std;

class Student{
    private:
    string name;
    Behavior behavior;
    unordered_map<string, int> grades;
    unordered_map<Preference> preferences;

    public:
    string get_name();
    Behavior get_behavior();
    int get_grade(Grade grade);
    vector<Preferences> get_preferences();
    void set_name(string name);
    void set_behavior(Behavior behavior);
    void push_grade(Grade grade);
    void remove_grade(Grade grade);
    void set_preference(Preference preference);
    void remove_preference(Preference preference);
    void remove_all_preferences();
        
};

#endif