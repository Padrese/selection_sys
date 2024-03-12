#include "../../include/SelectiveSystem/SelectiveSystem.hpp"

SelectiveSystem::SelectiveSystem(string system_name){
    this->system_name = system_name;
    vector<Student> students;
    vector<Training> trainings;
}

SelectiveSystem::~SelectiveSystem(){}

map<long, Couple> gale_shapley(){
    map<long, Couple> results;
    //TODO
    return results;
}

string SelectiveSystem::get_system_name() const{
    return this->system_name;
}

vector<Student> SelectiveSystem::get_students() const{
    return this->students;
}
vector<Training> SelectiveSystem::get_trainings() const{
    return this->trainings;
}

