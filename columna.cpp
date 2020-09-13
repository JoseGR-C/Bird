#include "columna.h"
#include<cstdlib>

Columna :: Columna(){
    this->columna_inferior = rand()%100;
    this->columna_superior = 100-50-columna_inferior;
}

Columna :: Columna( int dificultad ){
    if (dificultad<100){
    //Dificultad es un numero de 100->10
    this->columna_inferior = rand()%(100-dificultad);
    this->columna_superior = 100-dificultad-this->columna_inferior;
}
    else {
        this->columna_inferior = 0;
        this->columna_superior = 0;
    }
}

void Columna :: getColumna (int * superior, int * inferior)
{
    superior =& this->columna_superior;
    inferior =& this->columna_inferior;
}

int Columna :: getSuperior(){
    return this->columna_superior;
}

int Columna :: getInferior(){
    return this->columna_inferior;
}
