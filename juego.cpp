#include "juego.h"

Juego :: Juego(){

    this-> lengthX = 100;
    this-> lengthY = 75;
    this-> avance = 0;
    this->perdido = false;
    this->round = 1;
    todoNegro();


    this->columnas[0] = Columna(100);
    //Ponemos las columnas
    for(int i=1; i<=4;i++){

        this->columnas[i] = Columna(31-round);

    }

    //POnemos el pájaro
    this->txoria=35;
    this->bateria=0;

}

void Juego :: moverTxoria(){
  tablero[12][this->txoria]=0; // borrar esa casilla
//movemos

  if(this->bateria==0)
    this->txoria++;

  else {
      this->txoria--;
      bateria--;

  }

  // comprobamos si hemos perdido
  if ((avance<=4) && ((avance>=-1)) ){   //Primero hay que comprobar que el pájaro estta a la altura de la valla
    if ( ((this->txoria < columnas[0].getInferior()*75/100))  || ((this->txoria+5) > (75 - columnas[0].getSuperior()*75/100)) )
    { perdido=true;}
     }
  }

void Juego :: cargarBateria(){

    this->bateria=8;

}

void Juego :: todoNegro(){
    //Pintamos todo de negro
    for(int i=0; i<lengthX ; i++) {

        for(int j=0; j<lengthY ; j++) {

            tablero[i][j]=0;
        }

    }
}

void Juego :: nuevaColumna(){


    for(int i=0; i<4; i++){
        this->columnas[i] = columnas[i+1];
    }

    this->columnas[4]= Columna(31-round);
}

int Juego :: getColor(int i, int j){

    return tablero[i][j];
}

void Juego :: sincronizar(){

    todoNegro();

    //Sincronizamos txoria
  tablero[12][txoria]=1;

    //Sincronizamos columnas
    for(int i=0; i<4;i++){
        for(int j=0;j<75;j++)
        {
            if ( (j<(columnas[i].getInferior()*75/100)) ||  ((75-j)<(columnas[i].getSuperior()*75/100)) )
               this->tablero[25*(i)+13+avance][j] = 2;

        }

    }

}

void Juego :: avanceTablero(){



    if(avance==-13) {nuevaColumna(); avance=12;}

    this->avance-=1;
}

bool Juego :: getPerdido(){
    return perdido;
}

int Juego :: getRound(){

    return this->round;}

void Juego :: increaseRound(){
    this->round++;
}
