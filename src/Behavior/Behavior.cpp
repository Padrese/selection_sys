#include "../../include/Behavior/Behavior.hpp"

Behavior::Behavior(){}

Behavior::Behavior(int justified_absences = 0,
    int unjustified_absences = 0,
    int justified_delays = 0,
    int unjustified_delays = 0,
    bool personal_issues = 0,
    int detention_hours = 0,
    int reports = 0,
    int disciplinary_boards = 0){

    this->justified_absences = justified_absences;
    this->unjustified_absences = unjustified_absences;
    this->justified_delays = justified_delays;
    this->unjustified_delays = unjustified_delays;
    this->personal_issues = personal_issues;
    this->detention_hours = detention_hours;
    this->reports = reports;
    this->disciplinary_boards = disciplinary_boards;
}

Behavior::~Behavior(){}

int Behavior::get_justified_absences(){
    return this->justified_absences;
}

int Behavior::get_unjustified_absences(){
    return this->unjustified_absences;
}

int Behavior::get_justified_delays(){
    return this->justified_delays;
}

int Behavior::get_unjustified_delays(){
    return this->unjustified_delays;
}

bool Behavior::get_personal_issues(){
    return this->personal_issues;
}

int Behavior::get_detention_hours(){
    return this->detention_hours;
}

int Behavior::get_reports(){
    return this->reports;
}

int Behavior::get_disciplinary_boards(){
    return this->disciplinary_boards;
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