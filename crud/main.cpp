#include "mainwindow.h"
#include <QApplication>
#include<QMessageBox>
#include<connexion.h>
#include<QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

   connexion c;
   bool test=c.ouvrirconnexion();
   if(test){

    w.show();
    QMessageBox::information(nullptr, QObject::tr("data base is open"),QObject::tr("connexion successful"),QMessageBox::Cancel);
   }else QMessageBox::critical(nullptr,QObject::tr("data base is not open"),QObject::tr("connexion failed"),QMessageBox::Cancel);















    return a.exec();
}
