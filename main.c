#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    char nome[100];
    int quantidade;
    float preco;
} Produto;

Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

int exibirMenu() {
    int opcao;
    printf("\n=== MENU ===\n");
    printf("1. Criar produto\n");
    printf("2. Listar todos os produtos\n");
    printf("3. Procurar um produto\n");
    printf("4. Atualizar quantidade em stock\n");
    printf("5. Apagar produto\n");
    printf("6. Exibir produto com maior preço\n");
    printf("7. Mostrar valor do stock\n");
    printf("8. Ordenar produtos\n");
    printf("9. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}

void criarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }
    Produto novoProduto;
    printf("\n=== Criar Produto ===\n");
    printf("Código: ");
    scanf("%d", &novoProduto.codigo);
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == novoProduto.codigo) {
            printf("Erro: Já existe um produto com esse código!\n");
            return;
        }
    }
    getchar();
    printf("Nome: ");
    fgets(novoProduto.nome, sizeof(novoProduto.nome), stdin);
    novoProduto.nome[strcspn(novoProduto.nome, "\n")] = 0;
    printf("Quantidade em stock: ");
    scanf("%d", &novoProduto.quantidade);
    printf("Preço: ");
    scanf("%f", &novoProduto.preco);
    produtos[totalProdutos] = novoProduto;
    totalProdutos++;
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos() {
    int codigo;
    printf("\n=== Lista de Produtos ===\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Código: %d | Nome: %s | Quantidade: %d | Preço: %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
    }
}

void procurarProduto() {
    int codigo;
    printf("\nDigite o c\u00f3digo do produto que deseja procurar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("\nProduto encontrado:\n");
            printf("C\u00f3digo: %d\nNome: %s\nQuantidade: %d\nPre\u00e7o: %.2f\n",
                   produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
            return;
        }
    }
    printf("Produto n\u00e3o encontrado!\n");
}

void atualizarQuantidade() {
    int codigo, novaQuantidade;
    printf("\nDigite o c\u00f3digo do produto que deseja atualizar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Quantidade atual: %d\n", produtos[i].quantidade);
            printf("Digite a nova quantidade: ");
            scanf("%d", &novaQuantidade);
            produtos[i].quantidade = novaQuantidade;
            printf("Quantidade atualizada com sucesso!\n");
            return;
        }
    }
    printf("Produto n\u00e3o encontrado!\n");
}

void apagarProduto() {
    int codigo;
    printf("\nDigite o c\u00f3digo do produto que deseja apagar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            for (int j = i; j < totalProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            totalProdutos--;
            printf("Produto apagado com sucesso!\n");
            return;
        }
    }
    printf("Produto n\u00e3o encontrado!\n");
}

void exibirProdutoMaisCaro() {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado!\n");
        return;
    }
    Produto maisCaro = produtos[0];
    for (int i = 1; i < totalProdutos; i++) {
        if (produtos[i].preco > maisCaro.preco) {
            maisCaro = produtos[i];
        }
    }
    printf("Produto mais caro:\nCódigo: %d | Nome: %s | Preço: %.2f\n", maisCaro.codigo, maisCaro.nome, maisCaro.preco);
}

void calcularValorStock() {
    float total = 0;
    for (int i = 0; i < totalProdutos; i++) {
        total += produtos[i].quantidade * produtos[i].preco;
    }
    printf("Valor total do stock: %.2f\n", total);
}

void ordenarProdutos() {
    for (int i = 0; i < totalProdutos - 1; i++) {
        for (int j = i + 1; j < totalProdutos; j++){
            if (produtos[i].codigo > produtos[j].codigo) {
                Produto temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }
    printf("Produtos ordenados com sucesso!\n");
}

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
