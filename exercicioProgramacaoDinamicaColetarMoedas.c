#include <stdio.h>
#define tamTabuleiro 6

typedef struct caminho{
    int i;
    int j;
} tipoCaminho;

void coletarMoedas(int tabuleiro[tamTabuleiro][tamTabuleiro]){
    // matriz para armazenar os dados da programação dinâmica
    int pd[tamTabuleiro][tamTabuleiro];
    pd[1][1] = tabuleiro[1][1];

    // percorrendo a matriz para preencher com número de moedas
    for(int i=2; i<tamTabuleiro; i++) pd[1][i] = pd[1][i-1] + tabuleiro[1][i];

    // determinando o número de moedas máximo através da tabela
    // de programação dinâmica
    for(int i=2; i<tamTabuleiro; i++){
        pd[i][1] = pd[i-1][1] + tabuleiro[i][1];

        for(int j=2; j<tamTabuleiro; j++){
            if(pd[i-1][j] < pd[i][j-1]) pd[i][j] = pd[i][j-1] + tabuleiro[i][j];
            else pd[i][j] = pd[i-1][j] + tabuleiro[i][j];
        }
    }

    printf("--Número de Moedas Coletas: %d--\n", pd[tamTabuleiro-1][tamTabuleiro-1]);

    int i = tamTabuleiro-1;
    int j = tamTabuleiro-1;

    // determinando o caminho usado para coletar o maior número
    // de moedas
    printf("--Caminho:\n");
    printf("(%d %d) -> %d\n", i, j, pd[i][j]);
    while(1>0){
        if(i == 0 && j == 0) break;
        if((pd[i-1][j] == pd[i][j]) || (pd[i-1][j] == pd[i][j]-1)) i = i-1;
        else if((pd[i][j-1] == pd[i][j]) || (pd[i][j-1] == pd[i][j]-1)) j = j-1;
        printf("(%d %d) -> %d\n", i, j, pd[i][j]);
    }

    printf("--\n");
}

int main(){
    int tabuleiro[tamTabuleiro][tamTabuleiro] = {{0, 0, 0, 0, 1, 0}, 
                                                {0, 1, 0, 1, 0, 0}, 
                                                {0, 0, 0, 1, 0, 1}, 
                                                {0, 0, 1, 0, 0, 1},
                                                {1, 0, 0, 0, 1, 0},
                                                {0, 0, 0, 0, 0, 0}};
    coletarMoedas(tabuleiro);
}