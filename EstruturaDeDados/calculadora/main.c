#include <stdio.h>
#include "calculadora.h"

int main() {
    char postfix[512] = "";
    float resultado = getValor(postfix);
    char *infixa = getFormaInFixa(postfix);
    infixa = removeParenteses(infixa);

    printf("Expressão Infixa: %s\n", infixa);
    printf("Resultado: %f\n", resultado);

    return 0;
}