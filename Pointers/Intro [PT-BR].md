
# Ponteiros

* Composição — "Tipos de variáveis" com nome, tipo baseado na variável à qual está conectado, valor que é o ponteiro para o endereço de outra variável, e seu próprio endereço.
* Dois operadores —

  * `&` — Obtém o endereço de memória da variável ou ponteiro.
  * `*` — Obtém o valor no endereço de memória do ponteiro.

```c
int k;
int *ptr = NULL; // Declaração com "0", int porque é destinado à conexão com a variável k
```

# Vetores

* Um array em que cada elemento é um ponteiro.
* Útil para manipular strings ou arrays de estruturas.

# Tamanho de

* `sizeof(x)` retorna o tamanho em bytes de uma variável x.
* Se usado em um vetor, retorna o tamanho de todos os elementos no vetor.

# Programas de Eleudson

```c
#include <stdio.h>

void main() {
  int idade = 42;
  int *ptr = &idade;

  printf("Endereço de idade: %p\n", &idade); // Operador para acessar o endereço de uma variável
  printf("Valor de idade ..: %d\n\n", idade);

  printf("Endereço de ptr ......: %p\n", &ptr); // Endereço de ponteiros
  printf("Valor de ptr .........: %p\n", ptr);  // Endereço que é o valor do ponteiro
  printf("Valor apontado por ptr: %d\n", *ptr); // Valor no endereço de memória para o qual o ponteiro aponta
}
```

```c
#include <stdio.h>

void main() {
  float y = 3.14;
  float *ptr = &y; // ptr aponta para y

  printf("y = %f\n", y);
  printf("ptr = %p\n", ptr);

  *ptr = 2.71; // Opera a variável através do ponteiro
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
  printf("%d\n", *(ptr + 1)); // Como este é um ponteiro de inteiros, adiciona o tamanho de um inteiro ao endereço atual de memória, passando a apontar para o próximo elemento do vetor
                              // Cuidado ao ultrapassar o intervalo de 0 até o limite do vetor, ele mostrará algum valor de outra coisa que está na memória
                              // ' Repare nos parênteses acima, é necessário incrementar o ponteiro antes de obter o valor que ele aponta
}
```

```c
#include <stdio.h>

void main() {
  int vetor[] = {10, 20, 30}; // Vetor é como um ponteiro entre vários valores
  int *ptr = vetor;           // Ponteiro para vetor
  size_t t_total, t_elemento; // Duas variáveis do tipo size_t - usado para representar o tamanho de uma variável
  t_total = sizeof(vetor);    // Atribui o resultado da função à variável
                              // Conta o número de elementos
                              // Use isso para dividir o vetor por
  t_elemento = t_total / sizeof(int);
  printf("Bytes total do vetor ..: %zu\n", t_total);   // Isso é um casting, transformando size_t em int
                                                       // É proporcional
  printf(" total do vetor ..: %d\n", (int)t_elemento); // Isso é um casting, transformando size_t em int
}
```

Se quiser, posso também revisar o comentário que diz *"Imprime 'Banana'"*, pois o código imprime `"Maçã"` — me avise se quiser corrigir isso.
