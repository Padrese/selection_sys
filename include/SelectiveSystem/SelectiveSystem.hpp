#ifndef DEF_SELECTIVE_SYSTEM
#define DEF_SELECTIVE_SYSTEM

#include <string>
#include <map>
#include <vector>
using namespace std;

#include "../include/Couple/Couple.hpp"

class SelectiveSystem{

    private:
    string system_name;
    vector<Student> students;
    vector<Training> trainings;

    public:

    //Constructor
    SelectiveSystem(string system_name);

    //Destructor
    ~SelectiveSystem();

    map<long, Couple> gale_shapley() const;
    string get_system_name() const;
    vector<Student> get_students() const;
    vector<Training> get_trainings() const;
    void add_student(Student student);
    void add_training(Training training);
    void clear_all();

};

#endif