#ifndef EXPRESSAO_H
#define EXPRESSAO_H


typedef struct Item {
    int tipo; 
    union {
        char operador;
        double numero; 
    } valor;
    struct Item *proximo;
} Item;


typedef struct {
    Item *topo;
    int Tamanho; 
} Pilha;


void push(Pilha *p, int tipo, double chave);
double pop(Pilha *p);
int is_operator(char c);
int is_function(const char *str, int i);
float getValor(char *Str);
char *getFormaInFixa(char *str);
char *removeParenteses(char *inFixa);
#endif
