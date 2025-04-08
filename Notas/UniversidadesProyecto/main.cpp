#include "Votacion.h"
using namespace std;
int main() {
    srand(time(0));
    char opcion;
    int numcalculos =0;

    do {
        int numCandidatos;
        cout << "Ingrese el numero de Alumnos: ";
        cin >> numCandidatos;

        Votacion votacion(numCandidatos);
        votacion.ingresarCandidatos();
        votacion.simularVotacion();
        votacion.mostrarResultados();

        cout << "¿Desea realizar otra comparacion? (S/N): ";
        cin >> opcion;

        numcalculos++;

    } while (opcion == 'S' || opcion == 's');

    return 0;
}
