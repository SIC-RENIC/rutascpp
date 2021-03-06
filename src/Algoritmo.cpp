//
// Created by alfonso on 16/02/20.
//

#include "Algoritmo.h"

/**
 *
 * @param vLoc
 * @param vRuta
 */
Algoritmo::Algoritmo(vector<Localidad> &vLoc, vector<Ruta> &vRuta, vector<LocalidadE> &vLocE)
        : vLoc(vLoc), vRuta(vRuta), vLocE(vLocE) {

    calculaEstRuta();
    buscaLocalidad();
}

/**
 * Metodo que calcula la distancia entre 2 localidades en metros
 * @param p1
 * @param p2
 * @return
 */
double_t Algoritmo::distminML2L(Localidad &p1, Localidad &p2) {

    double d = (p1.x * p2.x);
    d += (p1.y * p2.y);
    d += (p1.z * p2.z);

    d = (d < -1.0) ? -1.0 : d;
    d = (d > 1.0) ? 1.0 : d;

    return RT * acos(d);

}

/**
 * Método que calcula la estadística básica de una ruta
 */
void Algoritmo::calculaEstRuta() {

    size_t tam = vRuta[0].vloc.size();

    if (tam == 0) return;

    vRuta[0].pobtot = vRuta[0].vloc[0].pob;

    if (tam >= 1) {
        for (size_t i = 1; i < tam; i++) {
            vRuta[0].costorec += distminML2L(vRuta[0].vloc[i], vRuta[0].vloc[i - 1]);
            vRuta[0].pobtot += vRuta[0].vloc[i].pob;
        }
    }

    vRuta[0].dist_eve = vRuta[0].costorec / vRuta[0].vloc.size();

    for (auto it = vRuta[0].vloc.begin(); it != vRuta[0].vloc.end(); ++it) {
        calculaPobBen(vRuta[0], *it);
    }

}

/**
 * Método que calcula la población beneficiaria de los eventos a un radio maximo
 * @param leve
 */
void Algoritmo::calculaPobBen(Ruta &r, Localidad &leve) {

    for (auto it = vLoc.begin(); it != vLoc.end(); ++it) {
        double_t daux = distminML2L(*it, leve);
        if (daux <= radio_max) {
            r.pobtot += it->pob;
            r.costopob += it->pob * daux;
        }
    }

}

/**
 * Método que busca una localidad que se de la mejor atencion posible como candidata a recibir un evento
 */
void Algoritmo::buscaLocalidad() {
    double_t distE = vRuta[0].dist_eve;
    cout << "Distancia entre eventos: " << distE << endl;

    for (auto it = vLoc.begin(); it != vLoc.end(); ++it) {
        bool besta = false;

        auto iter = find(vRuta[0].vloc.begin(), vRuta[0].vloc.end(), *it);
        if (iter != vRuta[0].vloc.end()) {
            besta = true;
        }

        if (!besta) {
            double_t daux = distminML2R(vRuta[0], *it);
            if (daux >= distE && daux <= 3 * distE && it->pob >= pob_min_e) {
                LocalidadE loce = *it;
                loce.distancia_min_eventos = distminML2R(vRuta[0], loce);
                calculaPobBen(loce);
                vLocE.push_back(loce);
            }
        }
    }


}

/**
 * Método que calcula la distancia mínima a una ruta
 * @param r
 * @param loc
 * @return
 */
double_t Algoritmo::distminML2R(Ruta &r, Localidad &loc) {

    double_t daux, dmin = 4 * RT;

    for (auto it = r.vloc.begin(); it != r.vloc.end(); ++it) {

        daux = distminML2L(*it, loc);
        if (daux <= dmin) {
            dmin = daux;
        }
    }

    return dmin;
}

/**
 * Metodo que calcula la poblacion potencial total beneficiada de una localidad donde ocurre un evento
 * @param loc
 */
void Algoritmo::calculaPobBen(LocalidadE &loc) {

    for (auto it = vLoc.begin(); it != vLoc.end(); ++it) {
        double_t daux = this->distminML2L(*it, loc);
        if (daux <= radio_max) {
            loc.pob_bene += it->pob;
            loc.distanciapob += (it->pob * daux);
        }
    }

    if (loc.pob_bene > 0) {
        loc.distancia_promedio = loc.distanciapob / loc.pob_bene;
    } else {
        loc.distancia_promedio = -1;
    }
}
