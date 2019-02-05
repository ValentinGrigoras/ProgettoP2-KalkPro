#include<View/formetab.h>
#include<Exception/eccezioni.h>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QGridLayout>
#include <QPalette>
FormeTab::FormeTab(QWidget *parent): QWidget(parent){

createOptionsGroupBox();
createDrawBox();
createOperationsGroupBox();
createLatiGroupBox();
QVBoxLayout *leftLayout = new QVBoxLayout;
QHBoxLayout *leftAndCentralLayout = new QHBoxLayout;
QHBoxLayout *rightLayout = new QHBoxLayout;

leftLayout->addWidget(horizontalGroupBox);
leftLayout->addWidget(operationsGroupBox);
rightLayout->addWidget(latiGroupBox);

leftAndCentralLayout->addItem(leftLayout);
leftAndCentralLayout->addWidget(drawGroupBox);
leftAndCentralLayout->addWidget(latiGroupBox);
setLayout(leftAndCentralLayout);

connect(disegna,SIGNAL(clicked()),this,SLOT(polygonRouter()));
connect(this,SIGNAL(disegnaCirconferenza(QPointF,double)),drawbox,SLOT(disegnaCirconferenza(QPointF,double)));
connect(this,SIGNAL(drawEdgedPolygon(QPolygonF)),drawbox,SLOT(drawEdgedPolygon(QPolygonF)));
connect(this,SIGNAL(updateDrawingColor(QString)),drawbox,SLOT(updateDrawingColor(QString)));
connect(calcolaArea,SIGNAL(clicked()),this,SIGNAL(trovaArea()));
connect(calcolaPerimetro,SIGNAL(clicked()),this,SIGNAL(findPerimetro()));
connect(calcolaBaricentro,SIGNAL(clicked()),this,SIGNAL(findBaricentro()));
connect(calcolaLati,SIGNAL(clicked()),this,SIGNAL(findLati()));
connect(this,SIGNAL(drawPoint(QPoint)),drawbox,SLOT(drawPoint(QPoint)));
connect(drawbox,SIGNAL(sendRadius(double)),this,SIGNAL(sendRadius(double)));
connect(drawbox,SIGNAL(sendPolygonPoint(QPointF,uint)),this,SIGNAL(sendPolygonPoint(QPointF,uint)));



}
void FormeTab::createOptionsGroupBox(){
        horizontalGroupBox = new QGroupBox(tr("Cosa vuoi disegnare?"));
        horizontalGroupBox->setStyleSheet("QGroupBox::title {subcontrol-origin: margin;subcontrol-position: top center;} QGroupBox{ font-size: 7pt;font-weight: bold;color:#00264d;}");

        //horizontalGroupBox->setFixedHeight(200);
       // horizontalGroupBox->setFixedWidth(250);

        polygonSelector = new QComboBox(this);
        polygonSelector->addItem(tr("Cerchio"));
        polygonSelector->addItem(tr("Triangolo"));
        polygonSelector->addItem(tr("Quadrilatero"));
        disegna = new QPushButton("Disegna",this);
        disegna->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgb(0, 51, 102), stop:1 rgb(0, 64, 128))}  QPushButton {background-color: #00264d;color:#e6e6e6; border: 1px solid black;border-radius: 5px; padding: 8px;font-size: 7pt;font-weight: bold;} ");
        QVBoxLayout * layout = new QVBoxLayout;

        layout->addWidget(polygonSelector);
        layout->addWidget(disegna);
        horizontalGroupBox->setLayout(layout);
}
void FormeTab::createDrawBox(){
        drawGroupBox = new QGroupBox(tr("Il tuo disegno"));
        QHBoxLayout *layout = new QHBoxLayout;
        drawbox = new DrawBox(this);

       // drawGroupBox->setFixedHeight(450);
       // drawGroupBox->setFixedWidth(500);
        drawGroupBox->setStyleSheet("QGroupBox::title {subcontrol-origin: margin;subcontrol-position: top center;} QGroupBox{ font-size: 7pt;font-weight: bold;color:#00264d;} margin-left:10px;");//togliere "border" se non si vede il disegno

        layout->addWidget(drawbox);
        drawGroupBox->setLayout(layout);
}
void FormeTab::createOperationsGroupBox(){
    operationsGroupBox = new QGroupBox(tr("Operazioni disponibili"));
    operationsGroupBox->setStyleSheet("QGroupBox::title {subcontrol-origin: margin;subcontrol-position: top center;} QGroupBox{ font-size: 7pt;font-weight: bold;color:#00264d;}");
    calcolaArea = new QPushButton("Trova Area",this);
    calcolaArea->setEnabled(false);
   // calcolaArea->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgb(0, 51, 102), stop:1 rgb(0, 64, 128))} QPushButton:disabled{background-color:#f7fbff;color:#00264d} QPushButton {background-color: #00264d;color:#e6e6e6; border: 1px solid black;border-radius: 5px; padding: 8px;font-size: 7pt;font-weight: bold;} ");
calcolaArea->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgb(0, 51, 102), stop:1 rgb(0, 64, 128))}  QPushButton {background-color: #00264d;color:#e6e6e6; border: 1px solid black;border-radius: 5px; padding: 8px;font-size: 7pt;font-weight: bold;} ");

    calcolaPerimetro = new QPushButton("Trova Perimetro",this);
    calcolaPerimetro->setEnabled(false);
    //calcolaPerimetro->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgb(0, 51, 102), stop:1 rgb(0, 64, 128))} QPushButton:disabled{background-color:#e6f2ff;color:#00264d} QPushButton {background-color: #00264d;color:#e6e6e6; border: 1px solid black;border-radius: 5px; padding: 8px;font-size: 7pt;font-weight: bold;} ");
calcolaPerimetro->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgb(0, 51, 102), stop:1 rgb(0, 64, 128))} QPushButton {background-color: #00264d;color:#e6e6e6; border: 1px solid black;border-radius: 5px; padding: 8px;font-size: 7pt;font-weight: bold;} ");

    calcolaBaricentro = new QPushButton("Trova e Disegna Baricentro",this);
    calcolaBaricentro->setEnabled(false);
    calcolaBaricentro->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgb(0, 51, 102), stop:1 rgb(0, 64, 128))} QPushButton {background-color: #00264d;color:#e6e6e6; border: 1px solid black;border-radius: 5px; padding: 8px;font-size: 7pt;font-weight: bold;} ");
    //calcolaBaricentro->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgb(0, 51, 102), stop:1 rgb(0, 64, 128))} QPushButton:disabled{background-color:#d5eaff;color:#00264d} QPushButton {background-color: #00264d;color:#e6e6e6; border: 1px solid black;border-radius: 5px; padding: 8px;font-size: 7pt;font-weight: bold;} ");

    calcolaLati = new QPushButton("Trova lunghezza lati",this);
    calcolaLati->setStyleSheet("QPushButton:pressed {background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,   stop:0 rgb(0, 51, 102), stop:1 rgb(0, 64, 128))} QPushButton {background-color: #00264d;color:#e6e6e6; border: 1px solid black;border-radius: 5px; padding: 8px;font-size: 7pt;font-weight: bold;} QPushButton:disabled{background-color:#ecf0f1;color:#000; border:none;}");
    calcolaLati->setEnabled(false);


    QGridLayout *mainLayout = new QGridLayout;
   //operationsGroupBox->setFixedHeight(200);
   operationsGroupBox->setFixedWidth(250);
    mainLayout->addWidget(calcolaArea,0,0,1,3);
    mainLayout->addWidget(calcolaPerimetro,1,0,1,3);
    mainLayout->addWidget(calcolaBaricentro,2,0,1,3);
    mainLayout->addWidget(calcolaLati,3,0,1,3);
    operationsGroupBox->setLayout(mainLayout);

}
void FormeTab::createLatiGroupBox(){
    latiGroupBox = new QGroupBox(tr("Informazioni sui lati"));
    latiGroupBox->setStyleSheet("QGroupBox::title {subcontrol-origin: margin;subcontrol-position: top center;} QGroupBox{ font-size: 7pt;font-weight: bold;color:#00264d;} padding: 8px;");
    /*latiGroupBox->setFixedHeight(400);
    latiGroupBox->setFixedWidth(200);*/
    //latiGroupBox->setFixedHeight(400);
    latiGroupBox->setFixedWidth(250);
    labelLato1 = new QLabel("Primo Lato");
    labelLato1->setStyleSheet("color:#00264d; padding: 8px;font-size: 7pt;font-weight: bold;} ");
    labelLato2 = new QLabel("Secondo Lato");
    labelLato2->setStyleSheet("color:#00264d; padding: 8px;font-size: 7pt;font-weight: bold;} ");
    labelLato3 = new QLabel("Terzo Lato");
    labelLato3->setStyleSheet("color:#00264d; padding: 8px;font-size: 7pt;font-weight: bold;} ");
    labelLato4 = new QLabel("Quarto Lato");
    labelLato4->setStyleSheet("color:#00264d; padding: 8px;font-size: 7pt;font-weight: bold; ");
    labelArea = new QLabel("Area");
    labelArea->setStyleSheet("color:#00264d; padding: 8px;font-size: 7pt;font-weight: bold; ");
    labelPerimetro = new QLabel("Perimetro");
    labelPerimetro->setStyleSheet("color:#00264d; padding: 8px;font-size: 7pt;font-weight: bold; ");



    lcdLato1 = new QLCDNumber(8);
    lcdLato1->setSegmentStyle(QLCDNumber::Flat);



    lcdLato2 = new QLCDNumber(8);
    lcdLato2->setSegmentStyle(QLCDNumber::Flat);
    lcdLato2->setStyleSheet("color:#00264d; padding: 8px;font-size: 7pt;font-weight: bold;");

    lcdLato3 = new QLCDNumber(8);
    lcdLato3->setSegmentStyle(QLCDNumber::Flat);
    lcdLato3->setStyleSheet("color:#00264d; padding: 8px;font-size: 7pt;font-weight: bold; ");

    lcdLato4 = new QLCDNumber(8);
    lcdLato4->setSegmentStyle(QLCDNumber::Flat);
    lcdLato4->setStyleSheet("color:#00264d; padding: 8px;font-size: 7pt;font-weight: bold; ");


    lcdArea = new QLCDNumber(8);
    lcdArea->setSegmentStyle(QLCDNumber::Flat);
    lcdArea->setStyleSheet("color:#00264d; padding: 8px;font-size: 7pt;font-weight: bold; ");

    lcdPerimetro = new QLCDNumber(8);
    lcdPerimetro->setSegmentStyle(QLCDNumber::Flat);
    lcdPerimetro->setStyleSheet("color:#00264d; padding: 8px;font-size: 7pt;font-weight: bold; ");


    lcdLato1->setMaximumHeight(25);
    lcdLato2->setMaximumHeight(25);
    lcdLato3->setMaximumHeight(25);
    lcdLato4->setMaximumHeight(25);
    lcdArea->setMaximumHeight(25);
    lcdPerimetro->setMaximumHeight(25);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(labelLato1,0,0,1,3);
    mainLayout->addWidget(lcdLato1,0,3,1,1);
    mainLayout->addWidget(labelLato2,1,0,1,3);
    mainLayout->addWidget(lcdLato2,1,3,1,1);
    mainLayout->addWidget(labelLato3,2,0,1,3);
    mainLayout->addWidget(lcdLato3,2,3,1,1);
    mainLayout->addWidget(labelLato4,3,0,1,3);
    mainLayout->addWidget(lcdLato4,3,3,1,1);
    mainLayout->addWidget(labelArea,4,0,1,3);
    mainLayout->addWidget(lcdArea,4,3,1,1);
    mainLayout->addWidget(labelPerimetro,5,0,1,3);
    mainLayout->addWidget(lcdPerimetro,5,3,1,1);
    latiGroupBox->setLayout(mainLayout);
}
void FormeTab::polygonRouter() {
    lcdArea->display(0);
    lcdPerimetro->display(0);
    lcdLato1->display(0);
    lcdLato2->display(0);
    lcdLato3->display(0);
    lcdLato4->display(0);
    emit(fetchPolygon(polygonSelector->currentIndex()));
    emit(setPolygonMode(polygonSelector->currentIndex()));
}
void FormeTab::setPolygonMode(int i){
   try {
        if(i==0)
        {
            polygonSelector->setCurrentIndex(0);
            calcolaArea->setEnabled(true);
            calcolaPerimetro->setEnabled(true);
            calcolaBaricentro->setEnabled(true);
            calcolaLati->setEnabled(false);
            lcdLato1->display("");
            lcdLato2->display("");
            lcdLato3->display("");
            lcdLato4->display("");
        }
        else if (i==1) {
            polygonSelector->setCurrentIndex(1);
            calcolaArea->setEnabled(true);
            calcolaPerimetro->setEnabled(true);
            calcolaBaricentro->setEnabled(true);
            calcolaLati->setEnabled(true);          
        }
        else if (i==2) {
            polygonSelector->setCurrentIndex(2);
            calcolaArea->setEnabled(true);
            calcolaPerimetro->setEnabled(true);
            calcolaBaricentro->setEnabled(true);
            calcolaLati->setEnabled(true);
        }
        else
            throw ViewUndefValue("Inizializzazione di operando poligono non valida. Operando inizializzato a Circonferenza.");
        }
    catch (Eccezioni k) {
        polygonSelector->setCurrentIndex(0);
        calcolaArea->setEnabled(true);
        calcolaPerimetro->setEnabled(true);
        calcolaBaricentro->setEnabled(true);
        calcolaLati->setEnabled(false);
        k.printError();
    }
}
void FormeTab::setPolygonOperand(int i) {
    try {
        if(i>=0 && i < polygonSelector->count())
            polygonSelector->setCurrentIndex(i);
        else
            throw ViewUndefValue("Inizializzazione di operando poligono non valida. Operando inizializzato a Circonferenza.");
    }
    catch (Eccezioni k) {
        polygonSelector->setCurrentIndex(0);
        k.printError();
    }
}

void FormeTab::showArea(double d) {
    QString s = QString::number(d, 'f',2);
    lcdArea->display(s);
}

void FormeTab::showPerimetro(double d) {
    QString s = QString::number(d, 'f',2);
    lcdPerimetro->display(s);
}

void FormeTab::showBaricentro(QPoint p) {
    emit(drawPoint(p));
}

void FormeTab::showLati(QVector<double> q) {
    QString s;
    if(q.size()>0) {
        s = QString::number(q[0], 'f',2);
        lcdLato1->display(s);
    }
    if(q.size()>1) {
        s = QString::number(q[1], 'f',2);
        lcdLato2->display(s);
    }
    if(q.size()>2) {
        s = QString::number(q[2], 'f',2);
        lcdLato3->display(s);
    }
    if(q.size()>3) {
        s = QString::number(q[3], 'f',2);
        lcdLato4->display(s);
    }
}
FormeTab::~FormeTab(){
    delete drawbox;
    delete calcolaArea;
    delete calcolaPerimetro;
    delete calcolaBaricentro;
    delete calcolaLati;
    delete lcdLato1;
    delete lcdLato2;
    delete lcdLato3;
    delete lcdLato4;
    delete lcdArea;
    delete lcdPerimetro;
}
