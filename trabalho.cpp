#include <stdio.h>
#include <string.h>

#define tamanhoVariavel 100
#define tamanhoTelefone 20
#define maxTrabalhadores 100
#define maxIncidentes 100
#define maxTrabalhadoresEnvolvidos 10

typedef struct {
    int idTrabalhador;
    char matriculaTrabalhador[tamanhoVariavel];
    char nomeTrabalhador[tamanhoVariavel];
    char enderecoTrabalhador[tamanhoVariavel];
    char telefoneTrabalhador[tamanhoTelefone];
    char telefoneEmergencialTrabalhador[tamanhoTelefone];
    char formacaoTrabalhador[tamanhoVariavel];
    char cargoTrabalhador[tamanhoVariavel];
    char alaTrabalhador[tamanhoVariavel];
    char cpfTrabalhador[tamanhoVariavel];
    int horasTrabalho;
} DadosTrabalhador;

typedef struct {
    int idIncidente;
    char descricaoIncidente[tamanhoVariavel];
    char dataIncidente[tamanhoVariavel];
    int trabalhadoresEnvolvidos[maxTrabalhadoresEnvolvidos];
    int quantidadeEnvolvidos;
} DadosIncidente;

void inserirTrabalhador(DadosTrabalhador trabalhadores[], int *contagemTrabalhadores, const char *matricula, const char *nome, const char *endereco, const char *telefone, const char *telefoneEmergencial, const char *formacao, const char *cargo, const char *ala, const char *cpf, int horasTrabalho);
void listarTrabalhadores(const DadosTrabalhador trabalhadores[], int contagemTrabalhadores);
void inserirIncidente(DadosIncidente incidentes[], int *contagemIncidentes, const char *descricao, const char *data, const int trabalhadores[], int quantidadeEnvolvidos);
void adicionarIncidente(DadosIncidente incidentes[], int *contagemIncidentes, const DadosTrabalhador trabalhadores[], int contagemTrabalhadores);
void listarIncidentes(const DadosIncidente incidentes[], int contagemIncidentes);

void inserirTrabalhador(DadosTrabalhador trabalhadores[], int *contagemTrabalhadores, const char *matricula, const char *nome, const char *endereco, const char *telefone, const char *telefoneEmergencial, const char *formacao, const char *cargo, const char *ala, const char *cpf, int horasTrabalho) {
    if (*contagemTrabalhadores >= maxTrabalhadores) {
        printf("Número máximo de trabalhadores atingido.\n");
        return;
    }

    DadosTrabalhador novoTrabalhador;
    novoTrabalhador.idTrabalhador = *contagemTrabalhadores + 1;
    strncpy(novoTrabalhador.matriculaTrabalhador, matricula, tamanhoVariavel - 1);
    novoTrabalhador.matriculaTrabalhador[tamanhoVariavel - 1] = '\0';
    strncpy(novoTrabalhador.nomeTrabalhador, nome, tamanhoVariavel - 1);
    novoTrabalhador.nomeTrabalhador[tamanhoVariavel - 1] = '\0';
    strncpy(novoTrabalhador.enderecoTrabalhador, endereco, tamanhoVariavel - 1);
    novoTrabalhador.enderecoTrabalhador[tamanhoVariavel - 1] = '\0';
    strncpy(novoTrabalhador.telefoneTrabalhador, telefone, tamanhoTelefone - 1);
    novoTrabalhador.telefoneTrabalhador[tamanhoTelefone - 1] = '\0';
    strncpy(novoTrabalhador.telefoneEmergencialTrabalhador, telefoneEmergencial, tamanhoTelefone - 1);
    novoTrabalhador.telefoneEmergencialTrabalhador[tamanhoTelefone - 1] = '\0';
    strncpy(novoTrabalhador.formacaoTrabalhador, formacao, tamanhoVariavel - 1);
    novoTrabalhador.formacaoTrabalhador[tamanhoVariavel - 1] = '\0';
    strncpy(novoTrabalhador.cargoTrabalhador, cargo, tamanhoVariavel - 1);
    novoTrabalhador.cargoTrabalhador[tamanhoVariavel - 1] = '\0';
    strncpy(novoTrabalhador.alaTrabalhador, ala, tamanhoVariavel - 1);
    novoTrabalhador.alaTrabalhador[tamanhoVariavel - 1] = '\0';
    strncpy(novoTrabalhador.cpfTrabalhador, cpf, tamanhoVariavel - 1);
    novoTrabalhador.cpfTrabalhador[tamanhoVariavel - 1] = '\0';
    novoTrabalhador.horasTrabalho = horasTrabalho;

    trabalhadores[*contagemTrabalhadores] = novoTrabalhador;
    (*contagemTrabalhadores)++;
}

void listarTrabalhadores(const DadosTrabalhador trabalhadores[], int contagemTrabalhadores) {
    if (contagemTrabalhadores == 0) {
        printf("Nenhum trabalhador cadastrado.\n");
        return;
    }

    for (int i = 0; i < contagemTrabalhadores; i++) {
        printf("ID: %d\n", trabalhadores[i].idTrabalhador);
        printf("Matrícula: %s\n", trabalhadores[i].matriculaTrabalhador);
        printf("Nome: %s\n", trabalhadores[i].nomeTrabalhador);
        printf("Endereço: %s\n", trabalhadores[i].enderecoTrabalhador);
        printf("Telefone: %s\n", trabalhadores[i].telefoneTrabalhador);
        printf("Telefone Emergencial: %s\n", trabalhadores[i].telefoneEmergencialTrabalhador);
        printf("Formação: %s\n", trabalhadores[i].formacaoTrabalhador);
        printf("Cargo: %s\n", trabalhadores[i].cargoTrabalhador);
        printf("Ala: %s\n", trabalhadores[i].alaTrabalhador);
        printf("CPF: %s\n", trabalhadores[i].cpfTrabalhador);
        printf("Horas de Trabalho: %d\n", trabalhadores[i].horasTrabalho);
        printf("-----\n");
    }
}

void inserirIncidente(DadosIncidente incidentes[], int *contagemIncidentes, const char *descricao, const char *data, const int trabalhadores[], int quantidadeEnvolvidos) {
    if (*contagemIncidentes >= maxIncidentes) {
        printf("Número máximo de incidentes atingido.\n");
        return;
    }

    DadosIncidente novoIncidente;
    novoIncidente.idIncidente = *contagemIncidentes + 1;

    strncpy(novoIncidente.descricaoIncidente, descricao, tamanhoVariavel - 1);
    novoIncidente.descricaoIncidente[tamanhoVariavel - 1] = '\0';

    strncpy(novoIncidente.dataIncidente, data, tamanhoVariavel - 1);
    novoIncidente.dataIncidente[tamanhoVariavel - 1] = '\0';

    for (int i = 0; i < quantidadeEnvolvidos; i++) {
        novoIncidente.trabalhadoresEnvolvidos[i] = trabalhadores[i];
    }
    novoIncidente.quantidadeEnvolvidos = quantidadeEnvolvidos;

    incidentes[*contagemIncidentes] = novoIncidente;
    (*contagemIncidentes)++;
}

void adicionarIncidente(DadosIncidente incidentes[], int *contagemIncidentes, const DadosTrabalhador trabalhadores[], int contagemTrabalhadores) {
    char descricao[tamanhoVariavel];
    char data[tamanhoVariavel];
    int trabalhadoresEnvolvidos[maxTrabalhadoresEnvolvidos];
    int quantidadeEnvolvidos;

    printf("Descrição do incidente: ");
    fgets(descricao, tamanhoVariavel, stdin);
    descricao[strcspn(descricao, "\n")] = '\0';

    printf("Data do incidente (DD/MM/AAAA): ");
    fgets(data, tamanhoVariavel, stdin);
    data[strcspn(data, "\n")] = '\0';

    printf("Quantidade de trabalhadores envolvidos: ");
    scanf("%d", &quantidadeEnvolvidos);
    getchar();

    if (quantidadeEnvolvidos > maxTrabalhadoresEnvolvidos) {
        printf("Número de trabalhadores envolvidos excede o limite permitido.\n");
        return;
    }

    printf("IDs dos trabalhadores envolvidos (separados por espaço): ");
    for (int i = 0; i < quantidadeEnvolvidos; i++) {
        scanf("%d", &trabalhadoresEnvolvidos[i]);
    }
    getchar();

    inserirIncidente(incidentes, contagemIncidentes, descricao, data, trabalhadoresEnvolvidos, quantidadeEnvolvidos);
}

void listarIncidentes(const DadosIncidente incidentes[], int contagemIncidentes) {
    if (contagemIncidentes == 0) {
        printf("Nenhum incidente registrado.\n");
        return;
    }

    for (int i = 0; i < contagemIncidentes; i++) {
        printf("ID: %d\n", incidentes[i].idIncidente);
        printf("Descrição: %s\n", incidentes[i].descricaoIncidente);
        printf("Data: %s\n", incidentes[i].dataIncidente);
        printf("Trabalhadores envolvidos: ");
        for (int j = 0; j < incidentes[i].quantidadeEnvolvidos; j++) {
            printf("%d ", incidentes[i].trabalhadoresEnvolvidos[j]);
        }
        printf("\n-----\n");
    }
}

int main() {
    DadosTrabalhador trabalhadores[maxTrabalhadores];
    DadosIncidente incidentes[maxIncidentes];
    int contagemTrabalhadores = 0;
    int contagemIncidentes = 0;

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
                    char matricula[tamanhoVariavel];
                    char nome[tamanhoVariavel];
                    char endereco[tamanhoVariavel];
                    char telefone[tamanhoTelefone];
                    char telefoneEmergencial[tamanhoTelefone];
                    char formacao[tamanhoVariavel];
                    char cargo[tamanhoVariavel];
                    char ala[tamanhoVariavel];
                    char cpf[tamanhoVariavel];
                    int horasTrabalho;

                    printf("Matrícula: ");
                    fgets(matricula, tamanhoVariavel, stdin);
                    matricula[strcspn(matricula, "\n")] = '\0';

                    printf("Nome: ");
                    fgets(nome, tamanhoVariavel, stdin);
                    nome[strcspn(nome, "\n")] = '\0';

                    printf("Endereço: ");
                    fgets(endereco, tamanhoVariavel, stdin);
                    endereco[strcspn(endereco, "\n")] = '\0';

                    printf("Telefone: ");
                    fgets(telefone, tamanhoTelefone, stdin);
                    telefone[strcspn(telefone, "\n")] = '\0';

                    printf("Telefone Emergencial: ");
                    fgets(telefoneEmergencial, tamanhoTelefone, stdin);
                    telefoneEmergencial[strcspn(telefoneEmergencial, "\n")] = '\0';

                    printf("Formação: ");
                    fgets(formacao, tamanhoVariavel, stdin);
                    formacao[strcspn(formacao, "\n")] = '\0';

                    printf("Cargo: ");
                    fgets(cargo, tamanhoVariavel, stdin);
                    cargo[strcspn(cargo, "\n")] = '\0';

                    printf("Ala: ");
                    fgets(ala, tamanhoVariavel, stdin);
                    ala[strcspn(ala, "\n")] = '\0';

                    printf("CPF: ");
                    fgets(cpf, tamanhoVariavel, stdin);
                    cpf[strcspn(cpf, "\n")] = '\0';

                    printf("Horas de Trabalho: ");
                    scanf("%d", &horasTrabalho);
                    getchar();

                    inserirTrabalhador(trabalhadores, &contagemTrabalhadores, matricula, nome, endereco, telefone, telefoneEmergencial, formacao, cargo, ala, cpf, horasTrabalho);
                }
                break;
            case 2:
                listarTrabalhadores(trabalhadores, contagemTrabalhadores);
                break;
            case 3:
                adicionarIncidente(incidentes, &contagemIncidentes, trabalhadores, contagemTrabalhadores);
                break;
            case 4:
                listarIncidentes(incidentes, contagemIncidentes);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

        if (opcao == 2 || opcao == 4) {
            char resposta;
            printf("Deseja fazer mais alguma coisa? (s/n): ");
            scanf(" %c", &resposta);
            getchar();
            if (resposta == 'n' || resposta == 'N') {
                opcao = 0;
            }
        }

    } while (opcao != 0);

    return 0;
}
