#include <stdio.h>

void main() {
  int vetor[] = {10, 20, 30}; // Vector is like a pointer between several values
  int *ptr = vetor;           // Pointer to vector
  size_t t_total, t_elemento; // Two variables of size_t type - used for representing the size of a variable
  t_total = sizeof(vetor);    // Attributes result of function to the varible
                              // Count number of elements
                              // Use this to divide vector to
  t_elemento = t_total / sizeof(int);
  printf("Bytes total do vetor ..: %zu\n", t_total);   // This is a casting, transfoming size_t into an int
                                                       // It's proportional
  printf(" total do vetor ..: %d\n", (int)t_elemento); // This is a casting, transfoming size_t into an int
}
