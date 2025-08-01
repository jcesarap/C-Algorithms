#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Fazer mais que o necessário no problema anterior ajudou a resolver esse rápido reutilizando lógica/funções
// E a escrever o fluxo de pensamento num arquivo separado

#define SECONDS 59
#define MINUTES 59
#define SECONDS_AND_MINUTES 59
#define HOURS 23
#define VALID 1
#define INVALID 0

typedef struct { // New data type grouping multiple variables
    int hora;
    int minuto;
    int segundo;
} Horario;

Horario horarioInstance;

void readTime(void);
int validateInput(char* inputString, int type);
int validateTime(Horario* pointerToTime);
void printTime(Horario horarioInstance);

// Horario Struct
// horas, minutos, segundos

// Read/Input

// validation
// gets Horario
//  1 if valid
//  0 if invalid

// print
// Horario in-words

void main() {
    Horario* pointerToTime = &horarioInstance;

    printf("\n --- Bem-vindo ao programa de analíse de hora ---");
    printf("\n Ele verifica o horario ao preencher cada campo, e depois também");

    readTime();
    validateTime(pointerToTime);
    printTime(horarioInstance);
}

void readTime() {
    char buffer[50];

    //do {
        printf("\nEscolha uma hora (Entre 0-23): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;
    //} while(!validateInput(buffer, HOURS));
    horarioInstance.hora = atoi(buffer);

    //do {
        printf("Escolha um minuto (Entre 0-59): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;
    //} while(!validateInput(buffer, MINUTES));
    horarioInstance.minuto = atoi(buffer);

    //do {
        printf("Escolha um segundo (Entre 0-59): ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;
    //} while(!validateInput(buffer, SECONDS));
    horarioInstance.segundo = atoi(buffer);
}

int validateInput(char* currentValidation, int type) {
    int digitCounter = 0;
    
    for(int i = 0; i < strlen(currentValidation); i++) {
        if (isdigit(currentValidation[i])) digitCounter++;
        else digitCounter--;
    }

    int convertido = atoi(currentValidation);

    if (type == HOURS) {
        if (strlen(currentValidation) == digitCounter && convertido >= 0 && convertido <= 23) {
            return VALID;
        } else {
            printf("\nInput inválido. \nPreencha corretamente o campo (0-23). \n");
            return INVALID;
        }
    }

    if (type == SECONDS_AND_MINUTES) {
        if (strlen(currentValidation) == digitCounter && convertido >= 0 && convertido <= 59) {
            return VALID;
        } else {
            printf("\nInput inválido. \nPreencha corretamente o campo (0-59).\n");
            return INVALID;
        }
    }

    return INVALID;
}

// Como dar valores a função validateTime
// Entregue a struct através de ponteiro
// Analise os valores
// Retorne
int validateTime(Horario* horario) {
    if (horario->hora < 0 || horario->hora > 23) {
        printf("\nHora inválida\n");
        return INVALID;
    }
    if (horario->minuto < 0 || horario->minuto > 59) {
        printf("\nMinuto inválido\n");
        return INVALID;
    }
    if (horario->segundo < 0 || horario->segundo > 59) {
        printf("\nSegundo inválido\n");
        return INVALID;
    }
    return VALID;
}

void printTime(Horario horarioInstance) {
    const char* numeros[60] = {
        "zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove", "vinte", "vinte e um", "vinte e dois", "vinte e três", "vinte e quatro", "vinte e cinco", "vinte e seis", "vinte e sete", "vinte e oito", "vinte e nove", "trinta", "trinta e um", "trinta e dois", "trinta e três", "trinta e quatro", "trinta e cinco", "trinta e seis", "trinta e sete", "trinta e oito", "trinta e nove", "quarenta", "quarenta e um", "quarenta e dois", "quarenta e três", "quarenta e quatro", "quarenta e cinco", "quarenta e seis", "quarenta e sete", "quarenta e oito", "quarenta e nove", "cinquenta", "cinquenta e um", "cinquenta e dois", "cinquenta e três", "cinquenta e quatro", "cinquenta e cinco", "cinquenta e seis", "cinquenta e sete", "cinquenta e oito", "cinquenta e nove"
    };

    if (horarioInstance.hora == 1) {
        printf("É uma hora");
    } else {
        printf("São %s horas", numeros[horarioInstance.hora]);
    }

    if (horarioInstance.minuto > 0) {
        if (horarioInstance.minuto == 1) {
            printf(" e um minuto");
        } else {
            printf(" e %s minutos", numeros[horarioInstance.minuto]);
        }
    }

    if (horarioInstance.segundo > 0) {
        if (horarioInstance.segundo == 1) {
            printf(" e um segundo");
        } else {
            printf(" e %s segundos", numeros[horarioInstance.segundo]);
        }
    }
}