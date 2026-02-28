#ifndef Vetor_H
#define Vetor_H

#include <stdlib.h>

#define Definir_Vetor(Tipo) \
typedef struct { \
    Tipo* Conteudo; \
    int Tamanho; \
    int Capacidade; \
    int Tamanho_Tipo; \
} Vetor_##Tipo; \
\
static Vetor_##Tipo* Criar_Vetor_##Tipo(){ \
    Vetor_##Tipo* Vetor_Temporario = (Vetor_##Tipo*)malloc(sizeof(Vetor_##Tipo)); \
    Vetor_Temporario->Tamanho = 0; \
    Vetor_Temporario->Tamanho_Tipo = sizeof(Tipo); \
    Vetor_Temporario->Capacidade = 2; \
    Vetor_Temporario->Conteudo = (Tipo*)malloc(Vetor_Temporario->Tamanho_Tipo * Vetor_Temporario->Capacidade); \
    return Vetor_Temporario; \
} \
static void Vetor_##Tipo##_Inserir_Elemento(Vetor_##Tipo* Vetor, Tipo Elemento){ \
    Vetor->Tamanho += 1; \
    if (Vetor->Tamanho > Vetor->Capacidade){ \
        Vetor->Capacidade *= 2; \
        Vetor->Conteudo = (Tipo*)realloc(Vetor->Conteudo, Vetor->Tamanho_Tipo * Vetor->Capacidade); \
    } \
    Vetor->Conteudo[Vetor->Tamanho - 1] = Elemento; \
} \
static void Deletar_Vetor_##Tipo(Vetor_##Tipo* Vetor){ \
    free(Vetor->Conteudo); \
    free((Vetor_##Tipo*) Vetor); \
} \
static void Concatenar_Vetor_##Tipo(Vetor_##Tipo* Vetor, Vetor_##Tipo* Vetor2){ \
    for (int i = 0; i < Vetor2->Tamanho; i++){ \
        Vetor_##Tipo##_Inserir_Elemento(Vetor, Vetor2->Conteudo[i]); \
    } \
} \
static void Limpar_Vetor_##Tipo(Vetor_##Tipo* Vetor){ \
    free(Vetor->Conteudo); \
    Vetor->Capacidade = 2; \
    Vetor->Tamanho = 0; \
    Vetor->Conteudo = (Tipo*)malloc(Vetor->Tamanho_Tipo * Vetor->Capacidade); \
}

//Defina todos vetores que voce vai usar aqui

Definir_Vetor(int);
Definir_Vetor(float);
Definir_Vetor(char);

#endif