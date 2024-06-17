#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "calculadora.h"

void push(Pilha *p, int tipo, double chave) {
    Item *novoItem = (Item *)malloc(sizeof(Item));
    if (novoItem == NULL) {
        printf("Erro: Não foi possível alocar memória para o item.\\n");
        exit(1);
    }
    novoItem->tipo = tipo;
    if (tipo == 1) {
        novoItem->valor.numero = chave;
    } else {
        novoItem->valor.operador = (char)chave;
    }
    novoItem->proximo = p->topo;
    p->topo = novoItem;
    p->Tamanho++;
}

double pop(Pilha *p) {
    if (p->Tamanho == 0) {
        printf("Erro: Pilha vazia.\\n");
        exit(1);
    }
    Item *temp = p->topo;
    double chave = temp->valor.numero;
    p->topo = temp->proximo;
    free(temp);
    p->Tamanho--;
    return chave;
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int is_function(const char *str, int i) {
    return (strncmp(&str[i], "raiz", 4) == 0 ||
            strncmp(&str[i], "sen", 3) == 0 ||
            strncmp(&str[i], "cos", 3) == 0 ||
            strncmp(&str[i], "tg", 2) == 0 ||
            strncmp(&str[i], "log", 3) == 0);
}

float getValor(char *Str) {
    Pilha pilha = { NULL, 0 }; // Inicializa a pilha
    char *token = strtok(Str, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(&pilha, 1, atof(token));
        } else if (is_operator(token[0])) {
            double a = pop(&pilha);
            double b = pop(&pilha);
            double result = 0;
            switch (token[0]) {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/': result = b / a; break;
                case '^': result = pow(b, a); break;
            }
            push(&pilha, 1, result);
        }
        token = strtok(NULL, " ");
    }
    return (float)pop(&pilha); // Retorna o resultado da expressão
}

char *getFormaInFixa(char *str) {
    // Lógica para converter para forma infixa
    return str; // Retorna a string convertida
}

char *removeParenteses(char *inFixa) {
    if (inFixa != NULL && strlen(inFixa) > 0 && inFixa[0] == '(' && inFixa[strlen(inFixa) - 1] == ')') {
        inFixa[strlen(inFixa) - 1] = '\0'; // Corrige a conversão de char
        return inFixa + 1;
    }
    return inFixa;
}
