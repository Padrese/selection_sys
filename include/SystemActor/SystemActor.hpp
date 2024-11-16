#pragma once

#ifndef DEF_ACTOR
#define DEF_ACTOR

#include <map>
#include "../Preference/Preference.hpp"

using namespace std;

class SystemActor{

    private:
    map<int, Preference> preferences;

    public:
    SystemActor();
    ~SystemActor();

    int get_nb_preferences() const;
    Preference get_preference(int order_preference) const;
    map<int, Preference> get_preferences() const;
    void add_preference(int order_preference, Preference preference);
    void remove_preference(int order_preference);
    void switch_preferences(int order_pref_1, int order_pref_2);
    void remove_all_preferences();
};

#endif