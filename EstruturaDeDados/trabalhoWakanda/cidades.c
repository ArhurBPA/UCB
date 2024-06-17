#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

Estrada *getEstrada(const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) return NULL;

    int T, N;
    fscanf(file, "%d", &T);
    fscanf(file, "%d", &N);

    if (T < 3 || T > 106 || N < 2 || N > 104) {
        fclose(file);
        return NULL;
    }

    Estrada *estrada = (Estrada *)malloc(sizeof(Estrada));
    estrada->T = T;
    estrada->N = N;
    estrada->C = (Cidade *)malloc(N * sizeof(Cidade));

    for (int i = 0; i < N; i++) {
        fscanf(file, "%d", &estrada->C[i].Posicao);
        fscanf(file, "%s", estrada->C[i].Nome);
    }

    fclose(file);
    return estrada;
}

double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) return -1;

    double menor_vizinhanca = estrada->T;

    for (int i = 0; i < estrada->N - 1; i++) {
        double vizinhanca = (estrada->C[i + 1].Posicao - estrada->C[i].Posicao) / 2.0;
        if (vizinhanca < menor_vizinhanca) {
            menor_vizinhanca = vizinhanca;
        }
    }

    free(estrada->C);
    free(estrada);
    return menor_vizinhanca;
}

char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) return NULL;

    double menor_vizinhanca = estrada->T;
    int cidade_index = 0;

    for (int i = 0; i < estrada->N - 1; i++) {
        double vizinhanca = (estrada->C[i + 1].Posicao - estrada->C[i].Posicao) / 2.0;
        if (vizinhanca < menor_vizinhanca) {
            menor_vizinhanca = vizinhanca;
            cidade_index = i;
        }
    }

    char *cidade_nome = (char *)malloc(256 * sizeof(char));
    strcpy(cidade_nome, estrada->C[cidade_index].Nome);

    free(estrada->C);
    free(estrada);
    return cidade_nome;
}