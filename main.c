#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do Item conforme o desafio
typedef struct {
char nome[30];
char tipo[20];
int quantidade;
} Item;

// Vetor para 10 itens e contador
Item mochila[10];
int totalItens = 0;

// Funcao para listar (chamada apos cada operacao)
void listarItens() {
printf("\n--- INVENTARIO ATUAL (%d/10) ---\n", totalItens);
if (totalItens == 0) {
printf("Mochila vazia.\n");
} else {
for (int i = 0; i < totalItens; i++) {
printf("%d. [%s] Tipo: %s | Qtd: %d\n", i+1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
}
}
printf("-------------------------------\n");
}

void inserirItem() {
if (totalItens >= 10) {
printf("\nErro: Mochila cheia!\n");
return;
}
Item novo;
printf("\nNome do item: ");
scanf(" %[^\n]s", novo.nome);
printf("Tipo (arma/cura/municao): ");
scanf(" %[^\n]s", novo.tipo);
printf("Quantidade: ");
scanf("%d", &novo.quantidade);
mochila[totalItens] = novo;
totalItens++;
printf("\nItem adicionado!");
listarItens();
}

void removerItem() {
char nomeBusca[30];
printf("\nNome para remover: ");
scanf(" %[^\n]s", nomeBusca);
for (int i = 0; i < totalItens; i++) {
if (strcmp(mochila[i].nome, nomeBusca) == 0) {
for (int j = i; j < totalItens - 1; j++) mochila[j] = mochila[j + 1];
totalItens--;
printf("\nItem removido.");
listarItens();
return;
}
}
printf("\nItem nao encontrado.");
}

void buscarItem() {
char nomeBusca[30];
printf("\nBuscar por nome: ");
scanf(" %[^\n]s", nomeBusca);
for (int i = 0; i < totalItens; i++) {
if (strcmp(mochila[i].nome, nomeBusca) == 0) {
printf("\nAchou! Nome: %s | Tipo: %s | Qtd: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
return;
}
}
printf("\nNao encontrado.");
}

int main() {
int op;
do {
printf("\n1.Inserir 2.Remover 3.Listar 4.Buscar 0.Sair\nEscolha: ");
scanf("%d", &op);
if(op==1) inserirItem();
else if(op==2) removerItem();
else if(op==3) listarItens();
else if(op==4) buscarItem();
} while (op != 0);
return 0;
}
