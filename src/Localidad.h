//
// Created by alfonso on 17/02/20.
//

#ifndef RUTASCPP_LOCALIDAD_H
#define RUTASCPP_LOCALIDAD_H



class Localidad {

public:
    int id;

    double_t lat;
    double_t lng;

    double_t x;
    double_t y;
    double_t z;

    int pob;

    bool operator==(const Localidad &loc) const {
        return loc.id==id;
    }


};


#endif //RUTASCPP_LOCALIDAD_H
