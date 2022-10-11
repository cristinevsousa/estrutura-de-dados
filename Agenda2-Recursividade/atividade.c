#include <stdio.h>

int vetor[5] = {5, 3, 8, 9, 4};

int somaVetor(int limite)
{
    if (limite <= 0)
    {
        return 0;
    }
    else
    {
        int proxLimite = limite - 1; //0
        return somaVetor(proxLimite) + vetor[proxLimite];
    }
}

int menorPosicao()
{
    int menor = vetor[0];
    int posicaoMenor = 0;
    int arraySize = sizeof(vetor) / sizeof(menor);
   
    for (int i = 0; i < arraySize; i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
            posicaoMenor = i;
        }
    }
  
    return posicaoMenor;
}

int main(void)
{
    int limite = menorPosicao();
      printf("Resultado: %d\n", 1 + somaVetor(limite));
}