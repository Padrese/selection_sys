#ifndef DEF_COUPLE
#define DEF_COUPLE

#include "../include/Student/Student.hpp"
#include "../include/Training/Training.hpp"

class Couple{

    private:
    Student student;
    Training training;

    public:

    //Constructor
    Couple(Student student, Training training);

    //Destructor
    ~Couple();

    Student get_student() const;
    Training get_training() const;
    void set_student(Student student);
    void set_training(Training training);
};

#endif