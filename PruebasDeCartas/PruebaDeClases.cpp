#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

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
                "o1", "*1", "~1", "+1", "!1",
                "o2", "*2", "~2", "+2", "!2",
                "o3", "*3", "~3", "+3", "!3",
                "o4", "*4", "~4", "+4", "!4",
                "o5", "*5", "~5", "+5", "!5",
                "o6", "*6", "~6", "+6", "!6",
                "o7", "*7", "~7", "+7", "!7",
                "o8", "*8", "~8", "+8", "!8"
                }; 
            /*
            clanes {"o","*","~","+","!"}; o:LUNA ; *:SOL ; ~:AGUA ; +:CRUZ; !:ESPADA
            guerreros {"1","2","3","4","5","6","7","8"};
            */
        }

        void mezclar(vector<string>baraja_m);
        void repartir(vector<string> baraja);

};
