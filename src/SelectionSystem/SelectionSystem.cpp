#include "../../include/SelectionSystem/SelectionSystem.hpp"
#include <iostream>
using namespace std;

SelectionSystem::SelectionSystem(string system_name){
    this->system_name = system_name;
}

SelectionSystem::~SelectionSystem(){}

map<string, long> SelectionSystem::gale_shapley() const{

    map<string, long> results;
    map<long, Student> copy_students = students; //Copy for updating results on students

    try{
        if (students.size() != trainings.size()){
            throw invalid_argument("Gale-Shapley only works on same-size sets");
        }
    }
    catch (string &e){
        cerr << "Gale-Shapley only works on same-size sets" << endl;
        return results;
    }


    //At the beginning, no one is assigned to a couple
    bool all_assigned;
    Student current_student;

    while (true){
        all_assigned = true;

        for (auto &student: copy_students){
            current_student = student.second;
            if (current_student.get_has_training() == false){
                all_assigned = false;
                break;
            }
        }

        if (all_assigned == true){ 
            break; //loop exit when everyone is assigned
        }

        else {
            //Find the most preferred training for the student
            Training most_preferred_training = trainings.at(current_student.get_preference(1).get_training_name());

            //Student and training form a couple if the training isn't already assigned to a student
            if (most_preferred_training.get_has_student() == false){
                most_preferred_training.set_has_student(true);
                current_student.set_has_training(true); 
                copy_students[current_student.get_id()] = current_student; //Update status of student in students map
                results[most_preferred_training.get_name()] = current_student.get_id();
            }

            //Otherwise, there exists another student preferred by the training 
            else {
                Student most_preferred_student = students.at(most_preferred_training.get_preference(1).get_student_id());
                Student actual_preferred_student = results.at(most_preferred_training.get_name());

                //Breaking the old couple here, if there is an equality, do nothing
                if (most_preferred_student.get_id() != actual_preferred_student.get_id()){
                    actual_preferred_student.set_has_training(false);
                    most_preferred_student.set_has_training(true);
                    copy_students[actual_preferred_student.get_id()] = actual_preferred_student; //Update status of student in students map
                    copy_students[most_preferred_student.get_id()] = most_preferred_student;
                    results[most_preferred_training.get_name()] = most_preferred_student.get_id();
                }
            }
        }
    }

    //Display results
    cout << "Assigning results between students and trainings:" <<endl;
    for (auto &result : results){
        cout << "Training " << result.first << " assigned to student " << result.second << endl;
    }
    
    return results;
}

string SelectionSystem::get_system_name() const{
    return system_name;
}

map<long,Student> SelectionSystem::get_students() const{
    return students;
}
map<string,Training> SelectionSystem::get_trainings() const{
    return trainings;
}

void SelectionSystem::add_student(Student student){
    this->students.insert({student.get_id(), student});
}

void SelectionSystem::add_training(Training training){
    this->trainings.insert({training.get_name(), training});
}

Student SelectionSystem::get_student(long student_id) const{
    return students.at(student_id);
}

Training SelectionSystem::get_training(string training_name) const{
    return trainings.at(training_name);
}

void SelectionSystem::clear_all(){
    this->students.clear();
    this->trainings.clear();
}