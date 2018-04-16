#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <fstream>
#include <queue>
#include <string>
#include <cstring>
#include <instrucao.h>
#include <list>
#include <tabelas.h>

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    std::list<Instrucao> listagem(QString file);
    ~Menu();
private slots:

    void on_radio_in_in_clicked(bool checked);

    void on_radio_in_out_clicked(bool checked);

    void on_radio_out_out_clicked(bool checked);

    void on_check_forwarding_toggled(bool checked);

    void on_Button_gera_clicked();

private:
    Ui::Menu *ui;
    bool in_in,in_out,out_out,forwarding;
    std::list<Instrucao>  lista;
    Tabelas  janela_de_resutado;

};

#endif // MENU_H
