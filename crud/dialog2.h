#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include"departement.h"

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr);
    ~Dialog2();

private slots:
    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_trie_id_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog2 *ui;
    departement tmpdep;
};

#endif // DIALOG2_H
