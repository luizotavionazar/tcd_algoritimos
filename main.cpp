#include <iostream>
#include <locale.h>
#include "estruturas.h"
using namespace std;
#define QTDEVT 50
void linha();
void linhad();
void spc();
int verifica_evento(evento festa[]);
evento *identifica_evento(evento festa[],int ident);
void clstel(int sis,int& param1);
void config(int sis,int& param1){//Menu Parâmetros do Sistema
    spc();
    linhad();
    cout<<"                            Parâmetros do Sistema"<<endl;
    linhad();
    cout<<"Parâmetros para configuração do sistema:"<<endl;
    spc();
    cout<<" 1- Habilitar histórico? 1-Sim/2-Não: ";
    cin>>param1;
    clstel(sis,param1);}
void menu(){//Menu de opções
    linhad();
    cout<<"                        Trabalho de Conclusão de Disciplina"<<endl;
    cout<<"                         Algoritmos e Estruturas de Dados"<<endl;
    cout<<"                             Luiz Otávio Nazar, ADS 2º"<<endl;
    linhad();
    cout<<"                                      EVENTOS"<<endl;
    linhad();
    cout<<"Escolha de 1 a 7 a opção desejada:"<<endl;
    spc();
    cout<<" 1- Cadastrar evento"<<endl;
    cout<<" 2- Pesquisar evento"<<endl;
    cout<<" 3- Ingressos vendidos"<<endl;
    cout<<" 4- Exibir resultado por evento"<<endl;
    cout<<" 5- Exibir resultado geral"<<endl;
    cout<<" 6- Configurações"<<endl;
    cout<<" 7- Sair"<<endl;
    spc();
    linha();
    spc();
    cout<<"Informe a opção desejada: ";}
void cadastra_evento(evento festa[], int i, int sis, int param1){//1° Opção
    spc();
    linhad();
    cout<<"                               CADASTRO DE EVENTOS" << endl;
    linhad();
    cout<<"Preencha as informações do eventos:"<< endl;
    spc();
    cout<<"Identificador único: ";
    cin>>festa[i].id;
    while (festa[i].id!=0){
        cout<<"Nome: ";
        cin>>ws;
        getline(cin, festa[i].nome);
        cout<<"Local: ";
        getline(cin, festa[i].local);
        cout<<"Data(formato DDMMYYYY): ";
        cin>>festa[i].data;
        cout<<"Quantidade de ingressos à venda: ";
        cin>>festa[i].ingre;
        cout<<"Custo de organização: ";
        cin>>festa[i].custo;
        cout<<"O evento é Open Bar? 1-Sim/0-Não: ";
        cin>>festa[i].openBar;
        if (festa[i].openBar) {
            festa[i].popu = festa[i].custo/festa[i].ingre;
            for (int j=0; j<4; j++) {
                cout<<"  Cadastro da "<<j+1<<"º bebida:"<<endl;
                cout<<"    Nome: ";
                cin>>festa[i].drinks[j].nome;
                cout<<"    Teor alcoólico: ";
                cin>>festa[i].drinks[j].teor;
                cout<< "    Valor: ";
                cin>>festa[i].drinks[j].valor;
                festa[i].popu+=1.75*festa[i].drinks[j].valor;}}
        else {
            festa[i].popu = festa[i].custo / festa[i].ingre;}
        festa[i].norm=festa[i].popu*1.1;
        festa[i].espec=festa[i].norm*1.15;
        spc();
        cout<<"                          EVENTO CADASTRADO COM SUCESSO"<<endl;
        linha();
        i=verifica_evento(festa);
        if(i != -1) {
            cout<<"Iniciando cadastro do próximo evento..."<<endl;
            spc();
            cout<<"Identificador único: ";
            cin>>festa[i].id;}
        else {
        cout << "Todos os eventos já foram cadastrados!" << endl;}}
    spc();
    cout<<"Fim de execução! Tecle 'Enter' para retornar ao Menu...";
    getchar();
    getchar();
    clstel(sis,param1);}
void pesquisa_evento(evento festa[], int sis, int param1){//2º Opção
    int ident;
    spc();
    linhad();
    cout<<"                               PESQUISA DE EVENTOS" << endl;
    linhad();
    cout<<"Informe o identificador do evento desejado::"<< endl;
    spc();
    cout<<"Identificador único: ";
    cin>>ident;
    evento *indice=identifica_evento(festa,ident);
    if (indice!=nullptr){
        cout<< "Nome: "<<indice->nome<<endl;
        cout<< "Local: "<<indice->local<<endl;
        cout<< "Data: "<<indice->data <<endl;
        cout<< "Quantidade de ingressos: "<<indice->ingre<<endl;
        if (indice->openBar==1){
            cout<<"  Evento Open Bar!"<<endl;
            for (int j=0; j<4; j++) {
            cout<<"    Bebida "<<j+1<<": "<<indice->drinks[j].nome<<endl;
            cout<<"    Teor alcoólico: "<<indice->drinks[j].teor<<endl;
            cout<<"    Valor: "<<indice->drinks[j].valor<<endl;}}
        else{ cout<<"  Evento não é Open Bar!"<<endl;}}
    else{ cout<<"Evento não encontrado na base de dados!"<<endl;}
    spc();
    linha();
    spc();
    cout<<"Fim de execução! Tecle 'Enter' para retornar ao Menu...";
    getchar();
    getchar();
    clstel(sis,param1);}
void venda_ingressos(evento festa[], int sis, int param1){//3º Opção
    int ident,qtdePopular,qtdeNormal,qtdeEspecial;
    spc();
    linhad();
    cout<<"                                  VENDA DE INGRESSOS" << endl;
    linhad();
    cout<<"Informe o identificador do evento desejado:" << endl;
    spc();
    cout<<"Identificador único: ";
    cin>>ident;
    evento *eventoSelecionado=identifica_evento(festa, ident);
    if (eventoSelecionado!=nullptr) {
        cout<<"Dados do evento:"<<endl;
        cout<<"Nome: "<<eventoSelecionado->nome<<endl;
        cout<<"Local: "<<eventoSelecionado->local<<endl;
        cout<<"Data: "<<eventoSelecionado->data<<endl;
        spc();
        cout<<"Quantidade de ingressos vendidos:"<<endl;
        cout<<"Popular: ";
        cin>>qtdePopular;
        cout<<"Normal: ";
        cin>>qtdeNormal;
        cout<<"Especial: ";
        cin>>qtdeEspecial;
        eventoSelecionado->popuvend += qtdePopular;
        eventoSelecionado->normvend += qtdeNormal;
        eventoSelecionado->especvend += qtdeEspecial;
        double totalArrecadado = qtdePopular*eventoSelecionado->popu +
                                 qtdeNormal*eventoSelecionado->norm +
                                 qtdeEspecial*eventoSelecionado->espec;
        double lucroPrejuizo=totalArrecadado-eventoSelecionado->custo;
        spc();
        cout<<"Resultados da venda:"<<endl;
        cout<<"    Total arrecadado: R$ "<<totalArrecadado<<endl;
        cout<<"    Custo do evento: R$ "<<eventoSelecionado->custo<<endl;
        cout<<"    Lucro/Prejuízo: R$ "<<lucroPrejuizo<<endl;}
    else { cout<<"Evento não encontrado na base de dados!"<<endl;}
    linha();
    spc();
    cout<<"Fim de execução! Tecle 'Enter' para retornar ao Menu...";
    getchar();
    getchar();
    clstel(sis, param1);}
void exibir_resultado_evento(evento festa[], int sis, int param1) {//4º Opção
    int ident;
    spc();
    linhad();
    cout<<"                                  RESULTADO POR EVENTO"<<endl;
    linhad();
    cout<<"Informe o identificador do evento desejado:"<<endl;
    spc();
    cout<<"Identificador único: ";
    cin>>ident;
    evento *eventoSelecionado=identifica_evento(festa,ident);
    if (eventoSelecionado != nullptr) {
        cout<<"Dados do evento:"<<endl;
        cout<<"Nome: "<<eventoSelecionado->nome<<endl;
        cout<<"Local: "<<eventoSelecionado->local<<endl;
        cout<<"Data: "<<eventoSelecionado->data<<endl;
        double totalArrecadado = eventoSelecionado->popuvend*eventoSelecionado->popu +
                                 eventoSelecionado->normvend*eventoSelecionado->norm +
                                 eventoSelecionado->especvend*eventoSelecionado->espec;
        double lucroPrejuizo = totalArrecadado-eventoSelecionado->custo;
        spc();
        cout<<"Resultados:"<<endl;
        cout<<"    Total arrecadado: R$"<<totalArrecadado<<endl;
        cout<<"    Custo do evento: R$"<<eventoSelecionado->custo<<endl;
        cout<<"    Lucro/Prejuízo: R$"<<lucroPrejuizo<<endl;}
    else{ cout<<"Evento não encontrado na base de dados!"<<endl;}
    linha();
    spc();
    cout << "Fim de execução! Tecle 'Enter' para retornar ao Menu...";
    getchar();
    getchar();
    clstel(sis, param1);}
void saldo_promoter(evento festa[], int sis, int param1){//5º Opção
    spc();
    linhad();
    cout << "                           SALDO ATUAL DO PROMOTER" << endl;
    linhad();
    double saldo=0.0;
    for (int i=0; i<QTDEVT; i++) {
        saldo += festa[i].popuvend*festa[i].popu +
                 festa[i].normvend*festa[i].norm +
                 festa[i].especvend*festa[i].espec;}
    spc();
    cout<<"Saldo atual do promoter: R$ "<<saldo<<endl;
    spc();
    linha();
    spc();
    cout<<"Fim de execução! Tecle 'Enter' para retornar ao Menu...";
    getchar();
    getchar();
    clstel(sis, param1);}
int main(){
    setlocale(LC_ALL,"Portuguese");
    int param1=2,opcao,sis,i,opc;
    evento festa[QTDEVT];
    double total;
    //=====Identifica o sistema operacional=====
    #if defined(_WIN32)||defined(_WIN64)
        sis=1;
    #elif defined(__linux__)
        sis=2;
    #endif
    //==========================================
    clstel(sis,param1);
    do {
            menu();
            cin>>opc;
            switch (opc){//Direcionamento de opções
            case 1:
                clstel(sis,param1);
                i=verifica_evento(festa);
                if(i!=-1){
                    cout<<"Iniciando a execução...";
                    cadastra_evento(festa,i,sis,param1);}
                break;
            case 2:
                clstel(sis,param1);
                cout<<"Iniciando a execução...";
                pesquisa_evento(festa,sis,param1);
                break;
            case 3:
                clstel(sis,param1);
                cout<<"Iniciando a execução...";
                venda_ingressos(festa,sis,param1);
                break;
            case 4:
                clstel(sis,param1);
                cout<<"Iniciando a execução...";
                exibir_resultado_evento(festa,sis,param1);
                break;
            case 5:
                clstel(sis,param1);
                cout<<"Iniciando a execução...";
                saldo_promoter(festa,sis,param1);
                break;
            case 6:
                clstel(sis,param1);
                config(sis,param1);
                break;
            case 7:
                spc();
                cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
                cout<<"                                 Até a próxima!"<<endl;
                spc();
                break;
            default:
                cout<<endl<<"Opção inválida! Tecle 'Enter' e selecione novamente...";
                cin.ignore();
                cin.ignore();
                clstel(sis,param1);
                break;}
        }while (opc !=7);
    return 0;}
