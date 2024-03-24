#include "../../include/SelectiveSystem/SelectiveSystem.hpp"

SelectiveSystem::SelectiveSystem(string system_name){
    this->system_name = system_name;
}

SelectiveSystem::~SelectiveSystem(){}

map<long, Couple> SelectiveSystem::gale_shapley() const{

    if (students.size() != trainings.size()){
        perror("Gale-Shapley only works on same-size sets \n");
        return;
    }

    map<long, Couple> results;

    //At the beginning, no one is assigned to a couple
    bool all_assigned = false;
    Student current_student;
    int SIZE = students.size();

    while (all_assigned == false){

        for (int i = 0; i < SIZE; ++i){
            if (students[i].get_has_training() == false){
                current_student = students[i];
                break;
            }
            if (i == SIZE-1){
                all_assigned == true; //Everyone is assigned
            }
        }

        if (all_assigned == false){
            //Find the most preferred training for the student
            Training most_preferred_training = current_student.get_preference(1);

            //Student and training form a couple if the training isn't already assigned to a student
            if (most_preferred_training.get_has_student() == false){
                most_preferred_training.set_has_student(true);
                current_student.set_has_training(true);
                Couple student_training_couple = Couple(current_student, most_preferred_training);
                results.insert({current_student.get_id(), student_training_couple});
            }

            //Otherwise, there exists another student preferred by the training 
            else {
                Student most_preferred_student = most_preferred_training.get_preference(1);
                // To get the more preferred student: look at the results table as there should be an existing couple
                
            }
        }
    }
    
    return results;
}

string SelectiveSystem::get_system_name() const{
    return system_name;
}

vector<Student> SelectiveSystem::get_students() const{
    return students;
}
vector<Training> SelectiveSystem::get_trainings() const{
    return trainings;
}

void SelectiveSystem::add_student(Student student){
    this->students.push_back(student);
}

void SelectiveSystem::add_training(Training training){
    this->trainings.push_back(training);
}

void SelectiveSystem::clear_all(){
    this->students.clear();
    this->trainings.clear();
}

