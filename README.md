# 🎒 Sistema de Inventário TechNova - Nível: Zona de Perigo

Este projeto foi atualizado para cumprir os requisitos avançados de Estrutura de Dados, focando na comparação entre alocação estática (Vetor) e dinâmica (Lista Encadeada).

## 🚀 Novas Funcionalidades e Requisitos
O sistema agora opera com duas estruturas em paralelo para fins de análise:

- **Mochila com Vetor (Lista Sequencial):** Capacidade fixa de 10 itens.
- **Mochila com Lista Encadeada (Estrutura Dinâmica):** Alocação de memória conforme a necessidade.
- **Ordenação por Nome:** Implementação do algoritmo **Bubble Sort** no vetor de structs.
- **Busca Binária:** Otimização da procura de itens no vetor após a ordenação.
- **Contador de Operações:** O sistema exibe o número de comparações realizadas para demonstrar a eficiência da Busca Binária frente à busca comum.

## 🛠️ Detalhes da Implementação
- **Linguagem:** C.
- **Structs:** Definição de `Item` (nome, tipo, quantidade) e `No` (para a lista encadeada).
- **Bibliotecas:** `stdio.h`, `stdlib.h`, `string.h`.

## 📦 Como Testar no Codespaces
1. Compile o programa:
```bash
gcc main.c -o programa
