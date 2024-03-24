#ifndef DEF_SELECTIVE_SYSTEM
#define DEF_SELECTIVE_SYSTEM

#include <string>
#include <map>
#include <vector>
using namespace std;

#include "../Couple/Couple.hpp"

class SelectiveSystem{

    private:
    string system_name;
    unordered_map<long,Student> students;
    unordered_map<string,Training> trainings;

    public:

    //Constructor
    SelectiveSystem(string system_name);

    //Destructor
    ~SelectiveSystem();

    map<string, Couple> gale_shapley() const;
    string get_system_name() const;
    unordered_map<long,Student> get_students() const;
    unordered_map<string,Training> get_trainings() const;
    void add_student(Student student);
    void add_training(Training training);
    void clear_all();

};

#endif