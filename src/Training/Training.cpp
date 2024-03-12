#include "../../include/Training/Training.hpp"


Training::Training(string training_name, string theme, string location, int ranking){
    this->training_name = training_name;
    this->theme = theme;
    this->location = location;
    this->ranking = ranking;
}

Training::~Training() {};

string Training::get_name() const{
    return this->training_name;
}

string Training::get_theme() const{
    return this->theme;
}

string Training::get_location() const{
    return this->location;
}

int Training::get_ranking() const{
    return this->ranking;
}

void Training::set_ranking(int ranking){
    this->ranking = ranking;
}