# Competitive Programming Standards & Rules

Este arquivo define os padrões e diretrizes obrigatórias para escrita, compilação e validação de soluções no repositório.

## 1. ⚙️ Padrão C++23 e Compilação
- O padrão obrigatório para soluções C++ é **C++23** (`-std=c++23`).
- **Flags Canônicas de Compilação:**
  ```bash
  g++ -std=c++23 -O2 -Wall -Wextra -Wconversion -Wshadow -fsanitize=undefined \
      -Wl,-z,stack-size=268435456 main.cpp -o main
  ```
- **Recursão Profunda & Tamanho da Pilha:** Sempre assegure a flag `-Wl,-z,stack-size=268435456` ao compilar no Linux para evitar *Segmentation Fault (SIGSEGV)* em problemas com grafos e árvores recursivas profundas (DFS, Euler Tour, LCA).

## 2. ⚡ Fast I/O e Boas Práticas
- Toda solução em C++ deve incluir a inicialização de Fast I/O:
  ```cpp
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  ```
- Use `'\n'` em vez de `std::endl` (exceto em problemas interativos, onde flush explícito é exigido).
- Evite `using namespace std;` em arquivos de biblioteca/headers (`algorithms/*.hpp`). Em soluções de contest (`practice/` e `competitions/`), `using namespace std;` é permitido para agilidade.

## 3. ⏱️ Análise de Complexidade
- Todo algoritmo catalogado em `algorithms/` e documentado em `HANDBOOK.md` deve conter anotações explícitas de:
  - Complexidade de Tempo: $\mathcal{O}(f(N))$
  - Complexidade de Espaço: $\mathcal{O}(g(N))$
- Soluções de problemas devem respeitar o limite padrão de $1.0\text{s} \approx 10^8$ operações básicas.

## 4. 📁 Organização de Pastas
- **`practice/<plataforma>/<divisao>/<round>/<problema>/`**: Para treinos e plataformas online (Codeforces, AtCoder, CSES, LeetCode, VJudge).
- **`competitions/<evento>/<ano>/<problema>/`**: Para maratonas e seleções oficiais (ICPC SBC, Seletiva USP, OBI).
- **`algorithms/<categoria>/<nome>.hpp`**: Para implementações canônicas, modulares e reutilizáveis (header-only com `#pragma once`).
- Cada pasta de problema deve conter:
  - `main.cpp` (ou `main.py`, `main.rs`)
  - `input.txt` (casos de teste de exemplo)
  - `expected.txt` (saída esperada para validação automática)
  - `Makefile` (para compilação e teste local)
