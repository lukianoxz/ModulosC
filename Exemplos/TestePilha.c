#include <stdio.h>
#include "ModulosC/Stack.h"

Definir_Pilha(int);

int main(){
    Pilha_int* Mp;

    Mp = Criar_Pilha_int();

    Pilha_int_Adicionar_Elemento(Mp, 1);
    Pilha_int_Adicionar_Elemento(Mp, 2);
    Pilha_int_Adicionar_Elemento(Mp, 3);

    printf("%d\n", Pilha_int_Pegar_Elemento(Mp));
    printf("%d\n", Pilha_int_Pegar_Elemento(Mp));
    printf("%d\n", Pilha_int_Pegar_Elemento(Mp));

    Erradicar_Pilha_int(Mp);

    return 0;
}