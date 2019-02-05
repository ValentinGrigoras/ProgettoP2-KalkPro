#ifndef TABDIALOG_H
#define TABDIALOG_H
#include<QDialog>
#include<QTabWidget>
#include<QDialogButtonBox>
#include "formetab.h"

class TabDialog:public QDialog
{
    Q_OBJECT
public:
    explicit TabDialog( QWidget *parent = 0);
    ~TabDialog();
private:
    QTabWidget *tabWidget;
    QDialogButtonBox *buttonBox;
    FormeTab *formeT;
    DrawBox *drawB;

signals:


    void setResult(QString);
    void fetchPolygon(int);
    void setPolygonMode(int);
    void setPolygonOperand(int);
    void disegnaCirconferenza(QPointF,double);
    void drawEdgedPolygon(QPolygonF);
    void updateDrawingColor(QString);
    void trovaArea();
    void findPerimetro();
    void findBaricentro();
    void findLati();
    void showArea(double);
    void showPerimetro(double);
    void showBaricentro(QPoint);
    void showLati(QVector<double>);
    void sendRadius(double);
    void sendPolygonPoint(QPointF,uint);

};

#endif // TABDIALOG_H
