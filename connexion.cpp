#include "connexion.h"

connexion::connexion()
{

}
bool connexion::ouvrirconnexion(){

    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet_2A")  ;
    db.setUserName("nour");
    db.setPassword("nour");
    if(db.open())
        test=true;
    return test;

}
void connexion::fermerconnexion(){db.close();}
