//
// Created by alfonso on 18/02/20.
//

#ifndef RUTASCPP_SALIDA_H
#define RUTASCPP_SALIDA_H

#include "rutascpp.h"

class Salida {
private:
    vector<LocalidadE>& vloce;
public:
    Salida();

    Salida(vector<LocalidadE> &vloce);

    void imprime();
};


#endif //RUTASCPP_SALIDA_H
