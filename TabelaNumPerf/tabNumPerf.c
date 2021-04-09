/* 
Escreva um programa que produza a tabela com os k primeiros números perfeitos. O valor de k é fornecido pelo teclado. 
E seu programa precisa calcular os números perfeitos usando a expressão abaixo.

O números perfeitos podem ser obtidos pela fórmula de Euclides, abaixo:

2n−1(2n−1),   onde n é um número primo.

*/

#include <stdio.h>
#include <math.h>


// functions declaration
void tabNum();

int main()
{
    tabNum();
    return 0;
}


void tabNum()
{
    int k;
    printf("Digite a quantidade de numeros perfeitos a serem impressos:\n");
    scanf("%d", &k);

    long table[k];

    // Refatorar para não dependermos da tabela de numeros primos
    int tabelaPrimo[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    int j = 0;

    for (int i = 0; i < k; i++)
    {
        int n = tabelaPrimo[j];
        table[i] = pow(2, n-1)* (pow(2, n)-1);
        j++;
    }
    // Imprime a tabela

    for (int w = 0; w < k; w++)
    {
        printf("%ld\t\n", table[w]);
    }
}
