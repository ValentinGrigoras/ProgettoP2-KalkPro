#include "poligono.h"

Poligono::Poligono(const QVector<Punto*>& v):vertici(v){}

double Poligono::Perimetro() const {
    double perim = 0;
    QVector<double> lati = getLati();
    for(QVector<double>::const_iterator it= lati.begin();it!=lati.end();++it) {
        perim += *it;
    }
    return perim;
}

unsigned int Poligono::contaVertici() const {
    unsigned int nVertici = 0;
    for(QVector<Punto*>::const_iterator cit=vertici.begin(); cit != vertici.end(); ++cit) {
        nVertici++;
    }
    return nVertici;
}

Punto Poligono::Baricentro() const {
    unsigned int nVertici = contaVertici();
    double numerX = 0;
    double numerY = 0;
    for(unsigned int i=0; i<nVertici; ++i) {
        numerX += vertici[i]->getX();
        numerY += vertici[i]->getY();
    }
    return Punto(numerX/nVertici,numerY/nVertici);

}
QVector<double> Poligono::getLati() const {
    QVector<double> aux; //vector ausiliario
    for(QVector<Punto*>::const_iterator it=vertici.begin(); it != vertici.end()-1; ++it) {
        aux.push_back(Punto::distanzaDuePunti(**it,**(it+1)));
    }
    aux.push_back(Punto::distanzaDuePunti(*(vertici.first()),*(vertici.last())));
    return aux;
}
double Poligono::Lato(unsigned int l) const {
    return getLati()[l];
}

Punto Poligono::getVertice(unsigned int i) const {
    return *vertici[i];
}

void Poligono::setVertice(unsigned int i, const Punto& p) {
    vertici[i]->setX(p.getX());
    vertici[i]->setY(p.getY());
}
void Poligono::AddVertice(const Punto& p){
    vertici.push_back(new Punto(p));
}
Poligono::~Poligono(){
    for(QVector<Punto*>::iterator it=vertici.begin(); it != vertici.end(); ++it) {
        delete *it;
    }
}
