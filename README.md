# SerpientesYEscaleras2
Versión final del juego de Serpientes y Escaleras. Ahora el usuario puede modificar el número de casillas que tendrá el tablero, el número de casillas especiales (Serpientes y Escaleras) que habrán en el mismo, cuántas casillas avanzan o retroceden en las casillas especiales, el número de jugadores y el máximo de turnos. Finalizado el 30/05/2024

Santiago Patricio Gómez Ochoa | A01735171
Programación Orientada a Objetos
31/05/2024

INSTRUCCIONES DE USO DEL JUEGO DE SERPIENTES Y ESCALERAS

NÚMERO DE JUGADORES: 2 en adelante

----- PRIMER PASO -----
Se debe descomnprimir los archivos de la carpeta .zip. 
Dicha carpeta incluye el archivo .h y el archivo .cpp 
de la clase "Tablero" y el archivo main llamado "snakes.cpp".
Este último es el archivo que se ejecutará para comenzar el juego. 

----- SEGUNDO PASO -----
Una vez descomprimida la carpeta, abrir una powershell o
una terminal en la ubicación en la que se descargaron los archivos,
y una vez realizado esto, ingresar en la powershell o terminal las siguientes instrucciones:

Instrucción para compilar el programa
> g++ game.cpp    

Instrucción para ejecutar el programa
> ./a.out

Posteriormente, esperar a que aparezca la siguiente leyenda:
"--------------- SERPIENTES Y ESCALERAS ---------------"

----- TERCER PASO -----
Seguir las instrucciones que aparecen a continuación. 
Se le pedirá que elija una de las opciones entre "C" (continuar con el juego)
y "E" (salir del juego). El juego no le dejará ingresar ninguna otra letra
y le seguirá pidiendo que ingrese alguna de estas dos letras. Puede ingresarlas
ya sea en mayúscula o en minúscula.

Si ingresa la tecla "E", el programa terminará, y tendrá que volver
a ingresar las instrucciones en la powershell (indicadas en el SEGUNDO PASO)
para volver a ejecutar el programa. 

Si ingresa la tecla "C", continuará con la configuración.

----- CUARTO PASO -----
Deberá configurar los parámetros del juego, como número de jugadores,
el tamaño del tablero, cantidad de casillas especiales, al igual que cuántas
casillas retrocederá o avanzará y el límite de turnos que tendrá el juego.

Después, podrá elegir entre ejecutarlo de forma automática o manual.

Si elije de forma automática, el juego transcurrirá sólo, y parará hasta que
un jugador gane, o se alcance el límite de turnos

Si se elije el modo manual, juego imprimirá el tablero en el que los jugadores aparecerán en la misma casilla (la primera).
Cada jugador tiene que teclear la letra "D" para tirar el dado. Una vez que lo hagan, 
se mostrará su nueva posición en el tablero, cuántas casillas avanzó, en qué número de casilla se encuentra,
y en qué tipo de casilla cayó. Posteriormente, será el turno del siguiente jugador. Esto se repetirá hasta
que un jugador llegue a la última casilla, o se alcance el máximo de turnos. Cuando eso suceda, el juego indicará si hubo ganadores, 
y el programa terminará. 



HERENCIA Y POLIMORFISMO

En estos programas de Serpientes y Escaleras, se aplicaron la herencia y el polimorfismo de las siguientes maneras:

Herencia
La herencia se utilizó para crear clases especializadas a partir de una clase base. La clase base es Casilla, que tiene propiedades comunes a todas las casillas del tablero, como id e icono. Luego, se derivan dos clases especializadas de Casilla:

Clase Serpiente: hereda de Casilla y añade la propiedad específica penalty.
Clase Escalera: hereda de Casilla y añade la propiedad específica reward.
Esto permite que las clases Serpiente y Escalera reutilicen la estructura y el comportamiento básicos de Casilla, añadiendo solo las funcionalidades específicas de cada tipo de casilla.

Polimorfismo
El polimorfismo se implementó a través del uso de punteros y la función dynamic_cast. En la clase Tablero, se utiliza un vector de punteros a Casilla (std::vector<Casilla*> board), que puede contener objetos de las clases derivadas Serpiente y Escalera. Esto permite tratar todas las casillas de manera uniforme, pero también realizar operaciones específicas dependiendo del tipo real de cada casilla en tiempo de ejecución.
