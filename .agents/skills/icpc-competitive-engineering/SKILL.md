---
name: icpc-competitive-engineering
description: Runbook cognitivo de engenharia para programação competitiva e maratona (ICPC, SBC, Codeforces). Cobre templates C++23 com fast I/O, estratégias de contest, stress-testing com oráculos e análise assintótica rigorosa.
---

# ICPC Competitive Engineering Skill

Este runbook instrui agentes autônomos na concepção, otimização, teste adversarial e catalogação de soluções para competições de programação (ICPC SBC, Codeforces, AtCoder, CSES, LeetCode).

## 1. Templates C++23 e Fast I/O Mandatório

Soluções em C++ MUST utilizar o padrão C++23 (`-std=c++23`) com flags de otimização e pilha:

```bash
g++ -std=c++23 -O2 -Wall -Wextra -Wconversion -Wshadow -fsanitize=undefined \
    -Wl,-z,stack-size=268435456 main.cpp -o main
```

Todo programa C++ MUST desvincular as streams padrão e MUST NOT usar `std::endl`:

```cpp
#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();
    // Use '\n' em vez de endl para evitar flush síncrono
    return 0;
}
```

- **Prevenção de TLE/MLE:** Soluções MUST pré-alocar memória via `vector::reserve()` ou arrays estáticos. Evite alocações repetidas em loops quentes.
- **Tipagem Defensiva:** Utilize `int64_t` ou `long long` sempre que somas, produtos ou valores acumulados puderem exceder $2 \times 10^9$.

## 2. Estratégias de Maratona e Fluxo Operacional

### Automação via CLI (`./tools/cpt`) e Makefile

- **Criação de Problemas/Contests:**
    ```bash
    ./tools/cpt new practice/codeforces/normal/div-2/round-1000 A B C D E
    ```
- **Execução e Validação:**
    ```bash
    ./tools/cpt run <caminho_do_problema>   # ou `make test` dentro da pasta
    ```
- **Clipboard para Submissão:**
    ```bash
    ./tools/cpt clip <caminho_do_problema>/main.cpp
    ```

### Gestão Tática de Contest

1. **Triagem Inicial:** Ler todo o caderno de problemas rapidamente. Agentes SHOULD identificar problemas de implementação direta antes de abordar estruturas pesadas.
2. **Controle de Penalty:** Agentes MUST NOT submeter código sem validação local prévia de corner cases ($N=0, 1$, grafos desconexos, limites superiores $10^9, 10^{18}$).
3. **Congelamento do Placar (Scoreboard Freeze):** Na última hora da maratona, equipes SHOULD priorizar problemas parcialmente codificados com maior probabilidade de aceite.

## 3. Stress-Testing Adversarial e Oráculos

Quando uma solução apresentar Wrong Answer (WA) em testes ocultos, agentes MUST implementar pipeline de stress-test:

1. **Gerador Aleatório (`gen.py`):** Produz entradas válidas dentro dos limites do problema:
    ```python
    import random

    n = random.randint(1, 10)
    print(n)
    print(*(random.randint(1, 100) for _ in range(n)))
    ```
2. **Solução Força-Bruta (`brute.cpp`):** Algoritmo garantidamente correto ($\mathcal{O}(N!)$ ou $\mathcal{O}(N^2)$).
3. **Loop de Verificação Automatizado (`stress.sh`):**
    ```bash
    while true; do
        python3 gen.py > in.txt
        ./main < in.txt > out_opt.txt
        ./brute < in.txt > out_brute.txt
        diff -u out_opt.txt out_brute.txt || break
    done
    ```

## 4. Análise Rigorosa de Complexidade Assintótica

Toda solução ou algoritmo de biblioteca (`algorithms/`) MUST documentar formalmente:

- **Complexidade Temporal:** $\mathcal{O}(f(N))$ compatível com o limite de tempo ($1.0\text{s} \approx 10^8$ operações básicas):
    - $N \le 10$: $\mathcal{O}(N!)$ ou $\mathcal{O}(2^N \cdot N^2)$
    - $N \le 20$: $\mathcal{O}(2^N \cdot N)$
    - $N \le 500$: $\mathcal{O}(N^3)$ (Floyd-Warshall)
    - $N \le 5000$: $\mathcal{O}(N^2)$ (DP quadrática)
    - $N \le 2 \times 10^5$: $\mathcal{O}(N \log N)$ (Segment Tree, Ordenação)
    - $N \le 10^7$: $\mathcal{O}(N)$ (Two pointers, Crivo linear)
    - $N > 10^9$: $\mathcal{O}(\log N)$ ou $\mathcal{O}(1)$ (Busca binária, Exponenciação modular)
- **Complexidade Espacial:** $\mathcal{O}(g(N))$ respeitando o teto de memória (geralmente 256MB ou 512MB). Evite recursão além de $10^6$ sem ajustar o stack-size.
