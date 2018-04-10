#include "instrucao.h"



Instrucao::Instrucao()
{
    id=num_ciclos=num_dependencias=0;
    dependentes.clear();// não e nesseçario

}

void Instrucao::operator=(Instrucao A)
{
    id=A.id;
    num_ciclos=A.num_ciclos;
    num_dependencias=A.num_dependencias;
    dependentes=A.dependentes;

}


void Instrucao::MontarObjeto(QString str)
{
    QStringList lista = str.split(':');
    if(lista.size()!=2) throw QString("Linha inválida! -Pessoa \n");

    id=tranforma(lista[0]);

    num_ciclos=lista[1].toInt()
            ;
    QStringList list_dependencia=lista[2].split(" ");

    int i= list_dependencia.size();

    for(i--;i>-1;i--) dependentes.push_front(  tranforma(list_dependencia[i])  );

}

int Instrucao::tranforma(QString A)
{
    std::string aux=A.toStdString();
    aux.erase(aux.begin());
    A=QString(aux.data());
    return A.toInt();

}




std::list<int> Instrucao::getDependentes() const
{
    return dependentes;
}

void Instrucao::setDependentes(const std::list<int> &value)
{
    dependentes = value;
}

int Instrucao::getNum_dependencias() const
{
    return num_dependencias;
}

void Instrucao::setNum_dependencias(int value)
{
    num_dependencias = value;
}

int Instrucao::getNum_ciclos() const
{
    return num_ciclos;
}

void Instrucao::setNum_ciclos(int value)
{
    num_ciclos = value;
}

int Instrucao::getId() const
{
    return id;
}

void Instrucao::setId(int value)
{
    id = value;
}

