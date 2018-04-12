#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    ui->radio_forwar->setVisible(false);
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
    ui->radio_forwar->setEnabled(0);






}

Menu::~Menu()
{
    delete ui;
}



void Menu::on_radio_in_in_clicked(bool checked)
{
    ui->radio_forwar->setVisible(checked);
    tipo=1;

}

void Menu::on_radio_in_out_clicked(bool checked)
{
    ui->radio_forwar->setVisible(checked);
    tipo=2;
}

void Menu::on_radio_out_out_clicked(bool checked)
{
    ui->radio_forwar->setVisible(!checked);
    tipo=0;

}
