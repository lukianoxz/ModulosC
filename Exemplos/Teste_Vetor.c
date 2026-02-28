#include <stdio.h>
#include "ModulosC/Vetor.h"

int main(){
    Vetor_int* Mv = Criar_Vetor_int();

    Puxar_Elemento_Vetor_int(Mv, 2);

    printf("\n");
    printf("%d", Mv->Conteudo[0]);
    printf("\n\n");

    Erradicar_Vetor_int(Mv);

    return 0;
}