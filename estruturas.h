#include <iostream>
#include <locale.h>
using namespace std;
typedef struct{
    string nome;
    int teor;
    double valor;} bebida;
typedef struct{
    int id,data,ingre,popuvend,normvend,especvend;
    bool openBar;
    string nome,local;
    double popu,norm,espec,custo,saldo;
    bebida drinks[4];} evento;
void linha(){//Apresenta uma "linha"
    cout<<"---------------------------------------------------------------------------------"<<endl;}
void linhad(){//Apresenta uma "linha dupla"
    cout<<"================================================================================="<<endl;}
void spc(){//Salta uma linha
    cout<<endl;}
