#include <stdio.h>

int main()
{

    printf("### BEM VINDO AO JOGO DO TABULEIRO ### \n");

    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10] = {0}; // representa água (0)



   // POSIÇÃO HORIZONTAL 
    int linhaH = 1;  
    int colunaH = 1; 
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[linhaH][colunaH + i] == 3)  
        {
            printf("Erro: sobreposição detectada no navio horizontal.\n\n");
            break;
        }
        tabuleiro[linhaH][colunaH + i] = 3;  
    }

    // POSIÇÃO VERTICAL 
    int linhaV = 4;  
    int colunaV = 5; 
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[linhaV + i][colunaV] == 3)  
        {
            printf("Erro: sobreposição detectada no navio vertical.\n\n");
            break;
        }
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // POSIÇÃO DIAGONAL 1 
    int linhaD = 3; 
    int colunaD = 7;
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[linhaD + i][colunaD + i] == 3)   
        {
            printf("Erro: sobreposição detectada no navio diagonal.\n\n");
            break;
        }
        tabuleiro[linhaD + i][colunaD + i] = 3;
    } 

         // POSIÇÃO DIAGONAL 2 
    int linhaE = 7; 
    int colunaE = 3;
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[linhaE + i][colunaE - i] == 3)   
        {
            printf("Erro: sobreposição detectada no navio diagonal.\n\n");
            break;
        }
        tabuleiro[linhaE + i][colunaE - i] = 3;
    } 

  // IMPRIME O TABULEIRO

printf("     "); 
for (int i = 0; i < 10; i++)
{
    printf("%2c ", colunas[i]); 
}
printf("\n");

for (int i = 0; i < 10; i++)
{
    printf("%2d | ", i + 1); 
    for (int j = 0; j < 10; j++)
    {
        printf("%2d ", tabuleiro[i][j]); 
    }
    printf("\n");
}

    return 0;
}
