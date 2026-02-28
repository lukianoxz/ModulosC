#ifndef Stack_H
#define Stack_H

#include "Vetor.h"

#define Definir_Pilha(Tipo) \
typedef struct { \
    Vetor_##Tipo* Pilha; \
} Pilha_##Tipo; \
static Pilha_##Tipo* Criar_Pilha_##Tipo(){ \
    Pilha_##Tipo* Temp; \
    Temp = (Pilha_##Tipo*)malloc(sizeof(Pilha_##Tipo)); \
    Temp->Pilha = Criar_Vetor_##Tipo(); \
    return Temp; \
} \
static void Pilha_##Tipo##_Adicionar_Elemento(Pilha_##Tipo* Pilha, Tipo Elemento){ \
    Puxar_Elemento_Vetor_##Tipo(Pilha->Pilha, Elemento); \
} \
static Tipo Pilha_##Tipo##_Pegar_Elemento(Pilha_##Tipo* Pilha){ \
    Pilha->Pilha->Tamanho--; \
    return Pilha->Pilha->Conteudo[Pilha->Pilha->Tamanho]; \
} \
static void Erradicar_Pilha_##Tipo(Pilha_##Tipo* Pilha){ \
    Erradicar_Vetor_##Tipo(Pilha->Pilha); \
    free(Pilha); \
}

#endif