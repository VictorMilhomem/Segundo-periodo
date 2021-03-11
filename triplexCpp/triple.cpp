#include <iostream>
#include <ctime>

void PrintIntro(int Level){
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "||############ TRIPLE X GAME #############||" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    // Print welcome messages to the terminal
    std::cout << "\nVocê é um agente secreto invadindo um sistema protegido nível "<< Level<< std::endl;
    std::cout << "\nColoque o codigo correto para continuar..."<< std::endl;
}

bool PlayGame(int Level){

    PrintIntro(Level);

    // Declare 3 random numbers code
    srand(time(NULL));
    const int CodeA = rand() % 3*Level + 3*Level;
    const int CodeB = rand() % 3*Level + 3*Level;
    const int CodeC = rand() % 3*Level + 3*Level;
    
    // The problem
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProd = CodeA * CodeB * CodeC;

    // Print the problem to the terminal
    std::cout << std::endl;
    std::cout << "+ O código tem 3 números"<< std::endl;
    std::cout << "+ O código somado: "<< CodeSum << std::endl;
    std::cout << "+ O produto do código: "<< CodeProd << std::endl;

    int GuessA, GuessB, GuessC;

    // Player starts to guess
    std::cout << "Digite o código: "<< std::endl;
    std::cin >> GuessA >> GuessB >> GuessC;
    

    // Check if the code is correct

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProd = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProd == CodeProd){
        std::cout << "\n*** Boa 06, você invadiu o sistema com sucesso!! ***" << std::endl;
        std::cout << "\n*** Vamos para o próximo sistema!! ***" << std::endl;
        
        return true;
    }else{
        std::cout << "\n*** Você errou, escape antes que seja capturado agente!! ***"<< std::endl;
        return false;
    }

}



int main(){

    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;

    while(LevelDifficulty <= MaxDifficulty){

        bool bLevelComplete = PlayGame(LevelDifficulty);

        std::cin.clear(); // clear any errors
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete){
            ++LevelDifficulty;
        }
    }

    std::cout << "\n*** Excelente trabalho agente, você invadiu com sucesso todos os sistemas!! ***" << std::endl;

    return 0;
 }