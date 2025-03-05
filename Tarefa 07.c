#include <stdio.h>
#include <string.h>

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
    printf("6. Exibir produto com maior pre\u00e7o\n");
    printf("7. Mostrar valor do stock\n");
    printf("8. Ordenar produtos\n");
    printf("9. Sair\n");
    printf("Escolha uma op\u00e7\u00e3o: ");
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
    printf("C\u00f3digo: ");
    scanf("%d", &novoProduto.codigo);
    getchar();

    printf("Nome: ");
    fgets(novoProduto.nome, sizeof(novoProduto.nome), stdin);
    novoProduto.nome[strcspn(novoProduto.nome, "\n")] = 0;

    printf("Quantidade em stock: ");
    scanf("%d", &novoProduto.quantidade);

    printf("Pre\u00e7o: ");
    scanf("%f", &novoProduto.preco);

    produtos[totalProdutos] = novoProduto;
    totalProdutos++;

    printf("Produto cadastrado com sucesso!\n");
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

int main() {
    int opcao;
    do {
        opcao = exibirMenu();
        switch (opcao) {
            case 1:
                criarProduto();
                break;
            case 3:
                procurarProduto();
                break;
            case 4:
                atualizarQuantidade();
                break;
            case 5:
                apagarProduto();
                break;
            case 9:
                printf("Saindo...\n");
                break;
            default:
                printf("Op\u00e7\u00e3o inv\u00e1lida! Tente novamente.\n");
        }
    } while (opcao != 9);
    return 0;
}
