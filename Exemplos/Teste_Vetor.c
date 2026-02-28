#include <stdio.h>
#include "../Modulos/Vetor.h"

int main(){
    Vetor_int* Mv = Criar_Vetor_int();

    Vetor_int_Inserir_Elemento(Mv, 2);

    printf("\n");
    printf("%d", Mv->Conteudo[0]);
    printf("\n\n");

    Deletar_Vetor_int(Mv);

    return 0;
}