---
name: cp-workflow
description: Guia de fluxo operacional para criação, teste e catalogação de soluções e algoritmos no repositório de Programação Competitiva usando cpt e Makefiles.
---

# Competitive Programming Workflow Skill

Este runbook instrui agentes de IA sobre o fluxo canônico de trabalho no repositório `cp-training`.

## 1. 🚀 Criar Novo Contest ou Problema

Sempre utilize a ferramenta CLI centralizada (`./tools/cpt`):

```bash
# Para um contest com múltiplos problemas (ex: A, B, C, D, E) em C++23:
./tools/cpt new practice/codeforces/normal/div-2/round-1000 A B C D E

# Para um único problema em Python:
./tools/cpt new practice/leetcode/dynamic-programming/coin-change --lang py

# Para um contest em Rust:
./tools/cpt new practice/atcoder/beginner/abc-350 A B C --lang rs
```

Isso gera automaticamente para cada pasta:
- `main.<ext>` com o template otimizado correspondente
- `input.txt` e `expected.txt`
- `Makefile` local configurado

## 2. 🧪 Testar e Validar Soluções

Após codificar a solução e preencher os exemplos em `input.txt` e `expected.txt`:

```bash
# Opção A: Usando a CLI do projeto
./tools/cpt run <caminho_da_pasta>
# Exemplo:
./tools/cpt run practice/codeforces/normal/div-2/round-1000/A

# Opção B: Entrando na pasta do problema e usando make
cd practice/codeforces/normal/div-2/round-1000/A
make test     # Roda e valida contra expected.txt
make run      # Executa contra input.txt
```

A CLI automaticamente calcula o tempo de execução em milissegundos e exibe `[ AC ]` (Accepted) ou o diff unificado em `[ WA ]` (Wrong Answer).

## 3. 📋 Copiar Código para Envio (Clipboard)

Quando a solução passar nos testes e estiver pronta para submissão:

```bash
./tools/cpt clip practice/codeforces/normal/div-2/round-1000/A/main.cpp
```

A ferramenta detecta automaticamente `wl-copy` (Wayland), `xclip` (X11) ou `clip.exe` (WSL).

## 4. 📚 Adicionar Novo Algoritmo à Biblioteca (`algorithms/`)

1. Crie o arquivo de cabeçalho modular em `algorithms/<categoria>/<nome>.hpp`.
2. Utilize `#pragma once` e tipos modernos de C++23.
3. Evite `using namespace std;` dentro do header.
4. Adicione o resumo com complexidades no [HANDBOOK.md](file:///home/gabrielfrigo/Documentos/Personal/Competitive%20Computing/HANDBOOK.md).
5. Rode `make test-algorithms` para validar que o novo cabeçalho compila sem warnings.
