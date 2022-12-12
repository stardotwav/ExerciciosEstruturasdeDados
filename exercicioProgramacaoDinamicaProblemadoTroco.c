#include <stdio.h>

const int INF = 100000;
// moedas é o vetor com as moedas disponivéis para troco tam é o número do troco, ou seja, o valor máximo do vetor
// numMoedas é o número de moedas que temos

// a posição 0 do vetor de moedas deve ser 0, para que possamos realizar os cálculos, visto que a posição de troco 0 é 0
void problemaTroco(int moedas[], int tam, int numMoedas){
    // vetor que realiza o cálculo do troco
    int troco[tam+1];
    troco[0] = 0;

    // vetor que salva as moedas usadas no troco
    int moedasUsadas[tam+1];
    moedasUsadas[0] = 0;

    for(int i=1; i<=tam; i++){
        // auxiliares para salvar as posições durante o cálculo
        int menor = INF;
        int moeda = 0;

        for(int j=1; j<=numMoedas; j++){
            // as verificações de mínimo do algoritmo original foram modificados de forma a ser tornar if's
            // assim sendo possível salvar a posição do vetor de moedas onde se encontra a moeda que desejamos
            // usar na solução
            if(i >= moedas[j]){
                if((1+troco[i-moedas[j]]) < menor){
                    menor = 1+troco[i-moedas[j]];
                    moeda = j;
                }
            }
        }

        troco[i] = menor;
        moedasUsadas[i] = moeda;
    }

    // são salvas as posições das moedas utilizadas
    // dessa forma, devemos printar olhando para a
    // posição que salvamos, diminuindo de acordo
    // com a mesma
    printf("-- MOEDAS USADAS: %d MOEDAS: ", troco[tam]);
    int aux = tam;
    while(aux > 0){
        printf("%d ", moedas[moedasUsadas[aux]]);
        aux -= moedas[moedasUsadas[aux]];
    }
    printf("--\n");
}

int main(){
    int moedas[] = {0, 1, 3, 4};
    problemaTroco(moedas, 10, 3);
    return 0;
}