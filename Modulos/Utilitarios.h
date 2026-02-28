#ifndef Utilitarios_H
#define Utilitarios_H

#include <stdio.h>

#include "Vetor.h"
#include "String.h"

static void Printar_Vetor_Int(Vetor_int* Vetor){
    for (int i = 0; i < Vetor->Tamanho; i++){
        printf("%d ", Vetor->Conteudo[i]);
    }
    printf("\n");
}

static void Limpar_Vetor_De_String(Vetor_String_Ptr* Vetor){
    for(int i = 0; i < Vetor->Tamanho; i++){
        Erradicar_String(Vetor->Conteudo[i]);
    }
    Erradicar_Vetor_String_Ptr(Vetor);
}

#endif