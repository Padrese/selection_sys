#include <iostream>
#include "../../include/Student/Student.hpp"

using namespace std;

Student::Student(long id){
    this->id = id;
    this->has_training = false;
}

Student::~Student(){}

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

Preference Student::get_preference(int order_preference) const {
    if (preferences.count(order_preference) == 0){
        perror("Preference key doesn't exist in preferences map");
        return (Preference) nullptr;
    }
    return preferences.at(order_preference);
}

map<int, Preference> Student::get_preferences() const{
    return preferences;
}

void Student::set_behavior(Behavior behavior){
    this->behavior = behavior;
}

void Student::push_grade(string id_grade, int grade){
    grades.insert({id_grade, grade});
}

void Student::add_preference(int order_preference, Preference preference){
    int initial_map_size = preferences.size();

    //Check index of preference
    if (order_preference > initial_map_size+1 || order_preference < 0){
        perror("Index error: Order preference doesn't match the logical sequence already in place");
        return;
    }

    /*We adapt the index of preferences when add a preference
    only if we do not add the last position preference.
    We cannot do parallel programming to move key indexes as
    keys are const elements.
    */

    else if (order_preference < initial_map_size+1){
        preferences[initial_map_size+1] = preferences[initial_map_size];
            for (map<int, Preference>::reverse_iterator it = preferences.rbegin(); it != preferences.rend(); ++it){
                int key = it->first;
                if (key > order_preference){
                    preferences[key] = preferences[next(it, 1)->first]; 
                }
            }
    }

    /*Finally, we create the key-value pair where the value linked to the removed key
    matches the new preference order.*/
    preferences[order_preference] = preference;

}

void Student::remove_preference(int order_preference){
    int initial_map_size = preferences.size();
    if (order_preference > initial_map_size || order_preference < 0){
        perror("Index error: Order preference doesn't match the logical sequence already in place");
        return;     
    }
    preferences.erase(order_preference);

    /*We adapt the index of preferences when removing a preference
    only if we do not remove the last position preference.
    We cannot do parallel programming to move key indexes as
    keys are const elements.
    */
    if (order_preference != initial_map_size){
            Preference removed_key_preference = preferences[order_preference+1];
            for (map<int, Preference>::iterator it = preferences.begin(); it != preferences.end(); ++it){
                int key = it->first;

                /*Second condition is to ensure next points to something relevant in the map.
                If we're at the end, we need to remove the last key-value pair.
                */
                if (key > order_preference){
                    if (key != preferences.size()+1){
                    preferences[key] = preferences[next(it, 1)->first]; 
                    }
                    else {
                        preferences.erase(key);
                    }
                }
            }

            /*Finally, we create the key-value pair where the value linked to the removed key
            matches the new preference order.*/
            preferences[order_preference] = removed_key_preference;
    }
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



