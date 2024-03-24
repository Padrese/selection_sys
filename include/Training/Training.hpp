#pragma once

#ifndef DEF_TRAINING
#define DEF_TRAINING

#include <string>
#include <map>
#include "../Preference/Preference.hpp"

using namespace std;

class Training{

    private:

    string training_name;
    string theme;
    string location;
    int ranking;
    map<int, Preference> preferences;
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
    Preference get_preference(int order_preference) const;
    map<int, Preference> get_preferences() const;
    void set_preference(int order_preference, Preference preference);
    void remove_preference(int order_preference);
    void switch_preferences(int order_pref_1, int order_pref_2);
    void remove_all_preferences();
};

#endif