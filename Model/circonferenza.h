#ifndef CIRCONFERENZA_H
#define CIRCONFERENZA_H

#include "punto.h"
#include "poligono.h"
#include<QtMath>

class Circonferenza : public Poligono {
private:
  Punto centro;
  double raggio;

public:
  Circonferenza(const Punto&, unsigned int);
  Circonferenza(const Circonferenza&);
  virtual ~Circonferenza()=default;
  double Area() const;
  double Perimetro() const;
  Punto Baricentro() const;   //da controllare il tipo di ritorno

  double getRaggio() const;

  void setRaggio(double);
};

#endif // CIRCONFERENZA_H
