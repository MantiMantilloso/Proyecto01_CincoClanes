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
                "1o", "1*", "1~", "1+", "1!",
                "2o", "2*", "2~", "2+", "2!",
                "3o", "3*", "3~", "3+", "3!",
                "4o", "4*", "4~", "4+", "4!",
                "5o", "5*", "5~", "5+", "5!",
                "6o", "6*", "6~", "6+", "6!",
                "7o", "7*", "7~", "7+", "7!",
                "8o", "8*", "8~", "8+", "8!"
            }; 
            /*
            clanes {"o","*","~","+","!"}; o:LUNA ; *:SOL ; ~:AGUA ; +:CRUZ; !:ESPADA
            guerreros {"1","2","3","4","5","6","7","8"};
            */
        }

        void mezclar(){
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

    Jugador(const string& nom, int num){
        this->nombre = nom ;
        this->numero = num;
    }

    int puntaje(){
	
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
    void setNumero(int num_jug){
        this->numero = num_jug;
    }
    void setNombre(string nom_jug){
        this->nombre = nom_jug;
    }

    int getNumero(){
        return this->numero;
    }
    string getNombre (){
        return this->nombre;
    }
    vector <string>& getMano(){
        return this->mano;
    }
    
};

int main(){

    Baraja miBaraja;
    miBaraja.mezclar();

    int cantidad_jugadores;
    cout << "Ingrese la cantidad de jugadores: ";
    cin >> cantidad_jugadores;

    vector<Jugador> jugadores;

    for (int i = 0; i < cantidad_jugadores; i++) {
        string nombre;
        cout << "Ingrese el nombre del Jugador " << i + 1 << ": ";
        cin >> nombre;
        Jugador jugador(nombre, i+1);
        jugadores.push_back(jugador);
    }

    int cantidad_cartas_a_repartir = 3;

    for (Jugador& jugador : jugadores) {
        miBaraja.repartir(jugador.getMano(), cantidad_cartas_a_repartir);
    }

    // Mostrar las manos de los jugadores
    for (Jugador& jugador : jugadores) {
        cout << "Mano de " << jugador.getNombre() << ":" << endl;
        for (const string& carta : jugador.getMano()) {
            cout << carta << " ";
        }
        cout << endl;
        cout<<"Puntaje: "<<jugador.puntaje()<<endl;
    }

    return 0;
}