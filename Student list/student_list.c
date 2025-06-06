#include <stdio.h>
#include <string.h>

// --- Requirements
// Aluno struct
// with nome, numMatricula e nota
// Note: Using typedef is the same thing as this, but acting as/giving an alias to the datatype

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
void printPassing(void);
// declare passing;

int main() {
    userPrompt();
    filterStudents(passing);
    printPassing();
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