#ifndef FORMA_H
#define FORMA_H

#include <QString>
#include "punto.h"
class Forma
{

public:

    Forma();


    //metodi virtuali puri
    virtual double Area() const=0;
    virtual double Perimetro() const=0;
    virtual Punto Baricentro() const=0;

    virtual ~Forma()=default;
};


#endif // FORMA_H
