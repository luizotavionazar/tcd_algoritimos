#include <iostream>
#include <locale.h>
#include "estruturas.h"
using namespace std;
void linha();
void linhad();
void spc();
void clstel(int sis,int& param1){//Limpa a tela
    if (param1==2){
        if (sis==1){
        system("cls");}
        else if (sis==2){
            system("clear");}}}
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
    spc();
    linhad();
    cout<<"                        Trabalho de Conclusão de Disciplina"<<endl;
    cout<<"                         Algoritmos e Estruturas de Dados"<<endl;
    cout<<"                             Luiz Otávio Nazar, ADS 2º"<<endl;
    linhad();
    cout<<"                                      EVENTOS"<<endl;
    linhad();
    cout<<"Escolha de 1 a 7 a opção desejada:"<<endl;
    spc();
    cout<<" 1- Cadastrar um evento"<<endl;
    cout<<" 2- Pesquisar um evento"<<endl;
    cout<<" 3- Ingressos vendidos"<<endl;
    cout<<" 4- Exibir resultado por evento"<<endl;
    cout<<" 5- Exibir resultado geral"<<endl;
    cout<<" 6- Configurações"<<endl;
    cout<<" 7- Sair"<<endl;
    linha();
    spc();
    cout<<"Informe a opção desejada: ";}
int verifica_evento(evento festa[]){
    int i;
    for(i=0; i<50; i++){
        if(festa[i].id==0)
        return i;}
    if (i==0){
        cout<<"Já foram cadastrados todos os 50 eventos!"<<endl;
        cout<<"Sinto muito :("<<endl;}}
//void cadastra_evento(evento festa[],int i,int sis, int param1){//1º Opção
//    spc();
//    linhad();
//    cout<<"                          CADASTRO DE EVENTO"<<endl;
//    linhad();
//    cout<<"Preencha as informações do evento:"<<endl;
//    linha();
//    cout<<"Identificador único: ";
//    cin>>festa[i].id;}
void cadastra_evento(evento festa[], int i, int sis, int param1) {
    spc();
    linhad();
    cout << "                          CADASTRO DE EVENTO" << endl;
    linhad();
    cout << "Preencha as informações do evento:" << endl;
    linha();
    cout << "Identificador único: " << i + 1 << endl; // Incrementa o identificador único
    festa[i].id = i + 1; // Atualiza o identificador único
    cout << "Nome: ";
    cin >> ws; // Ignora espaços em branco
    getline(cin, festa[i].nome);
    cout << "Local: ";
    getline(cin, festa[i].local);
    cout << "Data (formato DDMMYYYY): ";
    cin >> festa[i].data;
    cout << "Quantidade de ingressos colocados à venda: ";
    cin >> festa[i].ingre;
    cout << "Custo de organização: ";
    cin >> festa[i].custo;
    // Pergunta se o evento é open bar
    cout << "O evento é open bar? 1-Sim/0-Não: ";
    cin >> festa[i].openBar;
    // Lógica para calcular os valores de entrada (popu, norm, espec) conforme a descrição fornecida
    if (festa[i].openBar) {
        festa[i].popu = festa[i].custo / festa[i].ingre + 1.75 * festa[i].drinks[0].valor;
    } else {
        festa[i].popu = festa[i].custo / festa[i].ingre;}
    // Calcular valores de entrada normal e especial
    festa[i].norm = festa[i].popu * 1.1;
    festa[i].espec = festa[i].norm * 1.15;
    // Exemplo de exibição das informações cadastradas
    cout << "Evento cadastrado com sucesso!" << endl;
    cout << "Nome: " << festa[i].nome << endl;
    cout << "Local: " << festa[i].local << endl;
    cout << "Data: " << festa[i].data << endl;
    cout << "Quantidade de ingressos: " << festa[i].ingre << endl;
    cout << "Custo de organização: " << festa[i].custo << endl;
    cout << "Valor de entrada (Popular): " << festa[i].popu << endl;
    cout << "Valor de entrada (Normal): " << festa[i].norm << endl;
    cout << "Valor de entrada (Especial): " << festa[i].espec << endl;
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    int param1=2,opcao,sis,i,opc;
    evento festa[50];
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
            if(i!=-1)
                cout<<"Iniciando a execução...";
                cadastra_evento(festa,i,sis,param1);
            break;
        case 2:
            clstel(sis,param1);
            cout<<"Iniciando a execução...";
            //atv2(sis,param1);
            break;
        case 3:
            clstel(sis,param1);
            cout<<"Iniciando a execução...";
            //atv3(sis,param1);
            break;
        case 4:
            clstel(sis,param1);
            cout<<"Iniciando a execução...";
            //atv4(sis,param1);
            break;
        case 5:
            clstel(sis,param1);
            cout<<"Iniciando a execução...";
            //atv5(sis,param1);
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
