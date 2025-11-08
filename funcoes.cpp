#include <iostream>
#include <queue>
#include <string>
void menu(){
    std::cout<<"Selecione um evento:\n";
    std::cout<<"Digite 'C' para registrar a chegada de um paciente\n";
    std::cout<<"Digite 'A' para atender um paciente\n";
    std::cout<<"Digite 'D' para exeibir informaçoes sobre o estado das filas\n";
    std::cout<<"Digite 'Q' para sair\n";
}

void chegada(paciente &aux, std::queue<paciente> &pacientes){
    std::cout<<"Digite a senha do paciente:\n";
    std::cin>>aux.senha;

    std::cout<<"Digite a prioridade:\n";
    std::cin>>aux.prioridade;

    std::cout<<"Digite a hora de chegada:\n";
    std::cin>>aux.hora;

    std::cout<<"Digite o minuto de chegada\n";
    std::cin>>aux.minuto;

    pacientes.push(aux);
}
