#include "redcaf.h"
#include "qsqlquerymodel.h"
#include "ui_redcaf.h"
#include <QDebug>
#include <QComboBox>
#include <QVariant>
redcaf::redcaf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::redcaf)
{
    ui->setupUi(this);
//redcaf::on_pushButton_14_clicked();

}


redcaf::~redcaf()
{

    delete ui;
}

void redcaf::slot2(QSqlDatabase db)
{
this->db = db;
}


void redcaf::on_pushButton_2_clicked()
{
    QSqlQuery query( db );
    db.open();

QString l = QString("call delcaf('%1')").arg(ui->comboBox->currentText());

     query.exec(l);

redcaf::on_pushButton_14_clicked();
    //query.exec("create table ted(f int)");
}





void redcaf::on_pushButton_3_clicked()
{
    QSqlQuery query( db );
    db.open();


QString l = QString("call updcaf('%1', '%2','%3', '%4','%5')").arg(ui->comboBox_2->currentText(), ui->lineEdit_u1->text(), ui->lineEdit_u2->text(), ui->lineEdit_u3->text(),ui->lineEdit_u4->text());

     query.exec(l);
     redcaf::on_pushButton_14_clicked();

}





void redcaf::on_pushButton_4_clicked()
{
    QString l = QString("call addcaf('%1', '%2','%3', '%4')").arg(ui->lineEdit_i1->text(), ui->lineEdit_i2->text(), ui->lineEdit_i3->text(),ui->lineEdit_i4->text());
    QSqlQuery query( db );
    db.open();

         query.exec(l);
redcaf::on_pushButton_14_clicked();
         ui->lineEdit_i1->clear();
         ui->lineEdit_i2->clear();
         ui->lineEdit_i3->clear();
         ui->lineEdit_i4->clear();
         redcaf::on_pushButton_14_clicked();
         //db.close();
}







void redcaf::on_pushButton_6_clicked()
{

    QSqlQuery query( db );
    db.open();

QString l = QString("call deldisc('%1')").arg(ui->comboBox_4->currentText());

     query.exec(l);
     redcaf::on_pushButton_14_clicked();

}


void redcaf::on_pushButton_14_clicked()
{
    QSqlQuery query( db );
    db.open();
    model = new QSqlQueryModel(this);
     model->setQuery("SELECT namec FROM cafedra");
     ui->comboBox->setModel(model);
    model = new QSqlQueryModel(this);
     model->setQuery("SELECT namec FROM cafedra");
     ui->comboBox_2->setModel(model);
    model = new QSqlQueryModel(this);
     model->setQuery("SELECT named FROM disciplina");
     ui->comboBox_3->setModel(model);
     model = new QSqlQueryModel(this);
     model->setQuery("SELECT named FROM disciplina");
     ui->comboBox_4->setModel(model);
     model = new QSqlQueryModel(this);
     model->setQuery("SELECT names FROM spec");
     ui->comboBox_9->setModel(model);
     model = new QSqlQueryModel(this);
     model->setQuery("SELECT names FROM spec");
     ui->comboBox_8->setModel(model);
     model = new QSqlQueryModel(this);
     model->setQuery("SELECT cod FROM szyaz");
     ui->comboBox_11->setModel(model);

     model = new QSqlQueryModel(this);
     model->setQuery("SELECT cod FROM szyaz");
     ui->comboBox_12->setModel(model);

     model = new QSqlQueryModel(this);
     model->setQuery("SELECT namec FROM cafedra");
     ui->comboBox_d2->setModel(model);

     model = new QSqlQueryModel(this);
     model->setQuery("SELECT named FROM disciplina");
     ui->comboBox_sz1->setModel(model);

     model = new QSqlQueryModel(this);
     model->setQuery("SELECT names FROM spec");
     ui->comboBox_sz2->setModel(model);






}


void redcaf::on_pushButton_5_clicked()
{
    QSqlQuery query( db );
    db.open();


QString l = QString("call upddisc('%1', '%2','%3', '%4','%5')").arg(ui->comboBox_3->currentText(), ui->lineEdit_d1->text(), ui->comboBox_d2->currentText(), ui->lineEdit_d3->text(),ui->lineEdit_d4->text());

     query.exec(l);
     ui->lineEdit_d1->clear();
     ui->lineEdit_d3->clear();
     ui->lineEdit_d4->clear();
     redcaf::on_pushButton_14_clicked();


}


void redcaf::on_pushButton_7_clicked()
{
    QString l = QString("call insdisc('%1', '%2','%3', '%4')").arg(ui->lineEdit_d1->text(), ui->comboBox_d2->currentText(), ui->lineEdit_d3->text(),ui->lineEdit_d4->text());
    QSqlQuery query( db );
    db.open();

         query.exec(l);
         ui->lineEdit_d1->clear();
         ui->lineEdit_d3->clear();
         ui->lineEdit_d4->clear();
         redcaf::on_pushButton_14_clicked();

}


void redcaf::on_pushButton_9_clicked()
{
    QSqlQuery query( db );
    db.open();

QString l = QString("call delspec('%1')").arg(ui->comboBox_9->currentText());

     query.exec(l);
     redcaf::on_pushButton_14_clicked();
}


void redcaf::on_pushButton_8_clicked()
{
    QSqlQuery query( db );
    db.open();


QString l = QString("call updspec('%1', '%2','%3', '%4')").arg(ui->comboBox_8->currentText(), ui->lineEdit_s1->text(), ui->lineEdit_s2->text(), ui->lineEdit_s3->text());

     query.exec(l);
     ui->lineEdit_s1->clear();
     ui->lineEdit_s2->clear();
     ui->lineEdit_s3->clear();
     redcaf::on_pushButton_14_clicked();

}


void redcaf::on_pushButton_10_clicked()
{

    QString l = QString("call insspec('%1', '%2','%3')").arg(ui->lineEdit_s1->text(), ui->lineEdit_s2->text(), ui->lineEdit_s3->text());
    QSqlQuery query( db );
    db.open();


         query.exec(l);
         ui->lineEdit_s1->clear();
         ui->lineEdit_s2->clear();
         ui->lineEdit_s3->clear();
         redcaf::on_pushButton_14_clicked();

}


void redcaf::on_pushButton_12_clicked()
{
    QSqlQuery query( db );
    db.open();

QString l = QString("call delsz('%1')").arg(ui->comboBox_12->currentText());

     query.exec(l);
     redcaf::on_pushButton_14_clicked();
}


void redcaf::on_pushButton_11_clicked()
{
    QSqlQuery query( db );
    db.open();


QString l = QString("call updsz('%1', '%2','%3', '%4','%5')").arg(ui->comboBox_11->currentText(), ui->comboBox_sz1->currentText(), ui->comboBox_sz2->currentText(), ui->lineEdit_sz3->text(), ui->lineEdit_sz4->text());
qDebug()<< l;
     query.exec(l);
     ui->lineEdit_sz3->clear();
     ui->lineEdit_sz4->clear();
     redcaf::on_pushButton_14_clicked();


}


void redcaf::on_pushButton_13_clicked()
{

    QString l = QString("call inssz('%1', '%2','%3','%4','%5')").arg( ui->comboBox_sz1->currentText(), ui->comboBox_sz2->currentText(), ui->lineEdit_sz4_2->text(), ui->lineEdit_sz3->text(), ui->lineEdit_sz4->text());
    QSqlQuery query( db );
    db.open();
qDebug()<< l;
         query.exec(l);
         ui->lineEdit_sz3->clear();
         ui->lineEdit_sz4->clear();
          ui->lineEdit_sz4_2->clear();
         redcaf::on_pushButton_14_clicked();


}


