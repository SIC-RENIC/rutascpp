//
// Created by alfonso on 16/02/20.
//

#include "LectorRutas.h"


LectorRutas::LectorRutas(string sarch, vector<Ruta> &vruta, vector<Localidad> &vloc) : vruta(vruta), vloc(vloc) {
    sarchivo = move(sarch);

    rutas_id = 1;
    inicializa();
}

void LectorRutas::inicializa(void) {
    string sline;

    ifstream miarch;

    miarch.open(sarchivo.c_str(), ifstream::in);

    Ruta r;
    r.ruta_id = rutas_id;
    r.costopob = 0.0;
    r.pobtot = 0;
    r.costorec = 0.0;

    while (getline(miarch, sline)) {
        parser(r, sline);
    }

    vruta.push_back(r);
    rutas_id++;

    miarch.close();
}

void LectorRutas::parser(Ruta &r, string scad) {
    vector<string> vc;
    split(vc, scad, DELIMETER);

    if (vc.size() == 3) {
        ponLocalidad(r, eml2conapo(atoi(vc[0].c_str()), atoi(vc[1].c_str()), atoi(vc[2].c_str())));
    }

}

void LectorRutas::split(vector<string> &vscad, const string &scad, const string &delimitador) {
    size_t start = 0, end = 0;

    while (end != string::npos) {
        end = scad.find(delimitador, start);

        // If at end, use length=maxLength.  Else use length=end-start.
        vscad.push_back(scad.substr(start,
                                    (end == string::npos) ? string::npos : end - start));

        // If at end, use start=maxSize.  Else use start=end+delimiter.
        start = ((end > (string::npos - delimitador.size()))
                 ? string::npos : end + delimitador.size());
    }
}

void LectorRutas::ponLocalidad(Ruta &r, int id) {

    for (auto it = vloc.begin(); it != vloc.end(); ++it) {
        if (it->id == id) {
            r.vloc.push_back(*it);
        }
    }


}

