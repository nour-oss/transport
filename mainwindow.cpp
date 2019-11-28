#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "dialog2.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog d;
    d.setModal(true);
    d.exec();
}

void MainWindow::on_pushButton_clicked()
{
    Dialog2 d2;
    d2.setModal(true);
    d2.exec();
}
