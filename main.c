#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Definição das Structs
typedef struct {
char nome[30];
char tipo[20];
int quantidade;
} Item;

// Estrutura para Lista Encadeada
typedef struct No {
Item dados;
struct No* proximo;
} No;

// Variáveis Globais
Item vetorMochila[10];
int totalVetor = 0;
No* listaMochila = NULL;
int comparacoes = 0; // Contador de operações

// --- FUNÇÕES OBRIGATÓRIAS ---

void inserirItem(Item novo) {
// Inserir no Vetor
if (totalVetor < 10) {
vetorMochila[totalVetor++] = novo;
}
// Inserir na Lista Encadeada
No* novoNo = (No*)malloc(sizeof(No));
novoNo->dados = novo;
novoNo->proximo = listaMochila;
listaMochila = novoNo;
printf("\nItem inserido em ambas as estruturas!");
}

void listarItens() {
printf("\n--- EXIBINDO VETOR ---");
for (int i = 0; i < totalVetor; i++) {
printf("\n%d. %s | Qtd: %d", i+1, vetorMochila[i].nome, vetorMochila[i].quantidade);
}
printf("\n\n--- EXIBINDO LISTA ---");
No* atual = listaMochila;
while (atual != NULL) {
printf("\n- %s | Qtd: %d", atual->dados.nome, atual->dados.quantidade);
atual = atual->proximo;
}
}

// Ordenação Bubble Sort
void ordenarVetor() {
for (int i = 0; i < totalVetor - 1; i++) {
for (int j = 0; j < totalVetor - i - 1; j++) {
if (strcmp(vetorMochila[j].nome, vetorMochila[j+1].nome) > 0) {
Item temp = vetorMochila[j];
vetorMochila[j] = vetorMochila[j+1];
vetorMochila[j+1] = temp;
}
}
}
printf("\nVetor ordenado por nome!");
}

// Busca Binária no Vetor
void buscarBinaria(char* nome) {
comparacoes = 0;
int esq = 0, dir = totalVetor - 1;
while (esq <= dir) {
comparacoes++;
int meio = (esq + dir) / 2;
int res = strcmp(vetorMochila[meio].nome, nome);
if (res == 0) {
printf("\nItem encontrado! Comparacoes: %d", comparacoes);
return;
}
if (res < 0) esq = meio + 1;
else dir = meio - 1;
}
printf("\nItem nao encontrado. Comparacoes: %d", comparacoes);
}

int main() {
int opcao;
char nomeBusca[30];
do {
printf("\n\n1.Inserir 2.Listar 3.Ordenar 4.Busca Binaria 0.Sair\nEscolha: ");
scanf("%d", &opcao);
if (opcao == 1) {
Item it;
printf("Nome: "); scanf("%s", it.nome);
printf("Tipo: "); scanf("%s", it.tipo);
printf("Qtd: "); scanf("%d", &it.quantidade);
inserirItem(it);
} else if (opcao == 2) listarItens();
else if (opcao == 3) ordenarVetor();
else if (opcao == 4) {
printf("Nome para busca: "); scanf("%s", nomeBusca);
buscarBinaria(nomeBusca);
}
} while (opcao != 0);
return 0;
}
