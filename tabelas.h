#ifndef TABELAS_H
#define TABELAS_H

#include <QDialog>
#include<QString>
#include<QStringList>
#include<list>
#include<QTableWidget>
#include<QTableWidgetItem>

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

    void clear_tables();

private:
    Ui::Tabelas *ui;
    QString  SCHEDULER;
    QTableWidget IF,ID,EX,W;
};

#endif // TABELAS_H
