#include <stdio.h>

#define MAX 10

void classifica(int vetor[], int qtd) {
  int x, c = -1, e;

  while (c != 0) {
    c = 0;
    x = 0;
    while (x < qtd) {
      if (x + 1 < qtd && vetor[x] > vetor[x + 1]) {
        e = vetor[x + 1];
        vetor[x + 1] = vetor[x];
        vetor[x] = e;
        c++;
      }
      x++;
    }
  }
}

void mostra_vetor(int vetor[], int qtd) {
  for (int i = 0; i < qtd; i++)
    printf("%d - ", vetor[i]);
  printf("\n\n");
}

int main() {
  int vetor[MAX];
  int i = 0;

  printf("CLASSIFICACAO SIMPLES DE VETOR\n\n");
  printf("Vetor original\n");

  while (i < MAX) {
    printf("Digite o no. da posição %d: ", i + 1);
    scanf("%d", &vetor[i]);
    printf("\n");

    classifica(vetor, i + 1);

    mostra_vetor(vetor, i + 1);
    i++;
  }

  return 0;
}
