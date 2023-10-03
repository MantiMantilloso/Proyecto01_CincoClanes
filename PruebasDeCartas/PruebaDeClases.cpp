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

class baraja{
    private:
        vector <string> baraja_madre;
    
    public:
        void mezclar(vector<string>baraja_m);
        void repartir(vector<string> baraja);

};
