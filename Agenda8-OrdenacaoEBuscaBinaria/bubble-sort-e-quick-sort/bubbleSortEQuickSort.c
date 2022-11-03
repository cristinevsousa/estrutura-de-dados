#include <stdio.h>

void bubbleSort(int array[], int n)
{
    int i, j, aux;

    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}

void quickSort(int array[], int start, int end)
{
    int minor, aux;
    int pivot = start;

    for (int j = start + 1; j <= end; j++)
    {
        aux = j;
        if (array[j] < array[pivot])
        {
            minor = array[aux];
            while(aux > pivot)
            {
                array[aux] = array[aux - 1];
                aux--;
            }
            array[aux] = minor;
            pivot++;
        }
    }
    if(pivot - 1 >= start)
        quickSort(array, start, pivot - 1);

    if(pivot + 1 <= end)
        quickSort(array, pivot + 1, end);
}

void printVetor(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void)
{
    int array[14] = {45, 7, 10, 4, 13, 17, 20, 16, 41, 21, 38, 43, 31, 2};
    int size = (int)(sizeof(array) / sizeof(array[0]));

    bubbleSort(array, size);
    printf("\nBubbleSort: \n");
    printVetor(array, size);

    quickSort(array, 0, size - 1);
    printf("\nQuickSort: \n");
    printVetor(array, size);
}
