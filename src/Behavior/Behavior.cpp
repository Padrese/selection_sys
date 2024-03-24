#include "../../include/Behavior/Behavior.hpp"

Behavior::Behavior(){}

Behavior::~Behavior(){}

int Behavior::get_justified_absences(){
    return justified_absences;
}

int Behavior::get_unjustified_absences(){
    return unjustified_absences;
}

int Behavior::get_justified_delays(){
    return justified_delays;
}

int Behavior::get_unjustified_delays(){
    return unjustified_delays;
}

bool Behavior::get_personal_issues(){
    return personal_issues;
}

int Behavior::get_detention_hours(){
    return detention_hours;
}

int Behavior::get_reports(){
    return reports;
}

int Behavior::get_disciplinary_boards(){
    return disciplinary_boards;
}

void Behavior::set_justified_absences(int nb_justified_absences){
    this->justified_absences = nb_justified_absences;
}

void Behavior::set_unjustified_absences(int nb_unjustified_absences){
    this->unjustified_absences = nb_unjustified_absences;
}

void Behavior::set_justified_delays(int nb_justified_delays){
    this->justified_delays = nb_justified_delays;
}

void Behavior::set_unjustified_delays(int nb_unjustified_delays){
    this->unjustified_delays = nb_unjustified_delays;
}

void Behavior::set_personal_issues(bool has_issues){
    this->personal_issues = has_issues;
}

void Behavior::set_detention_hours(int nb_detention_hours){
    this->detention_hours = nb_detention_hours;
}

void Behavior::set_reports(int nb_reports){
    this->reports = nb_reports;
}

void Behavior::set_disciplinary_boards(int nb_disciplinary_boards){
    this->disciplinary_boards = nb_disciplinary_boards;
}