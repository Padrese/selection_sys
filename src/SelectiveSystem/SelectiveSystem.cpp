#include "../../include/SelectiveSystem/SelectiveSystem.hpp"

SelectiveSystem::SelectiveSystem(string system_name){
    this->system_name = system_name;
}

SelectiveSystem::~SelectiveSystem(){}

map<string, long> SelectiveSystem::gale_shapley() const{

    map<string, long> results;

    if (students.size() != trainings.size()){
        perror("Gale-Shapley only works on same-size sets \n");
        return results;
    }


    //At the beginning, no one is assigned to a couple
    bool all_assigned = false;
    Student current_student;
    bool has_broken;

    while (all_assigned == false){
        bool has_broken = false;

        for (const auto student: students){
            current_student = student.second;
            if (current_student.get_has_training() == false){
                has_broken = true;
                break;
            }
        }

        if (has_broken == false){
            all_assigned = true; //Everyone is assigned
        }
        else {
            //Find the most preferred training for the student
            Training most_preferred_training = trainings.at(current_student.get_preference(1).get_training_name());

            //Student and training form a couple if the training isn't already assigned to a student
            if (most_preferred_training.get_has_student() == false){
                most_preferred_training.set_has_student(true);
                current_student.set_has_training(true);  
                results.insert({most_preferred_training.get_name(), current_student.get_id()});
            }

            //Otherwise, there exists another student preferred by the training 
            else {
                Student most_preferred_student = students.at(most_preferred_training.get_preference(1).get_student_id());
                Student actual_preferred_student = results.at(most_preferred_training.get_name());

                //Breaking the old couple here, if there is an equality, do nothing
                if (most_preferred_student.get_id() != actual_preferred_student.get_id()){
                    results.erase(most_preferred_training.get_name());
                    actual_preferred_student.set_has_training(false);
                    most_preferred_student.set_has_training(true);
                    results.insert({most_preferred_training.get_name(),  most_preferred_student.get_id()});
                }
            }
        }
    }
    
    return results;
}

string SelectiveSystem::get_system_name() const{
    return system_name;
}

unordered_map<long,Student> SelectiveSystem::get_students() const{
    return students;
}
unordered_map<string,Training> SelectiveSystem::get_trainings() const{
    return trainings;
}

void SelectiveSystem::add_student(Student student){
    this->students.insert({student.get_id(), student});
}

void SelectiveSystem::add_training(Training training){
    this->trainings.insert({training.get_name(), training});
}

Student SelectiveSystem::get_student(long student_id) const{
    return students.at(student_id);
}

Training SelectiveSystem::get_training(string training_name) const{
    return trainings.at(training_name);
}

void SelectiveSystem::clear_all(){
    this->students.clear();
    this->trainings.clear();
}