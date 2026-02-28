#ifndef AlgoritimosSort_H
#define AlgoritimosSort_H

#include "Vetor.h"

static void Sort_Int_Simples(Vetor_int* Vetor){
    int Vetor_Organizado = 0;

    while (Vetor_Organizado == 0){
        for(int i = 0; i < Vetor->Tamanho; i++){
            if(i < (Vetor->Tamanho - 1)){
                if(Vetor->Conteudo[i] > Vetor->Conteudo[i+1]){
                    int Numero_Frente_Temp = Vetor->Conteudo[i+1];
                    Vetor->Conteudo[i+1] = Vetor->Conteudo[i];
                    Vetor->Conteudo[i] = Numero_Frente_Temp;
                }
            }
        }
        int Arrumado = 1;
        for(int i = 0; i < Vetor->Tamanho; i++){
            if(i < (Vetor->Tamanho - 1)){
                if(Vetor->Conteudo[i] > Vetor->Conteudo[i+1]){
                    Arrumado = 0;
                }
            }
        }
        if (Arrumado == 1){
            Vetor_Organizado = 1;
        }
    }
}


#endif