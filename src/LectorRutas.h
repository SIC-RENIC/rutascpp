//
// Created by alfonso on 16/02/20.
//

#ifndef RUTASCPP_LECTORRUTAS_H
#define RUTASCPP_LECTORRUTAS_H

#include "rutascpp.h"

class LectorRutas {

private:

    string sarchivo;
    vector<Ruta> &vruta;
    vector<Localidad> &vloc;

    int rutas_id;

    void inicializa(void);

    void parser(Ruta &r,string scad);

    void split(vector<string> &vscad, const string &scad, const string &delimitador);

    int eml2conapo(int e, int m, int l) { return (e * 1000 + m) * 10000 + l; }

     void ponLocalidad(Ruta &r,int id);

public:

    LectorRutas(string sarch, vector<Ruta> &vruta, vector<Localidad> &vloc);

};


#endif //RUTASCPP_LECTORRUTAS_H
