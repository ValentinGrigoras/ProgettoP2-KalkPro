#include "tabdialog.h"
#include <QFileInfo>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include "formetab.h"
#include<QSize>

TabDialog::TabDialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;


    tabWidget = new QTabWidget(this);


    formeT = new FormeTab(this);

    mainLayout->addWidget(tabWidget);

    tabWidget->addTab(formeT,tr("Forme Geometriche"));
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Close
                                        | QDialogButtonBox::Cancel);

       connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
       connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);




       mainLayout->addWidget(buttonBox);

       setWindowTitle(tr("KalkProP2"));
       QSize bestsize(1100,600);
       setMaximumSize(bestsize);
       setMinimumSize(bestsize);
       setLayout(mainLayout);

       connect(formeT,SIGNAL(fetchPolygon(int)),this,SIGNAL(fetchPolygon(int)));
       connect(this,SIGNAL(disegnaCirconferenza(QPointF,double)),formeT,SIGNAL(disegnaCirconferenza(QPointF,double)));
       connect(this,SIGNAL(drawEdgedPolygon(QPolygonF)),formeT,SIGNAL(drawEdgedPolygon(QPolygonF)));

       connect(this,SIGNAL(setPolygonMode(int)),formeT,SLOT(setPolygonMode(int)));
       connect(this,SIGNAL(setPolygonOperand(int)),formeT,SLOT(setPolygonOperand(int)));
       connect(this,SIGNAL(updateDrawingColor(QString)),formeT,SIGNAL(updateDrawingColor(QString)));
       connect(formeT,SIGNAL(trovaArea()),this,SIGNAL(trovaArea()));
       connect(formeT,SIGNAL(findPerimetro()),this,SIGNAL(findPerimetro()));
       connect(formeT,SIGNAL(findBaricentro()),this,SIGNAL(findBaricentro()));
       connect(formeT,SIGNAL(findLati()),this,SIGNAL(findLati()));
       connect(this,SIGNAL(showArea(double)),formeT,SLOT(showArea(double)));
       connect(this,SIGNAL(showPerimetro(double)),formeT,SLOT(showPerimetro(double)));
       connect(this,SIGNAL(showBaricentro(QPoint)),formeT,SLOT(showBaricentro(QPoint)));
       connect(this,SIGNAL(showLati(QVector<double>)),formeT,SLOT(showLati(QVector<double>)));
       connect(formeT,SIGNAL(sendRadius(double)),this,SIGNAL(sendRadius(double)));
       connect(formeT,SIGNAL(sendPolygonPoint(QPointF,uint)),this,SIGNAL(sendPolygonPoint(QPointF,uint)));

}
TabDialog::~TabDialog() {
    delete formeT;
}
