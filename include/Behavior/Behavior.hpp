#pragma once

#ifndef DEF_BEHAVIOR
#define DEF_BEHAVIOR

#include <string>

using namespace std;

class Behavior{

    private:

    int justified_absences;
    int unjustified_absences;
    int justified_delays;
    int unjustified_delays;
    bool personal_issues;
    int detention_hours;
    int reports;
    int disciplinary_boards;

    public:

    //Constructor
    Behavior();

    //Destructor
    ~Behavior();

    int get_justified_absences();
    int get_unjustified_absences();
    int get_justified_delays();
    int get_unjustified_delays();
    bool get_personal_issues();
    int get_detention_hours();
    int get_reports();
    int get_disciplinary_boards();
    void set_justified_absences(int nb_justified_absences);
    void set_unjustified_absences(int nb_unjustified_absences);
    void set_justified_delays(int nb_justified_delays);
    void set_unjustified_delays(int nb_unjustified_delays);
    void set_personal_issues(bool has_issues);
    void set_detention_hours(int nb_detention_hours);
    void set_reports(int nb_reports);
    void set_disciplinary_boards(int nb_disciplinary_boards);

};

#endif