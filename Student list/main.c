#include <stdio.h>
#include <string.h>

// PENDING NOTES IN SKETCH








// Gosto de manter minhas anotações em markdown, mas quando se trata de código
// Gosto de manter como comentários, no meio do código e em seções dedicadas
// Por isso a estrutura um pouco "bloated" - como é um código de estudo


// --- Requirements
// Aluno struct
// with nome, numMatricula e nota
// Note: Using typedef is the same thing as this, but acting as/giving an alias to the datatype

#define NUMBER 0
#define NAME 1

struct PassingStruct {
    char passing_nome[50];
    int passing_numMatricula;
    int passing_nota;
};

struct Aluno { // New data type grouping multiple variables
    char nome[50];
    int numMatricula;
    int nota;
    struct PassingStruct passingList; // nests the struct as a list inside Aluno
    // To access PassingStruct fields: pessoaVariable.endereco.rua, pessoaVariable.endereco.numero...
};

struct Aluno indexAlunos[100]; // Same as adding only the last item in the end of the struct definition

// --- Requirements
// On main, create vectors: index, name, numMatricula, nota
// Prompt user for these
// Print name of those who've failed the class (nota < 6)
// --- Function mapping
// userPrompt           needs: struct
// filterStudents       needs: each struct      returns: passing (which is: a struct)
// printPassing         needs: passing

void userPrompt(void);
int filterStudents(int passing);
int validateInput(void*, int type);
void printPassing();


// declare passing;

// --- --- --- --- --- --- --- --- --- --- --- --- Functions

int main() {
    // Find a ((n) efficient) way to run tests through the functions, to pin down problems
    // Begin studying and exploring "testing" and "debugging" and part of coding
    // ...not something you do when things go wrong, but by default - as they always do.
    userPrompt();
    filterStudents(passing);
    printPassing();
}

// Crie função que valída input
// recebe dois parametros
// 1 do dado que vai validar
// ... Isso cria um problema... Tipos de dados diferentes
// 2 para o tipo de validação (senha, nome, número)

void validadeInput(void*, int type) {
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
        scanf("%s", &Aluno.nome[50]);
        if (Aluno.nome == "voltar" || Aluno.numMatricula == "voltar" || Aluno.nota == "voltar") {
            i--;
            continue; // Skips the rest of the iteration
        }
        printf("Número da matrícula de %d: ", Aluno.numMatricula);
        scanf("%d", &Aluno.numMatricula);
        if (Aluno.nome == "voltar" || Aluno.numMatricula == "voltar" || Aluno.nota == "voltar") {
            i--;
            continue;
        }
        printf("Qual foi a nota de %s? ", Aluno.nome);
        scanf("%d", &Aluno.nota);
        if (Aluno.nome == "voltar" || Aluno.numMatricula == "voltar" || Aluno.nota == "voltar") {
            i--;
            continue;
        }
        // Num programa real precisaria tratar a excessão de dados impróprios - como adicionando números nas strings de nome, ou o contrário
    }
}

int filterStudents() {
    // --- Map
    return passing;
}

void printPassing() {
    // --- Map
}