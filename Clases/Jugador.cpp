#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Jugador.h"

using namespace std;

// Constructor
Jugador::Jugador(string n, int num){
	nombre = n;
	numero = num;
}

// Metodos
int Jugador::puntaje(){
	
	vector<string> baraja = mano;
    
    // Separacion de los rangos y clanes
    vector<string> mano_original;
    vector<string> clanes;
    
    for (auto carta : baraja) {
        string numero = carta.substr(0, carta.size() - 1); // Obtener todo excepto el último carácter
        string simbolo = carta.substr(carta.size() - 1); // Obtener el último carácter

        mano_original.push_back(numero);
        clanes.push_back(simbolo);
    }
    
    //------------------Caso 1 (Rangos duplicados)-----------------------------------
	vector<string> duplicados;
	int puntaje_r_duplicados = 0;
	
	// Creacion de vector de duplicados
	for(auto carta : mano_original){
		if (count(mano_original.begin(), mano_original.end(), carta) > 2)
            duplicados.push_back(carta);
	}
    
    // Calculo del puntaje
    puntaje_r_duplicados = duplicados.size() * 7; 
    
    
    //-------------------Caso 2 (Clanes duplicados)----------------------------------
    vector<string> clanes_duplicados;
    int puntaje_clanes_duplicados = 0;
    
    // Creacion de vector de clanes duplicados
	for(auto carta : clanes){
		if (count(clanes.begin(), clanes.end(), carta) > 2)
            clanes_duplicados.push_back(carta);
	}
	
	// Calculo del puntaje
    puntaje_clanes_duplicados = clanes_duplicados.size() * 5;
    
    
	//------------------Caso 3 (Rangos Consecutivos)---------------------------------
	vector<string> prueba = mano_original;
	int cont_rangos = 0;
	int puntaje_r_consecutivo = 0;
	
	// Ordenamiento del vector
	sort(prueba.begin(), prueba.end());
	
	// Reconocer numeros duplicados
	auto i_duplicado = unique(prueba.begin(), prueba.end());
	
	// Eliminacion de duplicados
	prueba.erase(i_duplicado, prueba.end());
	
	// Conteo de cuantos consecutivos hay
    for (int i=0; i<prueba.size()-1; i++){
    	int n_actual = stoi(prueba[i]);
        int n_siguiente = stoi(prueba[i + 1]);
        
        
        if (n_actual + 1 == n_siguiente) 
            cont_rangos++;
        
        // Si el elemento no es consecutivo al siguiente pero si al anterior
		else if (prueba[i] != prueba[0]){
			int n_anterior = stoi(prueba[i - 1]);
			if (n_actual - 1 == n_anterior)
				cont_rangos++;
			}
		}

	// Ultimo elemento
    if (cont_rangos>0){
	    int n_ultimo = stoi(prueba[prueba.size()-1]);
	    int n_anterior = stoi(prueba[prueba.size()-2]);
	    if (n_ultimo - 1 == n_anterior)
	        cont_rangos++;
	}
	
	// Calculo del puntaje
	if (cont_rangos>2){
		puntaje_r_consecutivo = cont_rangos * 3;
	}
	
	
	// Calculo del puntaje total
	int puntaje_total = puntaje_r_consecutivo + puntaje_clanes_duplicados + puntaje_r_duplicados;
	
	return puntaje_total;
}

void Jugador::setNumero(int num_jug){
    this->numero = num_jug;
    }

void Jugador::setNombre(string nom_jug){
    this->nombre = nom_jug;
    }

int Jugador::getNumero(){
    return this->numero;
    }
string Jugador::getNombre (){
    return this->nombre;
    }
vector <string>& Jugador::getMano(){
    return this->mano;
    }
