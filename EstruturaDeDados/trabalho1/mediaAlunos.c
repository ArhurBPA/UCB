#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100
#define MAX_NOME 50
#define MAX_NOTAS 10

typedef struct
{
    char nome[MAX_NOME];
    float notas[MAX_NOTAS];
    int num_notas;
} Aluno;

const char *determinar_situacao(float media)
{
    if (media >= 7.0)
    {
        return "APROVADO";
    }
    else
    {
        return "REPROVADO";
    }
}

// Função para calcular a média usando apenas os dois últimos números das notas
float calcular_media(float nota1, float nota2)
{
    float media = (((nota1) * 10 + (nota2) * 10) / 2) / 10;
    return media;
}

int main()
{
    FILE *entrada = fopen("/workspaces/UCB/EstruturaDeDados/trabalho1/DadosEntrada.csv", "r");
    FILE *saida = fopen("/workspaces/UCB/EstruturaDeDados/trabalho1/SituacaoFinal.csv", "w");

    if (entrada == NULL || saida == NULL)
    {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    Aluno alunos[MAX_ALUNOS];
    int num_alunos = 0;

    // Ler dados dos alunos e calcular médias
    char linha[MAX_NOME + MAX_NOTAS * 5]; // Tamanho máximo de uma linha
    while (fgets(linha, sizeof(linha), entrada) != NULL)
    {
        char *token = strtok(linha, ",");
        strncpy(alunos[num_alunos].nome, token, MAX_NOME);
        int num_notas = 0;
        float soma_notas = 0.0;
        while ((token = strtok(NULL, ",")) != NULL && num_notas < MAX_NOTAS)
        {
            float nota = atof(token);
            alunos[num_alunos].notas[num_notas] = nota;
            soma_notas += nota;
            num_notas++;
        }
        alunos[num_alunos].num_notas = num_notas;

        // Usando apenas os dois últimos números das notas
        float media = calcular_media(alunos[num_alunos].notas[num_notas - 2], alunos[num_alunos].notas[num_notas - 1]);
        fprintf(saida, "%s,%.2f,%s\n", alunos[num_alunos].nome, media, determinar_situacao(media));
        num_alunos++;
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}