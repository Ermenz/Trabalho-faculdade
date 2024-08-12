#include <stdio.h>
#include <string.h>

#define TAMANHO_STRING 100
#define TAMANHO_TELEFONE 20
#define MAX_TRABALHADORES 100
#define MAX_INCIDENTES 100
#define MAX_TRABALHADORES_ENVOLVIDOS 10

typedef struct {
    int id_trabalhador;
    char matricula_trabalhador[TAMANHO_STRING];
    char nome_trabalhador[TAMANHO_STRING];
    char endereco_trabalhador[TAMANHO_STRING];
    char telefone_trabalhador[TAMANHO_TELEFONE];
    char telefone_emergencial_trabalhador[TAMANHO_TELEFONE];
    char formacao_trabalhador[TAMANHO_STRING];
    char cargo_trabalhador[TAMANHO_STRING];
    char ala_trabalhador[TAMANHO_STRING];
    char cpf_trabalhador[TAMANHO_STRING];
    int horas_trabalho;
} DadosTrabalhador;

typedef struct {
    int id_incidente;
    char descricao_incidente[TAMANHO_STRING];
    char data_incidente[TAMANHO_STRING];
    int trabalhadores_envolvidos[MAX_TRABALHADORES_ENVOLVIDOS];
    int quantidade_envolvidos;
} DadosIncidente;

// Protótipos das funções
void inserir_trabalhador(DadosTrabalhador trabalhadores[], int *contagem_trabalhadores, const char *matricula, const char *nome, const char *endereco, const char *telefone, const char *telefone_emergencial, const char *formacao, const char *cargo, const char *ala, const char *cpf, int horas_trabalho);
void listar_trabalhadores(DadosTrabalhador trabalhadores[], int contagem_trabalhadores);
void mostrar_dados_trabalhador(DadosTrabalhador trabalhadores[], int contagem_trabalhadores, int id_trabalhador);
void inserir_incidente(DadosIncidente incidentes[], int *contagem_incidentes, const char *descricao, const char *data, int trabalhadores[], int quantidade_envolvidos);
void adicionar_incidente(DadosIncidente incidentes[], int *contagem_incidentes, DadosTrabalhador trabalhadores[], int contagem_trabalhadores);
void listar_incidentes(DadosIncidente incidentes[], int contagem_incidentes);

// Implementação das funções
void inserir_trabalhador(DadosTrabalhador trabalhadores[], int *contagem_trabalhadores, const char *matricula, const char *nome, const char *endereco, const char *telefone, const char *telefone_emergencial, const char *formacao, const char *cargo, const char *ala, const char *cpf, int horas_trabalho) {
    DadosTrabalhador novo_trabalhador;
    novo_trabalhador.id_trabalhador = *contagem_trabalhadores + 1;
    strncpy(novo_trabalhador.matricula_trabalhador, matricula, TAMANHO_STRING);
    strncpy(novo_trabalhador.nome_trabalhador, nome, TAMANHO_STRING);
    strncpy(novo_trabalhador.endereco_trabalhador, endereco, TAMANHO_STRING);
    strncpy(novo_trabalhador.telefone_trabalhador, telefone, TAMANHO_TELEFONE);
    strncpy(novo_trabalhador.telefone_emergencial_trabalhador, telefone_emergencial, TAMANHO_TELEFONE);
    strncpy(novo_trabalhador.formacao_trabalhador, formacao, TAMANHO_STRING);
    strncpy(novo_trabalhador.cargo_trabalhador, cargo, TAMANHO_STRING);
    strncpy(novo_trabalhador.ala_trabalhador, ala, TAMANHO_STRING);
    strncpy(novo_trabalhador.cpf_trabalhador, cpf, TAMANHO_STRING);
    novo_trabalhador.horas_trabalho = horas_trabalho;

    trabalhadores[*contagem_trabalhadores] = novo_trabalhador;
    (*contagem_trabalhadores)++;
}

void listar_trabalhadores(DadosTrabalhador trabalhadores[], int contagem_trabalhadores) {
    for (int i = 0; i < contagem_trabalhadores; i++) {
        printf("ID: %d\n", trabalhadores[i].id_trabalhador);
        printf("Matrícula: %s\n", trabalhadores[i].matricula_trabalhador);
        printf("Nome: %s\n", trabalhadores[i].nome_trabalhador);
        printf("Endereço: %s\n", trabalhadores[i].endereco_trabalhador);
        printf("Telefone: %s\n", trabalhadores[i].telefone_trabalhador);
        printf("Telefone Emergencial: %s\n", trabalhadores[i].telefone_emergencial_trabalhador);
        printf("Formação: %s\n", trabalhadores[i].formacao_trabalhador);
        printf("Cargo: %s\n", trabalhadores[i].cargo_trabalhador);
        printf("Ala: %s\n", trabalhadores[i].ala_trabalhador);
        printf("CPF: %s\n", trabalhadores[i].cpf_trabalhador);
        printf("Horas de Trabalho: %d\n", trabalhadores[i].horas_trabalho);
        printf("-----\n");
    }
}

void mostrar_dados_trabalhador(DadosTrabalhador trabalhadores[], int contagem_trabalhadores, int id_trabalhador) {
    for (int i = 0; i < contagem_trabalhadores; i++) {
        if (trabalhadores[i].id_trabalhador == id_trabalhador) {
            printf("ID: %d\n", trabalhadores[i].id_trabalhador);
            printf("Matrícula: %s\n", trabalhadores[i].matricula_trabalhador);
            printf("Nome: %s\n", trabalhadores[i].nome_trabalhador);
            printf("Endereço: %s\n", trabalhadores[i].endereco_trabalhador);
            printf("Telefone: %s\n", trabalhadores[i].telefone_trabalhador);
            printf("Telefone Emergencial: %s\n", trabalhadores[i].telefone_emergencial_trabalhador);
            printf("Formação: %s\n", trabalhadores[i].formacao_trabalhador);
            printf("Cargo: %s\n", trabalhadores[i].cargo_trabalhador);
            printf("Ala: %s\n", trabalhadores[i].ala_trabalhador);
            printf("CPF: %s\n", trabalhadores[i].cpf_trabalhador);
            printf("Horas de Trabalho: %d\n", trabalhadores[i].horas_trabalho);
            printf("-----\n");
            return;
        }
    }
    printf("Trabalhador com ID %d não encontrado.\n", id_trabalhador);
}

void inserir_incidente(DadosIncidente incidentes[], int *contagem_incidentes, const char *descricao, const char *data, int trabalhadores[], int quantidade_envolvidos) {
    DadosIncidente novo_incidente;
    novo_incidente.id_incidente = *contagem_incidentes + 1;
    strncpy(novo_incidente.descricao_incidente, descricao, TAMANHO_STRING);
    strncpy(novo_incidente.data_incidente, data, TAMANHO_STRING);
    novo_incidente.quantidade_envolvidos = quantidade_envolvidos;
    for (int i = 0; i < quantidade_envolvidos; i++) {
        novo_incidente.trabalhadores_envolvidos[i] = trabalhadores[i];
    }

    incidentes[*contagem_incidentes] = novo_incidente;
    (*contagem_incidentes)++;
}

void adicionar_incidente(DadosIncidente incidentes[], int *contagem_incidentes, DadosTrabalhador trabalhadores[], int contagem_trabalhadores) {
    DadosIncidente novo_incidente;
    char descricao[TAMANHO_STRING];
    char data[TAMANHO_STRING];
    int trabalhadores_envolvidos[MAX_TRABALHADORES_ENVOLVIDOS];
    int quantidade_envolvidos;

    printf("Descrição do incidente: ");
    fgets(descricao, TAMANHO_STRING, stdin);
    descricao[strcspn(descricao, "\n")] = '\0';

    printf("Data do incidente (DD/MM/AAAA): ");
    fgets(data, TAMANHO_STRING, stdin);
    data[strcspn(data, "\n")] = '\0';

    printf("Quantidade de trabalhadores envolvidos: ");
    scanf("%d", &quantidade_envolvidos);
    getchar();

    if (quantidade_envolvidos > MAX_TRABALHADORES_ENVOLVIDOS) {
        printf("Número de trabalhadores envolvidos excede o limite permitido.\n");
        return;
    }

    printf("IDs dos trabalhadores envolvidos (separados por espaço): ");
    for (int i = 0; i < quantidade_envolvidos; i++) {
        scanf("%d", &trabalhadores_envolvidos[i]);
    }
    getchar();

    inserir_incidente(incidentes, contagem_incidentes, descricao, data, trabalhadores_envolvidos, quantidade_envolvidos);
}

void listar_incidentes(DadosIncidente incidentes[], int contagem_incidentes) {
    for (int i = 0; i < contagem_incidentes; i++) {
        printf("ID: %d\n", incidentes[i].id_incidente);
        printf("Descrição: %s\n", incidentes[i].descricao_incidente);
        printf("Data: %s\n", incidentes[i].data_incidente);
        printf("Trabalhadores envolvidos: ");
        for (int j = 0; j < incidentes[i].quantidade_envolvidos; j++) {
            printf("%d ", incidentes[i].trabalhadores_envolvidos[j]);
        }
        printf("\n-----\n");
    }
}

int main() {
    DadosTrabalhador trabalhadores[MAX_TRABALHADORES];
    DadosIncidente incidentes[MAX_INCIDENTES];
    int contagem_trabalhadores = 0;
    int contagem_incidentes = 0;

    int opcao;
    do {
        printf("Menu:\n");
        printf("1. Inserir trabalhador\n");
        printf("2. Listar trabalhadores\n");
        printf("3. Adicionar incidente\n");
        printf("4. Mostrar registros de incidentes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                {
                    char matricula[TAMANHO_STRING];
                    char nome[TAMANHO_STRING];
                    char endereco[TAMANHO_STRING];
                    char telefone[TAMANHO_TELEFONE];
                    char telefone_emergencial[TAMANHO_TELEFONE];
                    char formacao[TAMANHO_STRING];
                    char cargo[TAMANHO_STRING];
                    char ala[TAMANHO_STRING];
                    char cpf[TAMANHO_STRING];
                    int horas_trabalho;

                    printf("Matrícula: ");
                    fgets(matricula, TAMANHO_STRING, stdin);
                    matricula[strcspn(matricula, "\n")] = '\0';

                    printf("Nome: ");
                    fgets(nome, TAMANHO_STRING, stdin);
                    nome[strcspn(nome, "\n")] = '\0';

                    printf("Endereço: ");
                    fgets(endereco, TAMANHO_STRING, stdin);
                    endereco[strcspn(endereco, "\n")] = '\0';

                    printf("Telefone: ");
                    fgets(telefone, TAMANHO_TELEFONE, stdin);
                    telefone[strcspn(telefone, "\n")] = '\0';

                    printf("Telefone Emergencial: ");
                    fgets(telefone_emergencial, TAMANHO_TELEFONE, stdin);
                    telefone_emergencial[strcspn(telefone_emergencial, "\n")] = '\0';

                    printf("Formação: ");
                    fgets(formacao, TAMANHO_STRING, stdin);
                    formacao[strcspn(formacao, "\n")] = '\0';

                    printf("Cargo: ");
                    fgets(cargo, TAMANHO_STRING, stdin);
                    cargo[strcspn(cargo, "\n")] = '\0';

                    printf("Ala: ");
                    fgets(ala, TAMANHO_STRING, stdin);
                    ala[strcspn(ala, "\n")] = '\0';

                    printf("CPF: ");
                    fgets(cpf, TAMANHO_STRING, stdin);
                    cpf[strcspn(cpf, "\n")] = '\0';

                    printf("Horas de Trabalho: ");
                    scanf("%d", &horas_trabalho);
                    getchar();

                    inserir_trabalhador(trabalhadores, &contagem_trabalhadores, matricula, nome, endereco, telefone, telefone_emergencial, formacao, cargo, ala, cpf, horas_trabalho);
                }
                break;
            case 2:
                listar_trabalhadores(trabalhadores, contagem_trabalhadores);
                break;
            case 3:
                adicionar_incidente(incidentes, &contagem_incidentes, trabalhadores, contagem_trabalhadores);
                break;
            case 4:
                listar_incidentes(incidentes, contagem_incidentes);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
