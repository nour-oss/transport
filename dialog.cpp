#include "dialog.h"
#include "ui_dialog.h"
#include"employee.h"
#include<QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tabetudiant_2->setModel(tmpemp.afficher("select * from EMPLOYEE"));





}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pb_ajouter_2_clicked()
{  QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit->text();
    int id = ui->lineEdit_id_3->text().toInt();

  employee e(nom,prenom,id);
  bool test=e.ajouter();
  if(test)
{ui->tabetudiant_2->setModel(tmpemp.afficher("select *from EMPLOYEE"));//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employee"),
                  QObject::tr("employee ajuoté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employee"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void Dialog::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id_supp->text().toInt();
    bool test=tmpemp.supprimer(id);
    if(test)
    {ui->tabetudiant_2->setModel(tmpemp.afficher("select *from EMPLOYEE"));//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Etudiant supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_lineEdit_2_textChanged(const QString &arg1)
{
    QString r;
    r="select *from EMPLOYEE where ID like "+arg1;
    ui->tabetudiant_4->setModel(tmpemp.afficher(r));
}

void Dialog::on_trie_id_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from employee order by ID");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
ui->tabetudiant_2->setModel(model);
}



void Dialog::on_modifier_clicked()//el code mtaa& el bouton mtaa el modifier
{
    int id=ui->lineEdit_id_5->text().toInt();
       QString nom=ui->lineEdit_id_4->text();
       QString prenom=ui->lineEdit_id_6->text();
        employee e(nom,prenom,id);
       bool test=e.modifier();

       if(test){ui->tabetudiant_2->setModel(tmpemp.afficher("select * from EMPLOYEE"));
           QMessageBox::critical(nullptr, QObject::tr("Modifier un employee"),
           QObject::tr("successful.\n"
                       "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else{
           QMessageBox::critical(nullptr, QObject::tr("modifier un employee"),
           QObject::tr("failed.\n"
                       "Click Cancel to exit."), QMessageBox::Cancel);
       }

}
