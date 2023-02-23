#ifndef REDCAF_H
#define REDCAF_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include "qsqlquerymodel.h"
#include <QDialog>

namespace Ui {
class redcaf;
}

class redcaf : public QDialog
{
    Q_OBJECT

public:


    explicit redcaf(QWidget *parent = nullptr);
    ~redcaf();

private slots:
    void on_pushButton_2_clicked();




    void on_pushButton_3_clicked();



    void on_pushButton_4_clicked();







    void on_pushButton_6_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();





private:

    QSqlDatabase db;
    QSqlQuery qr;
    QSqlQueryModel *model;
    Ui::redcaf *ui;
public slots:
    void slot2(QSqlDatabase db);
};



#endif // REDCAF_H
