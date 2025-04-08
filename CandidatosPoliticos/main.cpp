#include "Votacion.h"
using namespace std;
int main() {
    srand(time(0));
    char opcion;

    do {
        int numCandidatos;
        cout << "Ingrese el numero de candidatos: ";
        cin >> numCandidatos;

        Votacion votacion(numCandidatos);
        votacion.ingresarCandidatos();
        votacion.simularVotacion();
        votacion.mostrarResultados();

        cout << "¿Desea realizar otra comparacion? (S/N): ";
        cin >> opcion;

    } while (opcion == 'S' || opcion == 's');

    return 0;
}
