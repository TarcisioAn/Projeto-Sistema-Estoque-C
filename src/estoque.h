#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    char nome[100];
    int quantidade;
    float preco;
} Produto;

// Variáveis globais
extern Produto produtos[MAX_PRODUTOS];
extern int totalProdutos;

// Funções do sistema de estoque
int exibirMenu();
void criarProduto();
void listarProdutos();
void procurarProduto();
void atualizarQuantidade();
void apagarProduto();
void exibirProdutoMaisCaro();
void calcularValorStock();
void ordenarProdutos();

#endif
