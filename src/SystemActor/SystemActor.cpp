#include <iostream>
#include "../../include/SystemActor/SystemActor.hpp"

SystemActor::SystemActor(){};

SystemActor::~SystemActor(){};

int SystemActor::get_nb_preferences() const{
    return preferences.size();
}

Preference SystemActor::get_preference(int order_preference) const {
    int counter = preferences.count(order_preference);
    try {
        if (counter == 0){
            throw string("Order preference doesn't exist in preferences list");
        }
    }
    catch(string &e){
        cerr << "Order preference doesn't exist in preferences list" << endl;
        return (Preference) nullptr;
    }
    return preferences.at(order_preference);
}

map<int, Preference> SystemActor::get_preferences() const{
    return preferences;
}


void SystemActor::add_preference(int order_preference, Preference preference){
    int initial_map_size = preferences.size();

    //Check index of preference
    try{
        if (order_preference > initial_map_size+1 || order_preference < 0){
            throw invalid_argument("Index error: Order preference doesn't match the logical sequence already in place");
        }
    }
    catch(string &e){
        cerr << "Index error: Order preference doesn't match the logical sequence already in place" << endl;
        return;
    }

    /*We adapt the index of preferences when add a preference
    only if we do not add the last position preference.
    We cannot do parallel programming to move key indexes as
    keys are const elements.
    */

    if (order_preference < initial_map_size+1){
        preferences[initial_map_size+1] = preferences[initial_map_size];
            for (map<int, Preference>::reverse_iterator it = preferences.rbegin(); it != preferences.rend(); ++it){
                int key = it->first;
                if (key > order_preference){
                    preferences[key] = preferences[next(it, 1)->first]; 
                }
            }
    }

    /*Finally, we create the key-value pair where the value linked to the removed key
    matches the new preference order.*/
    preferences[order_preference] = preference;

}

void SystemActor::remove_preference(int order_preference){
    int initial_map_size = preferences.size();

    try{
        if (preferences.erase(order_preference) == 0){
            throw invalid_argument("Index error: Order preference doesn't match the logical sequence already in place");
        }
    }
    catch(string &e){
        cerr << "Index error: Order preference doesn't match the logical sequence already in place" << endl;
        return;
    }


    /**We adapt the index of preferences when removing a preference
    only if we do not remove the last position preference.
    We cannot do parallel programming to move key indexes as
    keys are const elements.
    */
    if (order_preference != initial_map_size){
            Preference removed_key_preference = preferences[order_preference+1];
            for (map<int, Preference>::iterator it = preferences.begin(); it != preferences.end(); ++it){
                int key = it->first;

                /*Second condition is to ensure next points to something relevant in the map.
                If we're at the end, we need to remove the last key-value pair.
                */
                if (key > order_preference){
                    if (key != preferences.size()+1){
                        preferences[key] = preferences[next(it, 1)->first]; 
                    }
                }
            }

            //We remove the last element, which is superfluous
            preferences.erase(initial_map_size);

            /*Finally, we create the key-value pair where the value linked to the removed key
            matches the new preference order.*/
            preferences[order_preference] = removed_key_preference;
    }
}

void SystemActor::switch_preferences(int order_pref_1, int order_pref_2){
    //TODO: check input for order_prefs
    int map_size = preferences.size();

    try{
        if (order_pref_1 > map_size || order_pref_1 < 0
            || order_pref_2 > map_size || order_pref_2 < 0){
            throw string("Index error: Order preference doesn't match the logical sequence already in place");
        }
    }
    catch(string &e){
        cerr << "Index error: Order preference doesn't match the logical sequence already in place" << endl;
        return;
    }

    Preference preference_to_store = preferences[order_pref_2];
    preferences[order_pref_2] = preferences[order_pref_1];
    preferences[order_pref_1] = preference_to_store;
}

void SystemActor::remove_all_preferences(){
    preferences.clear();
}