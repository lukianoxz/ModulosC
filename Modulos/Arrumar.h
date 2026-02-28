#ifndef Arrumar_H
#define Arrumar_H

#include "Vetor.h"

static void Arrumar_Vetor_Int_Bolha(Vetor_int* Vetor){
    int Vetor_Arrumado_Sinal;

    while (true){
        Vetor_Arrumado_Sinal = 1;
        for(int i = 0; i < (Vetor->Tamanho - 1); i++){
            if(Vetor->Conteudo[i] > Vetor->Conteudo[i+1]){
                int Numero_Frente = Vetor->Conteudo[i+1];
                Vetor->Conteudo[i+1] = Vetor->Conteudo[i];
                Vetor->Conteudo[i] = Numero_Frente;
                Vetor_Arrumado_Sinal = 0;
            }
        }
        if (Vetor_Arrumado_Sinal){
            break;
        }
    }
}

#endif