# 📖 Competitive Programming Handbook & Algorithms Reference

Um guia abrangente e moderno de algoritmos, estruturas de dados, técnicas de otimização e fórmulas matemáticas para maratonas de programação (ICPC, OBI, Codeforces, AtCoder).

---

## 📑 Tabela de Conteúdos

1. [⚡ Setup & Otimizações](#1--setup--otimizações)
2. [🏗️ Estruturas de Dados](#2-️-estruturas-de-dados)
3. [🌐 Teoria dos Grafos](#3--teoria-dos-grafos)
4. [🔢 Matemática & Teoria dos Números](#4--matemática--teoria-dos-números)
5. [🧩 Programação Dinâmica](#5--programação-dinâmica)
6. [🔤 Algoritmos em Strings](#6--algoritmos-em-strings)
7. [📐 Geometria Computacional](#7--geometria-computacional)

---

## 1. ⚡ Setup & Otimizações

### 1.1 Fast I/O em C++
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Desvincula streams C/C++ e desativa flush automático
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // Use '\n' em vez de endl para evitar flush desnecessário
    return 0;
}
```

### 1.2 Pragmas de Otimização GCC
```cpp
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
```

### 1.3 Flags de Compilação Recomendadas
```bash
g++ -std=c++23 -O2 -Wall -Wextra -Wconversion -Wshadow -fsanitize=undefined -Wl,-z,stack-size=268435456 main.cpp -o main
```

---

## 2. 🏗️ Estruturas de Dados

### 2.1 Disjoint Set Union (DSU / Union-Find)
Estrutura para gerenciar conjuntos disjuntos com **Path Compression** e **Union by Size/Rank**.
- **Complexidade:** $\mathcal{O}(\alpha(N))$ por operação quase linear ($\alpha(N) \le 4$).

```cpp
struct DSU {
    int n;
    vector<int> parent_or_size;

    explicit DSU(int n) : n(n), parent_or_size(n, -1) {}

    int leader(int a) {
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    bool same(int a, int b) { return leader(a) == leader(b); }

    bool merge(int a, int b) {
        int x = leader(a), y = leader(b);
        if (x == y) return false;
        if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return true;
    }

    int size(int a) { return -parent_or_size[leader(a)]; }
};
```

### 2.2 Fenwick Tree (Binary Indexed Tree - BIT)
Atualização pontual e consulta de soma de prefixos em $\mathcal{O}(\log N)$.

```cpp
template <typename T = int64_t>
struct FenwickTree {
    int n;
    vector<T> tree;

    explicit FenwickTree(int n = 0) : n(n), tree(n + 1, 0) {}

    void add(int i, T delta) {
        for (++i; i <= n; i += i & -i) tree[i] += delta;
    }

    T query(int i) const {
        T sum = 0;
        for (++i; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }

    T query(int l, int r) const {
        if (l > r) return 0;
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};
```

### 2.3 Sparse Table (Range Minimum Query em $\mathcal{O}(1)$)
Pré-processamento em $\mathcal{O}(N \log N)$ e consulta em $\mathcal{O}(1)$ para funções idempotentes ($\min, \max, \gcd$).

```cpp
template <typename T>
struct SparseTable {
    int n, K;
    vector<vector<T>> st;

    SparseTable(const vector<T>& a) : n(a.size()), K(bit_width((unsigned)n)) {
        st.assign(K, vector<T>(n));
        st[0] = a;
        for (int j = 1; j < K; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T query_min(int l, int r) const {
        int j = bit_width((unsigned)(r - l + 1)) - 1;
        return min(st[j][l], st[j][r - (1 << j) + 1]);
    }
};
```

---

## 3. 🌐 Teoria dos Grafos

### 3.1 Dijkstra (Caminho Mínimo em Grafos com Pesos Não-Negativos)
- **Complexidade:** $\mathcal{O}((V + E) \log V)$

```cpp
template <typename T = int64_t>
vector<T> dijkstra(int source, int n, const vector<vector<pair<int, T>>>& adj, T INF = 1e18) {
    vector<T> dist(n, INF);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;

    dist[source] = 0;
    pq.emplace(0, source);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}
```

### 3.2 Lowest Common Ancestor (LCA) via Binary Lifting
- **Pré-cálculo:** $\mathcal{O}(N \log N)$
- **Consulta:** $\mathcal{O}(\log N)$

```cpp
struct LCA {
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> up;

    LCA(int n, int root, const vector<vector<int>>& adj) : n(n), LOG(__lg(n) + 1), depth(n), up(n, vector<int>(LOG)) {
        auto dfs = [&](auto self, int u, int p, int d) -> void {
            depth[u] = d;
            up[u][0] = p;
            for (int i = 1; i < LOG; ++i) up[u][i] = up[up[u][i - 1]][i - 1];
            for (int v : adj[u]) {
                if (v != p) self(self, v, u, d + 1);
            }
        };
        dfs(dfs, root, root, 0);
    }

    int get_lca(int u, int v) const {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; ++i) if ((diff >> i) & 1) u = up[u][i];
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
};
```

---

## 4. 🔢 Matemática & Teoria dos Números

### 4.1 Exponenciação Rápida e Inverso Modular
$$a^b \pmod m, \quad a^{-1} \equiv a^{m-2} \pmod m \quad (\text{para } m \text{ primo})$$

```cpp
int64_t power(int64_t base, int64_t exp, int64_t mod = 1000000007) {
    int64_t res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp >>= 1;
    }
    return res;
}

int64_t mod_inv(int64_t n, int64_t mod = 1000000007) {
    return power(n, mod - 2, mod);
}
```

### 4.2 Crivo Linear de Eratóstenes $\mathcal{O}(N)$
Gera todos os primos até $N$ e permite fatoração prima em tempo $\mathcal{O}(\log X)$.

```cpp
struct LinearSieve {
    vector<int> primes;
    vector<int> min_prime;

    explicit LinearSieve(int n) : min_prime(n + 1, 0) {
        for (int i = 2; i <= n; ++i) {
            if (min_prime[i] == 0) {
                min_prime[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) {
                if (p > min_prime[i] || (int64_t)i * p > n) break;
                min_prime[i * p] = p;
            }
        }
    }

    bool is_prime(int x) const { return x >= 2 && min_prime[x] == x; }
};
```

---

## 5. 🧩 Programação Dinâmica

### 5.1 Longest Increasing Subsequence (LIS em $\mathcal{O}(N \log N)$)
```cpp
template <typename T>
int longest_increasing_subsequence(const vector<T>& a) {
    vector<T> tails;
    for (const auto& x : a) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return (int)tails.size();
}
```

### 5.2 0/1 Knapsack
$$\text{dp}[w] = \max(\text{dp}[w], \text{dp}[w - \text{weight}_i] + \text{value}_i)$$

```cpp
int64_t knapsack(int W, const vector<int>& weights, const vector<int64_t>& values) {
    vector<int64_t> dp(W + 1, 0);
    for (size_t i = 0; i < weights.size(); ++i) {
        for (int w = W; w >= weights[i]; --w) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[W];
}
```

---

## 6. 🔤 Algoritmos em Strings

### 6.1 KMP (Knuth-Morris-Pratt Matching em $\mathcal{O}(N + M)$)
```cpp
vector<int> prefix_function(const string& s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
```

---

## 7. 📐 Geometria Computacional

### 7.1 Ponto 2D & Produto Vetorial (Cross Product)
O produto vetorial determina a orientação:
- $> 0$: Curva à esquerda (anti-horário)
- $< 0$: Curva à direita (horário)
- $= 0$: Colinear

```cpp
template <typename T = double>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
    Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
    T cross(const Point& o) const { return x * o.y - y * o.x; }
    T dot(const Point& o) const { return x * o.x + y * o.y; }
};
```
