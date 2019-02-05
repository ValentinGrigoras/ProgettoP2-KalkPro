#ifndef POLIGONO_H
#define POLIGONO_H
#include "forma.h"
#include "punto.h"
#include <QVector>

class Poligono:public Forma
{
private:
  QVector<Punto*> vertici;

public:
    Poligono(const QVector<Punto*>& = QVector<Punto*>());// costruttore ad un argomento con argomento di default
    virtual double Area() const=0;
    virtual double Perimetro() const;
    Punto Baricentro() const;
    double Lato(unsigned int) const;
    QVector<double> getLati() const;
    Punto getVertice(unsigned int) const;
    void setVertice(unsigned int, const Punto&);
    unsigned int contaVertici() const;
    virtual ~Poligono();

protected:
  void AddVertice(const Punto&);
};

#endif // POLIGONO_H
