#include <stdio.h>

void quickSort(int vetor[], int start, int end)
{
    int minor, aux;
    int pivot = start;

    for (int j = start + 1; j <= end; j++)
    {
        aux = j;
        if (vetor[j] < vetor[pivot])
        {
            minor = vetor[aux];
            while(aux > pivot)
            {
                vetor[aux] = vetor[aux - 1];
                aux--;
            }
            vetor[aux] = minor;
            pivot++;
        }
    }
    if(pivot - 1 >= start)
        quickSort(vetor, start, pivot - 1);

    if(pivot + 1 <= end)
        quickSort(vetor, pivot + 1, end);
}

int buscabinaria(int array[], int key, int left, int right)
{
    int midium;

    if (right < left)
        return -1;

    midium = (left + right) / 2;

    if (array[midium] == key) 
        return midium;
    else if (key < array[midium])
        return buscabinaria(array, key, left, midium - 1);
    else
        return buscabinaria(array, key, midium + 1, right);
}

void printVetor(int array[], int size)
{
    int i;
    printf("\n");
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void)
{
    int array[14] = {45, 7, 10, 4, 13, 17, 20, 16, 41, 21, 38, 43, 31, 2};
    int size = (int)(sizeof(array) / sizeof(array[0]));
    int x;

    quickSort(array, 0, size - 1);
    printVetor(array, size);

    printf("\nEntre com o valor a ser pesquisado: ");
    scanf("%d", &x);

    int i = buscabinaria(array, x, 0, size - 1);

    if (i < 0)
        printf("\nValor %d nao encontrado\n", x);
    else
        printf("\nValor %d encontrado na posicao %d\n", x, i);
        
    printf("\n");
}
