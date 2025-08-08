#include <stdio.h>
#include <string.h>

// Melhor rodar funções diretamente - adicionar prototipos acima de main,
// adiciona mais complexidade, verbosidade, e portanto, espaço para erro e
// necessidade de correção

void printString() {
  // Variable: Choose a value for one (char[])
  // Pointer: Point there
  // Print:
  // // [ Pick value ]
  // // \n === Variable x === has y value, z address
  // // \n === Pointer x === \n has y value in z adress \n The adress of the
  // pointer itself is w
  char var[40];
  //
  printf("\n Escreva uma frase para atribuir à variável: ");
  fgets(var, sizeof(var), stdin);
  // The middle parameter is because the size of the vector isn't declared here,
  // so you need sizeof to determine that (which is the size in bytes)
  // Side note: size_t(ype) is used to store sizes
  var[strcspn(var, "\n")] = 0;
  // Means: assign rvalue to var, at the index of (then you run a
  // function to find a certain index)
  char *ptr;
  ptr = var; // Vetores... decaem para ponteiros para o primeiro elemento
  //
  printf("\n === Variável ===");
  printf("\n Tem valor \"%s\", no endereço %p", var, (void *)&var); // Get memory address, turn to pointer, print
  // Don't use [] unless you want to print an specific element/character
  // s is the shorthand for string Casting to pointer type
  // p is the shorthand-type for pointer
  printf("\n === Ponteiro ===");
  printf("\n Tem valor \"%s\", no endereço %p \n O endereço do ponteiro em si é: %p", ptr, (void *)ptr, &ptr);
  // Para imprimir strings, aponte para a string "ptr = var"
  // Para imprimir o endereço dela, faça o mesmo, casting it to a pointer
  // Para pegar o endereço do ponteiro, só use &
}

void printInt() {
  // Variable: Pick a number
  // Pointer: Point there
  // Print:
  // // \n === Variable x === \n Has y value, in z address
  // // \n === Pointer z ==== \n Points to z address, which has y value - whose pointer address is z
  // ========= READING
  int var;
  char buffer[100];
  printf("\n Escolha um número: ");
  fgets(buffer, sizeof(buffer), stdin);
  // === Redundancy for memorisation purposes
  buffer[strcspn(buffer, "\n")] = 0;
  // === Actual method
  sscanf(buffer, "%d", &var); // As default in scanf, use & - and use shorthands for type
  // ========= POINTER
  int *ptr;
  ptr = &var;
  // === POINTERS TO POINTERS
  // int **ptr2;
  // ptr2 = &ptr;
  // ========= PRINT
  printf("\n === VARIÁVEL ==== \n Tem valor %d, no endereço %p", var, &var);
  printf("\n === POINTER ==== \n Tem valor %d, no endereço %p - cujo endereço do ponteiro é %p", *ptr, (void *)ptr, &ptr);
}

void printVector() {
  // === === VECTOR
  // Print all elements - referencing them with pointer math
  // And normally, for checking
  int exampleArray[] = {1, 2, 3, 4, 5, 6};
  // For looping through an array, you need to know how many elements does it have
  // ...for that:    size of elements + number elements = size of array
  // number of elements = size of array / size of elements
  int numberOfElements = sizeof(exampleArray) / sizeof(exampleArray[0]);
  printf("\n O vetor tem %d elementos", numberOfElements);
  // === === POINTERS
  int *ptr;
  ptr = &exampleArray[0];
  //
  printf("\n Elemento padrão (%p) e designado para ponteiro: ", (void *)ptr);                         // Selecionar ínicio do stack de memória do vetor
  for (int i = 0; i < numberOfElements; i++) {                                                        // Define bounds do ponteiro, como boundaries do vetor
    printf("\n %d° Elemento = %d \n      No espaço de memória %p", i, *(ptr + i), (void *)(ptr + i)); // Próximo espaço de memória
    // Precisa somar o valor da iteração, como ptr se mantém não incrementado
  }
}

void kaiserAlgorithm() { // Você precisa usar outras funções
  // === LER INCREMENTO
  int increment;
  char buffer[100];
  printf("\n Escolha um incremento: ");
  fgets(buffer, sizeof(buffer), stdin);
  // === Redundancy for memorisation purposes
  buffer[strcspn(buffer, "\n")] = 0;
  // === Actual method
  sscanf(buffer, "%d", &increment);
  // === LER STRING
  char string[100];
  //
  printf("\n Escreva uma frase: ");
  fgets(string, sizeof(string), stdin);
  // The middle parameter is because the size of the vector isn't declared here,
  // so you need sizeof to determine that (which is the size in bytes)
  // Side note: size_t(ype) is used to store sizes
  string[strcspn(string, "\n")] = 0;
  // Means: assign rvalue to string, at the index of (then you run a
  // function to find a certain index)
  char *ptr;
  ptr = string; // Vetores... decaem para ponteiros para o primeiro elemento
  // === PREPARE CODIFICAÇÃO
  // = Define string for alphabet
  char ALPHABET[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  // = DEFINA BOUNDS DOS VETORES
  int string_length = strlen(string);
  printf("Frase de %d caracteres", string_length);
  // int string_limit = sizeof(string) / sizeof(string[0]);
  int string_limit = string_length;
  int ALPHABET_limit = sizeof(ALPHABET) / sizeof(ALPHABET[0]);
  int alphabet_limit = sizeof(alphabet) / sizeof(alphabet[0]);
  // === Codificar String
  // = Replace strings based on increment
  // Loop through string (in each letter, do)
  printf("\n CARREGANDO loop...");

  // DO IT WITH VECTORS FIRST, CHANGE TO POINTERS AFTER ISOLATING PROPER LOGIC <<<=========================
  for (int i = 0; i < string_limit; i++) { // i = character
    char *currentCharacter = &string[i];

    // Loop through alphabet and ALPHABET
    for (int j = 0; j < ALPHABET_limit; j++) {

      // Until you find equal characters (between string and alphabets)
      char *current_ALPHABET = &ALPHABET[j];

      if (strcmp(currentCharacter, current_ALPHABET) == 0) {
        printf("\n Substituindo %d° letra com alfabeto maíusculo...", (i + 1));
        // ===> When you do, you'll have the alphabet_coordinate (to increment from)
        int alphabet_coordinate = j;
        // Replace character => When you do, replace the character on string, for the character on alphabet (+ its equal + increment)
        string[i] = ALPHABET[alphabet_coordinate];
      }

      for (int k = 0; k < alphabet_limit; k++) {
        char *current_alphabet = &alphabet[k];

        if (strcmp(currentCharacter, current_alphabet) == 0) {
          printf("\n Substituindo %d° letra com alfabeto minusculo...", (i + 1));
          // ===> When you do, you'll have the alphabet_coordinate (to increment from)
          int alphabet_coordinate = k;
          // Replace character => When you do, replace the character on string, for the character on alphabet (+ its equal + increment)
          string[i] = alphabet[alphabet_coordinate];
        }
      }
    }
  }
  // === Print coded string
  printf("\n Frase Criptografada: %s", string);
}

int pickOption(int option) {
  printf("\n === Opções ===");
  printf("\n 1: Escrever pointeiros (string) e seus valores");
  printf("\n 2: Escrever ponteiros (int) e seus valores");
  printf("\n 3: Escrever ponteiros (vector) e seus valores");
  printf("\n 4: Escrever ponteiros (vector DINÂMICO) e seus valores");
  printf("\n 5: Escrever ponteiros (matriz) e seus valores");
  printf("\n 6: Escrever ponteiros (função) e seus valores");
  printf("\n 7 (Extra): Escrevendo arquivos");
  printf("\n 8 (Extra): Lendo arquivos");
  printf("\n 9 (Extra): Algoritmo de Caesar");
  printf("\n O que quer rodar: ");

  // New read method
  char buffer[100];
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strcspn(buffer, "\n")] = 0; // string character span
  // The following is redundant, but both are kept for learning purposes
  if (sscanf(buffer, "%d", &option) == 1) { // Extract (only), type, to
    //
  } else {
    printf("Opção inválida");
  }

  printf("\n === Opção Escolhida ===");
  switch (option) {
  case 1:
    printf("\n === Rodando Opção 1 (Escrever Ponteiros) ===");
    printString();
    break;
  case 2:
    printf("\n === Rodando Opção 2 ===");
    printInt();
    break;
  case 3:
    printf("\n === Rodando Opção 3 ===");
    printVector();
    break;
  case 9:
    printf("\n === Rodando Opção 9 ===");
    kaiserAlgorithm();
    break;
  default:
    printf("\n Opção \"Default\"");
    break;
  }
  return option;
}

void main() {
  int option = pickOption(option);
  //
}
