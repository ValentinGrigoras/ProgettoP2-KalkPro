#ifndef ECCEZIONI_H
#define ECCEZIONI_H
#include <QString>

class Eccezioni {
private:
    QString error;
public:
    Eccezioni(QString = "Errore sconosciuto");
    void printError() const;
};

class TypeErr : public Eccezioni {
public:
    TypeErr(QString = "Errore di tipo");
};

class UndefValue : public Eccezioni {
public:
    UndefValue(QString = "Valore non definito");
};

class EmptyObj : public Eccezioni {
public:
    EmptyObj(QString = "Oggetto non presente");
};

class OperatErr : public Eccezioni {
public:
    OperatErr(QString = "Errore operazione");
};

class EmptyPoly : public EmptyObj {
public:
    EmptyPoly(QString = "Poligono non implementato");
};

class ViewUndefValue : public UndefValue {
public:
    ViewUndefValue(QString = "Valore non definito nella View");
};

#endif // ECCEZIONI_H
