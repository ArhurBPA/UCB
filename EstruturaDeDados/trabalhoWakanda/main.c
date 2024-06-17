#include <stdio.h>
#include "cidades.h"
#include <stdlib.h>
int main() {
    const char *nomeArquivo = "teste01.txt";
    
    Estrada *estrada = getEstrada(nomeArquivo);
    if (estrada) {
        printf("Estrada carregada com sucesso!\n");
        printf("Comprimento da estrada: %d\n", estrada->T);
        printf("Número de cidades: %d\n", estrada->N);
        for (int i = 0; i < estrada->N; i++) {
            printf("Cidade %d: %s (Posição: %d)\n", i+1, estrada->C[i].Nome, estrada->C[i].Posicao);
        }
        free(estrada->C);
        free(estrada);
    } else {
        printf("Erro ao carregar a estrada.\n");
    }

    double menor_vizinhanca = calcularMenorVizinhanca(nomeArquivo);
    if (menor_vizinhanca >= 0) {
        printf("Menor vizinhança: %.2f\n", menor_vizinhanca);
    } else {
        printf("Erro ao calcular a menor vizinhança.\n");
    }

    char *cidade = cidadeMenorVizinhanca(nomeArquivo);
    if (cidade) {
        printf("Cidade com menor vizinhança: %s\n", cidade);
        free(cidade);
    } else {
        printf("Erro ao determinar a cidade com menor vizinhança.\n");
    }

    return 0;
}
