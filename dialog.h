#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"employee.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_trie_id_clicked();

    void on_trie_id_2_clicked();

    void on_modifier_clicked();

private:
    Ui::Dialog *ui;
    employee tmpemp;
};

#endif // DIALOG_H
