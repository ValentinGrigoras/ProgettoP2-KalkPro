#include "eccezioni.h"
#include <QString>
#include <iostream>

Eccezioni::Eccezioni(QString s) : error(s) {}

void Eccezioni::printError() const {
    std::cout << error.toStdString() << std::endl;
}

TypeErr::TypeErr(QString s) : Eccezioni(s) {}

UndefValue::UndefValue(QString s) : Eccezioni(s) {}

EmptyObj::EmptyObj(QString s) : Eccezioni(s) {}

OperatErr::OperatErr(QString s) : Eccezioni(s) {}

EmptyPoly::EmptyPoly(QString s) : EmptyObj(s) {}

ViewUndefValue::ViewUndefValue(QString s) : UndefValue(s) {}
