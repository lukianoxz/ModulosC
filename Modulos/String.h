#ifndef String_H
#define String_H

#include <stdlib.h>
#include <stdio.h>

#include "Vetor.h"

typedef struct {
    Vetor_char* Texto;
} String;

static String* Criar_Str(){
    String* Str = (String*)malloc(sizeof(String));
    Str->Texto = Criar_Vetor_char();
    return Str;
}

static void Colocar_Texto(String* Str, const char* Texto){
    int Tamannho_T = 0;

    while (Texto[Tamannho_T] != '\0'){
        Tamannho_T++;
    }
    
    for (int i = 0; i < Tamannho_T; i++){
        Puxar_Elemento_Vetor_char(Str->Texto, Texto[i]);
    }
}

static void Printar(String* Str){
    for (int i = 0; i < Str->Texto->Tamanho; i++){
        putchar(Str->Texto->Conteudo[i]);
    }
}

static void Erradicar_String(String* Str){
    Erradicar_Vetor_char(Str->Texto);
    free(Str);
}

static void Concatenar_Texto_String(String* Str, const char* Texto){
    String* TempStr = Criar_Str();
    Colocar_Texto(TempStr, Texto);
    Concatenar_Vetor_char(Str->Texto, TempStr->Texto);
    Erradicar_String(TempStr);
}

static void Concatenar_String_String(String* Str, String* Str2){
    Concatenar_Vetor_char(Str->Texto, Str2->Texto);
}

static void Limpar_String(String* Str){
    Limpar_Vetor_char(Str->Texto);
}

static int Comparar_String(String* Str, String* Str2){
    int T_Str = Str->Texto->Tamanho;
    int T_Str2 = Str2->Texto->Tamanho;

    if (T_Str != T_Str2) return 0;

    for(int i = 0; i != T_Str; i++){
        if(Str->Texto->Conteudo[i] != Str2->Texto->Conteudo[i]) return 0;
    }

    return 1;
}

static void Pegar_Input_Str(String* Str){
    Limpar_String(Str);
    char C;

    while ((C = getchar()) != '\n' && C != EOF){
        Puxar_Elemento_Vetor_char(Str->Texto, C);
    }
}

static void String_Lower(String* Str){
    for (int i = 0; i < Str->Texto->Tamanho; i++){
        if (Str->Texto->Conteudo[i] >= 'A' && Str->Texto->Conteudo[i] <= 'Z') Str->Texto->Conteudo[i] += 32;
    }
}

static void String_Upper(String* Str){
    for (int i = 0; i < Str->Texto->Tamanho; i++){
        if (Str->Texto->Conteudo[i] >= 'a' && Str->Texto->Conteudo[i] <= 'z') Str->Texto->Conteudo[i] -= 32;
    }
}

static int String_Int_T(String* Str){
    int Negativo = 0;
    if(Str->Texto->Conteudo[0] == '-'){
        if (Str->Texto->Tamanho < 2){
            return 0;
        }
        Negativo = 1;
    }

    for(int i = 0 + Negativo; i < Str->Texto->Tamanho; i++){
        if (Str->Texto->Conteudo[i] > '9' || Str->Texto->Conteudo[i] < '0'){
            return 0;
        }
    }
    return 1;
}

static int String_Int(String* Str){
    int Acumulador = 0;
    int Negativo = 0;

    if(Str->Texto->Conteudo[0] == '-'){
        Negativo = 1;
    }

    for(int i = 0 + Negativo; i < Str->Texto->Tamanho; i++){
        Acumulador = (Acumulador * 10) + (int)(Str->Texto->Conteudo[i] - '0');
    }

    return (Negativo == 1) ? Acumulador * -1 : Acumulador;
}


typedef String* String_Ptr;
Definir_Vetor(String_Ptr);

#endif