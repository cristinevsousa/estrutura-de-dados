#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int item;
    short alt;
    struct No *esq, *dir;
} No;

No *inicializar()
{
    return NULL;
}

No *novoNo(int x)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->item = x;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->alt = 0;
    return novo;
}

short altNo(No *no)
{
    if (no == NULL)
        return -1;
    else
        return no->alt;
}

short fatorBalancNo(No *no)
{
    if (no != NULL)
        return (altNo(no->esq) - altNo(no->dir));
    else
        return 0;
}

short maior(short x, short y)
{
    if (x > y)
        return x;
    else
        return y;
}

No *rotacaoDir(No *raiz)
{
    No *y, *f;

    y = raiz->esq;
    f = y->dir;

    y->dir = raiz;
    raiz->esq = f;

    raiz->alt = maior(altNo(raiz->esq), altNo(raiz->dir)) + 1;
    y->alt = maior(altNo(y->esq), altNo(y->dir)) + 1;

    return y;
}

No *rotacaoEsq(No *raiz)
{
    No *y, *f;

    y = raiz->dir;
    f = y->esq;

    y->esq = raiz;
    raiz->dir = f;

    raiz->alt = maior(altNo(raiz->esq), altNo(raiz->dir)) + 1;
    y->alt = maior(altNo(y->esq), altNo(y->dir)) + 1;

    return y;
}

No *rotacaoEsqDir(No *raiz)
{
    raiz->esq = rotacaoEsq(raiz->esq);
    return rotacaoDir(raiz);
}

No *rotacaoDirEsq(No *raiz)
{
    raiz->dir = rotacaoDir(raiz->dir);
    return rotacaoEsq(raiz);
}

No *balancear(No *raiz)
{
    short fb = fatorBalancNo(raiz);

    if (fb < -1 && fatorBalancNo(raiz->dir) <= 0)
    {
        raiz = rotacaoEsq(raiz);
    }
    else if (fb > 1 && fatorBalancNo(raiz->esq) >= 0)
    {
        raiz = rotacaoDir(raiz);
    }
    else if (fb > 1 && fatorBalancNo(raiz->esq) < 0)
    {
        raiz = rotacaoEsqDir(raiz);
    }
    else if (fb < -1 && fatorBalancNo(raiz->esq) > 0)
    {
        raiz = rotacaoDirEsq(raiz);
    }
    return raiz;
}

No *inserir(No *raiz, int x)
{
    if (raiz == NULL)
        return novoNo(x);
    else
    {
        if (x > raiz->item)
            raiz->dir = inserir(raiz->dir, x);
        else if (x < raiz->item)
            raiz->esq = inserir(raiz->esq, x);
        else
            printf("\nInserção não realizada!\nO elemento %d não existe!\n", x);
    }
    raiz->alt = maior(altNo(raiz->esq), altNo(raiz->dir)) + 1;
    raiz = balancear(raiz);

    return raiz;
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

No *remover(No *raiz, int item)
{
    if (raiz != NULL)
    {
        if (item == raiz->item)
        { // remove nós folhas
            if (raiz->esq == NULL && raiz->dir == NULL)
            {
                free(raiz);
                return NULL;
            }
            else
            { // remove nós com 2 filhos
                if (raiz->esq != NULL && raiz->dir != NULL)
                {
                    No *aux = raiz->esq;

                    while (aux->dir != NULL)
                        aux = aux->dir;

                    raiz->item = aux->item;
                    aux->item = item;
                    raiz->esq = remover(raiz->esq, item);
                    return raiz;
                }
                else
                { // remove nós com 1 filho
                    No *aux;
                    if (raiz->esq != NULL)
                        aux = raiz->esq;
                    else
                        aux = raiz->dir;
                    free(raiz);
                    return aux;
                }
            }
        }
        else
        {
            if (item < raiz->item)
                raiz->esq = remover(raiz->esq, item);
            else
                raiz->dir = remover(raiz->dir, item);
        }
    }
    else
        printf("Valor não encontrado!");

    raiz->alt = maior(altNo(raiz->esq), altNo(raiz->dir)) + 1;
    raiz = balancear(raiz);

    return raiz;
}

void imprimir(No *raiz, int nivel)
{
    int i;
    if (raiz != NULL)
    {
        imprimir(raiz->dir, nivel + 1);
        printf("\n\n");

        for (i = 0; i < nivel; i++)
            printf("\t");

        printf("%d", raiz->item);
        imprimir(raiz->esq, nivel + 1);
    }
}

int main(void)
{
    No *raiz = inicializar();
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 13);
    raiz = inserir(raiz, 11);
    raiz = inserir(raiz, 9);

    imprimir(raiz, 0);
    printf("\n\n");
    printf("***************************");

    raiz = remover(raiz, 5);

    imprimir(raiz, 0);
    printf("\n\n");
}
