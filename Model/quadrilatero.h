#ifndef QUADRILATERO_H
#define QUADRILATERO_H
#include "poligono.h"
#include <QVector>

class Quadrilatero : public Poligono {
public:
  Quadrilatero(const Punto&, const Punto&, const Punto&, const Punto&);
  double Area() const;//la calcoliamo dividendo in due con una diagonale, e calcolando per due triangoli generici
};

#endif // QUADRILATERO_H
