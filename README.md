# PSE em Ação — Sistema de Planejamento e Acompanhamento de Ações de Saúde na Escola

Aplicação em **linguagem C**, executável em terminal, para apoiar o planejamento, o registro e o
acompanhamento de ações coletivas do **Programa Saúde na Escola (PSE)**.

Projeto desenvolvido como **Atividade de Estudo Prática (AEP)** do 2º semestre de 2026 —
UNICESUMAR Maringá, curso de Engenharia de Software.

**Vídeo de apresentação:** [INSERIR O LINK DO VÍDEO]

---

## Integrantes do grupo

| Nome completo | RA | GitHub |
|---|---|---|
| Lucas Machado Feltrim Seco | 26012183-2 | [@lucasmfseco](https://github.com/lucasmfseco) |
| Victor Henrique da Silva Stander | 26006004-2 | [@Victorstander](https://github.com/Victorstander) |
| Fábio Henrique Soares Ferreira | 26006522-2 | [@fhsoares08](https://github.com/fhsoares08) |

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

## Funcionalidades

| Opção | Funcionalidade | Requisito |
| :-: | :-- | :-: |
| 1 | Cadastrar ação: código, escola, tema, data prevista, público-alvo, responsável, participantes previstos e situação inicial | RF01 |
| 2 | Listar todas as ações | RF02 |
| 3 | Pesquisar por código, escola ou tema (aceita parte do nome) | RF03 |
| 4 | Atualizar a situação (planejada, realizada ou cancelada) | RF04 |
| — | Registrar os participantes efetivos quando a ação é marcada como realizada | RF05 |
| 5 | Gerar resumo geral: ações por situação, total de participantes e percentual de participação | RF06 |
| 0 | Sair | RF08 |

**Validações (RF07):** código duplicado, zero ou negativo; letras em campos numéricos; campos
vazios; textos maiores que o campo; quantidades negativas; opções inexistentes; registro
inexistente; limite de 100 ações.

Ao iniciar, o sistema carrega **4 ações fictícias** para demonstração (RF09).

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
├── src/
│   └── pse_em_acao.c         # código-fonte completo (2ª entrega)
├── testes/
│   └── registro-de-testes.md # 22 casos de teste, todos aprovados
└── docs/
    ├── README.md             # o que há em cada subpasta
    ├── entrega-1/            # documento escrito da 1ª entrega (.pdf)
    └── fluxogramas/          # imagens (.png) e os fontes Graphviz (.dot)
```

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

### Dev-C++ (Windows)

1. Baixe o repositório (botão **Code > Download ZIP**) e extraia a pasta.
2. No Dev-C++, abra `src/pse_em_acao.c` em **Arquivo > Abrir**.
3. Clique em **Executar > Compilar & Executar** (ou F11).

> Use o **Embarcadero Dev-C++** (versão atual). O Dev-C++ 4.9.9.2, de 2005, tem um compilador que
> trava no Windows 10/11 e não gera o executável.

### GCC (Windows ou Linux)

```bash
gcc -Wall -std=c99 src/pse_em_acao.c -o pse
./pse          # Linux
pse.exe        # Windows
```

O código usa apenas `stdio.h` e `string.h` e compila sem avisos com `gcc -Wall -Wextra -pedantic`.

### Exemplo: resumo geral com as ações fictícias

```
----- RESUMO GERAL -----
Acoes cadastradas: 4
Planejadas: 1 | Realizadas: 2 | Canceladas: 1
Participantes previstos (acoes realizadas): 180
Participantes efetivos  (acoes realizadas): 151
Percentual de participacao: 83.9%
```

---

## Testes

Foram executados **22 casos de teste**, cobrindo as seis funcionalidades e todas as validações,
incluindo código duplicado, registro inexistente e o limite de 100 ações. Todos foram aprovados.
O registro completo, com entradas e saídas, está em
[`testes/registro-de-testes.md`](testes/registro-de-testes.md).

---

## Limitações e melhorias futuras

- Os dados ficam só na memória e se perdem ao fechar o programa.
- A data não é validada quanto ao formato DD/MM/AAAA.
- A pesquisa por escola e tema diferencia maiúsculas de minúsculas.
- Não há login nem controle de acesso por perfil.
- Melhorias possíveis: gravar em arquivo, validar a data, editar e excluir ações, resumo por escola.

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
