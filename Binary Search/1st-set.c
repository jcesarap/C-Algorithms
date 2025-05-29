#include <stdio.h>

int query_vector();
int order_vector();
// Original idea was to pass vector to choose, and the index - to return the number in that index

int query = 0;
int *ptr = dataset;
int current_value = 0;

int main() {
  order_vector();
}

int order_vector() {
  int query = 0;
  int *ptr = dataset;
  int current_value = 0;
  int previous_value = 0;
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
  int *ptr = dataset;
  int current_value = 0;
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
