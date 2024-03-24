#include "../../include/Preference/Preference.hpp"

Preference::~Preference(){};

Preference::Preference(long student_id){
    this->student_id = student_id;
    this->training_name = "";
}

Preference::Preference(string training_name){
    this->student_id = -1;
    this->training_name = training_name;
}

long Preference::get_student_id() const{
    return student_id;
}

string Preference::get_training_name() const{
    return training_name;
}

void Preference::set_training_name(string training_name){
    this->training_name = training_name;
}

void Preference::set_student_id(long student_id){
    this->student_id = student_id;
}