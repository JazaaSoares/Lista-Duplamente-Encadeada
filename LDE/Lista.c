#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>


struct No {
    int valor;
    struct No* prox;
    struct No* ant;
} ;

struct ListaDuplamenteEncadeada {
    No* inicio;
    No* fim;
    int tamanho;
};

  ListaDuplamenteEncadeada* criarLista() {
    ListaDuplamenteEncadeada* lista = (ListaDuplamenteEncadeada*) malloc(sizeof(ListaDuplamenteEncadeada));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    return lista;
}

void inserirElemento(ListaDuplamenteEncadeada* lista, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (lista->inicio == NULL) {
        // Lista vazia
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        struct No* atual = lista->inicio; //++
        struct No* anterior = NULL; // ++

        // Procurando posição correta para inserção
        while (atual != NULL && atual->valor < valor) {
            anterior = atual;
            atual = atual->prox;
        }

        if (anterior == NULL) {
            // Inserção no início
            novo->prox = lista->inicio;
            lista->inicio->ant = novo;
            lista->inicio = novo;
        } else {
            // Inserção no meio ou no fim
            novo->prox = anterior->prox;
            novo->ant = anterior;
            anterior->prox = novo;
            if (novo->prox != NULL) {
                novo->prox->ant = novo;
            } else {
                // Inserção no fim
                lista->fim = novo;
            }
        }
    }
    lista->tamanho++;
}

void removerElemento(ListaDuplamenteEncadeada* lista, int valor) {
    if (lista->inicio == NULL) return;

    No* atual = lista->inicio;

    while (atual != NULL && atual->valor != valor) {
        atual = atual->prox;
    }

    if (atual == NULL) return; // Elemento não encontrado

    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    } else {
        lista->inicio = atual->prox;
    }

    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    } else {
        lista->fim = atual->ant;
    }

    free(atual);
    lista->tamanho--;
}

int obterElementoPorPosicao(ListaDuplamenteEncadeada* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Erro: Posição inválida\n");
        return -1;
    }

    No* atual = lista->inicio;
    for (int i = 0; i < posicao; i++) {
        atual = atual->prox;
    }

    return atual->valor;
}

int procurarElemento(ListaDuplamenteEncadeada* lista, int valor) {
   No* atual = lista->inicio;
   int posicao = 0;

   while (atual != NULL){
    if (atual->valor == valor){
        return posicao;
    }
    atual = atual->prox;
    posicao++;

   }

    return -1;


}

int tamanhoLista(ListaDuplamenteEncadeada* lista){

    return lista->tamanho;

}

void imprimirLista(ListaDuplamenteEncadeada* lista){

    No* atual = lista->inicio;
    while (atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");

}

void imprimirListaReversa(ListaDuplamenteEncadeada* lista) {

    No* atual = lista->fim;
    while (atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->ant;
    }

    printf("\n");

}




void liberarLista(ListaDuplamenteEncadeada* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
       struct No* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(lista);
}


void menu() {
   struct ListaDuplamenteEncadeada* lista = criarLista();
    int opc, valor, posicao;

    do {
        printf("Menu:\n");
        printf("1. Inserir Elemento\n");
        printf("2. Remover Elemento por Valor\n");
        printf("3. Obter Elemento por Posição\n");
        printf("4. Procurar Elemento\n");
        printf("5. Tamanho da Lista\n");
        printf("6. Imprimir Lista\n");
        printf("7. Imprimir Lista Reversa\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        system("cls || clear");

        switch (opc) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserirElemento(lista, valor);
                printf("Elemento inserido com sucesso!!");
                sleep(2);
                system("cls || clear");
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                removerElemento(lista, valor);
                printf("Elemento removido com sucesso!!");
                sleep(2);
                system("cls || clear");
                break;
            case 3:
                printf("Digite a posição: ");
                scanf("%d", &posicao);
                valor = obterElementoPorPosicao(lista, posicao);
                if (valor != -1) {
                    printf("Valor na posição %d: %d\n", posicao, valor);
                }
                sleep(2);
                system("cls || clear");
                break;
            case 4:
                printf("Digite o valor a ser procurado: ");
                scanf("%d", &valor);
                posicao = procurarElemento(lista, valor);
                if (posicao != -1) {
                    printf("Valor encontrado na posição: %d\n", posicao);
                } else {
                    printf("Valor não encontrado\n");
                }
                sleep(2);
                system("cls || clear");
                break;
            case 5:
                printf("Tamanho da lista: %d\n", tamanhoLista(lista));
                sleep(2);
                system("cls || clear");
                break;
            case 6:
                printf("Lista: ");
                imprimirLista(lista);
                sleep(2);
                system("cls || clear");
                break;
            case 7:
                printf("Lista (reversa): ");
                imprimirListaReversa(lista);
                sleep(2);
                system("cls || clear");
                break;
            case 0:
                liberarLista(lista);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida\n");
                sleep(2);
                system("cls || clear");
                break;
        }
    } while (opc != 0);
}
