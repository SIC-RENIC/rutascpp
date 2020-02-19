//
// Created by alfonso on 16/02/20.
//

#ifndef RUTASCPP_ALGORITMO_H
#define RUTASCPP_ALGORITMO_H

#include "rutascpp.h"

class Algoritmo {


private:
    vector<Localidad>& vLoc;
    vector<Ruta>& vRuta;
    vector<LocalidadE>& vLocE;

    double_t distprom_e;
    double_t poblacion_total;

    double_t distanciaML2L(Localidad &p1, Localidad &p2);

    double_t distanciaML2R(Ruta &r,Localidad &loc);

    void calculaEstRuta();

    void calculaPobBen(Ruta &r,Localidad& leve);

    void calculaPobBen(LocalidadE& loc);

    void buscaLocalidad(void);



public:
    Algoritmo(vector<Localidad> &vLoc, vector<Ruta> &vRuta, vector<LocalidadE> &vLocE);
};


#endif //RUTASCPP_ALGORITMO_H
