/* 
Mauricio Mantilla
Los Cinco Clanes:
Para este proyecto la mecánica del juego es la siguiente:
• El programa se inicia solicitando el número de jugadores que van a participar. Deben ser de dos 
a cinco jugadores. (Manti) X
• Luego debe solicitar el nombre de cada Jugador. (Manti) X
• El sistema debe entregar a cada jugador 3 cartas tomadas de la baraja que representan la 
armada de cada jugador.(Manti) pendiente
• Luego el sistema debe calcular y mostrar en la pantalla el valor de la armada de cada jugador. (james) pendiente
• El jugador que tenga la armada con el valor más grande gana la partida. Si existe un empate el 
juego debe continuar.(james) pendiente
• Si no existe un ganador (todos tienen 0) o hay un empate, el usuario podrá pedirle al sistema 
que entregue otra carta a cada jugador. (Manti) pendiente
• Y luego se repite el proceso hasta que un jugador gane (James) pendiente
• El juego termina cuando un jugador gana o cuando ya no hay la posibilidad de seguir sacando 
cartas de la baraja (James) pendiente

ver 0.1 Implementar una baraja de 40 cartas
ver 0.2 Implementar jugadores

*/
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

    //Implementar los jugadores

    int num_jugadores{};
    
    cout<<"Cuantos jugadores (escoja de 2 a 5): ";
    cin>>num_jugadores; //Validacion en la clase (num_jugadores>=2 y num_jugadores<=5)

    while (num_jugadores<2 or num_jugadores>5){
        cout<<"Numero invalido, ";
        cout<<"Cuantos jugadores (escoja de 2 a 5): ";
        cin>>num_jugadores;
    }

    string lista_jugadores[num_jugadores];

    //Ingresar Jugadores
    for(int i = 0; i<num_jugadores; i++){
        cout<<"Ingrese el el nombre del jugador "<<i+1<<": ";
        cin>>lista_jugadores[i];
    }

    //Mostrar Jugadores
    for(int i = 0; i<num_jugadores; i++){
        cout<<"el nombre del jugador "<<i+1<<" es: "<<lista_jugadores[i]<<endl;
    }

    //Agregar cartas a cada jugador (realizar un unico metodo donde se añadan cartas aleatorias)
    return 0;
}