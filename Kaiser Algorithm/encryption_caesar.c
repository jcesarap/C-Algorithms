#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// === === Notas === === === === === === === === === === === === === === === ===
// === === PACE (Postergação => Comece algoritmos com versões simplificadas, para isolar partes perfeitamente funcionais da lógida)
// === Fazer com vetores primeiro - quando lógica estiver funcional, use ponteiros
// === Faça primeiro com um único caractere

// === === Global === ===
// Alphabet vectors

// === === Required Functions === ===
// === In each function, HAVE PRINTS TO DEBUG/ENSURE THEY'RE WORKING (TO ISOLATE CODE, SO YOU CAN FIND/FOCUS ON WHAT IS WRONG)
// Read string
// Read int
// Encrypt ==== ==== ==
// === Helper functions
// * Loop (through string)
//      * Select element
//      * Send to another function
//      * Compares (and increments (Paced to the end))
//          * For debugging (print what characters are in each, and if they're equal)

// === === Required Constants === ===
//

int readIncrement() {
  int increment;
  char buffer[100];
  printf("\n Escolha um incremento: ");
  fgets(buffer, sizeof(buffer), stdin);
  // === Redundancy for memorisation purposes
  buffer[strcspn(buffer, "\n")] = 0;
  // === Actual method
  sscanf(buffer, "%d", &increment);
  return increment;
}

char *readString() { // Strings são ponteiros
  char *string = malloc(sizeof(char)*100);
  printf("\n Escreva uma frase: ");
  fgets(string, sizeof(string), stdin);
  // The middle parameter is because the size of the vector isn't declared here,
  // so you need sizeof to determine that (which is the size in bytes)
  // Side note: size_t(ype) is used to store sizes
  string[strcspn(string, "\n")] = 0;
  return string;
}

void encrypt(char *string, int increment) {
  // === === === TOOLS
  char ALPHABET[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  int string_limit = strcspn(string, "\0");
  int alphabet_limit = sizeof(alphabet) / sizeof(alphabet[0]); // Bounds dos vetores
  int ALPHABET_limit = sizeof(ALPHABET) / sizeof(ALPHABET[0]); // Altere a equação para descobrir outras coisas:       numero de elementos * tamanho de cada = tamanho do vetor
  printf("\n DEBUG: Ambos vetores devem ter 26 elementos, e têm \"%d\" e \"%d\" elementos", alphabet_limit, ALPHABET_limit); // Checando tamanho dos vetores
  printf("\n DEBUG: Você escolheu um incremento de %d letras, para criptografar a frase: \"%s\" de %d caracteres", increment, string, string_limit);
  // === === === CODE
  // Loop through characters
  // In each character, loop through alphabets
  // Print which character (from string) was found in the index of which alphabet
  
  // Houveram erros criando os loops... na próxima faça loops que printem seus elementos (e teste se eles estão rodando como quer - antes de fazer qualquer outra coisa, como comparações)
  // STRING
  for (int i = 0; i < string_limit; i++) {
    
    // MAIUSCULO
    for(int j = 0; j < ALPHABET_limit; j++) {
      if(string[i] == ALPHABET[j]) {
        printf("\n DEBUG: Caractere %c encontrado no index %d do alfabeto maiusculo - que é a letra %c (usando pointer do vetor de alfabeto)", string[i], (j+1), ALPHABET[j]);
        string[i] = ALPHABET[j + increment];
        break;
      }
    }
    
    // MINUSCULO
    for(int k = 0; k < alphabet_limit; k++) {
      if(string[i] == alphabet[k]) {
        printf("\n DEBUG: Caractere %c encontrado no index %d do alfabeto minusculo - que é a letra %c (usando pointer do vetor de alfabeto)", string[i], (k+1), alphabet[k]);
        string[i] = alphabet[k + increment];
        break;
      }
    }

  }
}

void main() {
  printf("=== Bem Vindo ao Algoritmo de César (literalmente) ===");
  int increment = readIncrement();
  char *string = readString(); // Estabelecendo um ponteiro que aponta para o retorno da função (outra opção é: strcpy(string, readString());)
  encrypt(string, increment);
  printf("\n === > Frase Criptografada: %s", string);
  free(string);
}
