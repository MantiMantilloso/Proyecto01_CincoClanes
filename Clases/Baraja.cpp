#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include "Baraja.h"

using namespace std;

Baraja::Baraja(){
	baraja_madre = {
                "1o", "1*", "1~", "1+", "1!",		// clanes {"o","*","~","+","!"}; o:LUNA ; *:SOL ; ~:AGUA ; +:CRUZ; !:ESPADA
                "2o", "2*", "2~", "2+", "2!",		// guerreros {"1","2","3","4","5","6","7","8"};
                "3o", "3*", "3~", "3+", "3!",
                "4o", "4*", "4~", "4+", "4!",
                "5o", "5*", "5~", "5+", "5!",
                "6o", "6*", "6~", "6+", "6!",
                "7o", "7*", "7~", "7+", "7!",
                "8o", "8*", "8~", "8+", "8!"
                }; 
}

void Baraja::mezclar(){
	random_device rd;
    std::mt19937 rng(rd()); //Generador de numeros aleatorios del algoritmo Mersenne Twister

    shuffle(baraja_madre.begin(), baraja_madre.end(), rng);
}

void Baraja::repartir(vector<string>& mano, int cantidad){
	if (cantidad > 0 and cantidad <= baraja_madre.size()) {
        for (int i = 0; i < cantidad; i++) {
        	mano.push_back(baraja_madre.back());
        	baraja_madre.pop_back();
            }} 
	else {
        cout << "No se pueden repartir " << cantidad << " cartas." << endl;
        }
}

bool Baraja::cartas_disponibles(){
	if (baraja_madre.size()!=0)
		return false;
	
	else
		return true;
}
