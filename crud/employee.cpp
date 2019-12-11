#include "employee.h"

employee::employee()
{ nom ="";
    prenom ="";

    id=0;

}
employee ::employee(QString nom,QString prenom,int id,int cin,QString adresse){

    this->nom=nom;
    this->prenom=prenom;
  this->id=id;
this->cin=cin;
this->adresse=adresse;
}
QString employee ::getnom(){
    return nom;}

QString employee ::getprenom(){
    return prenom;}
int employee::getid(){
    return id;}

int employee::getcin(){
    return cin;}

QString employee ::getadresse(){
    return adresse;}

bool employee ::ajouter(){

  QSqlQuery query;
  QString res= QString::number(cin);
  QString res1= QString::number(id);
  query.prepare("INSERT INTO EMPLOYEE (NOM,PRENOM,ID,CIN,ADRESSE)"
                "VALUES (:NOM, :PRENOM,:ID,:CIN ,:ADRESSE)");

  query.bindValue(":NOM", nom);
  query.bindValue(":PRENOM", prenom);
  query.bindValue(":ID", res1);
query.bindValue(":CIN", res);

query.bindValue(":ADRESSE", adresse);


  return    query.exec();
}


QSqlQueryModel *employee::afficher(QString r)
{
    QSqlQueryModel *model=new QSqlQueryModel();
   /** model->setQuery(r);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));****/

    model->setQuery(r);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
    return  model;


}
bool employee::supprimer(int id){

    QSqlQuery query;
    query.prepare("Delete from EMPLOYEE where ID= :ID");
    query.bindValue(":ID", id);
    return query.exec();






}

QSqlQueryModel * employee::trieid()
{
    QSqlQueryModel * model= new QSqlQueryModel();
/*
    model->setQuery("select * from employee order by ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));*/
    //*********
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));

    return model;
}
bool employee::modifier(){


    QSqlQuery query;
    query.prepare("Update EMPLOYEE set NOM=:NOM,PRENOM=:PRENOM,ID=:ID where ID=:ID");
    query.bindValue(":NOM",nom);
     query.bindValue(":PRENOM", prenom);
    query.bindValue(":ID", id);
    query.bindValue(":CIN", cin);
    query.bindValue(":ADRESSE", adresse);

    return query.exec();







}
