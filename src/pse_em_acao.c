/*
 * PSE em Acao - Sistema de Planejamento e Acompanhamento de Acoes
 * de Saude na Escola
 *
 * AEP 2o semestre 2026 - Engenharia de Software - UNICESUMAR Maringa
 * Grupo: Lucas Machado Feltrim Seco, Victor Henrique da Silva Stander,
 *        Fabio Henrique Soares Ferreira
 *
 * Aplicacao de terminal que registra apenas dados ficticios e coletivos
 * sobre as acoes. Nao ha campos para dados pessoais ou clinicos de
 * estudantes.
 */

#include <stdio.h>
#include <string.h>

#define MAX_ACOES  100
#define TAM        60
#define TAM_DATA   15

#define PLANEJADA  0
#define REALIZADA  1
#define CANCELADA  2

typedef struct {
    int  codigo;
    char escola[TAM];
    char tema[TAM];
    char data[TAM_DATA];          /* DD/MM/AAAA */
    char publico[TAM];
    char responsavel[TAM];
    int  previstos;
    int  efetivos;
    int  situacao;
} Acao;

Acao acoes[MAX_ACOES];
int  totalAcoes = 0;

/* ---------------------------------------------------------------
 * Funcoes de leitura
 * --------------------------------------------------------------- */

/* Descarta o que sobrou digitado no teclado ate o Enter. */
void limparBuffer() {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/* Le um numero inteiro. O scanf devolve 1 quando consegue ler um
 * numero; se o usuario digitar letras, ele devolve 0 e a pergunta
 * e repetida. */
int lerInteiro(char rotulo[]) {
    int valor;
    int leu;

    do {
        printf("%s", rotulo);
        leu = scanf("%d", &valor);
        limparBuffer();

        if (leu != 1) {
            printf("Entrada invalida! Digite apenas numeros inteiros.\n");
        }
    } while (leu != 1);

    return valor;
}

/* Le um texto com espacos usando fgets. Recusa campo vazio e texto
 * maior do que o tamanho do campo. */
void lerTexto(char destino[], int tamanho, char rotulo[]) {
    int tam;
    int valido;

    do {
        valido = 1;
        printf("%s: ", rotulo);
        fgets(destino, tamanho, stdin);
        tam = strlen(destino);

        if (tam > 0 && destino[tam - 1] == '\n') {
            destino[tam - 1] = '\0';          /* tira o Enter do final */
            if (tam - 1 == 0) {
                printf("Campo obrigatorio! Nao pode ficar vazio.\n");
                valido = 0;
            }
        } else {
            /* nao achou o Enter: o texto nao coube no campo */
            limparBuffer();
            printf("Texto muito longo! Use no maximo %d caracteres.\n",
                   tamanho - 2);
            valido = 0;
        }
    } while (valido == 0);
}

int lerSituacao() {
    int opcao;

    do {
        printf("1 - Planejada\n");
        printf("2 - Realizada\n");
        printf("3 - Cancelada\n");
        opcao = lerInteiro("Situacao: ");

        if (opcao < 1 || opcao > 3) {
            printf("Opcao invalida! Digite 1, 2 ou 3.\n");
        }
    } while (opcao < 1 || opcao > 3);

    return opcao - 1;   /* 1, 2, 3 viram PLANEJADA, REALIZADA, CANCELADA */
}

int lerEfetivos() {
    int efetivos;

    do {
        efetivos = lerInteiro("Participantes efetivos: ");
        if (efetivos < 0) {
            printf("A quantidade nao pode ser negativa!\n");
        }
    } while (efetivos < 0);

    return efetivos;
}

/* ---------------------------------------------------------------
 * Funcoes de apoio
 * --------------------------------------------------------------- */

/* Devolve a posicao da acao no vetor, ou -1 se nao existir. */
int buscarPorCodigo(int codigo) {
    int i;
    for (i = 0; i < totalAcoes; i++) {
        if (acoes[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void mostrarSituacao(int situacao) {
    if (situacao == PLANEJADA) {
        printf("PLANEJADA");
    } else if (situacao == REALIZADA) {
        printf("REALIZADA");
    } else {
        printf("CANCELADA");
    }
}

void exibirAcao(int i) {
    printf("----------------------------------------------\n");
    printf("Codigo ........: %d   [", acoes[i].codigo);
    mostrarSituacao(acoes[i].situacao);
    printf("]\n");
    printf("Escola ........: %s\n", acoes[i].escola);
    printf("Tema ..........: %s\n", acoes[i].tema);
    printf("Data prevista .: %s\n", acoes[i].data);
    printf("Publico-alvo ..: %s\n", acoes[i].publico);
    printf("Responsavel ...: %s\n", acoes[i].responsavel);
    printf("Participantes .: %d previstos", acoes[i].previstos);

    if (acoes[i].situacao == REALIZADA) {
        printf(" | %d efetivos\n", acoes[i].efetivos);
    } else {
        printf("\n");
    }
}

void adicionarAcao(int codigo, char escola[], char tema[], char data[],
                   char publico[], char responsavel[], int previstos,
                   int efetivos, int situacao) {
    acoes[totalAcoes].codigo = codigo;
    strcpy(acoes[totalAcoes].escola, escola);
    strcpy(acoes[totalAcoes].tema, tema);
    strcpy(acoes[totalAcoes].data, data);
    strcpy(acoes[totalAcoes].publico, publico);
    strcpy(acoes[totalAcoes].responsavel, responsavel);
    acoes[totalAcoes].previstos = previstos;
    acoes[totalAcoes].efetivos  = efetivos;
    acoes[totalAcoes].situacao  = situacao;
    totalAcoes++;
}

/* Acoes ficticias carregadas no inicio, para a demonstracao.
 * Responsaveis identificados pela funcao, sem nomes de pessoas. */
void carregarDadosFicticios() {
    adicionarAcao(101, "EM Jardim das Flores", "Alimentacao saudavel",
                  "12/08/2026", "Alunos do 5o ano",
                  "Nutricionista da UBS Jardim", 60, 54, REALIZADA);
    adicionarAcao(102, "EM Vila Esperanca", "Atividade fisica",
                  "26/08/2026", "Alunos do 6o ao 9o ano",
                  "Profissional de educacao fisica", 120, 97, REALIZADA);
    adicionarAcao(103, "CE Parque Industrial", "Alimentacao saudavel",
                  "18/11/2026", "Alunos da 1a serie do EM",
                  "Nutricionista da UBS Centro", 80, 0, PLANEJADA);
    adicionarAcao(104, "EM Jardim das Flores", "Saude bucal",
                  "09/09/2026", "Alunos do 1o ao 3o ano",
                  "Cirurgiao-dentista da UBS Jardim", 70, 0, CANCELADA);
}

/* ---------------------------------------------------------------
 * Funcionalidades do menu
 * --------------------------------------------------------------- */

void cadastrarAcao() {
    int codigo;

    printf("\n----- CADASTRAR ACAO -----\n");

    if (totalAcoes >= MAX_ACOES) {
        printf("Limite de %d registros atingido! Nao e possivel cadastrar.\n",
               MAX_ACOES);
        return;
    }

    do {
        codigo = lerInteiro("Codigo da acao: ");

        if (codigo <= 0) {
            printf("Codigo invalido! Digite um numero positivo.\n");
        } else if (buscarPorCodigo(codigo) != -1) {
            printf("Codigo ja cadastrado! Digite outro.\n");
        }
    } while (codigo <= 0 || buscarPorCodigo(codigo) != -1);

    /* a nova acao e gravada direto na proxima posicao livre do vetor */
    acoes[totalAcoes].codigo = codigo;
    lerTexto(acoes[totalAcoes].escola,      TAM,      "Escola");
    lerTexto(acoes[totalAcoes].tema,        TAM,      "Tema");
    lerTexto(acoes[totalAcoes].data,        TAM_DATA, "Data prevista (DD/MM/AAAA)");
    lerTexto(acoes[totalAcoes].publico,     TAM,      "Publico-alvo");
    lerTexto(acoes[totalAcoes].responsavel, TAM,      "Responsavel");

    do {
        acoes[totalAcoes].previstos = lerInteiro("Participantes previstos: ");
        if (acoes[totalAcoes].previstos <= 0) {
            printf("A quantidade deve ser maior que zero!\n");
        }
    } while (acoes[totalAcoes].previstos <= 0);

    printf("Situacao inicial da acao:\n");
    acoes[totalAcoes].situacao = lerSituacao();

    acoes[totalAcoes].efetivos = 0;
    if (acoes[totalAcoes].situacao == REALIZADA) {
        acoes[totalAcoes].efetivos = lerEfetivos();
    }

    totalAcoes++;

    printf("Acao %d cadastrada com sucesso! (%d de %d registros)\n",
           codigo, totalAcoes, MAX_ACOES);
}

void listarAcoes() {
    int i;

    printf("\n----- ACOES CADASTRADAS -----\n");

    if (totalAcoes == 0) {
        printf("Nenhuma acao cadastrada ate o momento.\n");
        return;
    }

    for (i = 0; i < totalAcoes; i++) {
        exibirAcao(i);
    }
    printf("----------------------------------------------\n");
    printf("Total: %d acao(oes).\n", totalAcoes);
}

void pesquisarAcoes() {
    int tipo, codigo, i, posicao, encontrados;
    char termo[TAM];

    printf("\n----- PESQUISAR ACOES -----\n");

    if (totalAcoes == 0) {
        printf("Nenhuma acao cadastrada para pesquisar.\n");
        return;
    }

    do {
        printf("1 - Por codigo\n");
        printf("2 - Por escola\n");
        printf("3 - Por tema\n");
        printf("0 - Voltar\n");
        tipo = lerInteiro("Pesquisar: ");

        if (tipo < 0 || tipo > 3) {
            printf("Opcao invalida! Digite um numero de 0 a 3.\n");
        }
    } while (tipo < 0 || tipo > 3);

    if (tipo == 0) {
        return;
    }

    if (tipo == 1) {
        codigo = lerInteiro("Codigo: ");
        posicao = buscarPorCodigo(codigo);

        if (posicao == -1) {
            printf("Nenhuma acao encontrada com o codigo %d.\n", codigo);
        } else {
            exibirAcao(posicao);
        }
        return;
    }

    if (tipo == 2) {
        lerTexto(termo, TAM, "Nome (ou parte do nome) da escola");
    } else {
        lerTexto(termo, TAM, "Tema (ou parte do tema)");
    }

    /* strstr procura um texto dentro de outro; devolve NULL quando
     * nao encontra */
    encontrados = 0;
    for (i = 0; i < totalAcoes; i++) {
        if ((tipo == 2 && strstr(acoes[i].escola, termo) != NULL) ||
            (tipo == 3 && strstr(acoes[i].tema, termo) != NULL)) {
            exibirAcao(i);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhuma acao encontrada para \"%s\".\n", termo);
    } else {
        printf("----------------------------------------------\n");
        printf("%d acao(oes) encontrada(s).\n", encontrados);
    }
}

void atualizarSituacao() {
    int codigo, posicao;

    printf("\n----- ATUALIZAR SITUACAO -----\n");

    if (totalAcoes == 0) {
        printf("Nenhuma acao cadastrada para atualizar.\n");
        return;
    }

    codigo = lerInteiro("Codigo da acao: ");
    posicao = buscarPorCodigo(codigo);

    if (posicao == -1) {
        printf("Registro inexistente! Nenhuma acao com o codigo %d.\n",
               codigo);
        return;
    }

    exibirAcao(posicao);
    printf("Nova situacao:\n");
    acoes[posicao].situacao = lerSituacao();

    if (acoes[posicao].situacao == REALIZADA) {
        acoes[posicao].efetivos = lerEfetivos();
    } else {
        acoes[posicao].efetivos = 0;  /* so acoes realizadas tem participantes */
    }

    printf("Situacao da acao %d atualizada para ", codigo);
    mostrarSituacao(acoes[posicao].situacao);
    printf(".\n");
}

void gerarResumo() {
    int i;
    int planejadas = 0, realizadas = 0, canceladas = 0;
    int totalPrevistos = 0, totalEfetivos = 0;
    float percentual;

    printf("\n----- RESUMO GERAL -----\n");

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

    printf("Acoes cadastradas: %d\n", totalAcoes);
    printf("Planejadas: %d | Realizadas: %d | Canceladas: %d\n",
           planejadas, realizadas, canceladas);
    printf("Participantes previstos (acoes realizadas): %d\n", totalPrevistos);
    printf("Participantes efetivos  (acoes realizadas): %d\n", totalEfetivos);

    if (totalPrevistos > 0) {
        percentual = (totalEfetivos * 100.0) / totalPrevistos;
        printf("Percentual de participacao: %.1f%%\n", percentual);
    } else {
        printf("Percentual de participacao: nao aplicavel "
               "(nenhuma acao realizada).\n");
    }
}

/* ---------------------------------------------------------------
 * Programa principal
 * --------------------------------------------------------------- */

void exibirMenu() {
    printf("\n========== PSE EM ACAO ==========\n");
    printf("1 - Cadastrar acao\n");
    printf("2 - Listar acoes\n");
    printf("3 - Pesquisar acoes\n");
    printf("4 - Atualizar situacao\n");
    printf("5 - Gerar resumo geral\n");
    printf("0 - Sair\n");
}

int main() {
    int opcao;

    carregarDadosFicticios();
    printf("Sistema iniciado com %d acoes ficticias de demonstracao.\n",
           totalAcoes);

    do {
        exibirMenu();
        opcao = lerInteiro("Opcao: ");

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
