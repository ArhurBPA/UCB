#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float X;
    float Y;
} Ponto;

float AreaTriangulo(Ponto A, Ponto B, Ponto C)
{
    return -(0.5 * ((A.X * (B.Y - C.Y)) + (B.X * (C.Y - A.Y)) + (C.X * (A.Y - B.Y))));
}

// Armazena as coordenadas dos pontos em um array com nome "Ponto".
Ponto *lerVertices(FILE *arquivo, int *numVertices)
{
    fscanf(arquivo, "%d", numVertices);
    Ponto *vertices = (Ponto *)malloc(*numVertices * sizeof(Ponto));
    for (int i = 0; i < *numVertices; i++)
    {
        fscanf(arquivo, "%f %f", &vertices[i].X, &vertices[i].Y);
    }
    return vertices;
}
// Vou dividindo a área do polígono em porções de triângulos e somando as respectivas áreas dos triângulos, para dar a area total.
float calcularAreaPoligono(Ponto *vertices, int numVertices)
{
    float areaTotal = 0.0;
    for (int i = 1; i < numVertices - 1; i++)
    {
        areaTotal = AreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }
    return areaTotal;
}

int main()
{
    FILE *arquivo;
    arquivo = fopen("/workspaces/UCB/EstruturaDeDados/trabalho2/trianguloABC.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numVertices;
    Ponto *vertices = lerVertices(arquivo, &numVertices);

    fclose(arquivo);

    float areaPoligono = calcularAreaPoligono(vertices, numVertices);

    printf("A área do polígono é %.2f\n", areaPoligono);

    return 0;
}