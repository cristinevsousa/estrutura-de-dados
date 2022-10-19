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
    Ponto *fim;
} Fila;

void definir(Fila *filaVazia)
{
    filaVazia->inicio = NULL;
    filaVazia->fim = NULL;
}

int vazia(Fila *fila)
{
    if (fila->inicio == NULL)
        return 1;

    return 0;
}

void tornar_vazia(Fila *fila)
{
    Ponto *ponto1, *ponto2;
    if (vazia(fila) == 0)
    {
        ponto2 = fila->inicio;
        while (ponto2 != NULL)
        {
            ponto1 = ponto2;
            ponto2 = ponto2->prox;
            free(ponto1);
        }
    }
    definir(fila);
}

int inserir(Fila *lFila, int entrada)
{
    Ponto *novoPonto = malloc(sizeof(int));

    if (novoPonto == NULL)
    {
        return 0;
    }

    novoPonto->valor = entrada;
    novoPonto->prox = NULL;

    if (vazia(lFila) == 1)
    {
        lFila->inicio = novoPonto;
    }
    else
    {
        lFila->fim->prox = novoPonto;
    }

    lFila->fim = novoPonto;
    return 1;
}

int remover(Fila *lFila, int *item)
{
    Ponto *saidaPonto;
    if (vazia(lFila) == 1)
    {
        return 0;
    }

    saidaPonto = lFila->inicio;
    *item = saidaPonto->valor;
    lFila->inicio = saidaPonto->prox;

    if (lFila->inicio == NULL)
    {
        lFila->fim = NULL;
    }

    free(saidaPonto);
    return 1;
}

int tamanho(Fila *lFila)
{
    Ponto *lPonto;
    int cont = 0;
    lPonto = lFila->inicio;
    while (lPonto != NULL)
    {
        cont++;
        lPonto = lPonto->prox;
    }
    return cont;
}

int inicio_fila(Fila *lFila, int *item)
{
    if (vazia(lFila) == 1)
        return 0;

    *item = lFila->inicio->valor;
    printf("item do inicio: %d", *item);
    printf("\n\n");
    return 1;
}

void imprimir(Fila *fila)
{
    Ponto *pontoTemp = fila->inicio;

    printf("fila: ");
    while (pontoTemp != NULL)
    {
        printf("%d ", pontoTemp->valor);
        pontoTemp = pontoTemp->prox;
    }
    printf("\n\n");
}

int main(void)
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));

    definir(fila);

    inserir(fila, 5);
    inserir(fila, 6);
    inserir(fila, 7);
    inserir(fila, 8);

    imprimir(fila);

    int *item = malloc(sizeof(int));
    inicio_fila(fila, item);

    int resp = remover(fila, item);

    if (resp == 1)
    {
        printf("item removido.");
        printf("\n\n");
    }

    imprimir(fila);

    int tam = tamanho(fila);

    printf("tamanho da fila: %d", tam);
    printf("\n\n");

    tornar_vazia(fila);
    tam = tamanho(fila);
    printf("tamanho da fila: %d", tam);
    printf("\n\n");
}
