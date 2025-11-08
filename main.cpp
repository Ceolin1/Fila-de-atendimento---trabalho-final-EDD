#include <iostream>
#include <queue>
using namespace std;

struct paciente{
    string senha;
    char prioridade;
    int hora,minuto;
};

#include "funcoes.cpp"

int main(){
    paciente aux;
    queue<paciente>pacientes;
    menu();
    char tipoAtendimento;
    cin >> tipoAtendimento;
    if(tipoAtendimento=='C'){
        chegada(aux, pacientes);
    }

}