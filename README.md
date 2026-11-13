# PSE em Ação

Sistema em C, rodando no terminal, para planejar e acompanhar ações do **Programa Saúde na Escola (PSE)**.

AEP do 2º semestre de 2026 — Engenharia de Software, UNICESUMAR Maringá (turma ESOFT2S-N-C).

**Vídeo de apresentação:** https://youtu.be/glHC6U0cs7Q

## Grupo

- Lucas Machado Feltrim Seco — RA 26012183-2 — [@lucasmfseco](https://github.com/lucasmfseco)
- Victor Henrique da Silva Stander — RA 26006004-2 — [@Victorstander](https://github.com/Victorstander)
- Fábio Henrique Soares Ferreira — RA 26006522-2 — [@fhsoares08](https://github.com/fhsoares08)

## Sobre o projeto

As equipes que acompanham as escolas do PSE costumam controlar as ações em cadernos e planilhas separadas, então fica difícil saber o que foi feito, o que foi cancelado e quantos alunos participaram. O sistema junta tudo num lugar só e mostra um resumo da participação.

A gente usou só dados fictícios. O programa não tem nenhum campo para nome, matrícula ou dado de saúde de aluno.

O que dá para fazer no menu:

1. Cadastrar ação (código, escola, tema, data, público-alvo, responsável, participantes previstos e situação)
2. Listar as ações
3. Pesquisar por código, escola ou tema
4. Atualizar a situação (planejada, realizada ou cancelada) e informar quantos participaram
5. Ver o resumo geral, com o percentual de participação
0. Sair

O programa já começa com 4 ações de exemplo, para facilitar os testes. Ele também trata entradas erradas, como código repetido, letras em campo de número, campo vazio e limite de 100 ações.

## Como rodar

**No Dev-C++:** abra o arquivo `src/pse_em_acao.c` e clique em **Executar > Compilar & Executar**.
Use o Embarcadero Dev-C++. O Dev-C++ 4.9.9.2 antigo não consegue gerar o executável no Windows 10/11.

**Pelo terminal (GCC):**

```
gcc -Wall src/pse_em_acao.c -o pse
./pse
```

## Pastas

- `src/` — código-fonte
- `testes/` — registro dos 22 testes que fizemos (todos passaram)
- `docs/entrega-1/` — documento da 1ª entrega
- `docs/entrega-2/` — documento final da 2ª entrega (casos de uso, testes, manual e considerações finais)
- `docs/fluxogramas/` — fluxogramas da 1ª entrega

## O que ainda dá para melhorar

- Os dados se perdem quando fecha o programa (seria bom salvar em arquivo).
- A data não tem o formato conferido.
- A pesquisa diferencia letra maiúscula de minúscula.
- Não tem como editar ou excluir uma ação.
