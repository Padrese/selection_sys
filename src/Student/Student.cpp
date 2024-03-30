#include <iostream>
#include "../../include/Student/Student.hpp"

using namespace std;

Student::Student(){};

Student::~Student(){};

Student::Student(long id){
    this->id = id;
    this->has_training = false;
}

bool Student::operator==(Student &other) const{
    return (this->id == other.id);
}

long Student::get_id() const{
    return id;
}

Behavior Student::get_behavior() const{
    return behavior;
}

void Student::add_grade(string id_grade, int grade){
    this->grades.insert({id_grade, grade});
}

void Student::remove_grade(string id_grade){
    this->grades.erase(id_grade);
}

void Student::clear_all_grades(){
    this->grades.clear();
}

unordered_map<string, int> Student::get_grades() const{
    return grades;
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

void Student::set_behavior(Behavior behavior){
    this->behavior = behavior;
}

void Student::push_grade(string id_grade, int grade){
    grades.insert({id_grade, grade});
}

bool Student::get_has_training() const {
    return has_training;
}

void Student::set_has_training(bool status){
    this->has_training = status;
}
