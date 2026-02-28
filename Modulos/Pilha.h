#ifndef Pilha_H
#define Pilha_H

#include "Vetor.h"

#define Definir_Pilha(Tipo) \
typedef struct { \
    Vetor_##Tipo* Vetor; \
} Pilha_##Tipo; \
static Pilha_##Tipo* Criar_Pilha_##Tipo(){ \
    Pilha_##Tipo* Temp; \
    Temp = (Pilha_##Tipo*)malloc(sizeof(Pilha_##Tipo)); \
    Temp->Vetor = Criar_Vetor_##Tipo(); \
    return Temp; \
} \
static void Pilha_##Tipo##_Inserir_Elemento(Pilha_##Tipo* Pilha, Tipo Elemento){ \
    Vetor_##Tipo##_Inserir_Elemento(Pilha->Vetor, Elemento); \
} \
static Tipo Pilha_##Tipo##_Remover_Elemento(Pilha_##Tipo* Pilha){ \
    Pilha->Vetor->Tamanho--; \
    return Pilha->Vetor->Conteudo[Pilha->Vetor->Tamanho]; \
} \
static void Deletar_Pilha_##Tipo(Pilha_##Tipo* Pilha){ \
    Deletar_Vetor_##Tipo(Pilha->Vetor); \
    free(Pilha); \
}

#endif