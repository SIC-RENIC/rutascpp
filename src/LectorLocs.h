//
// Created by alfonso on 16/02/20.
//

#ifndef RUTASCPP_LECTORLOCS_H
#define RUTASCPP_LECTORLOCS_H

#include "rutascpp.h"

class LectorLocs {

private:
    string sarchivo;
    vector<Localidad> &vlocs;

    void inicializa(void);

    void parser(string scad);

    void split(vector<string> &vscad, const string &scad, const string &delimitador);

    void cesfe2carte(double_t lat, double_t lng, double_t *res);

    int eml2conapo(int e, int m, int l) { return (e * 1000 + m) * 10000 + l; }

    double_t deg2rad(double_t x) { return M_PI * x / 180.00; }

public:
    LectorLocs(string sarchivo, vector<Localidad> &vlocs);

};


#endif //RUTASCPP_LECTORLOCS_H
