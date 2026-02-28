#ifndef Texto_H
#define Texto_H

#include <stdlib.h>
#include <stdio.h>

#include "Vetor.h"

typedef struct {
    Vetor_char* Vetor;
} Texto;

static Texto* Criar_Texto(){
    Texto* T = (Texto*)malloc(sizeof(Texto));
    T->Vetor = Criar_Vetor_char();
    return T;
}

static void Texto_Inserir(Texto* T, const char* Conteudo){
    int Tamannho_T = 0;

    while (Conteudo[Tamannho_T] != '\0'){
        Tamannho_T++;
    }
    
    for (int i = 0; i < Tamannho_T; i++){
        Vetor_char_Inserir_Elemento(T->Vetor, Conteudo[i]);
    }
}

static void Imprimir_Texto(Texto* T){
    for (int i = 0; i < T->Vetor->Tamanho; i++){
        putchar(T->Vetor->Conteudo[i]);
    }
}

static void Deletar_Texto(Texto* T){
    Deletar_Vetor_char(T->Vetor);
    free(T);
}

static void Concatenar_Texto_Com_Lista_De_Letra(Texto* T, const char* Lista_De_Letra){
    Texto* TempT = Criar_Texto();
    Texto_Inserir(TempT, Lista_De_Letra);
    Concatenar_Vetor_char(T->Vetor, TempT->Vetor);
    Deletar_Texto(TempT);
}

static void Concatenar_Texto_Com_Texto(Texto* T, Texto* T2){
    Concatenar_Vetor_char(T->Vetor, T2->Vetor);
}

static void Limpar_Texto(Texto* T){
    Limpar_Vetor_char(T->Vetor);
}

static int Comparar_Texto(Texto* T, Texto* T2){
    int Tamanho_T = T->Vetor->Tamanho;
    int Tamanho_T2 = T2->Vetor->Tamanho;

    if (Tamanho_T != Tamanho_T2) return 0;

    for(int i = 0; i != Tamanho_T; i++){
        if(T->Vetor->Conteudo[i] != T2->Vetor->Conteudo[i]) return 0;
    }

    return 1;
}

static void Pegar_Entrada_Em_Texto(Texto* T){
    Limpar_Texto(T);
    int C;

    while ((C = getchar()) != '\n' && C != EOF){
        Vetor_char_Inserir_Elemento(T->Vetor, C);
    }
}

static void Texto_Letra_Minuscula(Texto* T){
    for (int i = 0; i < T->Vetor->Tamanho; i++){
        if (T->Vetor->Conteudo[i] >= 'A' && T->Vetor->Conteudo[i] <= 'Z') T->Vetor->Conteudo[i] += 32;
    }
}

static void Texto_Letra_De_Forma(Texto* T){
    for (int i = 0; i < T->Vetor->Tamanho; i++){
        if (T->Vetor->Conteudo[i] >= 'a' && T->Vetor->Conteudo[i] <= 'z') T->Vetor->Conteudo[i] -= 32;
    }
}

static int Texto_Contem_Apenas_Int(Texto* T){
    int Negativo = 0;
    if(T->Vetor->Conteudo[0] == '-'){
        if (T->Vetor->Tamanho < 2){
            return 0;
        }
        Negativo = 1;
    }

    for(int i = 0 + Negativo; i < T->Vetor->Tamanho; i++){
        if (T->Vetor->Conteudo[i] > '9' || T->Vetor->Conteudo[i] < '0'){
            return 0;
        }
    }
    return 1;
}

static int Texto_Para_Int(Texto* T){
    int Acumulador = 0;
    int Negativo = 0;

    if(T->Vetor->Conteudo[0] == '-'){
        Negativo = 1;
    }

    for(int i = 0 + Negativo; i < T->Vetor->Tamanho; i++){
        Acumulador = (Acumulador * 10) + (int)(T->Vetor->Conteudo[i] - '0');
    }

    return (Negativo == 1) ? Acumulador * -1 : Acumulador;
}


typedef Texto* Texto_Ptr;
Definir_Vetor(Texto_Ptr);

#endif