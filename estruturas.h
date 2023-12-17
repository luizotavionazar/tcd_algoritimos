#include <iostream>
#include <locale.h>
using namespace std;
#define QTDEVT 50
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
void clstel(int sis,int& param1){//Limpa a tela
    if (param1==2){
        if (sis==1){
        system("cls");}
        else if (sis==2){
            system("clear");}}}
int verifica_evento(evento festa[]){
    int i;
    for(i=0; i<QTDEVT; i++){
        if(festa[i].id==0)
        return i;}
        cout<<"Já foram cadastrados todos os 50 eventos!"<<endl;
        cout<<"Sinto muito :("<<endl;
        return -1;}
evento *identifica_evento(evento festa[],int ident){
    for(int i=0; i<50; i++){//Varre o vetor buscando o identificador desejado
        if (festa[i].id==ident){
            cout<<"Evento encontrado!"<<endl;
            spc();
            return &festa[i];}}
    return nullptr;}
