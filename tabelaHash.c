#include "tabelaHash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void matarProgramaFaltaMemoria()
{
    fputs("Falha ao alocar memoria.\n", stderr);
    exit(1);
}

struct aluno *getAluno1()
{
    struct aluno *retorno = malloc(sizeof(struct aluno));
    if (!retorno)
        matarProgramaFaltaMemoria();
    retorno->nome = malloc(sizeof("Mateus Siqueira Ruzene")); // sizeof conta o \0
    if (!retorno->nome)
        matarProgramaFaltaMemoria();
    retorno->nomeDinf = malloc(sizeof("msr22"));
    if (!(retorno->nomeDinf))
        matarProgramaFaltaMemoria();
    if (!(retorno->nomeDinf))
        matarProgramaFaltaMemoria();

    strcpy(retorno->nome, "Mateus Siqueira Ruzene");
    strcpy(retorno->nomeDinf, "msr22");
    retorno->grr = 20221223;

    return retorno;
}

struct aluno *getAluno2()
{
    return NULL;
}

void imprimirDadosAlunos()
{
    struct aluno *aluno = getAluno1();

    printf("Trabalho de %s\n", aluno->nome);
    printf("Login Dinf %s\n", aluno->nomeDinf);
    printf("GRR %u\n\n", aluno->grr);

    free(aluno->nome);
    free(aluno->nomeDinf);
    free(aluno);

    aluno = getAluno2();
    if (!aluno)
        return;

    printf("...E... \n\n");
    printf("Trabalho de %s\n", aluno->nome);
    printf("Login Dinf %s\n", aluno->nomeDinf);
    printf("GRR %u\n\n", aluno->grr);

    free(aluno->nome);
    free(aluno->nomeDinf);
    free(aluno);
}

struct tabelaHash *gerarTabelaHash(size_t tamTabela)
{
    struct tabelaHash *tabelaHash = (struct tabelaHash *)malloc(sizeof(struct tabelaHash));
    tabelaHash->tabela = (struct nodoHash **)calloc(tamTabela, sizeof(struct nodoHash *));
    tabelaHash->tamTabela = tamTabela;
    return tabelaHash;
}

int hash(int chave, size_t tamanhoTabela)
{
    return chave % tamanhoTabela;
}

struct nodoHash *inserir(struct tabelaHash tabelaHash[], size_t tamTabela, int chave)
{
    int index = hash(chave, tamTabela);

    struct nodoHash *novoNodo = (struct nodoHash *)malloc(sizeof(struct nodoHash));
    novoNodo->chave = chave;
    novoNodo->prox = NULL;

    if (tabelaHash->tabela[index] == NULL)
    {
        tabelaHash->tabela[index] = novoNodo;
    }
    else
    {
        struct nodoHash *atualNodo = tabelaHash->tabela[index];
        while (atualNodo->prox != NULL)
        {
            atualNodo = atualNodo->prox;
        }
        atualNodo->prox = novoNodo;
    }
    return novoNodo;
}

void liberarTabelaHash(struct tabelaHash tabelaHash[], size_t tamTabela)
{
    for (int i = 0; i < tamTabela; i++)
    {
        struct nodoHash *atualNodo = tabelaHash->tabela[i];
        while (atualNodo != NULL)
        {
            struct nodoHash *proxNodo = atualNodo->prox;
            free(atualNodo);
            atualNodo = proxNodo;
        }
    }
    free(tabelaHash->tabela);
    free(tabelaHash);
}

void imprimirTabelaHash(struct tabelaHash tabelaHash[], size_t tamTabela)
{
    for (int i = 0; i < tamTabela; i++)
    {
        printf("%d ", i);
        if (tabelaHash->tabela[i] == NULL)
        {
            printf("NULL");
        }
        else
        {
            struct nodoHash *atualNodo = tabelaHash->tabela[i];
            while (atualNodo != NULL)
            {
                printf("[%d] -> ", atualNodo->chave);
                atualNodo = atualNodo->prox;
            }
            printf("NULL");
        }
        printf("\n");
    }
}

struct nodoHash *buscar(struct tabelaHash tabelaHash[], size_t tamTabela, int chave)
{
    int index = hash(chave, tamTabela);

    if (tabelaHash->tabela[index] == NULL)
        return NULL; // Chave não encontrada
    else
    {
        struct nodoHash *atualNodo = tabelaHash->tabela[index];
        while (atualNodo != NULL)
        {
            if (atualNodo->chave == chave)
            {
                return atualNodo;
            }
            atualNodo = atualNodo->prox;
        }
        return NULL; // Chave não encontrada
    }
}

void excluir(struct tabelaHash tabelaHash[], size_t tamTabela, struct nodoHash *nodo)
{
    int index = hash(nodo->chave, tamTabela);

    if (tabelaHash->tabela[index] != NULL)
    {
        struct nodoHash *atualNodo = tabelaHash->tabela[index];
        struct nodoHash *anteriorNodo = NULL;

        while (atualNodo != NULL)
        {
            if (atualNodo->chave == nodo->chave)
            {
                if (anteriorNodo == NULL)
                    tabelaHash->tabela[index] = atualNodo->prox;
                else
                    anteriorNodo->prox = atualNodo->prox;
                free(atualNodo);
                return;
            }

            anteriorNodo = atualNodo;
            atualNodo = atualNodo->prox;
        }
    }
}