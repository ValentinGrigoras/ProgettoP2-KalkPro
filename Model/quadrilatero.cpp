#include "quadrilatero.h"

Quadrilatero::Quadrilatero(const Punto& p1, const Punto& p2, const Punto& p3, const Punto& p4) : Poligono() {
    AddVertice(p1);
    AddVertice(p2);
    AddVertice(p3);
    AddVertice(p4);
}

double Quadrilatero::Area() const {
    QVector<double> l = getLati();
    double diag1 = Punto::distanzaDuePunti((getVertice(0)),(getVertice(2)));
    double diag2 = Punto::distanzaDuePunti((getVertice(1)),(getVertice(3)));
    double diag = std::min(diag1, diag2);

    if(diag1 <= diag2) {
        double semiP1 = (l[0]+l[1]+diag)/2;
        double area1 = sqrt(semiP1 * (semiP1-l[0]) * (semiP1-l[1]) * (semiP1-diag));
        double semiP2 = (diag+l[2]+l[3])/2;
        double area2 = sqrt(semiP2 * (semiP2-diag) * (semiP2-l[2]) * (semiP2-l[3]));
        return area1+area2;
    }
    else {
        double semiP1 = (l[0]+l[3]+diag)/2;
        double area1 = sqrt(semiP1 * (semiP1-l[0]) * (semiP1-l[3]) * (semiP1-diag));
        double semiP2 = (diag+l[1]+l[2])/2;
        double area2 = sqrt(semiP2 * (semiP2-diag) * (semiP2-l[1]) * (semiP2-l[2]));
        return area1+area2;
    }
}
