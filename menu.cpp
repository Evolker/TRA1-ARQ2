#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    ui->check_forwarding->setChecked(false);
    ui->check_forwarding->setVisible(false);
    ui->radio_in_in->setChecked(false);
    ui->radio_in_out->setChecked(false);
    ui->radio_out_out->setChecked(true);
    in_in=in_out=forwarding=false;
    out_out=true;

    ui->spinBox_if->setRange(1,100);
    ui->spinBox_id->setRange(1,100);
    ui->spinBox_ex->setRange(1,100);
    ui->spinBox_w->setRange(1,100);
}

std::list<Instrucao> Menu::listagem(QString file)
{
    try{
    std::list<Instrucao> lista ;

        std::ifstream arquivo;
        arquivo.open(file.toStdString().c_str(),std::ios::in);
        if (!arquivo.is_open())
        {
            arquivo.close();
            throw QString("Erro, arquivo de instruções não encontrado!");
        }
        std::string linha;

        std::getline(arquivo,linha);
        while(!arquivo.eof())
        {
            QString linhaAux = QString::fromStdString(linha);
            Instrucao obj;
            obj.MontarObjeto(linhaAux);
            lista.push_back(obj);
            std::getline(arquivo,linha);
        }
        arquivo.close();

           return lista;

    }
    catch(QString &erro){
        throw erro;
    }



}

Menu::~Menu()
{
    delete ui;

}



void Menu::on_radio_in_in_clicked(bool checked)
{
    ui->check_forwarding->setVisible(checked);
    in_in=checked;
}

void Menu::on_radio_in_out_clicked(bool checked)
{
   ui->check_forwarding->setVisible(checked);
    in_in=checked;
}


void Menu::on_radio_out_out_clicked(bool checked)
{
   ui->check_forwarding->setVisible(!checked);
    in_in=checked;

}


void Menu::on_check_forwarding_toggled(bool checked)
{
    forwarding=checked;
}

void Menu::on_Button_gera_clicked()
{

    janela_de_resutado.clear_tables();

    if(in_in)//Iron
    {
        if(forwarding)
        {
            //janela_de_resutado.set();
        }
       else
        {
            //janela_de_resutado.set();
        }

    }
    else if(in_out)//Eduardo
    {
        if(forwarding)
        {
            //janela_de_resutado.set();
        }
       else
        {
            //janela_de_resutado.set();
        }
    }
    else//Aurélio
    {

            //janela_de_resutado.set();

    }


     janela_de_resutado.setModal(true);
     this->hide();
     janela_de_resutado.exec();
     this->show();
}
