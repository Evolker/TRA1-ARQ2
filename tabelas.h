#ifndef TABELAS_H
#define TABELAS_H

#include <QDialog>
#include<QString>
#include<QStringList>
#include<list>
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QMessageBox>

namespace Ui {
class Tabelas;
}

class Tabelas : public QDialog
{
    Q_OBJECT

public:
    explicit Tabelas(QWidget *parent = 0);
    ~Tabelas();

    void set(std::list<QString> If,std::list<QString> Id,std::list<QString> Ex,std::list<QString> w);
    void set(std::list<QString> If,std::list<QString> Id,std::list<QString> Ex,std::list<QString> w,QString Scheduler);
    void transform_into_table(std::list<QString> str,QTableWidget *Obj);
    QTableWidget * t_table(QTableWidget *Obj);




    void clear_tables();

private slots:


    void on_Box_tabelas_activated(int index);

private:
    Ui::Tabelas *ui;
    QString  SCHEDULER;
    QTableWidget *IF,*ID,*EX,*W;
    QTableWidget * aux_table;
};

#endif // TABELAS_H
