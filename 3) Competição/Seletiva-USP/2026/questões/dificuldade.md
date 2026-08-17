# Seletiva USP 2026 — Guia e Classificação das Questões por Dificuldade

Este documento contém o mapeamento e análise de dificuldade de todos os 12 problemas da **Seletiva para a Maratona de Programação de 2026 (IME-USP)**, com base no caderno oficial.

---

## 📊 Visão Geral e Tabela de Dificuldade

| # | Problema | Nome | Nível Estimado | Tópicos Principais | Complexidade Esperada |
|---|:---:|---|:---:|---|:---:|
| 1 | **C** | Economizando Espaço | 🟢 Muito Fácil | Strings, Run-Length Encoding | $\mathcal{O}(\|S\|)$ |
| 2 | **L** | Cópias do GePeTo | 🟢 Muito Fácil | Frequência, Hash Map, Ordenação | $\mathcal{O}(N)$ ou $\mathcal{O}(N \log N)$ |
| 3 | **J** | Está a par disso? | 🟡 Fácil | Kadane, Paridade, Subarray Máximo | $\mathcal{O}(N)$ |
| 4 | **B** | Troca de Casas | 🟡 Fácil / Médio-Fácil | Permutações, Decomposição em Ciclos, Guloso | $\mathcal{O}(N)$ |
| 5 | **K** | Catraca | 🟡 Médio-Fácil | Dígitos, Backtracking / Busca Gulosa | $\mathcal{O}(T \cdot \text{dígitos})$ |
| 6 | **G** | Os Quatro Quatros | 🟡 Médio-Fácil | Pré-computação, Busca / BFS, Expressões | $\mathcal{O}(1)$ via lookup / offline |
| 7 | **H** | Mineração de Teotonium | 🟠 Médio | SQRT Decomposition, Prefix Sums | $\mathcal{O}((N + Q)\sqrt{N})$ |
| 8 | **A** | Scrabble | 🟠 Médio-Avançado | Aho-Corasick / Suffix Automaton, DP em DAG | $\mathcal{O}(\sum \|w\|)$ |
| 9 | **F** | Rede de Esconderijos | 🟠 Médio-Avançado | Centroid Decomposition, FFT / DSU on Tree | $\mathcal{O}(N \log^2 N)$ |
| 10 | **D** | Escape | 🔴 Avançado | Probabilidade, Expectimax, DP com Estados | $\mathcal{O}(T \cdot \text{estados})$ |
| 11 | **E** | Ataque de Timeout | 🔴 Avançado | Teoria de Jogos, Grundy, Hipercubo | $\mathcal{O}(2^n)$ construtivo |
| 12 | **I** | Rota de Colisão | 🔴 Muito Difícil | Geometria Computacional, Minkowski, Sweepline | $\mathcal{O}((N + M) \log (N + M))$ |

---

## 🎯 Ordem Recomendada de Resolução (Roadmap)

Para maximizar a pontuação e o tempo em contest:

```text
[ C ] ──> [ L ] ──> [ J ] ──> [ B ] ──> [ K ] ──> [ G ] ──> [ H ] ──> [ A / F ] ──> [ D / E / I ]
```

---

## 📝 Detalhamento das Questões

### 🟢 Tier 1: As Mais Fáceis (Primeiros Balões)

#### **Problema C: Economizando Espaço**
- **Enunciado Resumido:** Dada uma string de até $1000$ caracteres minúsculos, aplicar compressão *Run-Length* substituindo repetições consecutivas de um caractere `c` por `c + n` (apenas se $n > 1$).
- **Estratégia:** Dois ponteiros ou iteração linear simples contando caracteres consecutivos iguais.
- **Dificuldade:** ⭐

#### **Problema L: Cópias do GePeTo**
- **Enunciado Resumido:** Dado um vetor $A$ com $N \le 2 \cdot 10^5$ elementos, contar a quantidade de pares $(i, j)$ com $i < j$ tais que $A_i = A_j$.
- **Estratégia:** Contar a frequência de cada elemento usando `std::map`, `std::unordered_map` ou ordenando o vetor. Para cada frequência $cnt$, acumular $\frac{cnt \cdot (cnt - 1)}{2}$ em uma variável de 64 bits (`long long`).
- **Dificuldade:** ⭐

---

### 🟡 Tier 2: Fáceis e Médio-Fáceis (Ideia Elegante)

#### **Problema J: Está a par disso?**
- **Enunciado Resumido:** Dado $A$ ($N \le 2000$), podemos escolher um $X \ge 1$ e um intervalo $[L, R]$, somando $X$ a todos os elementos em $A[L..R]$. Maximizar a quantidade final de números pares.
- **Estratégia:** 
  - Se $X$ for par, a paridade não se altera.
  - Se $X$ for ímpar, os pares em $[L, R]$ viram ímpares (perda de 1 par) e os ímpares viram pares (ganho de 1 par).
  - Transforme o vetor em $B_i = +1$ se $A_i$ for ímpar e $B_i = -1$ se $A_i$ for par. O problema se torna encontrar o subarray de soma máxima (**Algoritmo de Kadane**). Resposta: $\text{pares\_iniciais} + \max(0, \text{kadane}(B))$.
- **Dificuldade:** ⭐⭐

#### **Problema B: Troca de Casas**
- **Enunciado Resumido:** Dada uma permutação $\pi$ de $1 \dots N$ ($N \le 2 \cdot 10^5$), podemos trocar $\pi(i)$ com $\pi(j)$ (ou manter inalterada) para maximizar o tamanho do menor ciclo.
- **Estratégia:**
  - Decompor a permutação em seus ciclos disjuntos.
  - Trocar elementos de ciclos distintos une os dois ciclos em um só de tamanho $C_1 + C_2$.
  - Se houver apenas 1 ciclo, já é ótimo (resposta $N$).
  - Se houver 2 ou mais ciclos, una os dois menores ciclos. O novo menor ciclo será $\min(C_1 + C_2, C_3)$ (ou $N$ se só haviam 2 ciclos).
- **Dificuldade:** ⭐⭐

#### **Problema K: Catraca**
- **Enunciado Resumido:** Dado $C$ ($1 \le C \le 10^{10}$), encontrar o menor $P \ge 0$ tal que $C + P$ possui todos os dígitos distintos na base 10 (ou $-1$ se impossível). $T \le 10^5$ casos de teste.
- **Estratégia:**
  - O maior número com dígitos distintos é $9876543210$. Se $C > 9876543210$, a resposta é $-1$.
  - Existem apenas cerca de $8.87 \times 10^6$ números com dígitos distintos. É possível gerar o próximo número válido de forma gulosa a partir dos dígitos de maior ordem ou pré-computar/fazer busca binária.
- **Dificuldade:** ⭐⭐

#### **Problema G: Os Quatro Quatros**
- **Enunciado Resumido:** Construir uma expressão matemática que resulte em $X$ ($0 \le X \le 70$) usando exatamente quatro dígitos 4 e operadores permitidos (`+`, `-`, `*`, `/`, `^`, `()`, `.`, `sqrt`, `!`).
- **Estratégia:**
  - Como o domínio de $X$ é minúsculo ($0 \le X \le 70$), a maneira mais eficiente é escrever um pequeno script offline (ou busca BFS) para encontrar uma expressão válida para cada $X \in [0, 70]$ e embutir as 71 strings como uma tabela de consulta constante no código.
- **Dificuldade:** ⭐⭐

---

### 🟠 Tier 3: Intermediárias e Avançadas

#### **Problema H: Mineração de Teotonium**
- **Tópico:** *SQRT Decomposition*
- **Ideia:** $Q$ consultas de soma com $i \equiv X \pmod M$. Para $M \le \sqrt{N}$, pré-calculam-se somas de prefixo; para $M > \sqrt{N}$, itera-se em passos de tamanho $M$ (no máximo $\sqrt{N}$ passos).

#### **Problema A: Scrabble**
- **Tópico:** *String Matching* / Aho-Corasick + DP
- **Ideia:** Contar sequências de palavras onde cada palavra contém a anterior como substring. Constrói-se a árvore de sufixos/Aho-Corasick para determinar transições em um DAG e executa-se programação dinâmica com contagem de caminhos mod $10^9+7$.

#### **Problema F: Rede de Esconderijos**
- **Tópico:** Árvores / Centroid Decomposition + FFT
- **Ideia:** Contar pares de folhas a distância $X$ para $Q \le 10$. Requer decomposição em centróides e convolução polinomial (FFT) para combinar contagens de subárvores eficientemente.

---

### 🔴 Tier 4: Problemas Difíceis

- **Problema D (Escape):** MDP / Expectimax sobre os estados dos dados e decisões de reroll com limite de $K \le 5$ turnos.
- **Problema E (Ataque de Timeout):** Teoria combinatória de jogos em hipercubo booleano ($n \le 20$).
- **Problema I (Rota de Colisão):** Geometria computacional avançada para calcular a varredura linear de um polígono convexo sobre nuvem de pontos.

---

## 📌 Checklist de Progresso

- [ ] **C** — Economizando Espaço
- [ ] **L** — Cópias do GePeTo
- [ ] **J** — Está a par disso?
- [ ] **B** — Troca de Casas
- [ ] **K** — Catraca
- [ ] **G** — Os Quatro Quatros
- [ ] **H** — Mineração de Teotonium
- [ ] **A** — Scrabble
- [ ] **F** — Rede de Esconderijos
- [ ] **D** — Escape
- [ ] **E** — Ataque de Timeout
- [ ] **I** — Rota de Colisão
