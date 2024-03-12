#include <iostream>
#include "../../include/Student/Student.hpp"

using namespace std;

Student::Student(long id){
    this->id = id;
}

Student::~Student(){}

long Student::get_id() const{
    return this->id;
}

Behavior Student::get_behavior() const{
    return this->behavior;
}

int Student::get_grade(string id_grade) const{
    if (this->grades.count(id_grade) > 0){
        auto it = (this->grades).find(id_grade);
        return it->second;
    }
    else {
        return -1;
    }
}

map<string, Training> Student::get_preferences() const{
    return this->preferences;
}

void Student::set_behavior(Behavior behavior){
    this->behavior = behavior;
}

void Student::push_grade(string id_grade, int grade){
    this->grades.insert({id_grade, grade});
}

void Student::remove_grade(string id_grade){
    this->grades.erase(id_grade);
}

void Student::set_preference(Training training){
    this->preferences.insert({training.get_name(), training});
}

void Student::remove_preference(Training training){
    this->preferences.erase(training.get_name());
}

void Student::remove_all_preferences(){
    this->preferences.clear();
}



