//
// Created by alfonso on 18/02/20.
//

#include "rutascpp.h"

LocalidadE::LocalidadE(const Localidad &loc) {

    id = loc.id;
    pob = loc.pob;
    lng = loc.lng;
    lat = loc.lat;
    x = loc.x;
    y = loc.y;
    z = loc.z;

    distancia_min_eventos=0.0;
    pob_bene=0;
    distancia_promedio=0.0;
    distanciapob=0.0;
}
