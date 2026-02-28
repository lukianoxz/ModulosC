#include <stdlib.h>
#include <stdio.h>

#include "./Modulos/String.h"
#include "./Modulos/Utilitarios.h"

int main(int argc, char* argv[]){
    Vetor_String_Ptr* Argumentos;

    Argumentos = Criar_Vetor_String_Ptr();

    for(int i = 0; i < argc; i++){
        String* Temp;
        Temp = Criar_Str();

        Colocar_Texto(Temp, argv[i]);

        Puxar_Elemento_Vetor_String_Ptr(Argumentos, Temp);
    }

    String* Alvo;
    Alvo = Criar_Str();

    Colocar_Texto(Alvo, "Oi");

    if (argc >= 2){
        if (Comparar_String(Argumentos->Conteudo[1], Alvo)){
            printf("Oiiii voce descobriu o segredo\n");
        }
    }

    Limpar_Vetor_De_String(Argumentos);
    Erradicar_String(Alvo);

    return 0;
}