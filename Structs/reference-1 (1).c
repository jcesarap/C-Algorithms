#include <ncurses.h>
#include <stdlib.h>

// —————————  Structs
// ——— Pointers to structures
struct {
  char nome[40];
  unsigned int idade;
} pessoa;

struct pessoa *p;

// ——— Nested Structures
struct endereco_postal {
  char rua[40];
  unsigned int numero;
  char cidade[40];
};

struct pessoa {
  char nome[40];
  char email[40];
  unsigned int idade;
  struct endereco_postal endereco;
};

// ———————— Functions

// Practise from class, before ncurses
struct Pessoa {
  char nome[40];
  unsigned int idade;
} cliente, todosClientes[100];

// Do this using pointers

int main() {
  printf("Nome do cliente: ");
  scanf("%s", cliente.nome);
  printf("Idade do cliente: ");
  scanf("%d", &cliente.idade);
  todosClientes[1] = cliente;
  // Print to test struct
  printf("%s tem %i anos.", todosClientes[1].nome, todosClientes[1].idade);
  // Study pointers to structures, below
}

void pointersToStructures() {
  printf("Nome da pessoa: ");
  scanf("%s", pessoa.nome);
  printf("Idade da pessoa: ");
  scanf("%d", &pessoa.idade);
  p = *pessoa;
  printf("%s tem % i anos.", p->nome, p->idade);
}

void nestedStructures() {
  struct pessoa cliente;
  printf("Nome do cliente: ");
  scanf("%s", cliente.nome);
  printf("Rua: ");
  scanf("%s", cliente.endereco.rua);
  printf("Número: ");
  scanf("%d", &cliente.endereco.numero);
  printf("Cidade: ");
  scanf("%s", cliente.endereco.cidade);
}

// ——— Other subjects
// Uniões (union)
// Enumerações(enum)
// Definindo tipos(typedef)
