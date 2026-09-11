/*
 * PSE em Acao - Sistema de Planejamento e Acompanhamento de Acoes do PSE
 * AEP 2026/2 - Engenharia de Software - UNICESUMAR
 *
 * Esqueleto da 1a entrega: menu, cadastro, auxiliares e resumo geral.
 * listarAcoes(), pesquisarAcoes() e atualizarSituacao() entram na 2a entrega.
 *
 * Compilar: gcc -Wall -std=c99 main.c -o pse
 */

#include <stdio.h>
#include <string.h>

#define MAX_ACOES 100
#define TAM 60

#define PLANEJADA 0
#define REALIZADA 1
#define CANCELADA 2

typedef struct {
    int  codigo;
    char escola[TAM];
    char tema[TAM];
    char data[15];          /* DD/MM/AAAA */
    char publico[TAM];
    char responsavel[TAM];
    int  previstos;
    int  efetivos;
    int  situacao;
} Acao;

Acao acoes[MAX_ACOES];
int  totalAcoes = 0;

void limparEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerTexto(char destino[], int tamanho, char rotulo[]) {
    int i;
    do {
        printf("%s: ", rotulo);
        fgets(destino, tamanho, stdin);

        for (i = 0; destino[i] != '\0'; i++) {
            if (destino[i] == '\n') {
                destino[i] = '\0';
            }
        }

        if (strlen(destino) == 0) {
            printf("Campo obrigatorio! Nao pode ficar vazio.\n");
        }
    } while (strlen(destino) == 0);
}

int buscarPorCodigo(int codigo) {
    int i;
    for (i = 0; i < totalAcoes; i++) {
        if (acoes[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void cadastrarAcao() {
    int codigo, previstos;

    if (totalAcoes >= MAX_ACOES) {
        printf("Limite de registros atingido!\n");
        return;
    }

    do {
        printf("Codigo da acao: ");
        scanf("%d", &codigo);
        limparEntrada();

        if (codigo <= 0) {
            printf("Codigo invalido! Digite um numero positivo.\n");
        } else if (buscarPorCodigo(codigo) != -1) {
            printf("Codigo ja cadastrado! Digite outro.\n");
        }
    } while (codigo <= 0 || buscarPorCodigo(codigo) != -1);

    acoes[totalAcoes].codigo = codigo;
    lerTexto(acoes[totalAcoes].escola,      TAM, "Escola");
    lerTexto(acoes[totalAcoes].tema,        TAM, "Tema");
    lerTexto(acoes[totalAcoes].data,        15,  "Data prevista");
    lerTexto(acoes[totalAcoes].publico,     TAM, "Publico-alvo");
    lerTexto(acoes[totalAcoes].responsavel, TAM, "Responsavel");

    do {
        printf("Participantes previstos: ");
        scanf("%d", &previstos);
        limparEntrada();

        if (previstos <= 0) {
            printf("A quantidade deve ser maior que zero!\n");
        }
    } while (previstos <= 0);

    acoes[totalAcoes].previstos = previstos;
    acoes[totalAcoes].efetivos  = 0;
    acoes[totalAcoes].situacao  = PLANEJADA;
    totalAcoes++;

    printf("Acao cadastrada com sucesso!\n");
}

void gerarResumo() {
    int i;
    int planejadas = 0, realizadas = 0, canceladas = 0;
    int totalPrevistos = 0, totalEfetivos = 0;
    float percentual;

    for (i = 0; i < totalAcoes; i++) {
        if (acoes[i].situacao == PLANEJADA) {
            planejadas++;
        } else if (acoes[i].situacao == REALIZADA) {
            realizadas++;
            totalPrevistos = totalPrevistos + acoes[i].previstos;
            totalEfetivos  = totalEfetivos  + acoes[i].efetivos;
        } else {
            canceladas++;
        }
    }

    printf("\n----- RESUMO GERAL -----\n");
    printf("Acoes cadastradas: %d\n", totalAcoes);
    printf("Planejadas: %d | Realizadas: %d | Canceladas: %d\n",
           planejadas, realizadas, canceladas);
    printf("Participantes previstos: %d\n", totalPrevistos);
    printf("Participantes efetivos:  %d\n", totalEfetivos);

    if (totalPrevistos > 0) {
        percentual = (totalEfetivos * 100.0) / totalPrevistos;
        printf("Percentual de participacao: %.1f%%\n", percentual);
    } else {
        printf("Percentual: nao aplicavel (nenhuma acao realizada).\n");
    }
}

/* --- A implementar na 2a entrega --- */
void listarAcoes()       { printf("Em desenvolvimento.\n"); }
void pesquisarAcoes()    { printf("Em desenvolvimento.\n"); }
void atualizarSituacao() { printf("Em desenvolvimento.\n"); }

int main() {
    int opcao;

    do {
        printf("\n===== PSE EM ACAO =====\n");
        printf("1 - Cadastrar acao\n");
        printf("2 - Listar acoes\n");
        printf("3 - Pesquisar acoes\n");
        printf("4 - Atualizar situacao\n");
        printf("5 - Gerar resumo geral\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            if (feof(stdin)) {
                opcao = 0;       /* entrada encerrada */
            } else {
                opcao = -1;      /* usuario digitou letra */
            }
        }
        limparEntrada();

        if (opcao == 1) {
            cadastrarAcao();
        } else if (opcao == 2) {
            listarAcoes();
        } else if (opcao == 3) {
            pesquisarAcoes();
        } else if (opcao == 4) {
            atualizarSituacao();
        } else if (opcao == 5) {
            gerarResumo();
        } else if (opcao == 0) {
            printf("Encerrando o sistema...\n");
        } else {
            printf("Opcao invalida! Digite um numero de 0 a 5.\n");
        }
    } while (opcao != 0);

    return 0;
}
