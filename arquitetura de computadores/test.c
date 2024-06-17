#include <stdio.h>

int main() {
    int valor1, valor2;

    // Leitura dos valores
    printf("Digite o primeiro valor:\n");
    scanf("%d", &valor1);
    printf("Digite o segundo valor:\n");
    scanf("%d", &valor2);

    // Verificação e impressão
    if (valor1 < valor2) {
        printf("Valores do primeiro até o segundo:\n");
        for (int i = valor1; i <= valor2; i++) {
            printf("%d ", i);
        }
        printf("\n");
    } else if (valor1 > valor2) {
        printf("Valores do segundo até o primeiro em ordem decrescente:\n");
        for (int i = valor1; i >= valor2; i--) {
            printf("%d ", i);
        }
        printf("\n");
    } else {
        printf("Os valores são iguais: %d\n", valor1);
    }

    return 0;
}
