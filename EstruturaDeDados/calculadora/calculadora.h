#ifndef EXPRESSAO_H
#define EXPRESSAO_H

// Estrutura para um item da pilha: pode ser um operador ou um número
typedef struct Item {
    int tipo; // 0 para operador, 1 para número
    union {
        char operador; // Armazena o operador se for um item do tipo operador
        double numero; // Armazena o número se for um item do tipo número
    } valor;
    struct Item *proximo; // Ponteiro para o próximo item na pilha
} Item;

// Estrutura para a pilha
typedef struct {
    Item *topo; // Ponteiro para o topo da pilha
    int Tamanho; // Contador do tamanho da pilha
} Pilha;

// Protótipos das funções
void push(Pilha *p, int tipo, double chave); // Empilha um item na pilha
double pop(Pilha *p); // Desempilha um item da pilha
int is_operator(char c); // Verifica se o caractere é um operador matemático
int is_function(const char *str, int i); // Verifica se a substring é uma função matemática conhecida
float getValor(char *Str); // Calcula o valor da expressão em notação pós-fixa
char *getFormaInFixa(char *str); // Converte a expressão pós-fixa para infixa
char *removeParenteses(char *inFixa); // Remove os parênteses desnecessários na expressão infixa

#endif
