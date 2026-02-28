#include <stdlib.h>
#include <stdio.h>

#include "../Modulos/Texto.h"
#include "../Modulos/Utilitarios.h"

int main(int argc, char* argv[]){
    Vetor_Texto_Ptr* Argumentos;

    Argumentos = Criar_Vetor_Texto_Ptr();

    for(int i = 0; i < argc; i++){
        Texto* Temp;
        Temp = Criar_Texto();

        Texto_Inserir(Temp, argv[i]);

        Vetor_Texto_Ptr_Inserir_Elemento(Argumentos, Temp);
    }

    Texto* Alvo;
    Alvo = Criar_Texto();

    Texto_Inserir(Alvo, "Oi");

    if (argc >= 2){
        if (Comparar_Texto(Argumentos->Conteudo[1], Alvo)){
            printf("Oiiii voce descobriu o segredo\n");
        }
    }

    Limpar_Vetor_De_Texto(Argumentos);
    Deletar_Texto(Alvo);

    return 0;
}