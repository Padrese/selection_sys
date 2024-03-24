#include "../../include/Training/Training.hpp"


Training::Training(string training_name, string theme, string location, int ranking){
    this->training_name = training_name;
    this->theme = theme;
    this->location = location;
    this->ranking = ranking;
    this->has_student = false;
}

Training::~Training() {};

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

Student Training::get_preference(int order_preference) const {
    if (preferences.count(order_preference) == 0){
        perror("Preference key doesn't exist in preferences map");
        return;
    }
    return preferences.at(order_preference);
}

map<int, Student> Training::get_preferences() const{
    return preferences;
}

void Training::set_preference(int order_preference, Student student){
    preferences.insert({order_preference, student});
}

void Training::remove_preference(int order_preference){
    preferences.erase(order_preference);
}

void Training::switch_preferences(int order_pref_1, int order_pref_2){
    //TODO
}

void Training::remove_all_preferences(){
    preferences.clear();
}