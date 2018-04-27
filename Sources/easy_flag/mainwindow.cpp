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
    if(ui->lineEdit->text().toUtf8().toBase64() == "RkxBR3tFQVNZX0xJS0VfMTIzNH0="){
        QMessageBox::information(this,"","Correct!");
    }else{
        QMessageBox::information(this,"","Try Harder");
    }
}
