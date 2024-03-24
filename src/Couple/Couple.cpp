#include "../../include/Couple/Couple.hpp"

Couple::Couple(Student student, Training training){
    this->student = student;
    this->training = training;
}

Couple::~Couple(){}

Student Couple::get_student() const{
    return student;
}

Training Couple::get_training() const{
    return training;
}

void Couple::set_student(Student student){
    this->student = student;
}

void Couple::set_training(Training training){
    this->training = training;
}

