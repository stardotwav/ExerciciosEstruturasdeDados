#include<stdio.h>

// Implementar um algoritmo que resolva o problema da seleção 
// de atividades, apresentando as atividades escolhidas

// inicio[], começo de cada uma das atividades
// fim[], fim de cada uma das atividades
// n, o número de atividades

// nesta implementação, o vetor com o horário final
// das atividades deve estar ordenado de forma
// crescente
void problemaSelecaoAtividades(int inicio[], int fim[], int n){
    printf("As atividades selecionadas são: ");
    int i = 0;
    printf("%d ", i);

    for(int j=1; j<n; j++){
        if(inicio[j] >= fim[i]){
            printf("%d ", j);
            i = j;
        }
    }

    printf("\n");
}

int main(){
    int inicio[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int fim[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int n = sizeof(inicio)/sizeof(inicio[0]);
    problemaSelecaoAtividades(inicio, fim, n);
    return 0;
}