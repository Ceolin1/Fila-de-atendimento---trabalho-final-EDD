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
    queue<paciente>emergencia;
    queue<paciente>urgencia;
    queue<paciente>poucoUrgente;
    queue<paciente>naoUrgente;
    int hora, min, esperah, esperam;

    paciente aux;
    char tipoAtendimento;
    do{
        menu();
        cin >> tipoAtendimento;
        
        if(tipoAtendimento=='C'){
            chegada(aux, emergencia, urgencia, poucoUrgente, naoUrgente);
        }
        else if(tipoAtendimento=='A'){
            atendimento(hora,min, esperah,esperam ,emergencia, urgencia, poucoUrgente, naoUrgente);
        }
        else if(tipoAtendimento=='D'){

        }
    } while(tipoAtendimento != 'Q'); 
}