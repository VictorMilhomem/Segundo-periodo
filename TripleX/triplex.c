#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void printIntro(int level){
    for(int i = 0; i < 50; i++){
        putchar('-');
    }
    printf("\n");
    printf("###### TRIPLE X GAME ######");
    printf("\n");

    for(int i = 0; i < 50; i++){
        putchar('-');
    }

    printf("\nVocê é um agente secreto invadindo um sistema protegido nível %i\n", level);
    printf("\nColoque o código correto para continuar\n");
}


bool playGame(int level){
    printIntro(level);

    // declare 3 random numbers code
    srand(time(NULL));
    const int codeA = rand() % 3*level + 3*level;
    const int codeB = rand() % 3*level + 3*level;
    const int codeC = rand() % 3*level + 3*level;

    // Setting the problem for the solve it
    const int codeSum = codeA + codeB + codeC;
    const int codeProd = codeA * codeB * codeC;

    printf("\n+ O código tem 3 numeros.\n");
    printf("\n+ O código somado: %d\n", codeSum);
    printf("\n+ O produto do código: %d\n", codeProd);

    int guessA, guessB, guessC;

    printf("\nDigite o código:\n");
    scanf("%d %d %d", &guessA, &guessB, &guessC);


    // Checking if the guess is correct
    int guessSum = guessA + guessB + guessC;
    int guessProd = guessA * guessB * guessC;

    if(guessSum == codeSum && guessProd == codeProd){
        printf("\n*** Boa 06, você invadiu o sistema com sucesso!! ***\n");
        printf("\n*** Vamos para o próximo sistema!! ***\n");

        return true;
    }
    else{
        printf("\n*** Você errou, escape antes que seja capturado agente!! ***\n");
        return false;
    }


}

void clear_keyboard_buffer(void)
{
    // clear the buffer
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}


int main(){
    int levelDifficulty = 1;
    const int maxDifficulty = 10;

    while(levelDifficulty <= maxDifficulty){
        bool bLevelComplete = playGame(levelDifficulty);

        clear_keyboard_buffer();

        if (bLevelComplete){
            ++levelDifficulty;
        }
    }

    printf("\n*** Excelente trabalho agente, você invadiu com sucesso todos os sistemas!! ***\n");
    return 0;
}