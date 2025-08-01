#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Notas pessoais
//      Excesso de anotações de pesquisa foi documentado em "College/Estructured Programming/Advanced Concepts"
//      Nunca fazer (novamente) a morphographia no mesmo arquvivo do código ("Sketch" file serves that purpose)

#define NUMBER 0
#define NAME 1
#define GRADE 2
#define VALID 0
#define INVALID 1
// #define GO_BACK 2

// Using typedef is the same thing as this, but acting as/giving an alias to the datatype
typedef struct { // New data type grouping multiple variables
    char nome[50];
    int numMatricula;
    int nota;
} AlunoStruct;

AlunoStruct Aluno;
AlunoStruct indexAlunos[100]; // Você ainda precisa preencher o vetor com os alunos
// Resposta para dúvida anterior:
//      Para o compilador, isso não é "um vetor de 100 indexAlunos", mas sim "Reserve um bloco de memória contínuo que consiga guardar 100 AlunoStruct."
//      e se fosse "int notas[5];"
//      Para o compilador, isso não é "um vetor com 5 notas", mas sim "Reserve um bloco de memória contínuo que consiga guardar 5 ints."

// --- Requirements
// Aluno struct; with nome, numMatricula e nota
// On main, create vectors: index, name, numMatricula, nota
// Prompt user for these
// Print name of those who've failed the class (nota < 6)
// --- Function mapping
// userPrompt           needs: struct
// filterStudents       needs: each struct      returns: NonPassing (which is: a struct)
// printNonPassing         needs: NonPassing

// Features
int userPrompt();
int validateInput(char* currentValidation, int type);           // Sim, sei que não precisava
int filterStudents(int numOfStudents, int NonPassing[]);
void printNonPassing(int numOfStudents, int NonPassing[], int nonPassingCount);

// --- --- --- --- --- --- --- --- --- --- --- --- Functions

int main() {
    // Find a ((n) efficient) way to run tests through the functions, to pin down problems
    // Begin studying and exploring "testing" and "debugging" and part of coding
    // ...not something you do when things go wrong, but by default - as they always do.
    int numOfStudents = 0;
    int NonPassing[100] = {0};
    int nonPassingCount = 0;
    printf("\n--- Bem vindo ao Programa de cadastro de alunos ---");
    //printf("\nVocê pode voltar - para corrigir um campo - a qualquer momento, digitando \"voltar\" \n");

    numOfStudents = userPrompt(); // Não se esqueça de novo de armazenar o retorno de uma função, para tê-la no escopo e passar pra próxima
    nonPassingCount = filterStudents(numOfStudents, NonPassing);
    printNonPassing(numOfStudents, NonPassing, nonPassingCount); // It would be more efficient to store and trim the list, but printing is enough
    // Self-debugging
}

int userPrompt() {
    // --- Map
    // Prompt how many students to add          // In the future, adapt it to add from the last addition, instead of overwriting from the first position
    // Prompt Loop
    //      nome,   numMatricula,   nota
    //      add all of this to index
    int numOfStudents_prompt = 0;
    char buffer[51];
    int validationResult = 0;

    do {
        printf("\n Quantos alunos você quer adicionar? ");
        // scanf("%d", &numOfStudents_prompt);      // Causou problemas
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;  // Busca primeira occorrência da segunda string na primeira, retorna o valor onde ela é encontrada, buffer[] pega o retorno e substitue por 0
    } while(validateInput(buffer, NUMBER)); // Sim, sei que não precisava
    numOfStudents_prompt = atoi(buffer);
    
    for (int i = 0; i < numOfStudents_prompt; i++) {
        
        do {
            printf("\nNome do %dº aluno: ", (i+1));
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            strcpy(Aluno.nome, buffer);
            // Use validação em um loop... enquanto isso for inválido, ele vai fazer a leitura da seção   
        } while(validateInput(Aluno.nome, NAME));

        do {
            printf("Número da matrícula do %dº aluno: ", (i+1));
            fgets(buffer, sizeof(buffer), stdin); // Para poder verificar digitos, precisa que seja uma string (para loopar pelos caracters)
            buffer[strcspn(buffer, "\n")] = 0;
            Aluno.numMatricula = atoi(buffer); // aoti = ascii to integer
        } while(validateInput(buffer, NUMBER));
        
        do {
            printf("Qual foi a nota de %s? ", Aluno.nome);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            Aluno.nota = atoi(buffer);
        } while(validateInput(buffer, GRADE)); // You made a similar mistake to when using strlen, but here due to the fact vector already decay to pointers

        indexAlunos[i] = Aluno;     // Relacionando index e dado
                                    // Poderia colocar tudo logo no index, e poupar espaço?
                                    // Teste depois ou pergunte a Eleudson
    }
    return numOfStudents_prompt;
}

int filterStudents(int numOfStudents, int NonPassing[100]) {
    int j = 0;
    for(int i = 0; i < numOfStudents; i++) {
        // Map
        // Go through list of students
        // See if they have +6 grades
        // If one has, add their index to the NonPassing vector, and increment a position (so you add the next to another)
        if (indexAlunos[i].nota < 6) { // não passou
            NonPassing[j] = i;
            j++;
        }
    }
    return j;
}

void printNonPassing(int numOfStudents, int NonPassing[], int nonPassingCount) { // Needs this arguments so it doesn't read zeroes
    // Map
    // Go through positions of vector
	// Get the number
	// Read the name, matricula and grade - of the Aluno in that position in the vector
    int coordinate = 0;

    if (nonPassingCount > 0) {
        printf("\n--- Alunos Reprovados ---\n");
    } else {
        printf("\n--- Nenhum aluno foi reprovado ---\n");
    }

    for (int i = 0; i < nonPassingCount; i++) {
        coordinate = NonPassing[i];
        printf("\n");
        printf("\n Aluno: %s", indexAlunos[coordinate].nome);
        printf("\n Número da matrícula: %d", indexAlunos[coordinate].numMatricula);
        printf("\n Média: %d ", indexAlunos[coordinate].nota);
    }
}

// Morphographia
// recebe dois parametros
// 1 do dado que vai validar
// ... Isso cria um problema... Tipos de dados diferentes
//      Isso pode ser resolvido com Enum (ou diretiva de pre-processamento) & "Unions" com "void*"
// 2 para o tipo de validação (senha, nome, número)
int validateInput(char* currentValidation, int type) { // Num programa real precisaria tratar a excessões mais minuciosas
    // Morphographia
    // Se numero; não deve ter letras dentro
    // Se string; loop em todos caracteres; não deve ter números dentro
    //      Use: "isdigit()"
    //      Retorno falso ou verdadeiro cobre ambos casos
    // Veja também se o usuário não digitou "voltar"
    //      Use strcmp
    
    // Go back
    // if (strcmp(currentValidation, "voltar") == 0) {
    //         printf("Voltando...");
    //         return GO_BACK;
    // }

    // Count digits
    int digitCounter = 0;
    for(int i = 0; i < strlen(currentValidation); i++) { // strlen uses the pointer, so don't dereference
        if (isdigit(currentValidation[i])) { // Then it's a number
            digitCounter++;
        } else {
            digitCounter--;
        }
    }

    // Return All digits
    if (type == NUMBER) {
        if (strlen(currentValidation) == digitCounter) {
            return VALID;
        } else {
            printf("\nInput inválido. \nPreencha corretamente o campo. \nNão devem haver números em campos de nomes, ou letras em campos de números\n");
            return INVALID;
        }
    }

    // Return No digits
    if (type == NAME) {
        if (strlen(currentValidation) == (digitCounter*(-1))) {
            return VALID;
        } else {
            printf("\nInput inválido. \nPreencha corretamente o campo. \nNão devem haver números em campos de nomes, ou letras em campos de números\n");
            return INVALID;
        }
    }

    if (type == GRADE) {
        int grade = atoi(currentValidation);
        if (strlen(currentValidation) == digitCounter && grade >= 0 && grade <= 10) {
            return VALID;
        } else {
            printf("\nInput inválido. \nPreencha corretamente o campo. \nNotas devem ser entre 0 e 10.\n");
            return INVALID;
        }
    }
}