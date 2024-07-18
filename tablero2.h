/*
Santiago Patricio Gómez Ochoa
A01735171
31/05/2024
Programación orientada a objetos
*/

#include <string>
#include <list>
#include <vector>
#include <cstdlib>

//CLASE CASILLA
class Casilla{
public:
    

private:
    int id;
    char icono;

public:
    Casilla(int idCasilla, char iconoCasilla);
    virtual ~Casilla() {} //Asegura que Casilla es una clase polimórfica

    int getId();
    char getIcono();
    void setId(int nuevoId);
    void setIcono(char nuevoIcono);
    
};


//CLASE SERPIENTE
class Serpiente : public Casilla{
private:
    int penalty;

public:
    Serpiente(int idSerpiente, char iconoSerpiente, int penaltyS);
    int getPenalty();
    void setPenalty(int nuevoPenalty);
    
};


//CLASE ESCALERA
class Escalera : public Casilla{
private:
    int reward;

public:
    Escalera(int idEscalera, char iconoEscalera, int rewardE);
    int getReward();
    void setReward(int nuevoReward);
    
};


// CLASE JUGADOR
class Jugador {
private:
    int id;
public:
    Jugador(int playerId);
    int getId();
    
};

//CLASE TABLERO
class Tablero{
private:
    std::vector<Casilla*> board;
    std::vector<Jugador> jugadores;
    void inicializarTablero(int numSerpientes, int penalty, int numEscaleras, int reward);
    
public:
    Tablero();
    Tablero(int size, int numSerpientes, int penalty, int numEscaleras, int reward, int numPlayers);
    ~Tablero();  
    void printTablero(std::vector<int>& posiciones);
    int getUpdatedPosition(int position);
    
};