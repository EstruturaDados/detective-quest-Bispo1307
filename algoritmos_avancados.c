#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da sala (nó da árvore)
typedef struct sala {
    char nome[50];
    struct sala *esquerda;
    struct sala *direita;
} Sala;

// Cria dinamicamente uma nova sala
Sala* criarSala(char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// Permite a exploração interativa das salas
void explorarSalas(Sala *atual) {
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está na %s.\n", atual->nome);

        // Verifica se é um nó folha (sem caminhos)
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Não há mais caminhos. Você chegou ao fim da exploração!\n");
            break;
        }

        printf("Escolha o caminho: (e) esquerda, (d) direita, (s) sair: ");
        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (escolha == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } else if (escolha == 's') {
            printf("Saindo da mansão...\n");
            break;
        } else {
            printf("Caminho inválido!\n");
        }
    }
}

int main() {
    // Criação automática do mapa da mansão
    Sala *hall = criarSala("Hall de entrada");
    Sala *salaEstar = criarSala("Sala de estar");
    Sala *cozinha = criarSala("Cozinha");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *jardim = criarSala("Jardim");
    Sala *despensa = criarSala("Despensa");

    // Conexões (estrutura da árvore)
    hall->esquerda = salaEstar;
    hall->direita = cozinha;
    salaEstar->esquerda = biblioteca;
    salaEstar->direita = jardim;
    cozinha->direita = despensa;

    // Inicia a exploração
    explorarSalas(hall);

    // Liberação de memória
    free(biblioteca);
    free(jardim);
    free(despensa);
    free(salaEstar);
    free(cozinha);
    free(hall);

    return 0;
}
