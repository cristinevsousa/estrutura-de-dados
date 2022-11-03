#include <stdio.h>

int main(void)
{
  int array[999], i, size, x, f, lastOne, mediumOne, flag = 0;

  printf("Entre com a quantidade de elementos\n");

  scanf("%d", &size);

  printf("Insira os %d valores em ordem ascendente\n", size);

  for (i = 0; i < size; i++)
    scanf("%d", &array[i]);

  printf("Entre com o valor a ser pesquisado: ");

  scanf("%d", &x);

  f = 0;
  lastOne = size - 1;

  while (f <= lastOne)
  {
    mediumOne = (f + lastOne) / 2;

    if (x == array[mediumOne])
    {
      flag = 1;
      break;
    }
    else if (x < array[mediumOne])
      lastOne = mediumOne - 1;
    else
      f = mediumOne + 1;
  }

  if (flag == 0)
    printf("%d nao encontrado\n", x);
  else
    printf("%d encontrado na posicao %d \n", x, mediumOne);
}
