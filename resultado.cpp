#include "resultado.h"
#include "ui_resultado.h"

Resultado::Resultado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Resultado)
{


}

void Resultado::set(std::list<QString> If, std::list<QString> Id, std::list<QString> Ex, std::list<QString> w)
{


    this->transform_into_table(If,&IF);
    this->transform_into_table(Id,&ID);
    this->transform_into_table(Ex,&EX);
    this->transform_into_table(w,&W);

    ui->label_SCHEDULER->setVisible(false);
    ui->lineEdit_SCHEDULER->setVisible(false);

}

void Resultado::set(std::list<QString> If, std::list<QString> Id, std::list<QString> Ex, std::list<QString> w, QString Scheduler)
{
    this->transform_into_table(If,&IF);
    this->transform_into_table(Id,&ID);
    this->transform_into_table(Ex,&EX);
    this->transform_into_table(w,&W);

    ui->label_SCHEDULER->setVisible(true);
    ui->lineEdit_SCHEDULER->setVisible(true);

}

void Resultado::transform_into_table(std::list<QString> str, QTableWidget *Obj)
{
    Obj->clear();
    Obj->setRowCount(str.size());
    QStringList linha=(*str.begin()).split(',');
    Obj->setColumnCount(linha.size());
    Obj->setSelectionBehavior(QAbstractItemView::SelectRows);
    Obj->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    Obj->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    int i=0;
    for(std::list<QString>::iterator it= str.begin();    it!=str.end()   ;   ++it , i++)
    {
         linha=(*it).split(',');
         for(int j=0;j<linha.size();j++)
         {
                if(linha[j]!=" ") Obj->setItem(i,j,new QTableWidgetItem(linha[j],1));
         }
    }
}

void Resultado::clear_tables()
{
    IF.clear();
    ID.clear();
    EX.clear();
    W.clear();
    //ui->tabela_de_exe->clear();
}

Resultado::~Resultado()
{
    delete ui;
}
