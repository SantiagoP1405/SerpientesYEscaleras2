/*
Santiago Patricio Gómez Ochoa
A01735171
31/05/2024
Programación orientada a objetos
*/

#include <iostream>
#include "tablero2.cpp"
#include <ctime>
#include <vector>
using namespace std;

int tirarDado(){
    return rand() % 6 + 1;
    
}
int main(){
    srand(static_cast<unsigned int>(time(0)));
    
    int nTurno = 1;
    int maxTurnos = 0;
    int sizeTablero, numSerpientes, penalty, numEscaleras, reward, players;
    string menu;
    char mode;
    
    
    cout << "--------------- SERPIENTES Y ESCALERAS ---------------" << endl;
    cout << "¡Bienvenido!" << endl;
    cout << endl;
    cout << "Este juego es para de 2 jugadores en adelante" << endl;
    cout << "Antes de continuar, porfavor asegúrate de que cuentas con otra persona para jugar." << endl;
    cout << "Decidan cuántos jugadores serán y el orden en el que jugarán" << endl;
    cout << endl;
    cout << "El objetivo es llegar a la última casilla del tablero." << endl;
    cout << "El primero que llegue a la útima casilla gana el juego." << endl;
    cout << endl;
    cout << "Todos los jugadores comienzan en la primera casilla" << endl;
    cout << endl;
    cout << "Antes de empezar, deberán configurar los parámetros del juego" << endl;
    cout << "Se les pedirá especificar el tamaño del tablero, cuántas casillas de ESCALERAS < L >" << endl;
    cout << "o de Serpientes < S > habrán, así como cuántas casillas avanzarán o retrocederán al" << endl;
    cout << "caer en alguna de estas. De igual manera, deben decir cuál es el máximo de turnos que habrán en el juego." << endl;
    cout << "Si para cuando lleguen al máximo de turnos, algún jugador no ha llegado a la meta, se acabará el juego y no habrán ganadores" << endl;
    cout << endl;
    cout << endl;
    cout << "Hay 4 tipos de casilla:" << endl;
    cout << endl;
    cout << "---------- Casillas normales ( N ) ----------" << endl;
    cout << "Si un jugador cae en este tipo de casillas, no se afecta su movimiento" << endl;
    cout << endl;
    cout << "-------------- Escaleras ( L ) --------------" << endl;
    cout << "Si un jugador cae en una escalera, avanzará el número especificado de casillas a partir de la casilla de escalera" << endl;
    cout << endl;
    cout << "------------- Serpientes ( S ) -------------" << endl;
    cout << "Si un jugador cae en una serpiente, regresará el número especificado de casillas a partir de la casilla de serpiente" << endl;
    cout << endl;
    cout << "------ Jugadores en la misma casilla ( B ) -------" << endl;
    cout << "Esta casilla solamente aparecerá cuando dos o más jugadores se encuentren en la misma casilla" << endl;
    cout << endl;

    cout << "Existen dos modos de juego: Juego automático < A > y Juego manual < M >" << endl;
    cout << endl;
    cout << "JUEGO AUTOMÁTICO < A >: después de la configuración, todo el juego se ejecuta de manera" << endl;
    cout << "automática hasta que un jugador llegue a la meta o se alcance el máximo de turnos" << endl;
    cout << endl;
    cout << "JUEGO MANUAL < M >: se trata del juego convencional de Serpientes y Escaleras, en" << endl;
    cout << "el que por turnos, cada jugador tirará un dado virtual, que le indicará" << endl;
    cout << "cuántas casillas se moverá en su turno." << endl;
    cout << endl;

    
    cout << "Por favor, elige alguna de estas opciones: " << endl;
    cout << "< C > ---- Continuar" << endl;
    cout << "< E > ---- Salir" << endl;
    cin >> menu;
    menu[0] = toupper(menu[0]);
    

    while(menu != "C" || menu != "E"){
        if(menu == "C"){
            cout << "--------------- CONFIGURACIÓN DEL JUEGO ---------------" << endl;
            cout << endl;
            cout << "Por favor, ingresa el tamaño del tablero: ";
            cin >> sizeTablero; 
            cout << endl;
            cout << "¿Cuántos jugadores habrán en este juego?  ";
            cin >> players;
            cout << endl;
            cout << "Ingresa cuántas casillas de SERPIENTES ( S ) habrá en el tablero: ";
            cin >> numSerpientes;
            cout << "Ingresa cuántas casillas RETROCEDERÁN los jugadores si caen en una SERPIENTE: ";
            cin >> penalty;
            cout << endl;
            cout << "Ingresa cuántas casillas de ESCALERAS ( E ) habrá en el tablero: ";
            cin >> numEscaleras;
            cout << "Ingresa cuántas casillas AVANZARÁN los jugadores si caen en una ESCALERA: ";
            cin >> reward;
            cout << endl;
            cout << "Ingresa el máximo de turnos que tendrá este juego: ";
            cin >> maxTurnos;
            cout << endl;
            Tablero tablero(sizeTablero, numSerpientes, penalty, numEscaleras, reward, players);
            vector<int> posiciones(players, 0); //Inicia las posiciones de los jugadores en 0
            int meta = sizeTablero-1;
            cout << "Elije tu modo de juego" << endl;
            cout << "< A > ---- Juego automático" << endl;
            cout << "< M > ---- Juego manual" << endl;
            cin >> mode;
            mode = toupper(mode);
            while(mode != 'A' && mode != 'M'){
                cout << "Elije una opción válida" << endl;
                cout << "< A > ---- Juego automático" << endl;
                cout << "< M > ---- Juego manual" << endl;
                cin >> mode;
                mode = toupper(mode);
            }
            
            cout << "¡Comienza el juego" << endl;
            cout << endl;
            tablero.printTablero(posiciones);
            cout << "Todos los jugadores se encuentran en la misma casilla" << endl;
    switch (mode){
        
        case 'A': //Automático
            while (true){
            for(int turn= 1; turn <= players ; turn++){
            cout << "--------------- TURNO NÚMERO " << nTurno << " DEL JUGADOR " << turn << " ---------------" << endl;
            int dado = tirarDado();
            cout << "El jugador " << turn << " se mueve " << dado << " casillas" << endl;
            cout << endl;

            posiciones[turn - 1] += dado; //    Actualiza la posición

            tablero.printTablero(posiciones); //Vuelve a imprimir el tablero

            posiciones[turn - 1] = tablero.getUpdatedPosition(posiciones[turn - 1]); //Actualiza su posición en las casillas

            cout << "El jugador " << turn << " se encuentra en la casilla " << posiciones[turn - 1] + 1 << endl;
            cout << endl;

            cout << "                        OTRAS POSICIONES                         " << endl;
            for(int i = 1; i <= players; i++){
                if(i != turn){
                cout << "El jugador " << i << " se encuentra en la casilla " << posiciones[i-1]+1 << endl;
                }

                cout << endl;
            }
            cout << endl;
            if (posiciones[turn - 1] >= meta) {
                        cout << "------------------------- GAME OVER -------------------------" << endl;
                        cout << "¡El jugador " << turn << " gana!" << endl;
                        cout << endl;
                        cout << "Gracias por jugar :)" << endl;
                        return 0;
                    }
                }

                if (nTurno >= maxTurnos) {
                    cout << "--------------- GAME OVER ---------------" << endl;
                    cout << "Máximo de turnos alcanzado" << endl;
                    cout << "Ningún jugador ha alcanzado la meta" << endl;
                    return 0;
                }

                nTurno++;
            }


            break;

        case 'M':
            while (true){
      for(int turn= 1; turn <= players ; turn++){
            cout << "--------------- TURNO NÚMERO " << nTurno << " DEL JUGADOR " << turn << " ---------------" << endl;
            cout << "Teclea la letra < D > para tirar el dado" << endl;
            string tirarTurno;
            int dado = tirarDado();
            cin >> tirarTurno;
            tirarTurno[0] = toupper(tirarTurno[0]);
            cout << endl;

            while(tirarTurno != "D"){
              if(tirarTurno == "D"){
                dado = tirarDado();
             }
              else{
                cout << "Teclea la letra < D > para tirar el dado" << endl;
                cin >> tirarTurno;
                tirarTurno[0] = toupper(tirarTurno[0]);
                cout << endl;
             }  
            }
            cout << "El jugador " << turn << " se mueve " << dado << " casillas" << endl;
            cout << endl;

            posiciones[turn - 1] += dado; //    Actualiza la posición

            tablero.printTablero(posiciones); //Vuelve a imprimir el tablero

            posiciones[turn - 1] = tablero.getUpdatedPosition(posiciones[turn - 1]); //Actualiza su posición en las casillas

            cout << "El jugador " << turn << " se encuentra en la casilla " << posiciones[turn - 1] + 1 << endl;
            cout << endl;

            cout << "                        OTRAS POSICIONES                         " << endl;
            for(int i = 1; i <= players; i++){
                if(i != turn){
                cout << "El jugador " << i << " se encuentra en la casilla " << posiciones[i-1]+1 << endl;
                }

                cout << endl;
            }
            cout << endl;
            if (posiciones[turn - 1] >= meta) {
                        cout << "------------------------- GAME OVER -------------------------" << endl;
                        cout << "¡El jugador " << turn << " gana!" << endl;
                        cout << endl;
                        cout << "Gracias por jugar :)" << endl;
                        return 0;
                    }
                }

                if (nTurno >= maxTurnos) {
                    cout << "--------------- GAME OVER ---------------" << endl;
                    cout << "Máximo de turnos alcanzado" << endl;
                    cout << "Ningún jugador ha alcanzado la meta" << endl;
                    return 0;
                }

                nTurno++;
            }

            break;

    }       
            
        } 
        else if (menu == "E") {
            cout << "¡Hasta pronto! :)" << endl;
            return 0;
        } 
        
        else {
            cout << "Introduce una opción válida" << endl;
            cout << "< C > ---- Continuar" << endl;
            cout << "< E > ---- Salir" << endl;
            cin >> menu;
            menu[0] = toupper(menu[0]);
        }
    }

    return 0;
}