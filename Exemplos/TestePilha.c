#include <stdio.h>
#include "../Modulos/Pilha.h"

Definir_Pilha(int);

int main(){
    Pilha_int* Mp;

    Mp = Criar_Pilha_int();

    Pilha_int_Inserir_Elemento(Mp, 1);
    Pilha_int_Inserir_Elemento(Mp, 2);
    Pilha_int_Inserir_Elemento(Mp, 3);

    printf("%d\n", Pilha_int_Remover_Elemento(Mp));
    printf("%d\n", Pilha_int_Remover_Elemento(Mp));
    printf("%d\n", Pilha_int_Remover_Elemento(Mp));

    Deletar_Pilha_int(Mp);

    return 0;
}