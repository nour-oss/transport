#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

#include <QObject>
#include <QWidget>

class departement
{private:
    QString type;
    int nombre_emp;

public:
    departement();
    departement(QString ,int );
    QString gettype();


          int getnombre_emp();
                bool ajouter();
                QSqlQueryModel *afficher(QString r);
                    bool supprimer (int);
                    bool modifier ();
                    QSqlQueryModel * trieid();
};

#endif // DEPARTEMENT_H
