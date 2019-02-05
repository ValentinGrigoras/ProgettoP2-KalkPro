#ifndef TRIANGOLO_H
#define TRIANGOLO_H
#include "poligono.h"

class Triangolo: public Poligono
{
public:
    Triangolo(const Punto&, const Punto&, const Punto&);
    double Area() const;//formula di erone
    double Altezza()const;

};

#endif // TRIANGOLO_H
