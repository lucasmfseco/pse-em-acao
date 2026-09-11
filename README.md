# PSE em Ação — Sistema de Planejamento e Acompanhamento de Ações de Saúde na Escola

Aplicação em **linguagem C**, executável em terminal, para apoiar o planejamento, o registro e o
acompanhamento de ações coletivas do **Programa Saúde na Escola (PSE)**.

Projeto desenvolvido como **Atividade de Estudo Prática (AEP)** do 2º semestre de 2026 —
UNICESUMAR Maringá, curso de Engenharia de Software.

---

## Integrantes do grupo

| Nome completo | RA | GitHub |
|---|---|---|
| Lucas Machado Feltrim Seco | 26012183-2 | [lucasmfseco](https://github.com/lucasmfseco) |
| Victor Henrique da Silva Stander | 26006004-2 ||
| Fábio Henrique Soares Ferreira | 26006522-2 | — |

**Curso:** Engenharia de Software — 2º semestre · **Turma:** ESOFT2S-N-C

---

## O problema

Equipes intersetoriais que acompanham as escolas participantes do PSE registram o planejamento das
atividades em anotações, formulários e planilhas separadas. Com isso, torna-se difícil localizar
ações programadas, verificar quais já foram concluídas, identificar cancelamentos e consolidar a
quantidade de participantes atendidos em cada escola.

### Questão norteadora

> Como uma aplicação desenvolvida em linguagem C pode auxiliar uma equipe escolar e de saúde a
> planejar, registrar e acompanhar ações coletivas do Programa Saúde na Escola, apresentando
> informações claras e preservando a privacidade dos estudantes?

### Recorte temático

A demonstração do sistema usa como contexto as temáticas **alimentação saudável** e
**atividade física**. O cadastro, porém, é genérico: o tema é apenas um campo do registro, de modo
que a mesma aplicação atende vacinação, saúde bucal, cultura de paz, saúde mental e demais eixos do
programa sem alteração de código.

---

## Funcionalidades previstas

| # | Funcionalidade | Descrição |
|---|---|---|
| 1 | Cadastrar ação | Código, escola, tema, data prevista, público-alvo, responsável e quantidade prevista de participantes |
| 2 | Listar ações | Exibição tabular de todos os registros em memória |
| 3 | Pesquisar ações | Busca por código, por escola ou por tema |
| 4 | Atualizar situação | Alterna entre planejada, realizada e cancelada |
| 5 | Registrar participantes | Quantidade efetiva informada quando a ação é marcada como realizada |
| 6 | Gerar resumo geral | Contagem por situação, total de participantes e percentual de participação |

Todas as operações validam as entradas: código duplicado ou não positivo, campos obrigatórios
vazios, quantidades negativas, opções inexistentes no menu e limite de armazenamento atingido.

---

## Limites éticos do projeto

Estes limites são **requisitos de projeto**, não recomendações:

- Somente dados **fictícios** e **coletivos** sobre as ações são utilizados.
- **Não há campos** para nome, matrícula, prontuário, diagnóstico ou qualquer condição clínica
  individual de estudante.
- O sistema **não realiza** diagnóstico, triagem, prescrição ou recomendação de tratamento.
- O percentual de participação é indicador de **cobertura da ação**, nunca de desempenho de pessoas.
- A delimitação segue o princípio da necessidade da Lei nº 13.709/2018 (LGPD).

---

## Estrutura do repositório

```
pse-em-acao/
├── README.md
├── docs/
│   ├── README.md             # o que há em cada subpasta
│   ├── entrega-1/            # documento escrito da 1ª entrega (.pdf)
│   └── fluxogramas/          # imagens (.png) e os fontes Graphviz (.dot)
└── src/main.c                # esqueleto em C: menu, cadastro, auxiliares e resumo
```

As pastas da 2ª entrega (`docs/entrega-2/` e `testes/`) serão criadas quando houver
conteúdo para elas.

---

## Documentação da 1ª entrega

| Artefato | Caminho |
|---|---|
| Documento escrito completo (PDF) | [`docs/entrega-1/AEP_1a_Entrega_PSE_em_Acao.pdf`](docs/entrega-1/AEP_1a_Entrega_PSE_em_Acao.pdf) |
| Fluxograma geral do sistema | [`docs/fluxogramas/fluxograma-geral.png`](docs/fluxogramas/fluxograma-geral.png) |
| Fluxograma do cadastro de ação | [`docs/fluxogramas/fluxograma-cadastro-acao.png`](docs/fluxogramas/fluxograma-cadastro-acao.png) |

O documento contém a contextualização com referências, a questão norteadora, os objetivos, a
justificativa, os usuários, o escopo, 8 requisitos funcionais, 5 requisitos não funcionais, a
análise de riscos, os dois fluxogramas, o pseudocódigo do menu, cinco blocos de código em C e o
planejamento das oito sprints.

---

## Processo de desenvolvimento

Abordagem **incremental**, com sprints semanais. Cada sprint entrega uma versão do programa que
compila e executa, encerrando com um commit de fechamento e a atualização da pasta `docs/`.

| Sprint | Foco | Entregável |
|---|---|---|
| 1 | Levantamento e contextualização | Fichamento das fontes e contextualização redigida |
| 2 | Modelagem e especificação | Documento da 1ª entrega e repositório criado |
| 3 | Estrutura base e cadastro | v0.1 — menu e cadastro |
| 4 | Listagem e pesquisa | v0.2 — cadastro, listagem e pesquisa |
| 5 | Atualização de situação e resumo | v0.3 — escopo mínimo completo |
| 6 | Testes e refinamento | v1.0 estável e registro de testes |
| 7 | Documentação e artefatos de ES | Casos de uso e manual do usuário |
| 8 | Apresentação final | Vídeo e repositório final |

---

## Compilação e execução

```bash
gcc -Wall -std=c99 src/main.c -o pse
./pse
# compila sem avisos; listar, pesquisar e atualizar entram na 2ª entrega
```

No Windows, com MinGW:

```bat
gcc -Wall -std=c99 src\main.c -o pse.exe
pse.exe
```

---

## Tecnologias

- Linguagem C (padrão C99), apenas biblioteca padrão
- Compilador GCC
- Git e GitHub para controle de versão

---

## Referências principais

- BRASIL. **Decreto nº 6.286, de 5 de dezembro de 2007.** Institui o Programa Saúde na Escola — PSE.
- BRASIL. Ministério da Saúde; Ministério da Educação. **Passo a passo PSE: tecendo caminhos da intersetorialidade.** Brasília, DF, 2011.
- IBGE. **Pesquisa Nacional de Saúde do Escolar: 2019.** Rio de Janeiro, 2021.
- SOUSA, M. C.; ESPERIDIÃO, M. A.; MEDINA, M. G. A intersetorialidade no Programa Saúde na Escola. **Ciência & Saúde Coletiva**, v. 22, n. 6, 2017.
- PRESSMAN, R. S.; MAXIM, B. R. **Engenharia de software: uma abordagem profissional.** 8. ed., 2016.

A lista completa está na seção *Referências* do documento da 1ª entrega.

---

## Licença

Projeto acadêmico, sem fins comerciais, desenvolvido para a AEP 2026/2 da UNICESUMAR.
