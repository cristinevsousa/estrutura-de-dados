#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto
{
    int valor;
    struct Ponto *prox;
} Ponto;

int cont;
Ponto *topo;

void definir()
{
    topo = NULL;
    cont = 0;
}

int vazia()
{
    if (topo == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int tornar_vazia()
{
    Ponto *pontoTemp;

    if (vazia() == 1)
    {
        return 0;
    }
    else
    {
        while (topo != NULL)
        {
            pontoTemp = topo;
            pontoTemp->prox = NULL;

            topo = topo->prox;

            free(pontoTemp);
        }
        cont = 0;
        printf("pilha esvaziada!");
        printf("\n\n");
        return 1;
    }
}

int tamanho()
{
    return cont;
}

int push(int novoValor)
{
    Ponto *novoPonto = (Ponto *)malloc(sizeof(Ponto));

    if (novoPonto == NULL)
    {
        return 0;
    }
    else
    {
        novoPonto->valor = novoValor;
        novoPonto->prox = topo;

        topo = novoPonto;

        cont++;
        return 1;
    }
}

int pop()
{
    int *valor = malloc(sizeof(int));
    Ponto *pontoTemp;
    if (vazia() == 1)
    {
        return 0;
    }
    else
    {
        *valor = topo->valor;

        pontoTemp = topo;
        topo = topo->prox;

        pontoTemp->prox = NULL;

        free(pontoTemp);
        cont--;
        return 1;
    }
}

void topo_pilha()
{
    int *valor = malloc(sizeof(int));
    if (vazia() == 1)
    {
        printf("pilha vazia");
    }
    else
    {
        *valor = topo->valor;
        printf("topo da pilha: %d", *valor);
        printf("\n\n");
    }
}

void imprimir()
{
    Ponto *pontoTemp = (Ponto *)malloc(sizeof(Ponto));
    pontoTemp = topo;

    if (vazia() == 1)
    {
        printf("pilha vazia");
    }
    else
    {
        printf("pilha: ");
        while (pontoTemp != NULL)
        {

            int valor = pontoTemp->valor;
            printf("%d ", valor);
            pontoTemp = pontoTemp->prox;
        }
    }

    free(pontoTemp);

    printf("\n\n");
}

int main(void)
{
    definir();

    push(2);
    push(3);
    push(4);
    push(5);

    printf("\n\n");
    imprimir();

    topo_pilha();

    int resp = pop();

    if (resp == 1)
    {
        printf("item removido!");
        printf("\n\n");
    }

    topo_pilha();
    imprimir();

    int tam = tamanho();

    printf("tamanho da pilha: %d", tam);
    printf("\n\n");

    tornar_vazia();
    tam = tamanho();
    printf("tamanho da pilha: %d", tam);
    printf("\n\n");
}
