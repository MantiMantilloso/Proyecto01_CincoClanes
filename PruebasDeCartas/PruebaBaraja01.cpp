#include <iostream>
using namespace std;

int main (){

    string clanes [] {"o","*","~","+","!"}; // o:LUNA ; *:SOL ; ~:AGUA ; +:CRUZ; !:ESPADA
    string guerreros [] {"1","2","3","4","5","6","7","8"};

    string baraja_maestra [40]; // baraja[i]%5 dice que tipo de guerrero es; baraja[i]/5 te da el numero de guerrero
    int num_carta=0;

    for (int i = 0; i < 8; i++){
        for (int k = 0; k < 5; k++){
            baraja_maestra[num_carta] = clanes[k]+guerreros[i];
            num_carta++;
        }
    }
    
    cout<<"Baraja Actual: {";
   for (int i = 0; i < 40; i++)
            cout<<baraja_maestra[i]<<", ";
    cout<<"}";

    string baraja_repartir[40];

    for (int i = 0; i<40;i++)
        baraja_repartir[i]=baraja_maestra[i]; 
    //Para tener fija la baraja maestra, en la clase implementar como static
    //Usar baraja_repartir para repartir las cartas a los jugadores, una vez que se reparta una carta, esta sera reemplazada por un "0"
    return 0;
}