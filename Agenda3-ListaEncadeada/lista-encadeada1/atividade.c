#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto
{
    int valor;
    struct Ponto *prox;
} Ponto;

typedef struct
{
    Ponto *inicio;
    int tam;
} Lista;

void inserirInicio(Lista *lista, int valor)
{
    Ponto *novo = (Ponto *)malloc(sizeof(Ponto));
    novo->valor = valor;        //(*novo).valor = valor
    novo->prox = lista->inicio; //(*novo).prox = (*lista).inicio
    lista->inicio = novo;
    lista->tam++;
}

void imprimir(Lista *lista)
{
    Ponto *inicio = lista->inicio;
    while (inicio != NULL)
    {
        printf("%d ", inicio->valor);
        inicio = inicio->prox;
    }
    printf("\n\n");
}

int main(void)
{
    Lista lista;
    int valor;

    lista.inicio = NULL;
    lista.tam = 0;

    inserirInicio(&lista, 5);
    inserirInicio(&lista, 6);
    inserirInicio(&lista, 7);

    imprimir(&lista);
}
