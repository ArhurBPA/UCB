#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float notas[10];
    int quant_notas;
} Pessoa;

const char *situacao(float media)
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


float calcular_media(float nota1, float nota2)
{
    float media = (((nota1) * 10 + (nota2) * 10) / 2) / 10;
    return media;
}

int main()
{
    FILE *entrada = fopen("/workspaces/UCB/EstruturaDeDados/trabalho1/DadosEntrada.csv", "r");
    FILE *saida = fopen("/workspaces/UCB/EstruturaDeDados/trabalho1/NotaFinal.csv", "w");

    if (entrada == NULL)
    {
        printf("Erro ao abrir DadosEntrada.csv.\n");
        return 1;
    }
    if (saida == NULL)
    {
        printf("Erro ao abrir NotaFinal.csv.\n");
        return 1;
    }

    Pessoa alunos[100];
    int num_alunos = 0;

    
    char lista[50 + 10 * 5]; 
    while (fgets(lista, sizeof(lista), entrada) != NULL)
    {
        char *token = strtok(lista, ",");
        strncpy(alunos[num_alunos].nome, token, 50);
        int quant_notas = 0;
        float soma_notas = 0.0;
        while ((token = strtok(NULL, ",")) != NULL && quant_notas < 10)
        {
            float nota = atof(token);
            alunos[num_alunos].notas[quant_notas] = nota;
            soma_notas += nota;
            quant_notas++;
        }
        alunos[num_alunos].quant_notas = quant_notas;

        
        float media = calcular_media(alunos[num_alunos].notas[quant_notas - 2], alunos[num_alunos].notas[quant_notas - 1]);
        fprintf(saida, "%s,%.2f,%s\n", alunos[num_alunos].nome, media, situacao(media));
        num_alunos++;
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}