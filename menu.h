#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <fstream>
#include <queue>
#include <string>
#include <cstring>
#include <instrucao.h>
#include <list>

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

private:
    Ui::Menu *ui;
    std::list<Instrucao>  list;
    int tipo; // 0=IN-IN ,1=IN-OUT, 2=IN-IN
};

#endif // MENU_H
