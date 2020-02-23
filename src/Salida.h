//
// Created by alfonso on 18/02/20.
//

#ifndef RUTASCPP_SALIDA_H
#define RUTASCPP_SALIDA_H

#include "rutascpp.h"

class Salida {
private:

    string nomarch;

public:


    Salida(string nomarch);

    void imprimeLocsP(vector<LocalidadE> &vloce);

    void imprimeDatosRuta(Ruta &r);
};


#endif //RUTASCPP_SALIDA_H
