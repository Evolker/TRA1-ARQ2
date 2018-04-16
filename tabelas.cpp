#include "tabelas.h"
#include "ui_tabelas.h"

Tabelas::Tabelas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tabelas)
{
    ui->setupUi(this);

    IF=new QTableWidget();

    ID=new QTableWidget();


    EX=new QTableWidget();
    W=new QTableWidget();


    IF->setRowCount(10);
    IF->setColumnCount(2);
    ID->setRowCount(10);
    ID->setColumnCount(2);
    EX->setRowCount(10);
    EX->setColumnCount(4);
    W->setRowCount(10);
    W->setColumnCount(3);

    IF->setItem(1,1,new QTableWidgetItem("ASDF",1));
    //QMessageBox::information(this,"ERRO",QString::number(IF.item(1,1)));

}

Tabelas::~Tabelas()
{
    delete ui;
}

void Tabelas::set(std::list<QString> If, std::list<QString> Id, std::list<QString> Ex, std::list<QString> w)
{
    this->transform_into_table(If,IF);
    this->transform_into_table(Id,ID);
    this->transform_into_table(Ex,EX);
    this->transform_into_table(w,W);

    ui->label_SCHEDULER->setVisible(false);
    ui->lineEdit_SCHEDULER->setVisible(false);
}

void Tabelas::set(std::list<QString> If, std::list<QString> Id, std::list<QString> Ex, std::list<QString> w, QString Scheduler)
{
    this->transform_into_table(If,IF);
    this->transform_into_table(Id,ID);
    this->transform_into_table(Ex,EX);
    this->transform_into_table(w,W);

    ui->label_SCHEDULER->setVisible(true);
    ui->lineEdit_SCHEDULER->setVisible(true);
    ui->lineEdit_SCHEDULER->setText(Scheduler);


}

void Tabelas::transform_into_table(std::list<QString> str, QTableWidget *Obj)
{
    Obj->clear();
    Obj->setRowCount(str.size());
    QStringList linha=(*str.begin()).split(',');
    Obj->setColumnCount(linha.size());
    Obj->setSelectionBehavior(QAbstractItemView::SelectRows);
    Obj->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    Obj->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList cabecalho;
    cabecalho.insert(linha.size()," ");
    ui->tabela_de_exe->setHorizontalHeaderLabels(cabecalho);

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

QTableWidget *Tabelas::t_table(QTableWidget *Obj)
{
    QStringList cabecalho;

    QTableWidget *Aux=new QTableWidget();
    int tr=Obj->rowCount(),tc=Obj->columnCount();
    Aux->setRowCount(tr);
    Aux->setColumnCount(tc);
    Aux->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //Aux->setFocusPolicy(Qt::NoFocus);
    Aux->setSelectionMode(QAbstractItemView::NoSelection);
    Aux->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    Aux->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);



    for(int i=0;i<tr;i++)
    {
        cabecalho.push_back(" ");
        for(int j=0;j<tc;j++)
        {
            if(Obj->item(i,j)!=0) Aux->setItem(i,j,new QTableWidgetItem(Obj->item(i,j)->text(),1));

        }

    }
  Aux->setHorizontalHeaderLabels(cabecalho);
  return Aux;
}

void Tabelas::clear_tables()
{
    IF->clear();
    ID->clear();
    EX->clear();
    W->clear();
    //ui->tabela_de_exe->clear();

}

void Tabelas::on_Box_tabelas_activated(int index)
{
  // QMessageBox::information(this,"ERRO",IF->item(1,1)->text());
   //if(IF->item(1,1)==0) IF->setItem(1,1,new QTableWidgetItem("ASDF",1));
   QStringList cabecalho;
   cabecalho.push_front(" ");
   ui->tabela_de_exe->clear();
   ui->tabela_de_exe->setRowCount(1);
   ui->tabela_de_exe->setVerticalHeaderLabels(cabecalho);
   cabecalho.clear();
    switch (index)
    {
        case 0:
        ui->tabela_de_exe->setColumnCount(4);
        ui->tabela_de_exe->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tabela_de_exe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tabela_de_exe->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        cabecalho.push_back("IF");
        cabecalho.push_back("ID");
        cabecalho.push_back("EX");
        cabecalho.push_back("W");
        ui->tabela_de_exe->setHorizontalHeaderLabels(cabecalho);


        ui->tabela_de_exe->setCellWidget(0,0,t_table(IF));
        ui->tabela_de_exe->setCellWidget(0,1,t_table(ID));
        ui->tabela_de_exe->setCellWidget(0,2,t_table(EX));
        ui->tabela_de_exe->setCellWidget(0,3,t_table(W));
        break;

        case 1:

        ui->tabela_de_exe->setColumnCount(1);
        ui->tabela_de_exe->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tabela_de_exe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tabela_de_exe->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        cabecalho.push_back("IF");
        ui->tabela_de_exe->setHorizontalHeaderLabels(cabecalho);
        ui->tabela_de_exe->setCellWidget(0,0,t_table(IF));


        break;

        case 2:

        ui->tabela_de_exe->setColumnCount(1);
        ui->tabela_de_exe->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tabela_de_exe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tabela_de_exe->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        cabecalho.push_back("ID");
        ui->tabela_de_exe->setHorizontalHeaderLabels(cabecalho);
        ui->tabela_de_exe->setCellWidget(0,0,t_table(ID));

            break;

        case 3:

        ui->tabela_de_exe->setColumnCount(1);
        ui->tabela_de_exe->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tabela_de_exe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tabela_de_exe->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        cabecalho.push_back("EX");
        ui->tabela_de_exe->setHorizontalHeaderLabels(cabecalho);
        ui->tabela_de_exe->setCellWidget(0,0,t_table(EX));

            break;

        case 4:

        ui->tabela_de_exe->setColumnCount(1);
        ui->tabela_de_exe->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tabela_de_exe->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tabela_de_exe->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        cabecalho.push_back("W");
        ui->tabela_de_exe->setHorizontalHeaderLabels(cabecalho);
         ui->tabela_de_exe->setCellWidget(0,0,t_table(W));


            break;


        default:
            break;
    }

}
