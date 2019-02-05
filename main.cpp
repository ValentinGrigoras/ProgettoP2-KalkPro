#include "View/tabdialog.h"
#include "Controller/datamanager.h"
#include <QApplication>
#include <iostream>
#include "Exception/eccezioni.h"
int main(int argc, char *argv[])
{
     QApplication app(argc, argv);


    TabDialog * view = new TabDialog();
    DataManager dm(view);

    view->show();

    return app.exec();
}
