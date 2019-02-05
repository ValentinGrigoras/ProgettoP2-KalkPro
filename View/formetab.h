#ifndef FORME_H
#define FORME_H
#include "drawbox.h"
#include <QFrame>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QLCDNumber>
#include<QFileInfo>
#include<QGroupBox>
#include<QLabel>

class FormeTab: public QWidget{

Q_OBJECT

private:
    QPushButton* selezionaTriangolo;
    QPushButton* selezionaQuadrilatero;
    QPushButton* selezionaCirconferenza;
    QPushButton* calcolaArea;
    QPushButton* calcolaPerimetro;
    QPushButton* calcolaBaricentro;
    QPushButton* calcolaLati;
    DrawBox* drawbox;

    QLabel *labelLato1;
    QLabel *labelLato2;
    QLabel *labelLato3;
    QLabel *labelLato4;
    QLabel *labelArea;
    QLabel *labelPerimetro;

    QLCDNumber* lcdLato1;
    QLCDNumber* lcdLato2;
    QLCDNumber* lcdLato3;
    QLCDNumber* lcdLato4;
    QLCDNumber* lcdArea;
    QLCDNumber* lcdPerimetro;

    QGroupBox *horizontalGroupBox;
    QGroupBox *drawGroupBox;
    QGroupBox *operationsGroupBox;
    QGroupBox *latiGroupBox;
    QComboBox* polygonSelector;
    QPushButton* disegna;

    void createOptionsGroupBox();
    void createDrawBox();
    void createOperationsGroupBox();
    void createLatiGroupBox();

public:
    explicit FormeTab(QWidget* parent = nullptr);

    ~FormeTab();

signals:

  void fetchPolygon(int);
    void disegnaCirconferenza(QPointF,double);
    void drawEdgedPolygon(QPolygonF);
    void updateDrawingColor(QString);
    void trovaArea();
    void findPerimetro();
    void findBaricentro();
    void findLati();
    void drawPoint(QPoint);
    void sendRadius(double);
    void sendPolygonPoint(QPointF,uint);

public slots:
   void setPolygonMode(int);
    void setPolygonOperand(int);
    void showArea(double);
    void showPerimetro(double);
    void showBaricentro(QPoint);
    void showLati(QVector<double>);
    void polygonRouter();
};

#endif // FORMETAB_H
