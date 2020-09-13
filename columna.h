#ifndef COLUMNA_H
#define COLUMNA_H


class Columna
{
private:
    int columna_superior;
    int columna_inferior;

public:
    Columna();
    Columna( int dificultad);
    void  getColumna(int *superior, int *inferior);
    int getSuperior();
    int getInferior();
};

#endif // COLUMNA_H
