//
// Created by alfonso on 16/02/20.
//

#include "LectorLocs.h"

LectorLocs::LectorLocs(string sarchivo, vector<Localidad>& vlocs) : vlocs(vlocs) {
    this->sarchivo = sarchivo;
    inicializa();
}

void LectorLocs::inicializa(void) {
    string sline;

    ifstream miarch;

    miarch.open(sarchivo.c_str(), ifstream::in);

    while (getline(miarch, sline)) {
        parser(sline);
    }

    miarch.close();
}

void LectorLocs::parser(string scad) {
    vector<string> vc;
    split(vc,scad,DELIMETER);

    if(vc.size()==6){
        Localidad loc;

        loc.id=eml2conapo(atoi(vc[0].c_str()),atoi(vc[1].c_str()),atoi(vc[2].c_str()));

        loc.lng=atof(vc[3].c_str());
        loc.lat=atof(vc[4].c_str());

        double_t * res = new double_t[3];

        cesfe2carte(deg2rad(loc.lat),deg2rad(loc.lng),res);

        loc.x=*res;
        loc.y=*(res+1);
        loc.z=*(res+2);

        delete[] res;

        loc.pob=atoi(vc[5].c_str());

        vlocs.push_back(loc);
    }

}

void LectorLocs::split(vector<string> &vscad, const string &scad, const string &delimitador) {
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

void LectorLocs::cesfe2carte(double_t lat, double_t lng, double_t *res) {
    double_t r2=0;

    *(res)=sin(lng)*cos(lat);
    *(res+1)=cos(lng)*cos(lat);
    *(res+2)=sin(lat);

    r2=pow(*(res),2)+pow(*(res+1),2)+pow(*(res+2),2);
    r2=sqrt(r2);

    *(res)/=r2;
    *(res+1)/=r2;
    *(res+2)/=r2;
}
