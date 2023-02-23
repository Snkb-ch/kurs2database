#include "cafedra.h"
#include "ui_cafedra.h"
#include<QSqlTableModel>

#include <QDebug>
#include<QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
cafedra::cafedra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cafedra)
{
    ui->setupUi(this);
    fc = new redcaf;
    connect(this, &cafedra::signal2, fc, &redcaf::slot2);




}
cafedra::~cafedra()
{
    delete ui;

}

void cafedra::on_pushButton_clicked()
{
db.open();
//QSqlQuery query( db );





        model = new QSqlQueryModel(this);
        model->setQuery("SELECT namec, zaved, number, cabinet FROM cafedra");
        ui->tableView->setModel(model);

}

void cafedra::slot(QSqlDatabase db)
{
this->db = db;
}







void cafedra::on_pushButton_7_clicked()
{
    db.open();


            model = new QSqlQueryModel(this);
            model->setQuery("SELECT names, formaobuch,timeofstud FROM spec");
            ui->tableView->setModel(model);
}


void cafedra::on_pushButton_6_clicked()
{
    db.open();


            model = new QSqlQueryModel(this);
            model->setQuery("SELECT named, formaotcheta, kurs,kolvospec FROM disciplina");
            ui->tableView->setModel(model);
}


void cafedra::on_pushButton_5_clicked()
{
    db.open();


            model = new QSqlQueryModel(this);
            model->setQuery("SELECT cod, timeofdisc, beginning FROM Szyaz");
            ui->tableView->setModel(model);
}







void cafedra::on_a_butt_clicked()
{

    db.open();
    model = new QSqlQueryModel(this);
    model->setQuery( "SELECT szyaz.cod, szyaz.timeofdisc, szyaz.beginning, spec.names, disciplina.named FROM szyaz RIGHT JOIN spec  ON CASE spec.id3 WHEN szyaz.spec THEN 1 ELSE 0 END = 1 RIGHT JOIN disciplina on case disciplina.id2 when szyaz.disc THEN 1 ELSE 0 END = 1");
    ui->tableView->setModel(model);

}


void cafedra::on_b_butt_clicked()
{

    db.open();
    model = new QSqlQueryModel(this);
    model->setQuery(" SELECT named, namec FROM viewn");
    ui->tableView->setModel(model);
}


void cafedra::on_pushButton_c1_clicked()
{

    db.open();
    model = new QSqlQueryModel(this);
    model->setQuery(" SELECT named, (select zaved from cafedra where cafedra.id1 = disciplina.cafedra) as zaved from disciplina");
    ui->tableView->setModel(model);
}


void cafedra::on_pushButton_c2_clicked()
{
    db.open();
    model = new QSqlQueryModel(this);
    model->setQuery("  SELECT named, formaotcheta FROM (SELECT * FROM disciplina WHERE formaotcheta  = 'экзамен') as a");
    ui->tableView->setModel(model);

}


void cafedra::on_pushButton_c3_clicked()
{
    db.open();
    model = new QSqlQueryModel(this);
    model->setQuery("      SELECT named FROM disciplina WHERE id2 in (SELECT disc FROM Szyaz where beginning = 1)");
    ui->tableView->setModel(model);

}


void cafedra::on_pushButton_d1_clicked()
{
    db.open();
    model = new QSqlQueryModel(this);
    model->setQuery(" SELECT a.namec, a.zaved, a.number from cafedra a where 'да' in "
                    "( select b.Kurs from disciplina b where  b.cafedra = a.id1) ");
    ui->tableView->setModel(model);

}


void cafedra::on_pushButton_d2_clicked()
{

    db.open();
    model = new QSqlQueryModel(this);
    model->setQuery("SELECT disc, spec, (select cafedra from disciplina d  where d.id2 = s.disc) as cafedra, "
                    "(select named from disciplina d  where d.id2 = s.disc)"

                  "  from Szyaz s");
    ui->tableView->setModel(model);
}


void cafedra::on_pushButton_d3_clicked()
{
    db.open();
    model = new QSqlQueryModel(this);
    model->setQuery("SELECT named , cafedra, (select zaved from cafedra where cafedra.id1 = disciplina.cafedra) as zaved from disciplina ");
    ui->tableView->setModel(model);
}


void cafedra::on_pushButton_e_clicked()
{
    db.open();
    model = new QSqlQueryModel(this);
    model->setQuery("SELECT named, formaotcheta, spec  from disciplina JOIN Szyaz ON Szyaz.disc = disciplina.id2    GROUP BY named,  formaotcheta, spec having MIN(timeofdisc) >2");
    ui->tableView->setModel(model);
}


void cafedra::on_pushButton_f1_clicked()
{
    db.open();
    model = new QSqlQueryModel(this);
    model->setQuery("SELECT cod, timeofdisc from Szyaz where timeofdisc >= all (select timeofdisc from Szyaz)");
    ui->tableView->setModel(model);
}


void cafedra::on_pushButton_f2_clicked()
{
    db.open();
    model = new QSqlQueryModel(this);
    model->setQuery("SELECT named, cod timeofdisc from (select *from disciplina  join Szyaz on disciplina.id2 = Szyaz.disc) as a where timeofdisc > some (select timeofdisc from Szyaz where beginning>=2)");
    ui->tableView->setModel(model);
}


void cafedra::on_pushButton_f3_clicked()
{
    db.open();
    model = new QSqlQueryModel(this);
    model->setQuery("select named from disciplina where id2 = any (select disc from Szyaz)");
    ui->tableView->setModel(model);

}


void cafedra::on_pushButton_8_clicked()
{
   // this->close();
   fc->show();
   emit signal2(db);

}


void cafedra::on_pushButton_c3_2_clicked()
{
    db.open();
    model = new QSqlQueryModel(this);
    QSqlQuery query( db );
    QString l = QString("select getsr('%1')").arg(ui->lineEdit->text());
        // query.exec(l);

    model->setQuery(l);
    ui->tableView->setModel(model);
    ui->lineEdit->clear();
}


void cafedra::on_pushButton_c3_3_clicked()
{
    db.open();
    model = new QSqlQueryModel(this);
    QSqlQuery query( db );
    QString l = QString("select namec, zaved, number, cabinet from public.selcafedra('%1')").arg(ui->lineEdit_3->text());
        // query.exec(l);

    model->setQuery(l);
    ui->tableView->setModel(model);
     ui->lineEdit->clear();
}


void cafedra::on_pushButton_2_clicked()
{
    db.open();
    model = new QSqlQueryModel(this);
    QSqlQuery query( db );
    QString l = QString("  call public.updprk2('%1', '%2')").arg(ui->lineEdit_2->text(),ui->lineEdit_4->text() );
        // query.exec(l);

    model->setQuery(l);
    ui->tableView->setModel(model);
     ui->lineEdit_2->clear();
     ui->lineEdit_4->clear();

}


void cafedra::on_pushButton_3_clicked()
{
    db.open();
    model = new QSqlQueryModel(this);
    QSqlQuery query( db );
    if (ui->lineEdit_5->text() == "123"){
        QString d = QString("  call delall(true)");
            query.exec(d);
    }
    else{
        QString d = QString("  call delall(false)");
            query.exec(d);
    }





     ui->lineEdit_5->clear();
}

