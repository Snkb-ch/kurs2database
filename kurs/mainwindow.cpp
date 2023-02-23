#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QtGui>
#include<QSqlTableModel>
#include <QDate>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    form = new cafedra;
    connect(this, &MainWindow::signal, form, &cafedra::slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString login = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();



QSqlDatabase db = QSqlDatabase::addDatabase( "QPSQL" );

  db.setDatabaseName( "kurs" );

db.setHostName("localhost");
db.setPort(5433);

     db.setUserName(login);
       db.setPassword(pass);

      if(db.open()){
       //QSqlQuery query( db );


       this->close();
       form->show();


       emit signal(db);
}

}

