#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_STRING 100
#define TAMANHO_TELEFONE 20
#define MAX_TRABALHADORES 100
#define MAX_INCIDENTES 100
#define MAX_TRABALHADORES_ENVOLVIDOS 10

typedef struct {
    int id_empresa;
    char nome_empresa[TAMANHO_STRING];
    char cnpj_empresa[TAMANHO_STRING];
    char tipo_empresa[TAMANHO_STRING];
    char equipamentos_empresa[TAMANHO_STRING];
    char epicos_empresa[TAMANHO_STRING];
} DadosEmpresa;

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
    int id_tecnico;
    char matricula_tecnico[TAMANHO_STRING];
    char nome_tecnico[TAMANHO_STRING];
    char endereco_tecnico[TAMANHO_STRING];
    char telefone_tecnico[TAMANHO_TELEFONE];
    char telefone_emergencial_tecnico[TAMANHO_TELEFONE];
    char formacao_tecnico[TAMANHO_STRING];
    int anos_experiencia;
    char ala_responsabilidade_tecnico[TAMANHO_STRING];
} DadosTecnico;

typedef struct {
    int id_incidente;
    char descricao_incidente[TAMANHO_STRING];
    char data_incidente[TAMANHO_STRING];
    int trabalhadores_envolvidos[MAX_TRABALHADORES_ENVOLVIDOS];
    int quantidade_envolvidos;
} DadosIncidente;

// Protótipos das funções
void inserir_empresa(DadosEmpresa empresas[], int *contagem_empresas, const char *nome, const char *cnpj, const char *tipo, const char *equipamentos, const char *epicos);
void inserir_trabalhador(DadosTrabalhador trabalhadores[], int *contagem_trabalhadores, const char *matricula, const char *nome, const char *endereco, const char *telefone, const char *telefone_emergencial, const char *formacao, const char *cargo, const char *ala, const char *cpf, int horas_trabalho);
void atualizar_trabalhador(DadosTrabalhador trabalhadores[], int contagem_trabalhadores, int id_trabalhador, const char *matricula, const char *nome, const char *endereco, const char *telefone, const char *telefone_emergencial, const char *formacao, const char *cargo, const char *ala, const char *cpf, int horas_trabalho);
void inserir_tecnico(DadosTecnico tecnicos[], int *contagem_tecnicos, const char *matricula, const char *nome, const char *endereco, const char *telefone, const char *telefone_emergencial, const char *formacao, int anos_experiencia, const char *ala_responsabilidade);
void inserir_incidente(DadosIncidente incidentes[], int *contagem_incidentes, const char *descricao, const char *data, int trabalhadores[], int quantidade_envolvidos);
void adicionar_incidente(DadosIncidente incidentes[], int *contagem_incidentes, DadosTrabalhador trabalhadores[], int contagem_trabalhadores);
void listar_trabalhadores(DadosTrabalhador trabalhadores[], int contagem_trabalhadores);
void mostrar_dados_trabalhador(DadosTrabalhador trabalhadores[], int contagem_trabalhadores, int id_trabalhador);

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

void atualizar_trabalhador(DadosTrabalhador trabalhadores[], int contagem_trabalhadores, int id_trabalhador, const char *matricula, const char *nome, const char *endereco, const char *telefone, const char *telefone_emergencial, const char *formacao, const char *cargo, const char *ala, const char *cpf, int horas_trabalho) {
    for (int i = 0; i < contagem_trabalhadores; i++) {
        if (trabalhadores[i].id_trabalhador == id_trabalhador) {
            strncpy(trabalhadores[i].matricula_trabalhador, matricula, TAMANHO_STRING);
            strncpy(trabalhadores[i].nome_trabalhador, nome, TAMANHO_STRING);
            strncpy(trabalhadores[i].endereco_trabalhador, endereco, TAMANHO_STRING);
            strncpy(trabalhadores[i].telefone_trabalhador, telefone, TAMANHO_TELEFONE);
            strncpy(trabalhadores[i].telefone_emergencial_trabalhador, telefone_emergencial, TAMANHO_TELEFONE);
            strncpy(trabalhadores[i].formacao_trabalhador, formacao, TAMANHO_STRING);
            strncpy(trabalhadores[i].cargo_trabalhador, cargo, TAMANHO_STRING);
            strncpy(trabalhadores[i].ala_trabalhador, ala, TAMANHO_STRING);
            strncpy(trabalhadores[i].cpf_trabalhador, cpf, TAMANHO_STRING);
            trabalhadores[i].horas_trabalho = horas_trabalho;
            printf("Dados atualizados com sucesso.\n");
            return;
        }
    }
    printf("Trabalhador com ID %d não encontrado.\n", id_trabalhador);
}

void inserir_tecnico(DadosTecnico tecnicos[], int *contagem_tecnicos, const char *matricula, const char *nome, const char *endereco, const char *telefone, const char *telefone_emergencial, const char *formacao, int anos_experiencia, const char *ala_responsabilidade) {
    DadosTecnico novo_tecnico;
    novo_tecnico.id_tecnico = *contagem_tecnicos + 1;
    strncpy(novo_tecnico.matricula_tecnico, matricula, TAMANHO_STRING);
    strncpy(novo_tecnico.nome_tecnico, nome, TAMANHO_STRING);
    strncpy(novo_tecnico.endereco_tecnico, endereco, TAMANHO_STRING);
    strncpy(novo_tecnico.telefone_tecnico, telefone, TAMANHO_TELEFONE);
    strncpy(novo_tecnico.telefone_emergencial_tecnico, telefone_emergencial, TAMANHO_TELEFONE);
    strncpy(novo_tecnico.formacao_tecnico, formacao, TAMANHO_STRING);
    novo_tecnico.anos_experiencia = anos_experiencia;
    strncpy(novo_tecnico.ala_responsabilidade_tecnico, ala_responsabilidade, TAMANHO_STRING);

    tecnicos[*contagem_tecnicos] = novo_tecnico;
    (*contagem_tecnicos)++;
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
    descricao[strcspn(descricao, "\n")] = '\0'; // Remove newline

    printf("Data do incidente (DD/MM/AAAA): ");
    fgets(data, TAMANHO_STRING, stdin);
    data[strcspn(data, "\n")] = '\0'; // Remove newline

    printf("Quantidade de trabalhadores envolvidos: ");
    scanf("%d", &quantidade_envolvidos);
    getchar(); // Limpa o buffer

    if (quantidade_envolvidos > MAX_TRABALHADORES_ENVOLVIDOS) {
        printf("Número de trabalhadores envolvidos excede o limite permitido.\n");
        return;
    }

    printf("IDs dos trabalhadores envolvidos (separados por espaço): ");
    for (int i = 0; i < quantidade_envolvidos; i++) {
        scanf("%d", &trabalhadores_envolvidos[i]);
    }
    getchar(); // Limpa o buffer

    inserir_incidente(incidentes, contagem_incidentes, descricao, data, trabalhadores_envolvidos, quantidade_envolvidos);
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

int main() {
    DadosEmpresa empresas[MAX_TRABALHADORES];
    DadosTrabalhador trabalhadores[MAX_TRABALHADORES];
    DadosTecnico tecnicos[MAX_TRABALHADORES];
    DadosIncidente incidentes[MAX_INCIDENTES];

    int contagem_empresas = 0;
    int contagem_trabalhadores = 0;
    int contagem_tecnicos = 0;
    int contagem_incidentes = 0;

    // Exemplo de uso das funções
    inserir_trabalhador(trabalhadores, &contagem_trabalhadores, "123", "João Silva", "Rua A, 123", "1234567890", "0987654321", "Engenheiro", "Analista", "Ala 1", "12345678901", 40);
    listar_trabalhadores(trabalhadores, contagem_trabalhadores);

    adicionar_incidente(incidentes, &contagem_incidentes, trabalhadores, contagem_trabalhadores);

    return 0;
}
