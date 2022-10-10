#include <stdio.h>

//a utilização de ponteiros permite o acesso ao endereço de armazenamento em memória de uma variável, assim como seu valor

//o método tem como parâmetro valores do tipo ponteiro. Este tipo é indicado através do '*' ao declarar a variável
void inverteRef(int *pNum1, int *pNum2) {
    
    //armazena o valor do ponteiro pNum1 antes que este seja modificado
    int *aux = pNum1;

    //pNum1 recebe o valor de pNum2
    pNum1 = pNum2;

    //pNum2 recebe o valor de pNum1
    pNum2 = aux;

    //o '*' aqui permite acesso ao valor da variável indicada no ponteiro
    printf("\n3-Valores das variaveis apos inversao: num1 = %d, num2 = %d\n",*pNum1, *pNum2);

    printf("\n4-Valores dos ponteiros apos inversao: pNum1 = %d, pNum2 = %d\n",pNum1, pNum2);
    
    printf("\n");
        
}

int main(void) {

    int num1 = 1;
    int num2 = 2;

    printf("\n1-Valores iniciais das variaveis: num1 = %d, num2 = %d\n",num1,num2);

    printf("\n2-Valores dos ponteiros das variaveis: num1 = %d, num2 = %d\n",&num1, &num2);

    //o método recebe os valores dos ponteiros das variaveis num1 e num2, acessados através do '&'
    inverteRef(&num1, &num2);

}  

