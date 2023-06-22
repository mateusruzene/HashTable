#include <stdio.h>

#include "tabelaHash.h"

int main()
{
    imprimirDadosAlunos();

    size_t tamanho;
    scanf("%ld", &tamanho);

    struct tabelaHash *tabela = gerarTabelaHash(tamanho);

    struct nodoHash *auxNodo;
    char operacao;
    int valor;

    while (1)
    {
        scanf(" %c", &operacao);

        if (operacao == 'i')
        { // Inserir
            scanf("%d", &valor);
            auxNodo = buscar(tabela, tabela->tamTabela, valor);
            if (!auxNodo)
                inserir(tabela, tabela->tamTabela, valor);
            else
                printf("Falha ao inserir %d\n", valor);
        }
        else if (operacao == 'r')
        { // Remover
            scanf("%d", &valor);
            auxNodo = buscar(tabela, tabela->tamTabela, valor);
            if (auxNodo)
                excluir(tabela, tabela->tamTabela, auxNodo);
            else
                printf("Falha ao remover %d\n", valor);
        }
        else if (operacao == 'b')
        { // Buscar
            scanf("%d", &valor);
            if (buscar(tabela, tabela->tamTabela, valor))
                printf("Encontrado %d.\n", valor);
            else
                printf("Nao encontrado %d.\n", valor);
        }
        else if (operacao == 'l') // Imprimir tabela
            imprimirTabelaHash(tabela, tabela->tamTabela);
        else if (operacao == 'f') // Finalizar e sair
            break;
        else
            printf("Operação inválida.\n");
    }

    liberarTabelaHash(tabela, tabela->tamTabela);

    return 0;
}