#include "Votacion.h"
using namespace std;
Votacion::Votacion(int numCandidatos) {
    this->numCandidatos = numCandidatos;
    candidatos = new string[numCandidatos];
    votos = new int*[numCandidatos];
    totalVotos = new int[numCandidatos] {0};

    for (int i = 0; i < numCandidatos; i++) {
        votos[i] = new int[4]{0};
    }
}

Votacion::~Votacion() {
    for (int i = 0; i < numCandidatos; i++) {
        delete[] votos[i];
    }
    delete[] votos;
    delete[] candidatos;
    delete[] totalVotos;
}

void Votacion::ingresarCandidatos() {
    cin.ignore();
    for (int i = 0; i < numCandidatos; i++) {
        cout << "Ingrese el nombre del Alumno " << i + 1 << ": ";
        getline(cin, candidatos[i]);
    }
}
//agrega las notas aleatorias a cada alumno
void Votacion::simularVotacion() {
    for (int j = 0; j < 4; j++) {
        int votosRestantes = 50;
        for (int i = 0; i < numCandidatos; i++) {
            if (i == numCandidatos - 1) {
                votos[i][j] = votosRestantes;
            } else {
                votos[i][j] = rand() % (votosRestantes - (numCandidatos - i - 1)) + 1;
                votosRestantes -= votos[i][j];
            }
            totalVotos[i] += votos[i][j]/4;
        }
    }
}
//Muestra el total de las notas
void Votacion::mostrarResultados() {
    cout << "\nTabla de notas:\n";
    imprimirLinea();
    cout << "| " << setw(12) << "Alumno" << " | ";
    for (int j = 0; j < 4; j++) {
        cout << "Notas " << j + 1 << " | ";
    }
    cout << "Total  |\n";
    imprimirLinea();

    for (int i = 0; i < numCandidatos; i++) {
        cout << "| " << setw(12) << candidatos[i] << " | ";
        for (int j = 0; j < 4; j++) {
            cout << setw(7) << votos[i][j] << " | ";
        }
        cout << setw(6) << totalVotos[i] << " |\n";
        imprimirLinea();
    }
//muestra el alumno con mayor nota y con menor nota
    int maxVotos = totalVotos[0], minVotos = totalVotos[0];
    int ganador = 0, perdedor = 0;

    for (int i = 1; i < numCandidatos; i++) {
        if (totalVotos[i] > maxVotos) {
            maxVotos = totalVotos[i];
            ganador = i;
        }
        if (totalVotos[i] < minVotos) {
            minVotos = totalVotos[i];
            perdedor = i;
        }
    }

    cout << "\nEl Alumno ganador es: " << candidatos[ganador] << " con " << maxVotos << " Notas.\n";
    cout << "El candidato con menor Nota es: " << candidatos[perdedor] << " con " << minVotos << " Notas.\n";
}


//Divisiones de la tabla al ejecutar el programa
void Votacion::imprimirLinea() {
    cout << "+--------------+---------+---------+---------+---------+---------+-------+\n";
}
