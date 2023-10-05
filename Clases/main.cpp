#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Jugador.h"
#include "Baraja.h"

using namespace std;

bool Ganador(vector<Jugador>& jugadores, Baraja& baraja);
void jugar();

int main() {
	
	jugar();
	
	return 0;
}

bool Ganador(vector<Jugador>& jugadores, Baraja& baraja){
    int puntajeMaximo = -1;
    vector<Jugador> ganadores;

    for (Jugador& jugador : jugadores) {
        int puntaje = jugador.puntaje();

        if (puntaje > puntajeMaximo) {
            puntajeMaximo = puntaje;
            ganadores.clear();
            ganadores.push_back(jugador);
        } else if (puntaje == puntajeMaximo) {
            ganadores.push_back(jugador);
        }
    }

    if (!ganadores.empty() and ganadores.size()<2) {
        cout << endl << "Ganador: ";
        for (Jugador& ganador : ganadores) {
            cout << ganador.getNombre() << endl;
        }
        return false; // Se encontr� un ganador
    } else if (baraja.cartas_disponibles()) {
        cout << "No se pueden repartir m�s cartas. El juego ha terminado en empate." << endl;
        return false; // No se pueden repartir m�s cartas, el juego termina en empate
    } else {
    	cout<<"Hubo un empate, se repartira una carta a cada jugador.";
        // Repartir una carta a todos los jugadores
        for (Jugador& jugador : jugadores) {
            baraja.repartir(jugador.getMano(), 1);
        }
        return true; // El juego contin�a
    }
}
void jugar(){
	string titulo = " Bienvenido a 5 Clanes";
    int ancho = 50;  // Ancho total del encabezado
    
    // Configuraci�n para dar formato al encabezado
    cout << string(ancho, '*') << endl;
    cout << setw((ancho + titulo.length()) / 2) << titulo << endl;
    cout << string(ancho, '*') << endl;
    
    //------------------------Creacion de la baraja------------------------
    Baraja miBaraja;
    miBaraja.mezclar();
    
    //---------------------Ingreso de jugddores----------------------------
    int cant;
    
    cout<<"Ingresa la cantidad de jugadores a participar (de 2 a 5): ";
    cin >> cant;
    
    while (cant<2 or cant>5){
    	cout<<"Cantidad de jugadores invalida, ingresa de nuevo: ";
    	cin>>cant;
	}
	
	vector<Jugador> jugadores;

    for (int i = 0; i < cant; i++) {
        string nombre;
        cout << "Ingrese el nombre del Jugador " << i + 1 << ": ";
        cin >> nombre;
        Jugador jugador(nombre, i+1);
        jugadores.push_back(jugador);
    }
    cout<<endl;
    
    //---------Reparticion inicial de 3 cartas a los jugadores-------------

    int cantidad_cartas_a_repartir = 3;
    
    for (Jugador& jugador : jugadores) {
        miBaraja.repartir(jugador.getMano(), cantidad_cartas_a_repartir);
    }
    
    // Mostrar las manos de los jugadores y puntajes
    for (Jugador& jugador : jugadores) {
        cout << "Mano de " << jugador.getNombre() << ":" << endl;
        for (const string& carta : jugador.getMano()) {
            cout << carta << " ";
        }
        cout << endl;
        cout<<"Puntaje: "<<jugador.puntaje()<<endl<<endl;
    }
    
    while(Ganador(jugadores, miBaraja)){
    	cout<<endl<<"-----------------------------------Reparticion-------------------------------------"<<endl;
    	for (Jugador& jugador : jugadores) {
        	cout << "Mano de " << jugador.getNombre() << ":" << endl;
        	for (const string& carta : jugador.getMano()) {
            	cout << carta << " ";
        	}
        cout << endl;
        cout<<"Puntaje: "<<jugador.puntaje()<<endl<<endl;
    	}
	}
}
