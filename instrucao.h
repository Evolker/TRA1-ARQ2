#ifndef INSTRUCAO_H
#define INSTRUCAO_H
#include<QString>
#include<QStringList>
#include<list>


class Instrucao
{
private:
   int id; // indentificador de instrução
   int num_dependencias; // quantidade de  instrunçõe que  esta dependente
   int num_ciclos;// numero de ciclos no ex
   std::list<int> dependentes;//instrucos que dependes

public:
    Instrucao();

    void operator=( Instrucao A);
    //void operator ++(Instrucao &A);
   // void operator --(Instrucao &A);

    void MontarObjeto(QString str);

    int tranforma(QString A);

    std::list<int> getDependentes() const;
    void setDependentes(const std::list<int> &value);

    int getNum_dependencias() const;
    void setNum_dependencias(int value);

    int getNum_ciclos() const;
    void setNum_ciclos(int value);

    int getId() const;
    void setId(int value);


};

#endif // INSTRUCAO_H
