# Registro dos testes — PSE em Ação (2ª entrega)

Cada caso foi executado no terminal, digitando as entradas indicadas, e a saída foi comparada ao resultado esperado. CT10 e CT20 usaram uma cópia do programa sem as ações fictícias (chamada de `carregarDadosFicticios()` comentada), porque a versão final sempre inicia com elas.

Compilação: `gcc -std=c99 -Wall -Wextra -pedantic src/pse_em_acao.c`, sem nenhum erro ou aviso. Também compilado no Embarcadero Dev-C++ (Windows), sem erros.

**Resultado: 22 de 22 casos aprovados.**

| ID | Cenário | Requisito | Resultado |
| :-: | :-- | :-: | :-: |
| CT01 | Opção inexistente no menu | RF07, RF08 | Aprovado |
| CT02 | Letras no lugar de número no menu | RF07, RNF04 | Aprovado |
| CT03 | Cadastro completo válido | RF01 | Aprovado |
| CT04 | Código duplicado, zero, negativo e com letras | RF07 | Aprovado |
| CT05 | Campo obrigatório vazio | RF07 | Aprovado |
| CT06 | Texto maior que o campo | RF07, RNF04 | Aprovado |
| CT07 | Previstos negativo e zero | RF07 | Aprovado |
| CT08 | Cadastro já com situação REALIZADA | RF01, RF05 | Aprovado |
| CT09 | Listar ações cadastradas | RF02 | Aprovado |
| CT10 | Listar com o sistema vazio | RF02 | Aprovado |
| CT11 | Pesquisar código existente | RF03 | Aprovado |
| CT12 | Pesquisar código inexistente | RF03 | Aprovado |
| CT13 | Pesquisar escola por parte do nome | RF03 | Aprovado |
| CT14 | Pesquisar por tema | RF03 | Aprovado |
| CT15 | Pesquisa sem resultado e tipo inválido | RF03, RF07 | Aprovado |
| CT16 | Atualizar código inexistente | RF04, RF07 | Aprovado |
| CT17 | Atualizar para REALIZADA com efetivos | RF04, RF05 | Aprovado |
| CT18 | Atualizar para CANCELADA | RF04 | Aprovado |
| CT19 | Resumo com os dados fictícios | RF06 | Aprovado |
| CT20 | Resumo sem ações realizadas | RF06 | Aprovado |
| CT21 | Limite de armazenamento atingido | RF07 | Aprovado |
| CT22 | Encerrar o sistema | RF08 | Aprovado |

## Detalhes de cada caso

### CT01 — Opção inexistente no menu

**Entradas:** `9`, `0`

**Verificado na saída:** “Opcao invalida! Digite um numero de 0 a 5.”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Opcao invalida! Digite um numero de 0 a 5.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT02 — Letras no lugar de número no menu

**Entradas:** `abc`, `0`

**Verificado na saída:** “Entrada invalida! Digite apenas numeros inteiros.”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Entrada invalida! Digite apenas numeros inteiros.
Opcao: Encerrando o sistema...
```

</details>

### CT03 — Cadastro completo válido

**Entradas:** `1`, `105`, `EM Vila Esperanca`, `Alimentacao saudavel`, `25/11/2026`, `Alunos do 4o ano`, `Nutricionista da UBS Vila`, `45`, `1`, `0`

**Verificado na saída:** “Acao 105 cadastrada com sucesso! (5 de 100 registros)”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- CADASTRAR ACAO -----
Codigo da acao: Escola: Tema: Data prevista (DD/MM/AAAA): Publico-alvo: Responsavel: Participantes previstos: Situacao inicial da acao:
1 - Planejada
2 - Realizada
3 - Cancelada
Situacao: Acao 105 cadastrada com sucesso! (5 de 100 registros)

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT04 — Código duplicado, zero, negativo e com letras

**Entradas:** `1`, `101`, `0`, `-3`, `abc`, `106`, `EM Jardim das Flores`, `Atividade fisica`, `02/12/2026`, `Alunos do 2o ano`, `Profissional de educacao fisica`, `30`, `1`, `0`

**Verificado na saída:** “Codigo ja cadastrado! Digite outro.”; “Codigo invalido! Digite um numero positivo.”; “Entrada invalida! Digite apenas numeros inteiros.”; “Acao 106 cadastrada com sucesso!”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- CADASTRAR ACAO -----
Codigo da acao: Codigo ja cadastrado! Digite outro.
Codigo da acao: Codigo invalido! Digite um numero positivo.
Codigo da acao: Codigo invalido! Digite um numero positivo.
Codigo da acao: Entrada invalida! Digite apenas numeros inteiros.
Codigo da acao: Escola: Tema: Data prevista (DD/MM/AAAA): Publico-alvo: Responsavel: Participantes previstos: Situacao inicial da acao:
1 - Planejada
2 - Realizada
3 - Cancelada
Situacao: Acao 106 cadastrada com sucesso! (5 de 100 registros)

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT05 — Campo obrigatório vazio

**Entradas:** `1`, `107`, `(vazio)`, `CE Parque Industrial`, `Saude mental`, `10/12/2026`, `Alunos do EM`, `Psicologa da eMulti`, `50`, `1`, `0`

**Verificado na saída:** “Campo obrigatorio! Nao pode ficar vazio.”; “Acao 107 cadastrada com sucesso!”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- CADASTRAR ACAO -----
Codigo da acao: Escola: Campo obrigatorio! Nao pode ficar vazio.
Escola: Tema: Data prevista (DD/MM/AAAA): Publico-alvo: Responsavel: Participantes previstos: Situacao inicial da acao:
1 - Planejada
2 - Realizada
3 - Cancelada
Situacao: Acao 107 cadastrada com sucesso! (5 de 100 registros)

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT06 — Texto maior que o campo

**Entradas:** `1`, `108`, `EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE`, `EM Vila Esperanca`, `Cultura de paz`, `01/02/2026/extra`, `01/12/2026`, `Alunos do 8o ano`, `Assistente social`, `40`, `1`, `0`

**Verificado na saída:** “Texto muito longo! Use no maximo 58 caracteres.”; “Texto muito longo! Use no maximo 13 caracteres.”; “Acao 108 cadastrada com sucesso!”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- CADASTRAR ACAO -----
Codigo da acao: Escola: Texto muito longo! Use no maximo 58 caracteres.
Escola: Tema: Data prevista (DD/MM/AAAA): Texto muito longo! Use no maximo 13 caracteres.
Data prevista (DD/MM/AAAA): Publico-alvo: Responsavel: Participantes previstos: Situacao inicial da acao:
1 - Planejada
2 - Realizada
3 - Cancelada
Situacao: Acao 108 cadastrada com sucesso! (5 de 100 registros)

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT07 — Previstos negativo e zero

**Entradas:** `1`, `109`, `EM Vila Esperanca`, `Atividade fisica`, `03/12/2026`, `Alunos do 7o ano`, `Profissional de educacao fisica`, `-10`, `0`, `35`, `1`, `0`

**Verificado na saída:** “A quantidade deve ser maior que zero!”; “Acao 109 cadastrada com sucesso!”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- CADASTRAR ACAO -----
Codigo da acao: Escola: Tema: Data prevista (DD/MM/AAAA): Publico-alvo: Responsavel: Participantes previstos: A quantidade deve ser maior que zero!
Participantes previstos: A quantidade deve ser maior que zero!
Participantes previstos: Situacao inicial da acao:
1 - Planejada
2 - Realizada
3 - Cancelada
Situacao: Acao 109 cadastrada com sucesso! (5 de 100 registros)

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT08 — Cadastro já com situação REALIZADA

**Entradas:** `1`, `110`, `EM Jardim das Flores`, `Saude bucal`, `05/11/2026`, `Alunos do 4o ano`, `Cirurgiao-dentista da UBS Jardim`, `40`, `2`, `-1`, `38`, `2`, `0`

**Verificado na saída:** “A quantidade nao pode ser negativa!”; “Acao 110 cadastrada com sucesso!”; “38 efetivos”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- CADASTRAR ACAO -----
Codigo da acao: Escola: Tema: Data prevista (DD/MM/AAAA): Publico-alvo: Responsavel: Participantes previstos: Situacao inicial da acao:
1 - Planejada
2 - Realizada
3 - Cancelada
Situacao: Participantes efetivos: A quantidade nao pode ser negativa!
Participantes efetivos: Acao 110 cadastrada com sucesso! (5 de 100 registros)

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- ACOES CADASTRADAS -----
----------------------------------------------
Codigo ........: 101   [REALIZADA]
Escola ........: EM Jardim das Flores
Tema ..........: Alimentacao saudavel
Data prevista .: 12/08/2026
Publico-alvo ..: Alunos do 5o ano
Responsavel ...: Nutricionista da UBS Jardim
Participantes .: 60 previstos | 54 efetivos
----------------------------------------------
Codigo ........: 102   [REALIZADA]
Escola ........: EM Vila Esperanca
Tema ..........: Atividade fisica
Data prevista .: 26/08/2026
Publico-alvo ..: Alunos do 6o ao 9o ano
Responsavel ...: Profissional de educacao fisica
Participantes .: 120 previstos | 97 efetivos
----------------------------------------------
Codigo ........: 103   [PLANEJADA]
Escola ........: CE Parque Industrial
Tema ..........: Alimentacao saudavel
Data prevista .: 18/11/2026
Publico-alvo ..: Alunos da 1a serie do EM
Responsavel ...: Nutricionista da UBS Centro
Participantes .: 80 previstos
----------------------------------------------
Codigo ........: 104   [CANCELADA]
Escola ........: EM Jardim das Flores
Tema ..........: Saude bucal
Data prevista .: 09/09/2026
Publico-alvo ..: Alunos do 1o ao 3o ano
Responsavel ...: Cirurgiao-dentista da UBS Jardim
Participantes .: 70 previstos
----------------------------------------------
Codigo ........: 110   [REALIZADA]
Escola ........: EM Jardim das Flores
Tema ..........: Saude bucal
Data prevista .: 05/11/2026
Publico-alvo ..: Alunos do 4o ano
Responsavel ...: Cirurgiao-dentista da UBS Jardim
Participantes .: 40 previstos | 38 efetivos
----------------------------------------------
Total: 5 acao(oes).

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT09 — Listar ações cadastradas

**Entradas:** `2`, `0`

**Verificado na saída:** “Total: 4 acao(oes).”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- ACOES CADASTRADAS -----
----------------------------------------------
Codigo ........: 101   [REALIZADA]
Escola ........: EM Jardim das Flores
Tema ..........: Alimentacao saudavel
Data prevista .: 12/08/2026
Publico-alvo ..: Alunos do 5o ano
Responsavel ...: Nutricionista da UBS Jardim
Participantes .: 60 previstos | 54 efetivos
----------------------------------------------
Codigo ........: 102   [REALIZADA]
Escola ........: EM Vila Esperanca
Tema ..........: Atividade fisica
Data prevista .: 26/08/2026
Publico-alvo ..: Alunos do 6o ao 9o ano
Responsavel ...: Profissional de educacao fisica
Participantes .: 120 previstos | 97 efetivos
----------------------------------------------
Codigo ........: 103   [PLANEJADA]
Escola ........: CE Parque Industrial
Tema ..........: Alimentacao saudavel
Data prevista .: 18/11/2026
Publico-alvo ..: Alunos da 1a serie do EM
Responsavel ...: Nutricionista da UBS Centro
Participantes .: 80 previstos
----------------------------------------------
Codigo ........: 104   [CANCELADA]
Escola ........: EM Jardim das Flores
Tema ..........: Saude bucal
Data prevista .: 09/09/2026
Publico-alvo ..: Alunos do 1o ao 3o ano
Responsavel ...: Cirurgiao-dentista da UBS Jardim
Participantes .: 70 previstos
----------------------------------------------
Total: 4 acao(oes).

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT10 — Listar com o sistema vazio

**Entradas:** `2`, `0`

**Verificado na saída:** “Nenhuma acao cadastrada ate o momento.”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 0 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- ACOES CADASTRADAS -----
Nenhuma acao cadastrada ate o momento.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT11 — Pesquisar código existente

**Entradas:** `3`, `1`, `102`, `0`

**Verificado na saída:** “Codigo ........: 102”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- PESQUISAR ACOES -----
1 - Por codigo
2 - Por escola
3 - Por tema
0 - Voltar
Pesquisar: Codigo: ----------------------------------------------
Codigo ........: 102   [REALIZADA]
Escola ........: EM Vila Esperanca
Tema ..........: Atividade fisica
Data prevista .: 26/08/2026
Publico-alvo ..: Alunos do 6o ao 9o ano
Responsavel ...: Profissional de educacao fisica
Participantes .: 120 previstos | 97 efetivos

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT12 — Pesquisar código inexistente

**Entradas:** `3`, `1`, `999`, `0`

**Verificado na saída:** “Nenhuma acao encontrada com o codigo 999.”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- PESQUISAR ACOES -----
1 - Por codigo
2 - Por escola
3 - Por tema
0 - Voltar
Pesquisar: Codigo: Nenhuma acao encontrada com o codigo 999.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT13 — Pesquisar escola por parte do nome

**Entradas:** `3`, `2`, `Jardim`, `0`

**Verificado na saída:** “2 acao(oes) encontrada(s).”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- PESQUISAR ACOES -----
1 - Por codigo
2 - Por escola
3 - Por tema
0 - Voltar
Pesquisar: Nome (ou parte do nome) da escola: ----------------------------------------------
Codigo ........: 101   [REALIZADA]
Escola ........: EM Jardim das Flores
Tema ..........: Alimentacao saudavel
Data prevista .: 12/08/2026
Publico-alvo ..: Alunos do 5o ano
Responsavel ...: Nutricionista da UBS Jardim
Participantes .: 60 previstos | 54 efetivos
----------------------------------------------
Codigo ........: 104   [CANCELADA]
Escola ........: EM Jardim das Flores
Tema ..........: Saude bucal
Data prevista .: 09/09/2026
Publico-alvo ..: Alunos do 1o ao 3o ano
Responsavel ...: Cirurgiao-dentista da UBS Jardim
Participantes .: 70 previstos
----------------------------------------------
2 acao(oes) encontrada(s).

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT14 — Pesquisar por tema

**Entradas:** `3`, `3`, `Alimentacao`, `0`

**Verificado na saída:** “2 acao(oes) encontrada(s).”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- PESQUISAR ACOES -----
1 - Por codigo
2 - Por escola
3 - Por tema
0 - Voltar
Pesquisar: Tema (ou parte do tema): ----------------------------------------------
Codigo ........: 101   [REALIZADA]
Escola ........: EM Jardim das Flores
Tema ..........: Alimentacao saudavel
Data prevista .: 12/08/2026
Publico-alvo ..: Alunos do 5o ano
Responsavel ...: Nutricionista da UBS Jardim
Participantes .: 60 previstos | 54 efetivos
----------------------------------------------
Codigo ........: 103   [PLANEJADA]
Escola ........: CE Parque Industrial
Tema ..........: Alimentacao saudavel
Data prevista .: 18/11/2026
Publico-alvo ..: Alunos da 1a serie do EM
Responsavel ...: Nutricionista da UBS Centro
Participantes .: 80 previstos
----------------------------------------------
2 acao(oes) encontrada(s).

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT15 — Pesquisa sem resultado e tipo inválido

**Entradas:** `3`, `7`, `3`, `Vacinacao`, `0`

**Verificado na saída:** “Opcao invalida! Digite um numero de 0 a 3.”; “Nenhuma acao encontrada para "Vacinacao".”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- PESQUISAR ACOES -----
1 - Por codigo
2 - Por escola
3 - Por tema
0 - Voltar
Pesquisar: Opcao invalida! Digite um numero de 0 a 3.
1 - Por codigo
2 - Por escola
3 - Por tema
0 - Voltar
Pesquisar: Tema (ou parte do tema): Nenhuma acao encontrada para "Vacinacao".

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT16 — Atualizar código inexistente

**Entradas:** `4`, `999`, `0`

**Verificado na saída:** “Registro inexistente! Nenhuma acao com o codigo 999.”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- ATUALIZAR SITUACAO -----
Codigo da acao: Registro inexistente! Nenhuma acao com o codigo 999.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT17 — Atualizar para REALIZADA com efetivos

**Entradas:** `4`, `103`, `5`, `2`, `-5`, `75`, `5`, `0`

**Verificado na saída:** “Opcao invalida! Digite 1, 2 ou 3.”; “A quantidade nao pode ser negativa!”; “Situacao da acao 103 atualizada para REALIZADA.”; “Planejadas: 0 | Realizadas: 3 | Canceladas: 1”; “Percentual de participacao: 86.9%”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- ATUALIZAR SITUACAO -----
Codigo da acao: ----------------------------------------------
Codigo ........: 103   [PLANEJADA]
Escola ........: CE Parque Industrial
Tema ..........: Alimentacao saudavel
Data prevista .: 18/11/2026
Publico-alvo ..: Alunos da 1a serie do EM
Responsavel ...: Nutricionista da UBS Centro
Participantes .: 80 previstos
Nova situacao:
1 - Planejada
2 - Realizada
3 - Cancelada
Situacao: Opcao invalida! Digite 1, 2 ou 3.
1 - Planejada
2 - Realizada
3 - Cancelada
Situacao: Participantes efetivos: A quantidade nao pode ser negativa!
Participantes efetivos: Situacao da acao 103 atualizada para REALIZADA.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- RESUMO GERAL -----
Acoes cadastradas: 4
Planejadas: 0 | Realizadas: 3 | Canceladas: 1
Participantes previstos (acoes realizadas): 260
Participantes efetivos  (acoes realizadas): 226
Percentual de participacao: 86.9%

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT18 — Atualizar para CANCELADA

**Entradas:** `4`, `101`, `3`, `5`, `0`

**Verificado na saída:** “Situacao da acao 101 atualizada para CANCELADA.”; “Participantes efetivos  (acoes realizadas): 97”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- ATUALIZAR SITUACAO -----
Codigo da acao: ----------------------------------------------
Codigo ........: 101   [REALIZADA]
Escola ........: EM Jardim das Flores
Tema ..........: Alimentacao saudavel
Data prevista .: 12/08/2026
Publico-alvo ..: Alunos do 5o ano
Responsavel ...: Nutricionista da UBS Jardim
Participantes .: 60 previstos | 54 efetivos
Nova situacao:
1 - Planejada
2 - Realizada
3 - Cancelada
Situacao: Situacao da acao 101 atualizada para CANCELADA.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- RESUMO GERAL -----
Acoes cadastradas: 4
Planejadas: 1 | Realizadas: 1 | Canceladas: 2
Participantes previstos (acoes realizadas): 120
Participantes efetivos  (acoes realizadas): 97
Percentual de participacao: 80.8%

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT19 — Resumo com os dados fictícios

**Entradas:** `5`, `0`

**Verificado na saída:** “Planejadas: 1 | Realizadas: 2 | Canceladas: 1”; “Participantes previstos (acoes realizadas): 180”; “Participantes efetivos  (acoes realizadas): 151”; “Percentual de participacao: 83.9%”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- RESUMO GERAL -----
Acoes cadastradas: 4
Planejadas: 1 | Realizadas: 2 | Canceladas: 1
Participantes previstos (acoes realizadas): 180
Participantes efetivos  (acoes realizadas): 151
Percentual de participacao: 83.9%

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT20 — Resumo sem ações realizadas

**Entradas:** `5`, `0`

**Verificado na saída:** “Percentual de participacao: nao aplicavel (nenhuma acao realizada).”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 0 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: 
----- RESUMO GERAL -----
Acoes cadastradas: 0
Planejadas: 0 | Realizadas: 0 | Canceladas: 0
Participantes previstos (acoes realizadas): 0
Participantes efetivos  (acoes realizadas): 0
Percentual de participacao: nao aplicavel (nenhuma acao realizada).

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT21 — Limite de armazenamento atingido

**Entradas:** `96 cadastros validos`, `1 (nova tentativa)`

**Verificado na saída:** “Limite de 100 registros atingido! Nao e possivel cadastrar.”

<details><summary>Ver saída</summary>

```
----- CADASTRAR ACAO -----
Limite de 100 registros atingido! Nao e possivel cadastrar.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>

### CT22 — Encerrar o sistema

**Entradas:** `0`

**Verificado na saída:** “Encerrando o sistema...”

<details><summary>Ver saída</summary>

```
Sistema iniciado com 4 acoes ficticias de demonstracao.

========== PSE EM ACAO ==========
1 - Cadastrar acao
2 - Listar acoes
3 - Pesquisar acoes
4 - Atualizar situacao
5 - Gerar resumo geral
0 - Sair
Opcao: Encerrando o sistema...
```

</details>
