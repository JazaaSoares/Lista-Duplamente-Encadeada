#include <stdio.h>
#include <stdlib.h>

typedef struct No No;
typedef struct ListaDuplamenteEncadeada ListaDuplamenteEncadeada;

ListaDuplamenteEncadeada* criarLista();
void inserirElemento(ListaDuplamenteEncadeada* lista, int valor);
void removerElemento(ListaDuplamenteEncadeada* lista, int valor);
int obterElementoPorPosicao(ListaDuplamenteEncadeada* lista, int posicao);
int procurarElemento(ListaDuplamenteEncadeada* lista, int valor);
int tamanhoLista(ListaDuplamenteEncadeada* lista);
void imprimirLista(ListaDuplamenteEncadeada* lista);
void imprimirListaReversa(ListaDuplamenteEncadeada* lista);
void liberarLista(ListaDuplamenteEncadeada* lista);
