#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto
{
    int valor;
    int index;
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
    novo->index = lista->tam;
    lista->inicio = novo;
    lista->tam++;
}

void imprimir(Lista *lista)
{
    Ponto *inicio = lista->inicio;
    while (inicio != NULL)
    {
        printf("Dado: %d\n", inicio->valor);
        inicio = inicio->prox;
    }
    printf("\n");
}

void encontrarValor(Lista *lista, int valor)
{
    int cont = 0;
    Ponto *atual = lista->inicio;
    while (atual != NULL)
    {
        if (atual->valor == valor)
        {
            printf("O index de %d eh: %d\n", atual->valor, atual->index);
            cont = 1;
            atual = NULL;
        }
        else
        {
            atual = atual->prox;
        }
    }
    if (cont == 0)
    {
        printf("Valor %d nao encontrado!", valor);
    }
}

int main(void)
{
    Lista lista;

    lista.inicio = NULL;
    lista.tam = 0;

    inserirInicio(&lista, 5);
    inserirInicio(&lista, 6);
    inserirInicio(&lista, 7);

    imprimir(&lista);

    encontrarValor(&lista, 1);
    printf("\n");
    encontrarValor(&lista, 6);
}
