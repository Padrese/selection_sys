#pragma once

#ifndef DEF_PREFERENCE
#define DEF_PREFERENCE

#include <string>
using namespace std;

class Preference{
    private:

    string training_name;
    long student_id;

    public:

    //Constructor
    Preference(); //Default
    Preference(long student_id);
    Preference(string training_name);

    //Destructor
    ~Preference();

    string get_training_name() const;
    long get_student_id() const;
    void set_training_name(string training_name);
    void set_student_id(long student_id);
};

#endif