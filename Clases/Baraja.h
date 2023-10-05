#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Baraja{
	
    private:
    // Atributos
        vector <string> baraja_madre;
    
    public:
	
	// Constructor
        Baraja();

	// Metodos
        void mezclar();
        void repartir(vector<string>& mano, int cantidad);
        bool cartas_disponibles();

};
