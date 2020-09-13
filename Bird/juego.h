#ifndef JUEGO_H
#define JUEGO_H

#include<columna.h>

class Juego {

public:
   Juego();
   void  moverTxoria();
   int lengthX;
   int lengthY;
   int getColor(int i, int j);
   void sincronizar();
   void avanceTablero();
   void nuevaColumna();
   void todoNegro();
   void cargarBateria();
   bool getPerdido();
   int  getRound();
   void increaseRound();



private:

  Columna columnas[5]; //Solo mostramos 3 a la vez
  int txoria; // altura del pajaro
  int tablero[100][75];
  int avance; // para saber dónde esta la primera columna
  int bateria; // para saber cuando subir.
  bool perdido;
  int round;

};

#endif // JUEGO_H
