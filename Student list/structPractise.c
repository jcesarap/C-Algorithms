#include <stdio.h>
#include <locale.h>

// --- Estrutura para um Endereço Postal ---
typedef struct {
    char rua[40];
    unsigned int numero;
    char cidade[40];
} Endereco_estrutura;

// --- Estrutura para informações completas de uma pessoa, aninhando o endereço ---
typedef struct {
    char nome[40];
    char email[40];
    unsigned int idade;
    Endereco_estrutura endereco_campo; // Estrutura aninhada
    // O segundo nome de endereço é a declaração de uma variável, em PessoalInfo, para referenciar a outra struct
} PessoaInfo;


// --- Uma estrutura mais simples, usada para outra demonstração ---
typedef struct {
    char nome[40];
    unsigned int idade;
} Cliente;

void demonstrarPonteiros();
void cadastrarPessoaCompleta();

int main() {
    // Agora vamos chamar as funções para ver o código em ação.
    demonstrarPonteiros();

    // Uma pequena separação para clareza na saída do terminal
    printf("\n--------------------------------------\n");

    cadastrarPessoaCompleta();

    return 0; // É uma boa prática a função main retornar 0 em caso de sucesso.
}


// ======================================================
// --- Definições das Funções ---
// ======================================================

/**
 * @brief Demonstra o uso de ponteiros para acessar membros de uma struct.
 * Esta função agora usa o tipo 'Cliente'.
 */
void demonstrarPonteiros() {
    // Declara uma variável local do tipo Cliente.
    Cliente cliente_local;
    
    // Declara um ponteiro que apontará para uma variável do tipo Cliente.
    Cliente *p_cliente;

    printf("--- Demonstração de Ponteiros ---\n");
    printf("Digite o nome do cliente: ");
    // Limita a entrada a 39 caracteres para evitar buffer overflow.
    // O espaço restante é para o caractere nulo '\0'.
    scanf("%39s", cliente_local.nome);

    printf("Digite a idade do cliente: ");
    // O formato %u é para 'unsigned int'.
    scanf("%u", &cliente_local.idade);

    // O ponteiro 'p_cliente' agora guarda o endereço de memória da variável 'cliente_local'.
    p_cliente = &cliente_local;

    // Acessamos os dados da struct através do ponteiro usando o operador seta (->).
    printf("\nDados acessados via ponteiro: %s tem %u anos.\n", p_cliente->nome, p_cliente->idade);
}


/**
 * @brief Demonstra o cadastro de dados em uma struct aninhada.
 * Esta função agora usa o tipo 'PessoaInfo'.
 */
void cadastrarPessoaCompleta() {
    // Declara uma variável local do tipo PessoaInfo.
    PessoaInfo pessoa;

    printf("\n--- Cadastro de Endereço (Estrutura Aninhada) ---\n");
    printf("Digite o nome da pessoa: ");
    scanf("%39s", pessoa.nome);

    printf("Rua: ");



    //                  PARA ACESSAR OS CAMPOS DA SUB-STRUCT, É SÓ ISSO



    scanf("%39s", pessoa.endereco_campo.rua); 

    printf("Número: ");
    scanf("%u", &pessoa.endereco_campo.numero);

    printf("Cidade: ");
    scanf("%39s", pessoa.endereco_campo.cidade);

    // Imprime os dados coletados para verificar se tudo foi armazenado corretamente.
    printf("\n--- Dados Cadastrados ---\n");
    printf("Nome: %s\n", pessoa.nome);
    printf("Endereço: Rua %s, Nº %u, Cidade: %s\n", pessoa.endereco_campo.rua, pessoa.endereco_campo.numero, pessoa.endereco_campo.cidade);
}
