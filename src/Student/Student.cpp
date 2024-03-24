#include <iostream>
#include "../../include/Student/Student.hpp"

using namespace std;

Student::Student(long id){
    this->id = id;
    this->has_training = false;
}

Student::~Student(){}

long Student::get_id() const{
    return id;
}

Behavior Student::get_behavior() const{
    return behavior;
}

int Student::get_grade(string id_grade) const{
    if (grades.count(id_grade) > 0){
        auto it = grades.find(id_grade);
        return it->second;
    }
    else {
        return -1;
    }
}

Training Student::get_preference(int order_preference) const {
    if (preferences.count(order_preference) == 0){
        perror("Preference key doesn't exist in preferences map");
        return;
    }
    return preferences.at(order_preference);
}

map<int, Training> Student::get_preferences() const{
    return preferences;
}

void Student::set_behavior(Behavior behavior){
    this->behavior = behavior;
}

void Student::push_grade(string id_grade, int grade){
    grades.insert({id_grade, grade});
}

void Student::remove_grade(string id_grade){
    grades.erase(id_grade);
}

void Student::set_preference(int order_preference, Training training){
    preferences.insert({order_preference, training});
}

void Student::remove_preference(int order_preference){
    preferences.erase(order_preference);
}

void Student::switch_preferences(int order_pref_1, int order_pref_2){
    //TODO
}

void Student::remove_all_preferences(){
    preferences.clear();
}

bool Student::get_has_training() const {
    return has_training;
}

void Student::set_has_training(bool status){
    this->has_training = status;
}



