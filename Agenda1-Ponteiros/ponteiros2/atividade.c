#include <stdio.h>

int main(void) {

    int tamanhoVetor, maior, menor = 0;
        

    printf("\nTamanho do vetor: \n");
    scanf("%d",&tamanhoVetor);

    int vetor[tamanhoVetor];

    int i = 0;
    while (i < tamanhoVetor){
        printf("\nValor %d: \n", i+1);
        scanf("%d",&vetor[i]);
        i++;
    }

    printf("\nVetor:\n");
    for (int i = 0; i < tamanhoVetor; i++){
        if (i+1 != tamanhoVetor){
            printf("%d, ", vetor[i]);
        }else{
            printf("%d\n", vetor[i]);
        }
    }

    menor = vetor[0];
            
    for (int i = 0; i < tamanhoVetor; i++){
        if (vetor[i] > maior){
            maior = vetor[i];
        }        
        if (vetor[i] < menor){
            menor = vetor[i];
        }
    }

    printf("\nMaior elemento do vetor: %d\n", maior);
    printf("\nMenor elemento do vetor: %d\n", menor);
}  

