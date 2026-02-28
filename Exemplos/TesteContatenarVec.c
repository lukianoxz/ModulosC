#include <stdio.h>
#include "./Modulos/Vetor.h"

int main(){
    Vetor_int* Mv = Criar_Vetor_int();
    Vetor_int* Mv1 = Criar_Vetor_int();

    Puxar_Elemento_Vetor_int(Mv, 2);
    Puxar_Elemento_Vetor_int(Mv1, 4);

    Concatenar_Vetor_int(Mv, Mv1);

    printf("\n");
    printf("%d%d", Mv->Conteudo[0], Mv->Conteudo[1]);
    printf("\n\n");

    Erradicar_Vetor_int(Mv);
    Erradicar_Vetor_int(Mv1);

    return 0;
}