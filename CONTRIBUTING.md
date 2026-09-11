# 🤝 Guia de Contribuição & Setup de Ambiente

Obrigado pelo interesse em contribuir com o **Competitive Programming Hub** (`cp-training`)! Este guia contém as instruções passo a passo para configurar seu ambiente local após clonar o repositório, garantindo que os hooks do Git, ferramentas CLI e automações funcionem perfeitamente.

---

## 🚀 1. Configuração Rápida (Clone & Setup)

Ao clonar o repositório em uma nova máquina ou ambiente:

```bash
# 1. Clone o repositório
git clone https://github.com/GabrielFrigo4/cp-training.git
cd cp-training

# 2. Execute o setup automático (1 único comando)
make setup
```

### O que o `make setup` faz automaticamente?
1. **Ativa os Git Hooks versionados:** executa `git config core.hooksPath .githooks` para que o Git local passe a utilizar os scripts do repositório em vez de `.git/hooks/` locais.
2. **Concede permissões de execução:** aplica `chmod +x .githooks/*` e `chmod +x tools/cpt tools/cptool`.
3. **Valida pré-requisitos:** verifica se o compilador `g++` (com suporte a C++23) e o `python3` estão instalados no seu sistema.

---

### 🔧 Configuração Manual (Caso não tenha o `make`)
Se o comando `make` não estiver disponível no seu terminal, execute os comandos equivalentes manualmente:

```bash
# Concede permissão de execução aos hooks e ferramentas
chmod +x .githooks/*
chmod +x tools/cpt tools/cptool

# Configura o Git para usar a pasta .githooks
git config core.hooksPath .githooks
```

Para verificar se o Git Hook está ativo:
```bash
git config --get core.hooksPath
# Deve retornar: .githooks
```

---

## 📦 2. Pré-requisitos do Sistema

| Ferramenta | Versão Recomendada | Finalidade |
|---|---|---|
| **GCC / G++** | 13+ (ou 14/15/16) | Compilação com suporte completo a **C++23** (`-std=c++23`) |
| **Python** | 3.10 ou superior | Execução da CLI (`./tools/cpt`) e scripts de estatística (sem dependências externas) |
| **Make** | GNU Make 4+ | Automação unificada de testes, lint e setup |
| **Clipboard** *(opcional)* | `wl-clipboard` ou `xclip` | Cópia rápida de soluções para submissão via `./tools/cpt clip` |

---

## 🛠️ 3. Comandos Úteis do Makefile

O repositório possui um `Makefile` centralizado na raiz:

```bash
make help             # Exibe todos os comandos disponíveis com descrições
make setup            # Configura hooks, permissões e valida ferramentas
make test             # Executa a suíte de testes (CLI + compilação de algoritmos)
make test-algorithms  # Valida compilação de todos os headers de algorithms/ em C++23
make test-tool        # Executa testes unitários da ferramenta CLI
make lint             # Verifica sintaxe e assegura que não há binários no stage
make stats            # Exibe estatísticas consolidadas do repositório
make clean            # Remove executáveis compilados, temporários e saídas de teste
```

---

## 💻 4. Fluxo de Desenvolvimento de Soluções

### 4.1 Criar Novo Contest ou Problema
Sempre utilize a CLI `./tools/cpt` para manter a padronização das pastas:

```bash
# Exemplo 1: Criar contest do Codeforces com problemas A, B, C, D, E (C++23)
./tools/cpt new practice/codeforces/normal/div-2/round-1000 A B C D E

# Exemplo 2: Criar problema com template Python
./tools/cpt new practice/leetcode/dynamic-programming/coin-change --lang py

# Exemplo 3: Criar contest em Rust
./tools/cpt new practice/atcoder/beginner/abc-350 A B C --lang rs
```

### 4.2 Testar Localmente contra Exemplos
Abra a pasta do problema, cole os exemplos do enunciado em `input.txt` e a saída esperada em `expected.txt`:

```bash
# Executa e compara automaticamente com diff visual:
./tools/cpt run practice/codeforces/normal/div-2/round-1000/A
```
- Se a saída for idêntica: exibe `[ AC ]` com tempo de execução em milissegundos.
- Se houver divergência: exibe `[ WA ]` com diff unificado linha a linha.

### 4.3 Copiar para Submissão
Copie o código-fonte diretamente para a área de transferência do sistema operacional:
```bash
./tools/cpt clip practice/codeforces/normal/div-2/round-1000/A/main.cpp
```

---

## 📚 5. Adicionando Novos Algoritmos (`algorithms/`)

Ao implementar um novo algoritmo canônico ou estrutura de dados:
1. Crie o arquivo de cabeçalho modular em `algorithms/<categoria>/<nome>.hpp`.
2. Inclua `#pragma once` no início.
3. Não use `using namespace std;` no arquivo `.hpp`.
4. Documente o algoritmo no [HANDBOOK.md](file:///home/gabrielfrigo/Documentos/Personal/Competitive%20Computing/HANDBOOK.md) com sua respectiva complexidade temporal e espacial ($\mathcal{O}(N \log N)$).
5. Inclua o cabeçalho no arquivo de verificação [tests/test_algorithms.cpp](file:///home/gabrielfrigo/Documentos/Personal/Competitive%20Computing/tests/test_algorithms.cpp).
6. Rode `make test-algorithms` para validar que não há erros nem warnings de compilação com `-std=c++23`.

---

## 📝 6. Padrão de Mensagens de Commit

O repositório utiliza um hook `commit-msg` que valida o padrão **Conventional Commits**:

```text
<tipo>(<escopo opcional>): <descrição no imperativo>
```

### Tipos Permitidos:
- **`solution`**: Adição ou ajuste de solução de maratona ou treino (ex: `solution(codeforces): solve div2 1000 A`).
- **`algo`**: Nova estrutura ou algoritmo na biblioteca (ex: `algo(graphs): add dinic max flow`).
- **`feat`**: Nova funcionalidade na CLI ou automações (ex: `feat(cpt): add rust template support`).
- **`fix`**: Correção de bug em algoritmo, Makefile ou script (ex: `fix(makefile): fix stack-size linker flag`).
- **`docs`**: Atualização de documentação (ex: `docs(handbook): add fenwick tree tutorial`).
- **`refactor`**: Refatoração de código sem alterar comportamento.
- **`test`**: Adição ou alteração de testes unitários.
- **`chore`**: Tarefas de manutenção, git hooks ou CI/CD.

---

## 🛡️ 7. O que os Git Hooks Protegem?

- **`pre-commit`**:
  - Impede o commit acidental de arquivos executáveis compilados (`main`, `main_bin`, `*.exe`, `*.out`, `*.o`).
  - Impede commits com conflitos de merge não resolvidos (`<<<<<<<`, `=======`).
  - Bloqueia arquivos gigantes (> 5MB).
  - Valida a sintaxe de arquivos Python e C++ alterados.
- **`commit-msg`**:
  - Garante que todas as mensagens sigam o padrão Conventional Commits.
- **`pre-push`**:
  - Executa `make lint` antes de permitir o envio para o repositório remoto.
