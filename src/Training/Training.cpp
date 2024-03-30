#include "../../include/Training/Training.hpp"

Training::Training(){};

Training::~Training(){};

Training::Training(string training_name, string theme, string location, int ranking){
    this->training_name = training_name;
    this->theme = theme;
    this->location = location;
    this->ranking = ranking;
    this->has_student = false;
}

string Training::get_name() const{
    return training_name;
}

string Training::get_theme() const{
    return theme;
}

string Training::get_location() const{
    return location;
}

int Training::get_ranking() const{
    return ranking;
}

void Training::set_ranking(int ranking){
    this->ranking = ranking;
}

bool Training::get_has_student() const{
    return has_student;
}

void Training::set_has_student(bool status){
    this->has_student = status;
}