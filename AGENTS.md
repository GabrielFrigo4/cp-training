# 🤖 Competitive Computing Hub — AI Agent Briefing

> Centro de treinamento, biblioteca de algoritmos e registro de soluções para competições de programação competitiva (ICPC, OBI, Codeforces, AtCoder).

---

## 🧭 Identidade e Papel

O repositório **Competitive Programming Hub** (`cp-training`) serve como centro de treinamento e biblioteca canônica de algoritmos:

- **Foco:** Performance extrema, rigor algorítmico, modularidade e automação via terminal Linux.
- **Linguagens principais:**
    - **C++23** (linguagem primária para soluções de alta performance e algoritmos canônicos).
    - **Python 3.12+** (para automação, scripts auxiliares e problemas ad-hoc).
    - **Rust 2021** (para soluções que exigem segurança de memória e alta velocidade).
    - **C** (para soluções clássicas e de baixo nível).

---

## 📁 Estrutura do Repositório

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
├── LEARNING.md               # Roteiro de aprendizagem e tópicos
├── LICENSE                   # Licença MIT
├── PRINCIPLES.md             # 22 Princípios de Engenharia adaptados
├── README.md                 # Visão geral do repositório
└── TODO.md                   # Backlog de treinamento e matriz de cobertura
```

---

## ⚠️ Regras Críticas para Agentes de IA

### Convenções Técnicas e Flags Canônicas

### 1. C++23 (GCC)

- O padrão obrigatório é **C++23** (`-std=c++23`).
- **Flags recomendadas de compilação:**
    ```bash
    g++ -std=c++23 -O2 -Wall -Wextra -Wl,-z,stack-size=268435456 main.cpp -o main
    ```
- **Tamanho de Pilha (Stack Size):** A flag `-Wl,-z,stack-size=268435456` (256 MB) é fundamental em sistemas Linux para evitar _Segmentation Fault_ por estouro de pilha de recursão (como em buscas DFS profundas e Euler Tour).
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

### Automação e Ferramentas Disponíveis para o Agente

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

### Regras de Segurança e Higiene (Guardrails)

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

5. **Taxonomia Tripartite de Comentários:** O código adota estritamente três categorias: 1. Comentários de Sistema = PERMITIDOS (shebangs, pragmas, linters); 2. Comentários Estruturais de 64/32 colunas = PERMITIDOS (cabeçalhos de 64 `-`, seções de 32 colunas `### ===` e `### ---` com títulos em MAIÚSCULO, réguas de 64 `=` em `.gitignore` com títulos em MAIÚSCULO, sem vazamento); 3. Comentários Explicativos/Narrativos = PROIBIDOS em código, configs E blocos de código dentro de Markdowns.

---

---

## 🛡️ Regra da Proatividade e Correção Contínua (Boy Scout Rule)

O agente de IA atua de forma proativa na manutenção e aplicação dos padrões canônicos deste repositório.

Ao identificar linhas ou artefatos fora dos padrões estabelecidos:

1. **Notificar concisamente** o usuário sobre o ajuste realizado.
2. **Corrigir a inconformidade**, aplicando o padrão correspondente:
    - **Taxonomia Tripartite de Comentários:** Eliminar comentários explicativos óbvios em código, configs e blocos de código em Markdowns, preservando exclusivamente comentários de sistema e delimitadores estruturais (64/32 colunas).
    - **Banners Estruturais:** Ajustar réguas para exatamente 64 hífens no topo ou 32 caracteres com `### ` no corpo (ou 64 `=` em `.gitignore`), com títulos sempre em MAIÚSCULO.
    - **Portabilidade POSIX:** Substituir bashismos (`[[ ]]`, `&>`, arrays, `source`) por sintaxe estrita POSIX `/bin/sh`.
    - **Shebang Universal:** Garantir sempre `#!/usr/bin/env sh` ou `#!/usr/bin/env python3`.
    - **Sequências ANSI & Escapes:** Não use octais (`\033`, `\001`) para caracteres ou escapes. Use `[ -t 1 ] && echo -n $\x27\e...\x27` ou notação hexadecimal (`\x01`, `\x1b`). Octal é exclusivo para permissões POSIX (`chmod 0755`, `chmod 0644`, `umask`).
    - **Redirecionamento Seguro:** Envolver destinos em aspas duplas (ex: `> "/dev/null" 2>&1`).
    - **Makefiles:** Assegurar cabeçalho `.POSIX: .SILENT:`, `MAKEFLAGS += --no-print-directory -s`, alinhamento estético de variáveis e zero `@` redundante.
    - **Permissões Canônicas:** Aplicar 4 dígitos octais (`chmod 0755`, `chmod 0644`, `chmod 0700`, `chmod 0600`).
    - **Invariante Out-of-the-Box:** Garantir modos octais corretos no Git Index e auto-cura em tempo de execução sem requerer intervenção manual pós-clone.
    - **Emissão Semântica de UI:** Substituir `echo` avulsos com emojis pelas rotinas canônicas `_ui_*`.
    - **Antifragilidade & Resiliência:** Resolução ativa de caminhos em cascata, auto-cura de permissões (0600 em chaves/segredos) e validação defensiva de pré-requisitos.
    - **Curadoria Cognitiva:** Capturar decisões estruturais e regras tácitas em skills locais compactas (`.agents/skills/`), mantendo-as atualizadas e expurgando ruído obsoleto.
    - **Refatoração Sem Legado:** Expurgar aliases obsoletos, variáveis mortas e shims de compatibilidade em renomeações.
    - **Elevação Antifrágil & Shift Seguro:** Usar o bloco explícito `if [ "$(id -u)" -ne 0 ]` para resolução de `ELEVATE` (evitando término fatal sob `set -e` como root) e proteger todo comando `shift` com validação prévia de parâmetros (`[ "$#" -ge N ] && shift N`).
    - **Simetria de Documentação:** Mover regras ou invariantes universais documentadas erroneamente em sub-membros específicos para o documento de arquitetura do grupo correspondente, eliminando falsas assimetrias.

---

## 🚀 Comandos de Verificação Rápida (Quality Gates)

| Comando               | Finalidade Operacional                                               |
| :-------------------- | :------------------------------------------------------------------- |
| `make help`           | Exibe o catálogo completo de tarefas operacionais                    |
| `make setup`          | Configura permissões e ganchos em `.githooks/`                       |
| `make test`           | Executa a suíte completa de testes automatizados                     |
| `make lint`           | Valida linters e integridade estática do repositório                 |
| `make check-binaries` | Verifica se existem binários compilados indevidamente no repositório |
| `make format`         | Aplica formatação automática em arquivos de código                   |
| `make prettier`       | Formata arquivos Markdown e JSON com Prettier                        |
| `make clean`          | Remove binários compilados, saídas de teste e temporários            |
| `make ci`             | Executa a pipeline local completa de validação integrada             |

---

## 📖 Referências Obrigatórias

Antes de qualquer modificação neste ecossistema, consulte:

- [README.md](README.md) — Visão geral e catálogo do treinamento
- [PRINCIPLES.md](PRINCIPLES.md) — 22 Princípios de Engenharia adaptados
- [HANDBOOK.md](HANDBOOK.md) — Caderno consolidado de algoritmos e fórmulas
- [CONTRIBUTING.md](CONTRIBUTING.md) — Guia de contribuição e convenções locais
- [LEARNING.md](LEARNING.md) — Roteiro de aprendizagem e tópicos competitivos
- [TODO.md](TODO.md) — Backlog de treino e matriz de cobertura
- [LICENSE](LICENSE) — Licença MIT do projeto
- [Makefile](Makefile) — Catálogo de automação e scripts de build
- [.agents/rules/code-hygiene.md](.agents/rules/code-hygiene.md) — Diretrizes de higiene de código
- [.agents/rules/competitive-programming.md](.agents/rules/competitive-programming.md) — Convenções de CP
- [.agents/skills/icpc-competitive-engineering/SKILL.md](.agents/skills/icpc-competitive-engineering/SKILL.md) — Runbook de engenharia competitiva
