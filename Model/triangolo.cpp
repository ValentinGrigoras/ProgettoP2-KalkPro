#include "triangolo.h"

Triangolo::Triangolo(const Punto& p1, const Punto& p2, const Punto& p3):Poligono()
{
AddVertice(p1);AddVertice(p2);AddVertice(p3);
}

double Triangolo::Area()const{
    double semiPerimetro = Perimetro()/2;
    QVector<double> l = getLati();
    return sqrt(semiPerimetro * (semiPerimetro-l[0]) * (semiPerimetro-l[1]) * (semiPerimetro-l[2]));
}
double Triangolo::Altezza() const {
    return (Area()/2)/Lato(1);
}
