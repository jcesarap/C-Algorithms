/*
    BCC-PRE 2025.1
    Exercício de Busca Binária
    Data: 22/maio/2025

    Aluno(a): Júlio César de Amoraes Pinheiro
*/

#include <stdio.h>
// WARNING: Arrays can't be passed to functions - they only receive a pointer to first element
int query_vector(int chosen_vector[], int size, int query);
int sort_vector(int chosen_vector[], int size);
int print_vector(int chosen_vector[], int size);
// Vectors are like variables. Declare them the same way on the parameters, plus []

int main() {
  int option = 0;
  int query = 0;
  int dataset[] = {13, 1230, 1203, 1230, 1419823, 910, 1, 2, 3, 10};
  int boundaries = sizeof(dataset) / sizeof(int); // Size of vector / Size of data-type/element = Number of elements
  printf("Escolha uma função (digite o número): \n");
  printf("Opções          Descrição \n");
  printf("0               Busca Binária \n");
  scanf("%d", &option);
  switch (option) {
  case 0: {
    sort_vector(dataset, boundaries); // Using variables of said name as parameters
    printf("Escolha um número: ");
    scanf("%d", &query);
    query_vector(dataset, boundaries, query);
    break;
  }
    return 0;
  }
}

int query_vector(int chosen_vector[], int size, int query) {
  int numberOfVectorElements = size;
  int iterations = 1;
  int start = 0;
  int end = size;
  while (start != end) {
    int middle = (start + end) / 2;
    if (chosen_vector[middle] == query) {
      printf(" Valor: %d \n Encontrado na posição: %d \n Após: %d iterações", query, middle, iterations);
      break;
    } else if (chosen_vector[middle] > query) {
      // ignore right of the list, then continue search
      end = middle;
    } else if (chosen_vector[middle] < query) {
      // ignore left of the list, then continue search
      start = middle;
    }
    iterations++;
  }
  // Show index of where the number was, or message that it was not there, and how many iterations it took
  return 0;
}

int sort_vector(int chosen_vector[], int size) {
  int aux = 0;
  for (int i = 0; i < size - 1; i++) {
    if (chosen_vector[i] > chosen_vector[i + 1]) {
      aux = chosen_vector[i];
      chosen_vector[i] = chosen_vector[i + 1];
      chosen_vector[i + 1] = aux;
      i = -1; // This will restart to 0 once there's a change
    }
  }
  print_vector(chosen_vector, size);
  return 0;
}

int print_vector(int chosen_vector[], int size) {
  int index = 0;
  int counter = 0;
  printf("—————————————— \n");
  for (int i = 0; i < size; i++) {
    printf("%d:    %d \n", counter, chosen_vector[i]);
    counter++;
  }
  return 0;
}
