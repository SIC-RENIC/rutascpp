//
// Created by alfonso on 18/02/20.
//

#include "Salida.h"



void Salida::imprime() {

    sort(vloce.begin(),vloce.end(),[](const LocalidadE& loc1,const LocalidadE& loc2){return loc1.distancia_min_eventos<loc2.distancia_min_eventos;});

    ofstream fsal;

    fsal.open(nomarch);

    for(auto itloc=vloce.begin(); itloc != vloce.end(); ++itloc) {
            fsal << itloc->id << "," << itloc->lng << "," << itloc->lat << "," << itloc->distancia_min_eventos << ","
                 << itloc->pob_bene << "," << itloc->distanciapob << "," << itloc->distancia_promedio << endl;
    }


    fsal.close();


}

Salida::Salida(vector<LocalidadE> &vloce, string nomarch) : vloce(vloce), nomarch(nomarch) {
    imprime();
}

