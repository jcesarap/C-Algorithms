#include <stdio.h>

int query_vector();
int order_vector();
// Original idea was to pass vector to choose, and the index - to return the number in that index

int query = 0;
int counter = 0;
int dataset[] = {13, 1230, 1203, 1230, 1419823, 910, 1, 2, 3};
int *ptr = dataset;
int current_value = 0;
// Get size of the array - for bounds
int boundaries = sizeof(dataset) / sizeof(int);

int main() {
  // Given a vector of positive integers, make a function that gets a vector and an integer (to be searched)
  // Retorne a primeira posição do número no vetor, ou -1
  printf("\n ———————— Antes: ");
  for (int i = 0; i < boundaries; i++) {
    printf("%d ——— ", dataset[i]);
    counter++;
  }
  order_vector();
  counter = 0;
  printf("\n ———————— Depois: ");
  for (int i = 0; i < boundaries; i++) {
    printf("%d ——— ", dataset[i]);
    counter++;
  }
}

int order_vector() {
  int query = 0;
  int counter = 0;
  int dataset[] = {13, 1230, 1203, 1230, 1419823, 910, 1, 2, 3};
  int *ptr = dataset;
  int current_value = 0;
  int previous_value = 0;
  // Get size of the array - for bounds
  int boundaries = sizeof(dataset) / sizeof(int);
  for (int i = 0; i < boundaries; i++) {
    // printf("\n %d. = %d", counter, dataset[i]);
    counter++;
  }
  // Iterate through each vector (index) - up to the end; compare the query with the pointer (value on index)
  for (int i = 0; i < boundaries; i++) {
    previous_value = *ptr; // Assign from pointer
    ptr += 1;
    current_value = *ptr; // Assign from pointer
    if (current_value > previous_value) {
      dataset[i + 1] = previous_value;
      dataset[i] = current_value;
    }
  }
  printf("Negative");
  return -1;
}

int query_vector() {
  int query = 0;
  int counter = 0;
  int dataset[] = {13, 1230, 1203, 1230, 1419823, 910, 1, 2, 3};
  int *ptr = dataset;
  int current_value = 0;
  // Get size of the array - for bounds
  int boundaries = sizeof(dataset) / sizeof(int);
  for (int i = 0; i < boundaries; i++) {
    printf("\n %d. = %d", counter, dataset[i]);
    counter++;
  }
  printf("\n Choose a number (not index): ");
  scanf("%d", &query);
  // Iterate through each vector (index) - up to the end; compare the query with the pointer (value on index)
  for (int i = 0; i != boundaries; i++) {
    current_value = *ptr; // Assign from pointer
    // printf("\n ——————————");
    //  printf("\n Query is:%d", query);
    //   printf("\n Value:%d", current_value);
    //    printf("\n In index: %d", i);
    //     printf("\n by Pointer: %d", *ptr);
    // if (query == i) {
    //   printf("\n %d", query);
    //   return query;
    // }
    if (query == current_value) {
      printf("\n %d", i);
      return i;
    }
    ptr += 1;
  }
  printf("Negative");
  return -1;
}
