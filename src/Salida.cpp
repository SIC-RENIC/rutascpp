//
// Created by alfonso on 18/02/20.
//

#include "Salida.h"


/**
 * Metodo que imprime las localidades seleccionadas
 */
void Salida::imprimeLocsP(vector<LocalidadE> &vloce) {

    sort(vloce.begin(), vloce.end(), [](const LocalidadE &loc1, const LocalidadE &loc2) {
        return loc1.distancia_min_eventos < loc2.distancia_min_eventos;
    });

    ofstream fsal;

    fsal.open(nomarch + "_locs.csv");

    fsal << "id,lng,lat,distancia_min_eventos,pob_bene,distaciapob,distancia_promedio" << endl;

    for (auto itloc = vloce.begin(); itloc != vloce.end(); ++itloc) {
        fsal << itloc->id << ",";
        fsal.precision(9);
        fsal << itloc->lng << "," << itloc->lat;
        fsal.precision(6);
        fsal << "," << itloc->distancia_min_eventos << ","
             << itloc->pob_bene << "," << itloc->distanciapob << "," << itloc->distancia_promedio << endl;
    }

    fsal.close();
}

/**
 *
 * @param vloce
 * @param nomarch
 */
Salida::Salida(string nomarch) : nomarch(nomarch) {}

/**
 * Método que imprime los datos de la Ruta
 */
void Salida::imprimeDatosRuta(Ruta &r) {

    ofstream fsal;

    fsal.open(nomarch + "_ruta.txt");

    fsal << r.dist_eve << endl;
    fsal << r.costorec << endl;
    fsal << r.pobtot << endl;
    fsal << r.costopob << endl;

    for (auto itloc = r.vloc.begin(); itloc != r.vloc.end(); ++itloc) {
        fsal << itloc->id << "|";
    }

    fsal << endl;

    fsal.close();
}

