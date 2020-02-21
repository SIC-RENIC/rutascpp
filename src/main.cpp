
/**
 * Para ejecutar probar:
 * ./rutascpp /home/alfonso/NetBeansProjects/RENIC/utiles/cac2/localidades2016.txt ../ruta.txt
 */
#include "rutascpp.h"
#include "LectorLocs.h"
#include "LectorRutas.h"
#include "Algoritmo.h"
#include "Salida.h"

vector<Localidad> vLocs;
vector<Ruta> vRuta;

vector<LocalidadE> vLocsE;

int main(int argc, char *argv[]) {


   /* if (argc < 3) {
        cerr << "No estan completos los parámetros:" << endl;
        cerr << "rutascpp ArchivoLoc ArchivoREve ArchivoSal" << endl << endl;
        cerr << "\t ArchivoLoc:\tArchivo de localidades" << endl;
        cerr << "\t ArchivoREve:\tArchivo de eventos realizados" << endl;
        cerr << "\t ArchivoSal:\tArchivo de salidas" << endl;
        return 1;
    }*/


    LectorLocs mllocs(string(argv[1]),vLocs);

    LectorRutas mlruta(string(argv[2]),vRuta,vLocs);

    cout << "Total de localidades: "<<vLocs.size()<<", puntos ruta: "<<vRuta[0].vloc.size()<<endl;

    Algoritmo malg(vLocs, vRuta,vLocsE);

Salida salida(vLocsE);

    return 0;
}
