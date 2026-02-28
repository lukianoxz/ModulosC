#include "./Modulos/Texto.h"

int main(){

    String* MinhaStr = Criar_Str();

    Colocar_Texto(MinhaStr, "Ola meu nome e lucas");

    Printar(MinhaStr);
    Erradicar_String(MinhaStr);

    String* S2 = Criar_Str();

    Colocar_Texto(S2, "Testando a ");
    Concatenar_Texto_String(S2, "Concatenacao de texto em strings");

    printf("\n");
    Printar(S2);

    String* S3 = Criar_Str();

    Colocar_Texto(S3, " e eu amo vitamina de abacate");

    Concatenar_String_String(S2, S3);

    printf("\n");
    Printar(S2);

    Erradicar_String(S3);

    Limpar_String(S2);
    Colocar_Texto(S2, "String foi limpa e vai ser reusada");

    printf("\n");
    Printar(S2);

    String* S4 = Criar_Str();

    printf("\nTestando sistema de comparacao de string\nTeste 1 String a = Sim e String b = Nao\n");

    Limpar_String(S2);
    
    Colocar_Texto(S2, "Sim");
    Colocar_Texto(S4, "Nao");

    if (Comparar_String(S2, S4)){
        printf("Ue deu igual as strings reolhe o codigo tem um erro ai");
        Erradicar_String(S2);
        Erradicar_String(S4);
        return 0;
    } else {
        printf("Comparacao falou que é diferente indo para o teste 2\nString a = Sim e String b = Sim\n");
        Limpar_String(S4);
        Colocar_Texto(S4, "Sim");
    }

    if (Comparar_String(S2, S4)){
        printf("A comparacao entre duas strings iguais foi um sucesso teste encerrado\n");
    } else {
        printf("As strings sao iguais mas deu erro na comparacao\n");
    }

    Erradicar_String(S2);
    Erradicar_String(S4);

    return 0;
}