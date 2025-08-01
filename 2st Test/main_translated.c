#include <stdbool.h>
#include <stdio.h>

// ——— Em resumo, para fazer um loop sobre um loop:
// Faça o loop interno e suas condições
// Use um "do" e estabeleça as condições de parada

void imprimir_array(int vetor[], int tamanho);
void ordenar_array(int vetor[], int tamanho);

// ---

int main() {
  int vetor[10] = {1};
  int total_de_elementos_de_input = 10;
  for (int i = 0; i < total_de_elementos_de_input; i++) {
    // Prompt
    printf("\nDigite um número: ");
    scanf("%d", &vetor[i]);
    // Ordena e imprime
    ordenar_array(vetor, i + 1); // 1 até o índice atual - assim os números aleatórios não são mostrados, mas ainda estão lá
    imprimir_array(vetor, i + 1);
  }
  return 0;
}

// ---

void ordenar_array(int vetor[], int tamanho) {
  int modificado; // Inteiro no lugar de bool
  int i, aux;

  do {
    modificado = 0; // Considera que não há modificações

    for (i = 0; i < tamanho - 1; i++) {
      if (vetor[i] > vetor[i + 1]) {
        // Troca os elementos fora de ordem
        aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;

        modificado = 1; // Marca que houve pelo menos uma troca
      }
    }

    // Se nenhuma modificação foi feita, o vetor já está ordenado
  } while (modificado); // Continua enquanto houver trocas
}

// Imprime o array até o tamanho fornecido
void imprimir_array(int vetor[], int tamanho) {
  printf("\n ——— Array atualmente ordenado ———");
  for (int i = 0; i < tamanho; i++) { // Também pode imprimir até a iteração atual
    printf("\n %d: %d", i + 1, vetor[i]);
  }
}
