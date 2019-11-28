#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class employee
{ private:
    QString nom,prenom;
    int id;

public:
    employee();
    employee(QString,QString ,int );
    QString getnom();
          QString getprenom();

          int getid();
                bool ajouter();
                QSqlQueryModel *afficher(QString r);
                    bool supprimer (int);
                    bool modifier ();
                    QSqlQueryModel * trieid();

};


#endif // EMPLOYEE_H
