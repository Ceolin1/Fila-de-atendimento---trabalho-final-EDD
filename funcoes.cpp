#include <iostream>
#include <queue>
#include <string>

void menu(){
    std::cout<<"Selecione um evento:\n";
    std::cout<<"Digite 'C' para registrar a chegada de um paciente\n";
    std::cout<<"Digite 'A' para atender um paciente\n";
    std::cout<<"Digite 'D' para exibir informacoes sobre o estado das filas\n";
    std::cout<<"Digite 'Q' para sair\n";
    
}

void calcEspera(int &hora, int &minuto, int &esperah,int &esperam ,std::queue<paciente> lista){
    esperah = hora - lista.front().hora;
    esperam = minuto - lista.front().minuto;
    if(esperam<0){
        esperah=0;
        esperam=60-(esperam*-1);
    }
    if(esperah<0){
        esperah=00;
    }

}





void chegada(paciente &aux, 
            std::queue<paciente> &emergencia, 
            std::queue<paciente> &urgencia, 
            std::queue<paciente> &poucoUrgente, 
            std::queue<paciente> &naoUrgente){

    std::cout<<"Digite a senha do paciente:\n";
    std::cin>>aux.senha;

    std::cout<<"Digite a prioridade:\n";
    std::cin>>aux.prioridade;

    std::cout<<"Digite a hora de chegada:\n";
    std::cin>>aux.hora;

    std::cout<<"Digite o minuto de chegada\n";
    std::cin>>aux.minuto;

    if(aux.prioridade=='V'){
        emergencia.push(aux);
    }else if(aux.prioridade=='A'){
        urgencia.push(aux);
    }else if(aux.prioridade=='D'){
        poucoUrgente.push(aux);
    }else if(aux.prioridade=='B'){
        naoUrgente.push(aux);
    }
}
void atendimento(int &hora, int &minuto, int &esperah,int &esperam,
            std::queue<paciente> &emergencia, 
            std::queue<paciente> &urgencia, 
            std::queue<paciente> &poucoUrgente, 
            std::queue<paciente> &naoUrgente){
    std::cout<<"Digite o horario do atendimento: "<< "\n";
    std::cin>>hora;
    std::cin>>minuto;
    if(emergencia.empty()&&urgencia.empty()&&poucoUrgente.empty()&&naoUrgente.empty()){
        std::cout<< hora<<" "<<minuto <<" Sem pacientes aguardando atendimento"<<"\n";

    }else if(!emergencia.empty()){
        calcEspera(hora,minuto,esperah, esperam,emergencia);
        emergencia.pop();
        std::cout<<"o paciente esperou: "<<esperah<<" horas e "<<esperam<<" minutos."<<"\n";

    }else if(emergencia.empty()&&!urgencia.empty()){

        calcEspera(hora,minuto,esperah, esperam,urgencia);
        urgencia.pop();
        std::cout<<"o paciente esperou: "<<esperah<<" horas e "<<esperam<<" minutos."<<"\n";

    }else if(emergencia.empty()&&urgencia.empty()&&!poucoUrgente.empty()){

        calcEspera(hora,minuto,esperah, esperam,poucoUrgente);
        poucoUrgente.pop();
        std::cout<<"o paciente esperou: "<<esperah<<" horas e "<<esperam<<" minutos."<<"\n";

    }else if(emergencia.empty()&&urgencia.empty()&&poucoUrgente.empty()&&!naoUrgente.empty()){

        calcEspera(hora,minuto,esperah, esperam,naoUrgente);
        naoUrgente.pop();
        std::cout<<"o paciente esperou: "<<esperah<<" horas e "<<esperam<<" minutos."<<"\n";
    }
}
