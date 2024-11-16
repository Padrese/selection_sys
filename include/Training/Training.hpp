#pragma once

#ifndef DEF_TRAINING
#define DEF_TRAINING

#include <string>
#include "../SystemActor/SystemActor.hpp"

using namespace std;

class Training : public SystemActor{

    private:

    string training_name;
    string theme;
    string location;
    int ranking;
    bool has_student;

    public:

    //Constructor
    Training();
    Training(string training_name, string theme, string location, int ranking);

    //Destructor
    ~Training();

    string get_name() const;
    string get_theme() const;
    string get_location() const;
    int get_ranking() const;
    void set_ranking(int ranking);
    bool get_has_student() const;
    void set_has_student(bool status);
};

#endif