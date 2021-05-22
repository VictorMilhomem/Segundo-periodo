#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LINHA 20
#define COLUNA 20
char matriz[LINHA][COLUNA];
int pos[2];

void ler(char* arq)
{
    char c; int cont = 0;

    FILE *fp;
    if ((fp = fopen(arq, "r")) == NULL)
    {
        fprintf(stderr,  "Erro arquivo inexistente\n");
        exit(1);
    }
    else
    {
        fp = fopen(arq, "r");
        int i = 0;
        int j = 0;
        while (!feof(fp))
        {
            c = getc(fp);
            if(c == '\n'){
                cont++;
                i++;
                j = 0;
            }

            if (cont < 20){  // estoca os pixels
                if (c == 32 || c == 88)
                {
                    matriz[i][j] = c;
                    j++;
                }
            }

            if (cont == 20)
                fscanf(fp, "%d %d", &pos[0], &pos[1]);
        }
        // Debug
        //printf("%d %d\n", pos[0], pos[1]);
        //floodFill(pos[0], pos[1], ' ', 'X');
        //printf("%c\n", matriz[0][1]);
        //printf("%d %d\n", i, j);
    }
    fclose(fp);
}

int valido(int i,int j)
{
    if(i<0 || i>=LINHA || j<0 || j>=COLUNA)
        return 0;
    else
        return 1;
}

void floodFill(int x, int y, int ant, int novo)
{
    if(valido(x,y) == 0)
        return;
    if(matriz[x][y] != ant)
        return;
    if(matriz[x][y] == novo)
        return;
    if(matriz[x][y] == ant)
        matriz[x][y] = novo;
    floodFill(x-1,y,ant,novo);
    floodFill(x+1,y,ant,novo);
    floodFill(x,y-1,ant,novo);
    floodFill(x,y+1,ant,novo);
    floodFill(x-1,y-1,ant,novo);
    floodFill(x-1,y+1,ant,novo);
    floodFill(x+1,y-1,ant,novo);
    floodFill(x+1,y+1,ant,novo);
}

void aplica()
{
    floodFill(pos[0], pos[1], ' ', 'X');

    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
            printf("%c", matriz[i][j]);
        printf("\n");
    }
}