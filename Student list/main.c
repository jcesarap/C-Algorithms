#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Notas pessoais
//      Excesso de anotações de pesquisa foi documentado em "College/Estructured Programming/Advanced Concepts"
//      Nunca fazer (novamente) a morphographia no mesmo arquvivo do código ("Sketch" file serves that purpose)

#define NUMBER 0
#define NAME 1

// Using typedef is the same thing as this, but acting as/giving an alias to the datatype
typedef struct { // New data type grouping multiple variables
    char nome[50];
    int numMatricula;
    int nota;
} AlunoStruct;

AlunoStruct Aluno;
AlunoStruct indexAlunos [100];
// Declara um 

// --- Requirements
// Aluno struct; with nome, numMatricula e nota
// On main, create vectors: index, name, numMatricula, nota
// Prompt user for these
// Print name of those who've failed the class (nota < 6)
// --- Function mapping
// userPrompt           needs: struct
// filterStudents       needs: each struct      returns: passing (which is: a struct)
// printPassing         needs: passing

// Features
void userPrompt(void);
int filterStudents();
void validateInput(void*, int type);
void printPassing();
// Debugging
void test_userPrompt();
void test_filterStudents();
void test_printPassing();

// --- --- --- --- --- --- --- --- --- --- --- --- Functions

int main() {
    // Usando windows esses dias...
    setlocale(LC_ALL, "");
    setlocale(LC_CTYPE, "");
    // Find a ((n) efficient) way to run tests through the functions, to pin down problems
    // Begin studying and exploring "testing" and "debugging" and part of coding
    // ...not something you do when things go wrong, but by default - as they always do.

    userPrompt();
    test_userPrompt();

    filterStudents();
    test_filterStudents();

    printPassing(); // It would be more efficient to store and trim the list, but printing is enough
    // Self-debugging
}

// Morphographia
// recebe dois parametros
// 1 do dado que vai validar
// ... Isso cria um problema... Tipos de dados diferentes
//      Isso pode ser resolvido com Enum (ou diretiva de pre-processamento) & "Unions" com "void*"
// 2 para o tipo de validação (senha, nome, número)
void validateInput(void*, int type) { // Num programa real precisaria tratar a excessões mais minuciosas
    // Morphographia
    // Se numero; não deve ter letras dentro
    // Se string; loop em todos caracteres; não deve ter números dentro
    //      Use: "isdigit()"
    //      Retorno falso ou verdadeiro cobre ambos casos
    // Veja também se o usuário não digitou "voltar"
    //      Use strcmp
    if (type == NUMBER) {
        // Cast void* to int

    } else if (type == NAME) {
        // Cast void* to str

    }
}

void userPrompt() {
    // --- Map
    // Prompt how many students to add          // In the future, adapt it to add from the last addition, instead of overwriting from the first position
    // Prompt Loop
    //      nome,   numMatricula,   nota
    //      add all of this to index
    int numOfStudents = 0;
    printf("\n");
    printf("Quantos alunos você quer adicionar? ");
    scanf("%d", &numOfStudents);
    for (int i = 0; i < numOfStudents; i++) {
        printf("        (Você pode voltar a qualquer momento, digitando \"voltar\" num campo) \n");
        printf("Nome do %dº aluno: ", i);
        scanf("%c", &Aluno.nome);
        validateInput(*Aluno.nome, NUMBER);

        printf("Número da matrícula de %d: ", Aluno.numMatricula);
        scanf("%d", &Aluno.numMatricula);
        validateInput(Aluno.numMatricula, NAME);

        printf("Qual foi a nota de %s? ", Aluno.nome);
        scanf("%d", &Aluno.nota);
        validateInput(Aluno.nota, NUMBER);
    }
}

int filterStudents() {
    
}

void printPassing() {
    // --- Map
}

// Debugging

void test_userPrompt() {

}
void test_filterStudents() {

}
void test_printPassing() {

}