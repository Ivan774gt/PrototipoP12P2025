#ifndef VOTACION_H
#define VOTACION_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
class Votacion {
private:
    string* candidatos;
    int** votos;
    int* totalVotos;
    int numCandidatos;

public:
    Votacion(int numCandidatos);
    ~Votacion();

    void ingresarCandidatos();
    void simularVotacion();
    void mostrarResultados();
    void imprimirLinea();
};

#endif
