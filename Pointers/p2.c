#include <stdio.h>

void main() {
  float y = 3.14;
  float *ptr = &y; // ptr aponta para y

  printf("y = %f\n", y);
  printf("ptr = %p\n", ptr);

  *ptr = 2.71; // Operates the variable through the pointer
  printf("y = %f\n", y);
}
