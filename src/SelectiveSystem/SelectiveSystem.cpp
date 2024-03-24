#include "../../include/SelectiveSystem/SelectiveSystem.hpp"

SelectiveSystem::SelectiveSystem(string system_name){
    this->system_name = system_name;
}

SelectiveSystem::~SelectiveSystem(){}

map<string, Couple> SelectiveSystem::gale_shapley() const{

    if (students.size() != trainings.size()){
        perror("Gale-Shapley only works on same-size sets \n");
        return;
    }

    map<string, Couple> results;

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
            all_assigned == true; //Everyone is assigned
        }
        else {
            //Find the most preferred training for the student
            Training most_preferred_training = current_student.get_preference(1);

            //Student and training form a couple if the training isn't already assigned to a student
            if (most_preferred_training.get_has_student() == false){
                most_preferred_training.set_has_student(true);
                current_student.set_has_training(true);
                Couple student_training_couple = Couple(current_student, most_preferred_training);
                results.insert({most_preferred_training.get_name(), student_training_couple});
            }

            //Otherwise, there exists another student preferred by the training 
            else {
                Student most_preferred_student = most_preferred_training.get_preference(1);
                Student actual_preferred_student = results.at(most_preferred_training.get_name()).get_student();

                //Breaking the old couple here, if there is an equality, do nothing
                if (most_preferred_student.get_id() != actual_preferred_student.get_id()){
                    results.erase(most_preferred_training.get_name());
                    actual_preferred_student.set_has_training(false);
                    most_preferred_student.set_has_training(true);
                    Couple student_training_couple = Couple(most_preferred_student, most_preferred_training);
                    results.insert({most_preferred_training.get_name(), student_training_couple});
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

void SelectiveSystem::clear_all(){
    this->students.clear();
    this->trainings.clear();
}