#include <stdio.h>
#include "../Modulos/Vetor.h"

int main(){
    Vetor_int* Mv = Criar_Vetor_int();
    Vetor_int* Mv1 = Criar_Vetor_int();

    Vetor_int_Inserir_Elemento(Mv, 2);
    Vetor_int_Inserir_Elemento(Mv1, 4);

    Concatenar_Vetor_int(Mv, Mv1);

    printf("\n");
    printf("%d%d", Mv->Conteudo[0], Mv->Conteudo[1]);
    printf("\n\n");

    Deletar_Vetor_int(Mv);
    Deletar_Vetor_int(Mv1);

    return 0;
}