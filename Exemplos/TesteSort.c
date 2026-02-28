#include <stdio.h>
#include "../Modulos/Vetor.h"
#include "../Modulos/Arrumar.h"
#include "../Modulos/Utilitarios.h"

int main(){
    Vetor_int* VetorBaguncado = Criar_Vetor_int();

    Vetor_int_Inserir_Elemento(VetorBaguncado, 7);
    Vetor_int_Inserir_Elemento(VetorBaguncado, 2);
    Vetor_int_Inserir_Elemento(VetorBaguncado, 92);
    Vetor_int_Inserir_Elemento(VetorBaguncado, 1);
    Vetor_int_Inserir_Elemento(VetorBaguncado, 1);
    Vetor_int_Inserir_Elemento(VetorBaguncado, 14);

    Imprimir_Vetor_Int(VetorBaguncado);
    Arrumar_Vetor_Int_Bolha(VetorBaguncado);

    Imprimir_Vetor_Int(VetorBaguncado);
    Deletar_Vetor_int(VetorBaguncado);

    return 0;
}