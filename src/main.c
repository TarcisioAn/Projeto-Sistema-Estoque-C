#include <locale.h>
#include"estoque.h"

int main() {
    setlocale(LC_ALL, "pt_PT.utf8");
    int opcao;
    do {
        opcao = exibirMenu();
        switch (opcao) {
            case 1: criarProduto();
                break;
            case 2: listarProdutos();
                break;
            case 3: procurarProduto();
                break;
            case 4: atualizarQuantidade();
                break;
            case 5: apagarProduto();
                break;
            case 6: exibirProdutoMaisCaro();
                break;
            case 7: calcularValorStock();
                break;
            case 8: ordenarProdutos();
                break;
            case 9: printf("Saindo...\n");
                break;
            default: printf("Operação Inválida! Tente novamente.\n");
        }
    } while (opcao != 9);
    return 0;
}
