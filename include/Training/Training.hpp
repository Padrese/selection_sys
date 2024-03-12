#ifndef DEF_TRAINING
#define DEF_TRAINING

#include <string>
using namespace std;

class Training{

    private:

    string training_name;
    string theme;
    string location;
    int ranking;

    public:

    //Constructor
    Training(string training_name, string theme, string location, int ranking);

    //Destructor
    ~Training();


    string get_name() const;
    string get_theme() const;
    string get_location() const;
    int get_ranking() const;
    void set_ranking(int ranking);

};

#endif