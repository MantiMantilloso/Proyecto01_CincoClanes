#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*class Carta{
private:

    char guerrero;
    char clan;

public:
    
    void setClan(char sim_clan){
        this->clan = sim_clan;
    }
    
    void setGuerrero(char num_guerrero){
        this->guerrero = num_guerrero;
    }

    char getGuerrero(){
        return this->guerrero;
    }
    char getClan (){
        return this->clan;
    }
    James mato esto :(
};*/

class Baraja{
    private:
        vector <string> baraja_madre;
    
    public:

        Baraja(){
            baraja_madre = {
            "1o", "1*", "1~", "1+", "1!",
            "2o", "2*", "2~", "2+", "2!",
            "3o", "3*", "3~", "3+", "3!",
            "4o", "4*", "4~", "4+", "4!",
            "5o", "5*", "5~", "5+", "5!",
            "6o", "6*", "6~", "6+", "6!",
            "7o", "7*", "7~", "7+", "7!",
            "8o", "8*", "8~", "8+", "8!"
            };
        }

        void mezclar(vector<string>baraja_m);
        void repartir(vector<string> baraja);

};
