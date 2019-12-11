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
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));


   QRegExp rx("[A-Za-z_]+");//[A-Za-z0-9_]
      QRegExp   rx1("[0-9_]+");
        QValidator *validator = new QRegExpValidator(rx, this);
        QValidator *validator2 = new QRegExpValidator(rx1, this);
        ui->lineEdit->setValidator(validator);
ui->lineEdit_nom_2->setValidator(validator);
ui->lineEdit_id_3->setValidator(validator2);
ui->lineEdit_4->setValidator(validator2);
ui->lineEdit_3->setValidator(validator);

}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::sendMail()
{
    Smtp* smtp = new Smtp("nour.bouali@esprit.tn","yarabi123456", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("nour.bouali@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void Dialog::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
void Dialog::on_pb_ajouter_2_clicked()
{  QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit->text();
    int id = ui->lineEdit_id_3->text().toInt();
     int cin = ui->lineEdit_4->text().toInt();
    QString adresse =ui->lineEdit_3->text();



  employee e(nom,prenom,id,cin,adresse);
  bool test=e.ajouter();
  if(test)
{ ui->tabetudiant_2->setModel(tmpemp.afficher("select *from EMPLOYEE"));//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un employee"),
                  QObject::tr("employee ajuoté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employee"),
                  QObject::tr("Erreur**** !.\n"
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
       int cin=ui->lineEdit_id_8->text().toInt();
       QString adresse=ui->lineEdit_id_7->text();
        employee e(nom,prenom,id,cin,adresse);
       bool test=e.modifier();

       if(test){ui->tabetudiant_2->setModel(tmpemp.afficher("select * from EMPLOYEE"));
           QMessageBox::information(nullptr, QObject::tr("Modifier un employee"),
           QObject::tr("successful.\n"
                       "employee ajouter."), QMessageBox::Cancel);
       }
       else{
           QMessageBox::critical(nullptr, QObject::tr("modifier un employee"),
           QObject::tr("failed.\n"
                       "Click Cancel to exit."), QMessageBox::Cancel);
       }

}

void Dialog::on_pushButton_clicked()
{
    Dialog::hide();
}

void Dialog::on_pushButton_2_clicked()
{
    Dialog::hide();

}

void Dialog::on_pushButton_3_clicked()
{
    Dialog::hide();

}
