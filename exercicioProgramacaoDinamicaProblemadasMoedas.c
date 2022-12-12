#include <stdio.h>
#include <stdlib.h>

typedef struct moeda{
    int valor;
    int usada;
    int soma;
} tipoMoeda;

typedef struct vetorMoeda{
    tipoMoeda moedas[5];
    int ultimo;
} vetorMoeda;

void iniciaVetorMoeda(vetorMoeda *moedas){
    moedas->ultimo = 0;
}

void insereMoeda(vetorMoeda *moedas, int valor){
    moedas->moedas[moedas->ultimo].valor = valor;
    moedas->moedas[moedas->ultimo].usada = 0;
    moedas->moedas[moedas->ultimo].soma = 0;
    moedas->ultimo++;
}

void problemaMoedas(vetorMoeda *moedas){
    moedas->moedas[0].soma = moedas->moedas[0].valor;
    moedas->moedas[0].usada = 1;
    moedas->moedas[1].soma = moedas->moedas[0].valor;
    moedas->moedas[1].usada = 0;
    int somaMaxima = moedas->moedas[0].soma;

    for(int i=2; i<5; i++){
        int novoValor = moedas->moedas[i].valor + moedas->moedas[i-2].soma;

        if(novoValor > moedas->moedas[i-1].soma){
            moedas->moedas[i-1].usada = 0;
            moedas->moedas[i].usada = 1;
            moedas->moedas[i].soma = novoValor;
            somaMaxima = novoValor;
        }

        else{
            moedas->moedas[i].soma = moedas->moedas[i-1].soma;
            moedas->moedas[i-1].usada = 1;
            moedas->moedas[i-2].usada = 0;
        }
    }

    printf("-- Soma Máxima Não Subsequente: %d --\n", somaMaxima);
    printf("-- Moedas Usadas: ");

    for(int i=0; i<5; i++)
        if(moedas->moedas[i].usada == 1) 
            printf("%d ", moedas->moedas[i].valor);

    printf("--\n");
}

int main(){
    vetorMoeda moedas;
    iniciaVetorMoeda(&moedas);
    insereMoeda(&moedas, 2);
    insereMoeda(&moedas, 3);
    insereMoeda(&moedas, 1);
    insereMoeda(&moedas, 10);
    insereMoeda(&moedas, 5);
    problemaMoedas(&moedas);
    return 0;
}