#ifndef RESULTADO_H
#define RESULTADO_H

#include <QDialog>
#include<QString>
#include<QStringList>
#include<list>
#include<QTableWidget>
#include<QTableWidgetItem>

namespace Ui {
class Resultado;
}

class Resultado : public QDialog
{
    Q_OBJECT

public:
    explicit Resultado(QWidget *parent = 0);

   void set(std::list<QString> If,std::list<QString> Id,std::list<QString> Ex,std::list<QString> w);
   void set(std::list<QString> If,std::list<QString> Id,std::list<QString> Ex,std::list<QString> w,QString Scheduler);

   void transform_into_table(std::list<QString> str,QTableWidget *Obj);

   void clear_tables();

    ~Resultado();

private:
    Ui::Resultado *ui;
    QString  SCHEDULER;
    QTableWidget IF,ID,EX,W;
};

#endif // RESULTADO_H
