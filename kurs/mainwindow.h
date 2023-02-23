#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QSqlTableModel>
#include <QDialog>
#include <QMainWindow>
#include"cafedra.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
   cafedra *form;
signals:
   void signal(QSqlDatabase);
};

#endif // MAINWINDOW_H
