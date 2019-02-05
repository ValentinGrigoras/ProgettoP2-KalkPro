#include "datamanager.h"
#include "Exception/eccezioni.h"
#include <iostream>
DataManager::DataManager(TabDialog* t):view(t)
{
    poli = 0;


//segnali dalla view


    connect(view,SIGNAL(fetchPolygon(int)),this,SLOT(fetchPolygon(int)));
    connect(view,SIGNAL(fetchPolygon(int)),this,SLOT(drawPolygon(int)));
    connect(view,SIGNAL(trovaArea()),this,SLOT(trovaArea()));
    connect(view,SIGNAL(findRaggio()),this,SLOT(findRaggio()));
    connect(view,SIGNAL(findPerimetro()),this,SLOT(findPerimetro()));
    connect(view,SIGNAL(findBaricentro()),this,SLOT(findBaricentro()));
    connect(view,SIGNAL(findLati()),this,SLOT(findLati()));
    connect(view,SIGNAL(sendRadius(double)),this,SLOT(setRadius(double)));
    connect(view,SIGNAL(sendPolygonPoint(QPointF,uint)),this,SLOT(setPolygonPoint(QPointF,uint)));


//segnali verso la view

    connect(this,SIGNAL(setResult(QString)),view,SIGNAL(setResult(QString)));
    connect(this,SIGNAL(disegnaCirconferenza(QPointF,double)),view,SIGNAL(disegnaCirconferenza(QPointF,double)));
    connect(this,SIGNAL(drawEdgedPolygon(QPolygonF)),view,SIGNAL(drawEdgedPolygon(QPolygonF)));
    connect(this,SIGNAL(setPolygonMode(int)),view,SIGNAL(setPolygonMode(int)));
    connect(this,SIGNAL(setPolygonOperand(int)),view,SIGNAL(setPolygonOperand(int)));
    connect(this,SIGNAL(updateDrawingColor(QString)),view,SIGNAL(updateDrawingColor(QString)));
    connect(this,SIGNAL(showArea(double)),view,SIGNAL(showArea(double)));
    connect(this,SIGNAL(showPerimetro(double)),view,SIGNAL(showPerimetro(double)));
    connect(this,SIGNAL(showBaricentro(QPoint)),view,SIGNAL(showBaricentro(QPoint)));
    connect(this,SIGNAL(showLati(QVector<double>)),view,SIGNAL(showLati(QVector<double>)));
    connect(this,SIGNAL(showRaggio(double)),view,SIGNAL(showRaggio()));


}

void DataManager::fetchPolygon(int i) {
    try {
        if(i==0) {
            if(poli)
                delete poli;
            poli = new Circonferenza(Punto(0,0), 50);
        }
        else if(i==1) {
            if(poli)
                delete poli;
            poli = new Triangolo(Punto(-50,30),Punto(50,30),Punto(0,-50));
        }
        else if (i==2) {
            if(poli)
                delete poli;
            poli = new Quadrilatero(Punto(-50,50),Punto(50,50),Punto(50,-50),Punto(-50,-50));
        }
        else
            throw EmptyPoly("Impossibile creare questo poligono.");
    }
    catch(Eccezioni k) {
        k.printError();
    }

}

void DataManager::drawPolygon(int i) {
    try {
        emit(setPolygonMode(i));
        if(i==0) {
            Circonferenza* temp = static_cast<Circonferenza*>(poli);
            double x = temp->Baricentro().getX();
            double y = temp->Baricentro().getY();
            emit(disegnaCirconferenza(QPointF(x,y),temp->getRaggio()));
        }
        else if (i>0) {
            Poligono* temp = static_cast<Poligono*>(poli);
            QPolygonF p;
            double x;
            double y;
            for (unsigned int j = 0; j < temp->contaVertici(); ++j) {
                    x = temp->getVertice(j).getX();
                    y = temp->getVertice(j).getY();
                    QPointF q = QPointF(x,y);
                    p.push_back(q);
                }
            emit(drawEdgedPolygon(p));
        }
    }
    catch(Eccezioni k) {
        k.printError();
    }
}


void DataManager::trovaArea() {
    emit(showArea(poli->Area()));
}

void DataManager::findPerimetro() {
    emit(showPerimetro(poli->Perimetro()));
}

void DataManager::findBaricentro() {
    QPoint p = QPoint(poli->Baricentro().getX(),poli->Baricentro().getY());
    emit(showBaricentro(p));
}

void DataManager::findLati() {
    try {
        if(dynamic_cast<Poligono*>(poli))
            emit(showLati(static_cast<Poligono*>(poli)->getLati()));
        else
            throw TypeErr();
    }
    catch(Eccezioni k) {
        k.printError();
    }
}

void DataManager::setRadius(double r) {
    try {
        if(dynamic_cast<Circonferenza*>(poli))
            static_cast<Circonferenza*>(poli)->setRaggio(r);
        else
            throw TypeErr();
    }
    catch(Eccezioni k) {
        k.printError();
    }
}

void DataManager::setPolygonPoint(QPointF p, uint i) {
    try {
        Punto t(p.x(),p.y());
        if(dynamic_cast<Poligono*>(poli))
            static_cast<Poligono*>(poli)->setVertice(i,t);
        else
            throw TypeErr();
    }
    catch(Eccezioni k) {
        k.printError();
    }
}
