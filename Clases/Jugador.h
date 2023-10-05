#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Jugador{
	
	// Atributos de clase
	private:
		int numero;
    	string nombre;
    	vector <string> mano;
    
    public:
    // Constructor
    	Jugador(string n, int num);
    	
    // Metodos
    	int puntaje();
    	void setNumero(int num_jug);
    	void setNombre(string nom_jug);
    	int getNumero();
    	string getNombre ();
    	vector <string>& getMano();
};
