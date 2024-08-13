#include <stdio.h>
#include <string.h>

#define tamanhoVariavel 100
#define tamanhoTelefone 20
#define maxColaboradores 100
#define maxIncidentes 100
#define maxColaboradoresEnvolvidos 10

typedef struct {
    int idColaborador;
    char matriculaColaborador[tamanhoVariavel];
    char nomeColaborador[tamanhoVariavel];
    char enderecoColaborador[tamanhoVariavel];
    char telefoneColaborador[tamanhoTelefone];
    char telefoneEmergencialColaborador[tamanhoTelefone];
    char formacaoColaborador[tamanhoVariavel];
    char cargoColaborador[tamanhoVariavel];
    char alaColaborador[tamanhoVariavel];
    char cpfColaborador[tamanhoVariavel];
    int horasTrabalho;
} DadosColaborador;

typedef struct {
    int idIncidente;
    char descricaoIncidente[tamanhoVariavel];
    char dataIncidente[tamanhoVariavel];
    int colaboradoresEnvolvidos[maxColaboradoresEnvolvidos];
    int quantidadeEnvolvidos;
} DadosIncidente;

void inserirColaborador(DadosColaborador colaboradores[], int *contagemColaboradores, int id, const char *matricula, const char *nome, const char *endereco, const char *telefone, const char *telefoneEmergencial, const char *formacao, const char *cargo, const char *ala, const char *cpf, int horasTrabalho);
void listarColaboradores(const DadosColaborador colaboradores[], int contagemColaboradores);
void inserirIncidente(DadosIncidente incidentes[], int *contagemIncidentes, const char *descricao, const char *data, const int colaboradores[], int quantidadeEnvolvidos);
void adicionarIncidente(DadosIncidente incidentes[], int *contagemIncidentes, const DadosColaborador colaboradores[], int contagemColaboradores);
void listarIncidentes(const DadosIncidente incidentes[], int contagemIncidentes);

void inserirColaborador(DadosColaborador colaboradores[], int *contagemColaboradores, int id, const char *matricula, const char *nome, const char *endereco, const char *telefone, const char *telefoneEmergencial, const char *formacao, const char *cargo, const char *ala, const char *cpf, int horasTrabalho) {
    if (*contagemColaboradores >= maxColaboradores) {
        printf("Número máximo de colaboradores atingido.\n");
        return;
    }

    DadosColaborador novoColaborador;
    novoColaborador.idColaborador = id;
    strncpy(novoColaborador.matriculaColaborador, matricula, tamanhoVariavel - 1);
    novoColaborador.matriculaColaborador[tamanhoVariavel - 1] = '\0';
    strncpy(novoColaborador.nomeColaborador, nome, tamanhoVariavel - 1);
    novoColaborador.nomeColaborador[tamanhoVariavel - 1] = '\0';
    strncpy(novoColaborador.enderecoColaborador, endereco, tamanhoVariavel - 1);
    novoColaborador.enderecoColaborador[tamanhoVariavel - 1] = '\0';
    strncpy(novoColaborador.telefoneColaborador, telefone, tamanhoTelefone - 1);
    novoColaborador.telefoneColaborador[tamanhoTelefone - 1] = '\0';
    strncpy(novoColaborador.telefoneEmergencialColaborador, telefoneEmergencial, tamanhoTelefone - 1);
    novoColaborador.telefoneEmergencialColaborador[tamanhoTelefone - 1] = '\0';
    strncpy(novoColaborador.formacaoColaborador, formacao, tamanhoVariavel - 1);
    novoColaborador.formacaoColaborador[tamanhoVariavel - 1] = '\0';
    strncpy(novoColaborador.cargoColaborador, cargo, tamanhoVariavel - 1);
    novoColaborador.cargoColaborador[tamanhoVariavel - 1] = '\0';
    strncpy(novoColaborador.alaColaborador, ala, tamanhoVariavel - 1);
    novoColaborador.alaColaborador[tamanhoVariavel - 1] = '\0';
    strncpy(novoColaborador.cpfColaborador, cpf, tamanhoVariavel - 1);
    novoColaborador.cpfColaborador[tamanhoVariavel - 1] = '\0';
    novoColaborador.horasTrabalho = horasTrabalho;

    colaboradores[*contagemColaboradores] = novoColaborador;
    (*contagemColaboradores)++;
}

void listarColaboradores(const DadosColaborador colaboradores[], int contagemColaboradores) {
    if (contagemColaboradores == 0) {
        printf("Nenhum colaborador cadastrado.\n");
        return;
    }

    for (int i = 0; i < contagemColaboradores; i++) {
        printf("ID: %d\n", colaboradores[i].idColaborador);
        printf("Matrícula: %s\n", colaboradores[i].matriculaColaborador);
        printf("Nome: %s\n", colaboradores[i].nomeColaborador);
        printf("Endereço: %s\n", colaboradores[i].enderecoColaborador);
        printf("Telefone: %s\n", colaboradores[i].telefoneColaborador);
        printf("Telefone Emergencial: %s\n", colaboradores[i].telefoneEmergencialColaborador);
        printf("Formação: %s\n", colaboradores[i].formacaoColaborador);
        printf("Cargo: %s\n", colaboradores[i].cargoColaborador);
        printf("Ala: %s\n", colaboradores[i].alaColaborador);
        printf("CPF: %s\n", colaboradores[i].cpfColaborador);
        printf("Horas de Trabalho: %d\n", colaboradores[i].horasTrabalho);
        printf("-----\n");
    }
}

void inserirIncidente(DadosIncidente incidentes[], int *contagemIncidentes, const char *descricao, const char *data, const int colaboradores[], int quantidadeEnvolvidos) {
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
        novoIncidente.colaboradoresEnvolvidos[i] = colaboradores[i];
    }
    novoIncidente.quantidadeEnvolvidos = quantidadeEnvolvidos;

    incidentes[*contagemIncidentes] = novoIncidente;
    (*contagemIncidentes)++;
}

void adicionarIncidente(DadosIncidente incidentes[], int *contagemIncidentes, const DadosColaborador colaboradores[], int contagemColaboradores) {
    char descricao[tamanhoVariavel];
    char data[tamanhoVariavel];
    int colaboradoresEnvolvidos[maxColaboradoresEnvolvidos];
    int quantidadeEnvolvidos;

    printf("Descrição do incidente: ");
    fgets(descricao, tamanhoVariavel, stdin);
    descricao[strcspn(descricao, "\n")] = '\0';

    printf("Data do incidente (DD/MM/AAAA): ");
    fgets(data, tamanhoVariavel, stdin);
    data[strcspn(data, "\n")] = '\0';

    printf("Quantidade de colaboradores envolvidos: ");
    scanf("%d", &quantidadeEnvolvidos);
    getchar();

    if (quantidadeEnvolvidos > maxColaboradoresEnvolvidos) {
        printf("Número de colaboradores envolvidos excede o limite permitido.\n");
        return;
    }

    printf("IDs dos colaboradores envolvidos (separados por espaço): ");
    for (int i = 0; i < quantidadeEnvolvidos; i++) {
        scanf("%d", &colaboradoresEnvolvidos[i]);
    }
    getchar();

    inserirIncidente(incidentes, contagemIncidentes, descricao, data, colaboradoresEnvolvidos, quantidadeEnvolvidos);
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
        printf("Colaboradores envolvidos: ");
        for (int j = 0; j < incidentes[i].quantidadeEnvolvidos; j++) {
            printf("%d ", incidentes[i].colaboradoresEnvolvidos[j]);
        }
        printf("\n-----\n");
    }
}

int main() {
    DadosColaborador colaboradores[maxColaboradores];
    DadosIncidente incidentes[maxIncidentes];
    int contagemColaboradores = 0;
    int contagemIncidentes = 0;

    int opcao;
    do {
        printf("Menu:\n");
        printf("1. Inserir colaborador\n");
        printf("2. Listar colaboradores\n");
        printf("3. Adicionar incidente\n");
        printf("4. Mostrar registros de incidentes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                {
                    int id;
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

                    printf("ID do colaborador: ");
                    scanf("%d", &id);
                    getchar();

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

                    inserirColaborador(colaboradores, &contagemColaboradores, id, matricula, nome, endereco, telefone, telefoneEmergencial, formacao, cargo, ala, cpf, horasTrabalho);
                }
                break;
            case 2:
                listarColaboradores(colaboradores, contagemColaboradores);
                break;
            case 3:
                adicionarIncidente(incidentes, &contagemIncidentes, colaboradores, contagemColaboradores);
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
