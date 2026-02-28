#include <stdio.h>
#include "ModulosC/Vetor.h"
#include "ModulosC/AlgoritimosSort.h"
#include "ModulosC/Utilitarios.h"

int main(){
    Vetor_int* VetorBaguncado = Criar_Vetor_int();

    Puxar_Elemento_Vetor_int(VetorBaguncado, 7);
    Puxar_Elemento_Vetor_int(VetorBaguncado, 2);
    Puxar_Elemento_Vetor_int(VetorBaguncado, 92);
    Puxar_Elemento_Vetor_int(VetorBaguncado, 1);
    Puxar_Elemento_Vetor_int(VetorBaguncado, 1);
    Puxar_Elemento_Vetor_int(VetorBaguncado, 14);

    Printar_Vetor_Int(VetorBaguncado);
    Sort_Vetor_int(VetorBaguncado, Sort_Int_Simples);

    Printar_Vetor_Int(VetorBaguncado);
    Erradicar_Vetor_int(VetorBaguncado);

    return 0;
}