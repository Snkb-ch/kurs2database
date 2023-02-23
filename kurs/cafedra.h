#ifndef CAFEDRA_H
#define CAFEDRA_H
#include<QSqlTableModel>
#include <QDialog>
#include "redcaf.h"
namespace Ui {
class cafedra;
}

class cafedra : public QDialog
{
    Q_OBJECT

public:
    explicit cafedra(QWidget *parent = nullptr);
    ~cafedra();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_a_butt_clicked();

    void on_b_butt_clicked();

    void on_pushButton_c1_clicked();

    void on_pushButton_c2_clicked();

    void on_pushButton_c3_clicked();

    void on_pushButton_d1_clicked();

    void on_pushButton_d2_clicked();

    void on_pushButton_d3_clicked();

    void on_pushButton_e_clicked();

    void on_pushButton_f1_clicked();

    void on_pushButton_f2_clicked();

    void on_pushButton_f3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_c3_2_clicked();

    void on_pushButton_c3_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    redcaf *fc;
    Ui::cafedra *ui;
    QSqlDatabase db;
    QSqlQuery *qry;
    QSqlQueryModel *model;
public slots:
    void slot(QSqlDatabase db);
signals:
   void signal2(QSqlDatabase);
};

#endif // CAFEDRA_H
