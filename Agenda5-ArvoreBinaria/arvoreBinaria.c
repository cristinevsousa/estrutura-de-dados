#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int cod;
} Item;

typedef struct No
{
    Item item;
    struct No *esq;
    struct No *dir;
} No;

No *inicializar()
{
    return NULL;
}

Item criarItem(int cod)
{
    Item item;
    item.cod = cod;
    return item;
}

No *inserir(No *raiz, Item x)
{
    if (raiz == NULL)
    {
        No *aux = (No*)malloc(sizeof(No));
        aux->item = x;
        aux->esq = NULL;
        aux->dir = NULL;
        return aux;
    } 
    else 
    {
        if (x.cod > raiz->item.cod)
        {
            raiz->dir = inserir(raiz->dir, x);
        }
        else if (x.cod < raiz->item.cod)
        {
            raiz->esq = inserir(raiz->esq, x);
        }
    }
    return raiz;
}

void liberar(No *raiz)
{
    if (raiz != NULL)
    {
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}

No *buscarMenorEsq(No *raiz)
{
    if (raiz != NULL)
    {
        No *aux = raiz;
        while (aux->esq != NULL)
        {
            aux = aux->esq;
        }
    }
    return NULL;
}

No *remover(No *raiz, int cod)
{
    if (raiz != NULL)
    {
        if (cod > raiz->item.cod)
        {
            raiz->dir = remover(raiz->dir, cod);
        }
        else if (cod < raiz->item.cod)
        {
            raiz->esq = remover(raiz->esq, cod);
        }
        else
        {
            if (raiz->esq == NULL && raiz->dir == NULL)
            {
                free(raiz);
                return NULL;
            }
            else if (raiz->esq == NULL && raiz->dir != NULL)
            {
                No *aux = raiz->dir;
                free(raiz);
                return aux;
            }
            else if (raiz->esq != NULL && raiz->dir == NULL)
            {
                No *aux = raiz->esq;
                free(raiz);
                return aux;
            }
            else
            {
                No *aux = buscarMenorEsq(raiz->dir);
                Item itemAux = aux->item;
                raiz = remover(raiz, itemAux.cod);
                raiz->item = itemAux;
            }
            return raiz;
        }
    }
    return NULL;
}

void imprimir(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->item.cod);
        imprimir(raiz->esq);
        imprimir(raiz->dir);
    }
}

int main(void)
{

    No *raiz = inicializar();
    raiz = inserir(raiz, criarItem(5));
    raiz = inserir(raiz, criarItem(6));
    raiz = inserir(raiz, criarItem(7));
    raiz = inserir(raiz, criarItem(8));

    imprimir(raiz);
    printf("\n\n");

    raiz = remover(raiz, 5);

    imprimir(raiz);
    printf("\n\n");

    liberar(raiz);

    printf("\n\n");
    printf("\n\n");

}
