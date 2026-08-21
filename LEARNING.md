# 🎓 Competitive Programming Study Roadmap & Learning Resources

Curated list of competitive programming books, learning platforms, advanced theoretical topics, and problem reductions.

---

## 📚 Essential Books & Handbooks

- **[Competitive Programmer’s Handbook](https://cses.fi/book/book.pdf)** *(Antti Laaksonen)* — O melhor guia direto ao ponto para algoritmos modernos.
- **[Guide to Competitive Programming](https://link.springer.com/book/10.1007/978-3-319-72547-5)** *(Antti Laaksonen)* — Abordagem prática com foco em problemas do CSES e Codeforces.
- **[Computational Geometry: Algorithms and Applications](https://www.springer.com/gp/book/9783540779735)** *(de Berg et al.)* — Referência definitiva para geometria computacional.
- **[Introduction to Algorithms (CLRS)](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/)** — Provas formais e fundamentos teóricos.

---

## 🌐 Online Learning Platforms & Courses

- **[CP-Algorithms](https://cp-algorithms.com/)** — Artigos e implementações completas dos principais algoritmos de maratona.
- **[USACO Guide](https://usaco.guide/)** — Roadmap estruturado por divisões (Bronze $\to$ Platinum).
- **[NOIC Cursos](https://noic.com.br/materiais-informatica/curso/)** — Material didático de referência no Brasil para a OBI e Maratona SBC.
- **[YouKn0wWho Academy Topic List](https://youkn0wwho.academy/topic-list)** — Lista exaustiva de tópicos categorizados por nível.
- **[Project Euler](https://projecteuler.net/archives)** — Problemas de matemática pura e teoria dos números computacional.

---

## 🔬 Advanced Topics & Mathematics in CP

### 1. Álgebra Linear e Sistemas Dinâmicos
- **Sistemas Dinâmicos Lineares Invariantes no Tempo (LTI)**:
  - Modelagem de sequências recorrentes com exponenciação de matrizes $\mathcal{O}(K^3 \log N)$.
  - Algoritmo de Berlekamp-Massey para encontrar a menor recorrência linear a partir dos primeiros termos em $\mathcal{O}(N^2)$.
  - Algoritmo de Kitamasa / Fast Linear Recurrence em $\mathcal{O}(K \log K \log N)$.

### 2. Teoria dos Corpos Finitos (Galois Fields)
- **Corpos de Galois ($\mathbb{F}_{p^k}$ ou $GF(2^k)$)**:
  - Aplicação em criptografia, hashing perfeito e convolução rápida.
  - Nim-multiplication e Teoria dos Jogos Combinatórios em corpos finitos.

### 3. Reduções Algorítmicas Clássicas
- **Floyd-Warshall $\iff$ Eliminação Gaussiana (Álgebra de Semianel)**:
  - O algoritmo de Floyd-Warshall para caminhos mínimos pode ser visto como uma eliminação de Gauss-Jordan sobre o semianel $(\min, +)$.
- **Fecho Transitivo $\iff$ Multiplicação Booleana de Matrizes**.
- **Emparelhamento Máximo Bipartido $\iff$ Fluxo Máximo (Max Flow - Dinic / Hopcroft-Karp)**.
- **Min-Cut $\iff$ Conjunto Independente Máximo em Grafos Bipartidos**.

---

## 📌 Checklist de Tópicos Avançados para Treino

- [ ] **Data Structures**: Treap Implícita, Splay Tree, Li-Chao Tree, Segment Tree Persistente.
- [ ] **Graphs**: Centroid Decomposition, DSU on Tree (Sack), Hopcroft-Karp, 2-SAT.
- [ ] **Strings**: Suffix Automaton (SAM), Aho-Corasick, Palindromic Tree (EERTREE).
- [ ] **Math**: Fast Fourier Transform (FFT / NTT), Miller-Rabin + Pollard's Rho, Crivo de Min_25.
- [ ] **Geometry**: Half-Plane Intersection, Voronoi Diagrams, Rotating Calipers.
