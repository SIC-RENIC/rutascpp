//
// Created by alfonso on 17/02/20.
//

#ifndef RUTASCPP_LOCALIDADE_H
#define RUTASCPP_LOCALIDADE_H



class LocalidadE : public Localidad{
public:
    double_t distancia_min_eventos;

    int pob_bene;
    double_t distancia_promedio;
    double_t distanciapob;

    LocalidadE(const Localidad & loc);

};




#endif //RUTASCPP_LOCALIDADE_H
