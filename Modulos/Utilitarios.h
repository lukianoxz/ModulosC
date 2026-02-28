#ifndef Utilitarios_H
#define Utilitarios_H

#include <stdio.h>

#include "Vetor.h"
#include "Texto.h"

static void Imprimir_Vetor_Int(Vetor_int* Vetor){
    for (int i = 0; i < Vetor->Tamanho; i++){
        printf("%d ", Vetor->Conteudo[i]);
    }
    printf("\n");
}

static void Limpar_Vetor_De_Texto(Vetor_Texto_Ptr* Vetor){
    for(int i = 0; i < Vetor->Tamanho; i++){
        Deletar_Texto(Vetor->Conteudo[i]);
    }
    Deletar_Vetor_Texto_Ptr(Vetor);
}

#endif