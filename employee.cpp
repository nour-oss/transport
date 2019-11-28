#include "employee.h"

employee::employee()
{ nom ="";
    prenom ="";

    id=0;

}
employee ::employee(QString nom,QString prenom,int id){

    this->nom=nom;
    this->prenom=prenom;

this->id=id;
}
QString employee ::getnom(){
    return nom;}

QString employee ::getprenom(){
    return prenom;}

int employee::getid(){
    return id;}

bool employee ::ajouter(){

  QSqlQuery query;
  //QString res= QString::number(CIN);
  query.prepare("INSERT INTO EMPLOYEE (NOM,PRENOM,ID)"
                "VALUES (:NOM, :PRENOM, :ID)");

  query.bindValue(":NOM", nom);
  query.bindValue(":PRENOM", prenom);

  query.bindValue(":ID", id);



  return    query.exec();
}


QSqlQueryModel *employee::afficher(QString r)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery(r);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));

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

    model->setQuery("select * from employee order by ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
    return model;
}
bool employee::modifier(){


    QSqlQuery query;
    query.prepare("Update EMPLOYEE set NOM=:NOM,PRENOM=:PRENOM,ID=:ID where ID=:ID");
    query.bindValue(":NOM", getnom());
     query.bindValue(":PRENOM", getprenom());
    query.bindValue(":ID", getid());
    return query.exec();







}
