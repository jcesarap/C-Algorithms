#include <stdio.h>

void main() {
  int vetor[] = {10, 20, 30};
  int *ptr = vetor;
  printf("%d\n", *(ptr + 1)); // As this is a pointer of integers, adds a size of one integer to the current memory address, now pointing to the next element of the vector
                              // Careful as moving beyond the range of 0 to the vector's limit, it will show some value of something else that lies on memory
                              // ' Notice the parenthesis above, it needs to increment the pointer before getting the value it points to
}
