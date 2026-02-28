#include "../Modulos/Texto.h"

int main(){

    Texto* MinhaStr = Criar_Texto();

    Texto_Inserir(MinhaStr, "Ola meu nome e lucas");

    Imprimir_Texto(MinhaStr);
    Deletar_Texto(MinhaStr);

    Texto* S2 = Criar_Texto();

    Texto_Inserir(S2, "Testando a ");
    Concatenar_Texto_Com_Lista_De_Letra(S2, "Concatenacao de texto em Textos");

    printf("\n");
    Imprimir_Texto(S2);

    Texto* S3 = Criar_Texto();

    Texto_Inserir(S3, " e eu amo vitamina de abacate");

    Concatenar_Texto_Com_Texto(S2, S3);

    printf("\n");
    Imprimir_Texto(S2);

    Deletar_Texto(S3);

    Limpar_Texto(S2);
    Texto_Inserir(S2, "Texto foi limpa e vai ser reusada");

    printf("\n");
    Imprimir_Texto(S2);

    Texto* S4 = Criar_Texto();

    printf("\nTestando sistema de comparacao de Texto\nTeste 1 Texto a = Sim e Texto b = Nao\n");

    Limpar_Texto(S2);
    
    Texto_Inserir(S2, "Sim");
    Texto_Inserir(S4, "Nao");

    if (Comparar_Texto(S2, S4)){
        printf("Ue deu igual as Textos reolhe o codigo tem um erro ai");
        Deletar_Texto(S2);
        Deletar_Texto(S4);
        return 0;
    } else {
        printf("Comparacao falou que é diferente indo para o teste 2\nTexto a = Sim e Texto b = Sim\n");
        Limpar_Texto(S4);
        Texto_Inserir(S4, "Sim");
    }

    if (Comparar_Texto(S2, S4)){
        printf("A comparacao entre duas Textos iguais foi um sucesso teste encerrado\n");
    } else {
        printf("As Textos sao iguais mas deu erro na comparacao\n");
    }

    Deletar_Texto(S2);
    Deletar_Texto(S4);

    return 0;
}