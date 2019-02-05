#include "punto.h"
#include <math.h>

Punto::Punto(double a, double b) : x(a), y(b) {}
Punto::Punto(const Punto& p):x(p.x),y(p.y){}
double Punto::getX() const {return x;}

double Punto::getY() const {return y;}

Punto Punto::getPunto() const {return Punto(x,y);}

void Punto::setPunto(const Punto& p) {
    x = p.getX();
    y = p.getY();
}

void Punto::setX(double i) {x = i;}

void Punto::setY(double i) {y = i;}


double Punto::distanzaDuePunti(const Punto& a, const Punto& b) {
return sqrt(pow(b.getX() - a.getX(), 2)+pow(b.getY() - a.getY(), 2));


}
