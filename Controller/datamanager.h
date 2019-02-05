#ifndef DATAMANAGER_H
#define DATAMANAGER_H


#include <QObject>
#include<QString>
#include "Model/circonferenza.h"
#include "Model/quadrilatero.h"
#include "Model/triangolo.h"
#include "View/tabdialog.h"
class DataManager:public QObject
{
    Q_OBJECT

private:
    TabDialog* view;
    Poligono* poli;

public:

    DataManager(TabDialog*);
    void initializeOperands(int, int);

signals:


    void setResult(QString);
    void disegnaCirconferenza(QPointF,double);
    void drawEdgedPolygon(QPolygonF);
    void setPolygonMode(int);
    void setPolygonOperand(int);
    void updateDrawingColor(QString);
    void showArea(double);
    void showPerimetro(double);
    void showBaricentro(QPoint);
    void showLati(QVector<double>);
public slots:

    void fetchPolygon(int);
    void trovaArea();
    void findPerimetro();
    void findBaricentro();
    void findLati();
    void drawPolygon(int);
    void setRadius(double);
    void setPolygonPoint(QPointF,uint);
};

#endif // DATAMANAGER_H
