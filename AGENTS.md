# 🤖 AGENTS.md — Guia de Instruções para Agentes de IA

Bem-vindo ao repositório **Competitive Programming Hub** (`cp-training`). Este documento serve como diretriz canônica e instrução primária para agentes de Inteligência Artificial (Antigravity, Claude, Copilot, Cursor, etc.) operando nesta base de código.

---

## 🎯 Missão e Escopo do Repositório

O objetivo deste projeto é ser um centro de treinamento, biblioteca de algoritmos e registro de soluções para competições de programação competitiva (ICPC, OBI, Codeforces, AtCoder, Seletiva USP, LeetCode, CSES e Advent of Code).

- **Foco:** Performance extrema, rigor algorítmico, modularidade e automação via terminal Linux.
- **Linguagens principais:**
  - **C++23** (linguagem primária para soluções de alta performance e algoritmos canônicos).
  - **Python 3.12+** (para automação, scripts auxiliares e problemas ad-hoc).
  - **Rust 2021** (para soluções que exigem segurança de memória e alta velocidade).
  - **C** (para soluções clássicas e de baixo nível).

---

## 🏗️ Arquitetura de Diretórios

```text
cp-training/
├── algorithms/               # Biblioteca canônica de algoritmos e estruturas de dados (.hpp)
├── competitions/             # Soluções de maratonas oficiais (ICPC, OBI, Seletiva USP, etc.)
├── practice/                 # Treinamento categorizado por plataforma (Codeforces, AtCoder, etc.)
├── templates/                # Templates otimizados por linguagem
├── tools/                    # Ferramenta CLI de produtividade (tools/cpt e tools/cp_tool.py)
├── tests/                    # Suíte de testes automatizados (CLI e compilação de algoritmos)
├── docs/                     # Documentação de ambiente e notas
├── .githooks/                # Git hooks versionados (pre-commit, commit-msg, pre-push)
├── .agents/                  # Workspace Customizations para agentes (rules e skills)
├── .github/workflows/        # Workflows de CI/CD (GitHub Actions)
├── Makefile                  # Makefile centralizado com automações de build, test e lint
├── HANDBOOK.md               # Caderno consolidado de algoritmos e fórmulas com LaTeX
├── CONTRIBUTING.md           # Guia de setup e contribuição para novos clones
└── README.md                 # Visão geral do repositório
```

---

## ⚙️ Convenções Técnicas e Flags Canônicas

### 1. C++23 (GCC)
- O padrão obrigatório é **C++23** (`-std=c++23`).
- **Flags recomendadas de compilação:**
  ```bash
  g++ -std=c++23 -O2 -Wall -Wextra -Wl,-z,stack-size=268435456 main.cpp -o main
  ```
- **Tamanho de Pilha (Stack Size):** A flag `-Wl,-z,stack-size=268435456` (256 MB) é fundamental em sistemas Linux para evitar *Segmentation Fault* por estouro de pilha de recursão (como em buscas DFS profundas e Euler Tour).
- **Fast I/O:** Toda solução C++ deve desvincular as streams padrão:
  ```cpp
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  ```
- Use `'\n'` em vez de `std::endl` para evitar descargas desnecessárias do buffer.

### 2. Biblioteca Canônica (`algorithms/`)
- Mantenha headers modulares com `#pragma once`.
- Não inclua `using namespace std;` dentro dos headers da pasta `algorithms/`.
- Cada novo algoritmo implementado deve ser registrado no [HANDBOOK.md](file:///home/gabrielfrigo/Documentos/Personal/Competitive%20Computing/HANDBOOK.md) com sua respectiva complexidade temporal e espacial em LaTeX ($\mathcal{O}(V + E)$, $\mathcal{O}(N \log N)$).

---

## 🛠️ Automação e Ferramentas Disponíveis para o Agente

### 1. Makefile Centralizado
Ao trabalhar no repositório, utilize sempre o Makefile raiz para executar validações:
- `make setup`: Ativa os githooks locais e verifica ferramentas do sistema.
- `make test`: Roda a suíte completa de testes (CLI Python + Compilação C++23 de todos os algoritmos).
- `make test-algorithms`: Compila `tests/test_algorithms.cpp` garantindo zero erros e warnings na biblioteca.
- `make test-tool`: Executa testes unitários de `tools/cp_tool.py`.
- `make lint`: Verifica ausência de binários e valida sintaxe Python.
- `make stats`: Exibe estatísticas de problemas resolvidos no repositório.
- `make clean`: Limpa arquivos temporários (`output.txt`, `main_bin`, etc.).

### 2. Utilitário CLI (`./tools/cpt`)
Para criar novos problemas ou contests:
```bash
# Criação de contest com múltiplos problemas:
./tools/cpt new practice/codeforces/normal/div-2/round-1000 A B C D

# Testar um problema contra input.txt e expected.txt:
./tools/cpt run practice/codeforces/normal/div-2/round-1000/A

# Copiar solução para o clipboard do sistema:
./tools/cpt clip practice/codeforces/normal/div-2/round-1000/A/main.cpp

# Consultar estatísticas:
./tools/cpt stats
```

---

## 🛡️ Regras de Segurança e Higiene (Guardrails)

1. **NUNCA faça commit de binários compilados:**
   - O hook `pre-commit` bloqueia extensões como `.exe`, `.out`, `main`, `main_bin`, `.o`, `.a`.
   - Sempre execute `make clean` antes de preparar commits se gerou binários locais.
2. **NUNCA commite arquivos de saída de testes:**
   - Arquivos `output.txt`, `actual.txt`, `diff.txt`, `.tmp` são temporários.
   - `input.txt` e `expected.txt` são os únicos arquivos de teste persistidos na pasta do problema.
3. **Padrão de Commit (Conventional Commits):**
   - O hook `commit-msg` exige mensagens formatadas como:
     - `solution(codeforces): solve div2 1000 problem A`
     - `algo(graphs): add dinic max flow`
     - `feat(tools): enhance cpt test runner`
     - `docs(handbook): document segment tree complexity`
     - `fix(makefile): adjust linker flag`
   - Tipos válidos: `feat`, `fix`, `refactor`, `docs`, `style`, `test`, `chore`, `perf`, `ci`, `solution`, `algo`.
4. **Preservação de Soluções Existentes:**
   - Não delete nem quebre soluções já consolidadas ao fazer refatorações ou manutenções na estrutura.
