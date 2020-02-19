//
// Created by alfonso on 17/02/20.
//

#ifndef RUTASCPP_RUTA_H
#define RUTASCPP_RUTA_H

#include <vector>

using namespace std;

class Ruta {

public:
    int ruta_id;

    vector<Localidad> vloc;

    int pobtot;

    double_t costorec;
    double_t costopob;

    double_t dist_eve;
};


#endif //RUTASCPP_RUTA_H
