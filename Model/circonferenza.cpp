#include "circonferenza.h"
#include "punto.h"

Circonferenza::Circonferenza(const Punto& p, unsigned int r) : centro(p), raggio(r) {}
Circonferenza::Circonferenza(const Circonferenza& C):Poligono(), centro(C.centro), raggio(C.raggio){}

double Circonferenza::Area() const {
    return raggio * raggio * M_PI;

}

double Circonferenza::Perimetro() const {
    return  2 * raggio * M_PI;

}

Punto Circonferenza::Baricentro() const {
    return centro;
}

double Circonferenza::getRaggio() const {
    return raggio;
}

void Circonferenza::setRaggio(double d) {
    raggio  = d;
}
