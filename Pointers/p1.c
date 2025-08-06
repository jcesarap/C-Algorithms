#include <stdio.h>

void main() {
  int idade = 42;
  int *ptr = &idade;

  printf("Endereço de idade: %p\n", &idade); // Operator for accessing the address of a variable
  printf("Valor de idade ..: %d\n\n", idade);

  printf("Endereço de ptr ......: %p\n", &ptr); // Address of pointers
  printf("Valor de ptr .........: %p\n", ptr);  // Address that's the value of the pointer
  printf("Valor apontado por ptr: %d\n", *ptr); // Value on the memory address the pointer points to
}
