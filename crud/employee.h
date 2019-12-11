#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class employee
{ private:
    QString nom,prenom,adresse;
    int cin,id;


public:
    employee();
    employee(QString,QString,int,int,QString );
    QString getnom();
          QString getprenom();
int getid();
int getcin();
QString getadresse();

                bool ajouter();
                QSqlQueryModel *afficher(QString r);
                    bool supprimer (int);
                    bool modifier ();
                    QSqlQueryModel * trieid();

};


#endif // EMPLOYEE_H
