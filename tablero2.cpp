/*
Santiago Patricio Gómez Ochoa
A01735171
31/05/2024
Programación orientada a objetos
*/

#include "tablero2.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <cmath>
using namespace std;


//CASILLA
Casilla::Casilla(int idCasilla, char iconoCasilla) : id(idCasilla), icono(iconoCasilla) {

}

int Casilla::getId(){
    return id;
}

char Casilla::getIcono(){
    return icono;
}

void Casilla::setId(int nuevoId){
    id = nuevoId;
}

void Casilla::setIcono(char nuevoIcono){
    icono = nuevoIcono;
}


//SERPIENTE
Serpiente::Serpiente(int idSerpiente, char iconoSerpiente, int penaltyS):Casilla(idSerpiente, iconoSerpiente), penalty(penaltyS){

}

int Serpiente::getPenalty(){
    return penalty;
}

void Serpiente::setPenalty(int nuevoPenalty){
    penalty = nuevoPenalty;
}


//ESCALERA
Escalera::Escalera(int idEscalera, char iconoEscalera, int rewardE):Casilla(idEscalera, iconoEscalera), reward(rewardE){

}

int Escalera::getReward(){
    return reward;
}

void Escalera::setReward(int nuevoReward){
    reward = nuevoReward;
}


// JUGADOR
Jugador::Jugador(int playerId) : id(playerId){

}

int Jugador::getId(){
    return id; 

}


//TABLERO
Tablero::Tablero(int size, int numSerpientes, int penalty, int numEscaleras, int reward, int numPlayers){
    board.resize(size); 
    jugadores.reserve(numPlayers); // Reservar espacio para el número de jugadores

    for (int i = 1; i <= numPlayers; ++i) { //Ciclo for para añadir jugadores
        jugadores.emplace_back(i);
    }

    inicializarTablero(numSerpientes, penalty, numEscaleras, reward);
}

Tablero::~Tablero() {
    for (Casilla* casilla : board) {
        delete casilla;
    }
}

void Tablero::inicializarTablero(int numSerpientes, int penalty, int numEscaleras, int reward){
    srand(time(0)); //Iniciar semilla de valores aleatorios

    vector<int> positions(board.size());
    iota(positions.begin(), positions.end(), 0); //Lena el vector de números que serán los IDs

    random_shuffle(positions.begin(), positions.end()); //Mezcla aleatoriamente los valores del vector

    int contador = 0;
    for (int pos : positions) {
            if (contador < numSerpientes) {
                board[pos] = new Serpiente(pos, 'S', penalty);
                contador++;
            } 
            
            else if (contador < numSerpientes + numEscaleras) {
                board[pos] = new Escalera(pos, 'L', reward);
                contador++;
            } 
            
            else {
                board[pos] = new Casilla(pos, 'N');
            }
        }

    board[0] = new Casilla(0, 'N');    //Ni primera ni la última casilla pueden ser especiales
    board[board.size() - 1] = new Casilla(board.size() - 1, 'N');
}

void Tablero::printTablero(vector<int>& posiciones) {
    int numRows = (int)ceil((double)board.size() / 10); // Calcula el número de filas, asumiendo 10 columnas por fila
    int numCols = (int)ceil((double)board.size() / numRows); // Calcula el número de columnas en función del número de filas

    vector<vector<string>> tablero(numRows, vector<string>(numCols, "N")); // Inicializa un tablero vacío

    // Marcar las serpientes (S) y escaleras (L)
    for (int i = 0; i < board.size(); ++i) {
        if (dynamic_cast<Serpiente*>(board[i])) {
            int row = i / numCols;
            int col = i % numCols;
            tablero[row][col] = "S";
        } 
        
        else if (dynamic_cast<Escalera*>(board[i])) {
            int row = i / numCols;
            int col = i % numCols;
            tablero[row][col] = "L";
        }

    

    }

    // Actualizar las posiciones de los jugadores
    for (size_t i = 0; i < posiciones.size(); ++i) {
        int jugadorId = i + 1; // ID del jugador, comenzando desde 1
        int pos = posiciones[i]; // Posición actual del jugador
        int row = pos / numCols; // Fila en la que se encuentra el jugador
        int col = pos % numCols; // Columna en la que se encuentra el jugador

        // Asigna el ID del jugador a la casilla
        if (tablero[row][col] == "N" || tablero[row][col] == "S" || tablero[row][col] == "L") {
            tablero[row][col] = std::to_string(jugadorId); 
        } 
        
        else { // Si ya hay un jugador en la casilla
            tablero[row][col] = "B"; // Marca la casilla como ocupada por múltiples jugadores
        }
    }

    // Imprime el tablero
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl; // Imprime nueva línea al final de cada fila
    }
    cout << endl;
}




int Tablero::getUpdatedPosition(int position) {
    Casilla*casilla = board[position];
    if (Escalera*escalera = dynamic_cast<Escalera*>(casilla)) { /*dynamic_cast asegura una 
    conversion de punteros entre clases*/
        cout << "Ha caído en una casilla de escaleras ( L )" << endl;
        cout << "Avanza " << escalera -> getReward() << " casillas" << endl;
        return min((int)board.size() - 1, position + escalera->getReward()); /*Cambia la posición y
        se asegura que no se salga del tablero*/
    }
    if (Serpiente*serpiente = dynamic_cast<Serpiente*>(casilla)) {
        cout << "Ha caído en una casilla de serpiente ( S )" << endl;
        cout << "Retrocede " << serpiente -> getPenalty() << " casillas" << endl;
        return max(0, position - serpiente->getPenalty()); /*Cambia la posición y
        se asegura que no sea menor que 0*/
    }
    else {
        
        cout << "Ha caído en una casilla normal ( N )" << endl;
        return position;
        
    }
}
