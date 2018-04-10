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

private:
    Ui::Menu *ui;
    std::list<Instrucao>  list;

};

#endif // MENU_H
