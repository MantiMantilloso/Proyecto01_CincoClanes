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

        void mezclar(vector<string>baraja_m){
            random_device rd;
            std::mt19937 rng(rd()); //Generador de numeros aleatorios del algoritmo Mersenne Twister

            shuffle(baraja_madre.begin(), baraja_madre.end(), rng);
        }
        void repartir(vector<string>& mano, int cantidad){
            if (cantidad > 0 and cantidad <= baraja_madre.size()) {
                for (int i = 0; i < cantidad; i++) {
                    mano.push_back(baraja_madre.back());
                    baraja_madre.pop_back();
                }
            } else {
                cout << "No se pueden repartir " << cantidad << " cartas." << endl;
            }
        }

};

class Jugador{

    private: 
    int numero;
    string nombre;
    vector <string> mano;

    public:
    void puntos();
};