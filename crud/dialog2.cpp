#include "dialog2.h"
#include "ui_dialog2.h"
#include"departement.h"
#include<QMessageBox>
Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);




    QRegExp rx("[A-Za-z_]+");//[A-Za-z0-9_]
       QRegExp   rx1("[0-9_]+");
         QValidator *validator = new QRegExpValidator(rx, this);
         QValidator *validator2 = new QRegExpValidator(rx1, this);
       ui->lineEdit_nom_2->setValidator(validator);
       ui->lineEdit->setValidator(validator2);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pb_ajouter_2_clicked()
{
    QString type= ui->lineEdit_nom_2->text();

        int nombre_emp = ui->lineEdit->text().toInt();

      departement e(type,nombre_emp);
      bool test=e.ajouter();
      if(test)

    { ui->tabetudiant_2->setModel(tmpdep.afficher("select *from DEPARTEMENT"));//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un departement"),
                      QObject::tr("departement ajuoté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un departement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog2::on_pb_supprimer_2_clicked()
{
    int nombre_emp = ui->lineEdit_id_supp->text().toInt();
    bool test=tmpdep.supprimer(nombre_emp);
    if(test)
    {ui->tabetudiant_2->setModel(tmpdep.afficher("select *from DEPARTEMENT"));//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un departement"),
                    QObject::tr("DEPARTEMENT supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un departement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog2::on_lineEdit_2_textChanged(const QString &arg1)
{
    QString r;
    r="select *from DEPARTEMENT where NOMBRE_EMP like "+arg1;
    ui->tabetudiant_4->setModel(tmpdep.afficher(r));
}




void Dialog2::on_trie_id_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from departement order by NOMBRE_EMP");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMBRE_EMP"));
ui->tabetudiant_2->setModel(model);
}

void Dialog2::on_pushButton_3_clicked()

{
    Dialog2::hide();

}
