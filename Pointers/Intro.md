# Pointers
- Composition — "Variable types" with name, type based on the variable it's connecting to, value which is the pointer to the address of another variable, and its own address.
- Two operators —
    - & — Gets the memory address of the variable or pointer.
    - * — Gets the value on the memory address of the pointer.
```c
int k;
int *ptr = NULL; // Declaration with "0", int because it's meant for connecting with the k variable
```

# Vectors
- An array that every element is a pointer.
- Useful for manipulating strings or arrays of structures.

# Size of
- `sizeof(x)` returns byte size of a variable x.
- If used to a vector, returns the size of all elements in vector.

# Eleudson's Programs
```c
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
```

```c
#include <stdio.h>

void main() {
  float y = 3.14;
  float *ptr = &y; // ptr aponta para y

  printf("y = %f\n", y);
  printf("ptr = %p\n", ptr);

  *ptr = 2.71; // Operates the variable through the pointer
  printf("y = %f\n", y);
}
```

```c
#include <stdio.h>

void main() {
  char *frutas[] = {"Maçã", "Banana", "Laranja"};
  printf("%s\n", frutas[0]); // Imprime "Banana"
}
```

```c
#include <stdio.h>

void main() {
  int vetor[] = {10, 20, 30};
  int *ptr = vetor;
  printf("%d\n", *(ptr + 1)); // As this is a pointer of integers, adds a size of one integer to the current memory address, now pointing to the next element of the vector
                              // Careful as moving beyond the range of 0 to the vector's limit, it will show some value of something else that lies on memory
                              // ' Notice the parenthesis above, it needs to increment the pointer before getting the value it points to
}
```

```c
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
```
