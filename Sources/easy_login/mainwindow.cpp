#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
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

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text().toAscii().toHex().toBase64();    // neo
    QString password = ui->lineEdit_2->text().toAscii().toHex().toBase64();  // w4k3Upne00

    if(username == "NmU2NTZm" && password == "NzczNDZiMzM1NTcwNmU2NTMwMzA="){
        QMessageBox::information(this,"","Correct!!");
    }else{
        QMessageBox::information(this,"","Try Harder");
    }

}
