#include "departement.h"

departement::departement()
{

        type ="";

        nombre_emp=0;

}

departement ::departement(QString type,int nombre_emp){


    this->type=type;

this->nombre_emp=nombre_emp;
}
QString departement ::gettype(){
    return type;}


int departement::getnombre_emp(){
    return nombre_emp;}

bool departement ::ajouter(){

  QSqlQuery query;
  //QString res= QString::number(CIN);
  query.prepare("INSERT INTO DEPARTEMENT (TYPE,NOMBRE_EMP)"
                "VALUES (:TYPE, :NOMBRE_EMP)");


  query.bindValue(":TYPE", type);

  query.bindValue(":NOMBRE_EMP", nombre_emp);



  return    query.exec();
}


QSqlQueryModel *departement::afficher(QString r)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery(r);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE_EMP"));

    return  model;


}







bool departement::supprimer(int nombre_emp){

    QSqlQuery query;
    query.prepare("Delete from DEPARTEMENT                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       where NOMBRE_EMP= :NOMBRE_EMP");
    query.bindValue(":NOMBRE_EMP", nombre_emp);
    return query.exec();






}

QSqlQueryModel * departement::trieid()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from employee order by NOMBRE_EMP");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
    return model;
}
bool departement::modifier(){


    QSqlQuery query;
    query.prepare("Update DEPARTEMENT set TYPE=:TYPE,NOMBRE_EMP=:NOMBRE_EMP where NOMBRE_EMP=:NOMBRE_EMP");
    query.bindValue(":TYPE", gettype());
    query.bindValue(":NOMBRE_EMP", getnombre_emp());
    return query.exec();




}
