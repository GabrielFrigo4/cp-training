<div align="center">

# ⚡ Competitive Programming Hub
**Algorithms, Contest Solutions, Templates & Automation for Competitive Programming**

[![Codeforces](https://img.shields.io/badge/Codeforces-Gerbunte-1F8ACB?style=for-the-badge&logo=codeforces&logoColor=white)](https://codeforces.com/profile/Gerbunte)
[![GitHub](https://img.shields.io/badge/GitHub-GabrielFrigo4-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/GabrielFrigo4)
[![Language](https://img.shields.io/badge/C%2B%2B-23-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](templates/cpp/)
[![Language](https://img.shields.io/badge/Python-3.12-3776AB?style=for-the-badge&logo=python&logoColor=white)](templates/python/)
[![Language](https://img.shields.io/badge/Rust-Edition_2021-DEA584?style=for-the-badge&logo=rust&logoColor=white)](templates/rust/)
[![Linux](https://img.shields.io/badge/Platform-Linux%20%2F%20GCC-FCC624?style=for-the-badge&logo=linux&logoColor=black)](docs/)
[![Handbook](https://img.shields.io/badge/Handbook-Algorithms%20%26%20DS-8A2BE2?style=for-the-badge&logo=gitbook&logoColor=white)](HANDBOOK.md)

<p align="center">
  <a href="#-visão-geral">Visão Geral</a> •
  <a href="#-métricas-e-performance">Métricas</a> •
  <a href="#-estatísticas-do-repositório">Estatísticas</a> •
  <a href="#-mapa-de-navegação">Navegação</a> •
  <a href="#-ferramenta-cli-tools-cp">CLI Tooling</a> •
  <a href="#-compilação--configuração">Setup</a> •
  <a href="HANDBOOK.md">Algorithms Handbook</a>
</p>

---

</div>

## 📌 Visão Geral

Este repositório é um hub centralizado para treinamento, desenvolvimento de algoritmos e registro de soluções de **Programação Competitiva** (ICPC, OBI, Codeforces, AtCoder, Seletiva USP, LeetCode, CSES e Advent of Code).

O projeto é estruturado para proporcionar máxima produtividade no terminal Linux, suporte a múltiplas linguagens (C++23, Python, Rust, C), automação de testes com tempos de execução precisos e um handbook de consulta rápida durante simulados.

---

## 📊 Métricas e Performance

<div align="center">
  <table>
    <tr>
      <td align="center" valign="middle">
        <a href="https://github.com/GabrielFrigo4">
          <img src="https://github-readme-stats-beta-lime-83.vercel.app/api?username=GabrielFrigo4&show_icons=true&theme=radical&include_all_commits=true&count_private=true&v=4" alt="GitHub Stats" />
        </a>
        <br><br>
        <a href="https://github.com/GabrielFrigo4">
          <img src="https://github-readme-stats-beta-lime-83.vercel.app/api/top-langs/?username=GabrielFrigo4&layout=compact&langs_count=6&theme=radical&hide=html,css" alt="Top Languages" />
        </a>
      </td>
      <td align="center" valign="middle">
        <a href="https://codeforces.com/profile/Gerbunte">
          <img src="https://codeforces-readme-stats.vercel.app/api/card?username=Gerbunte&theme=radical" alt="Codeforces Stats" />
        </a>
      </td>
    </tr>
  </table>
</div>

---

## 📈 Estatísticas do Repositório

```text
============================================================
  🚀 Total de Soluções Registradas: 300+
============================================================
  • C++23               : 214 soluções   ████████████████████████
  • Python              :  54 soluções   ██████
  • Rust                :  29 soluções   ███
  • C                   :   6 soluções   █
============================================================
```

### 🏆 Competições & Maratonas
| Evento | Categoria | Diretório | Soluções / Conteúdo |
|---|---|:---:|:---:|
| **ICPC** | Maratona SBC (Fase Zero & Regional) | [`competitions/icpc/`](competitions/icpc/) | 2024, 2025 |
| **Seletiva USP** | Seletiva IME-USP | [`competitions/seletiva-usp/`](competitions/seletiva-usp/) | 2024, 2025, 2026 + Guia de Dificuldade |
| **OBI-UNICAMP** | Olimpíada Brasileira de Informática | [`competitions/obi-unicamp/`](competitions/obi-unicamp/) | 2023, 2024 (Fases 1, 2 e 3) |
| **Seletiva UFABC** | Seletiva Maratona UFABC | [`competitions/seletiva-ufabc/`](competitions/seletiva-ufabc/) | 2026 |
| **MFP** | Maratona Feminina de Programação | [`competitions/mfp/`](competitions/mfp/) | 2025 |
| **Advent of Code** | Desafios Anuais de Lógica | [`competitions/advent-of-code/`](competitions/advent-of-code/) | 2024 (Day 9, etc.) |
| **Layers** | Desafios & Hackathons | [`competitions/layers/`](competitions/layers/) | 2024, 2025, Desafios |

### 🎯 Treino por Plataforma
| Plataforma | Divisões / Categorias | Diretório |
|---|---|:---:|
| **Codeforces** | Div 1, Div 2, Div 3, Div 4, Edu, Global, Special (Good Bye, Hello) | [`practice/codeforces/`](practice/codeforces/) |
| **AtCoder** | ABC (Beginner), ARC (Regular), AGC (Grand), AHC (Heuristic) | [`practice/atcoder/`](practice/atcoder/) |
| **Virtual Judge** | Simulados individuais e listas temáticas | [`practice/vjudge/`](practice/vjudge/) |
| **LeetCode** | Dynamic Programming, Graphs, Data Structures | [`practice/leetcode/`](practice/leetcode/) |
| **CSES** | CSES Problem Set | [`practice/cses/`](practice/cses/) |
| **Diversos & Aulas** | Aulas GRUB (DP Clássico), Programação Estruturada, Criações | [`practice/misc/`](practice/misc/) |

---

## 🗂️ Arquitetura do Repositório

```text
competitive-programming/
├── algorithms/               # Biblioteca modular de algoritmos (DSU, SegTree, Dijkstra, etc.)
├── competitions/             # Códigos e cadernos de competições oficiais
├── practice/                 # Problemas categorizados por plataforma e tópicos
├── templates/                # Templates otimizados (C++23, PyPy, Rust, ACL Library)
├── tools/                    # Ferramenta CLI de produtividade (tools/cp)
├── docs/                     # Guias de configuração (Vim, Emacs, Linux)
├── .vscode/                  # Tasks de build C++23 e launch debug
├── HANDBOOK.md               # Caderno consolidado de algoritmos e fórmulas com LaTeX
└── README.md                 # Visão geral e documentação principal
```

---

## 🛠️ Ferramenta CLI (`tools/cp`)

O repositório inclui um utilitário CLI em Python (`./tools/cp`) sem dependências externas:

### 1. Criar novo Contest ou Problema
```bash
# Cria uma pasta para o contest com problemas A, B, C, D e templates prontos
./tools/cp new practice/codeforces/normal/div-2/round-1000 A B C D E

# Cria com template Python
./tools/cp new practice/atcoder/beginner/abc-350 A B C --lang py
```

### 2. Compilar, Executar e Testar
```bash
# Compila e roda o problema atual com o input.txt da pasta
./tools/cp run practice/codeforces/normal/div-2/round-1000/A

# Se houver expected.txt, valida automaticamente o AC ou WA com diff
./tools/cp test
```

### 3. Copiar Código para o Clipboard (1 comando)
```bash
# Detecta wl-copy (Wayland), xclip (X11) ou clip.exe (WSL/Windows)
./tools/cp clip practice/codeforces/normal/div-2/round-1000/A/main.cpp
```

### 4. Gerar Estatísticas em Tempo Real
```bash
./tools/cp stats
```

---

## ⚙️ Compilação & Configuração

### C++23 (GCC)
```bash
g++ -std=c++23 -O2 -Wall -Wextra -Wconversion -Wshadow -fsanitize=undefined \
    -Wl,-z,stack-size=268435456 main.cpp -o main
```

### Fast I/O Template (C++)
```cpp
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // Seu código aqui
    return 0;
}
```

### Atalhos no VS Code
- **`Ctrl + Shift + B`**: Compila o arquivo C++ ativo com `-std=c++23` e sanitizers.
- **Task `CP: Run Test with Input`**: Executa a solução contra o `input.txt` e mede o tempo em ms.

---

## 📚 Handbook & Referências Rápidas

Consulte o [**HANDBOOK.md**](HANDBOOK.md) para implementações canônicas, complexidades e notas de:
- **Estruturas de Dados:** DSU, Fenwick Tree, Segment Tree, Sparse Table, Trie.
- **Grafos:** Dijkstra, Tarjan SCC, LCA (Binary Lifting), Dinic Max Flow.
- **Matemática:** Exponenciação Rápida, Crivo Linear, Combinatória Modular, Euclides Estendido.
- **Programação Dinâmica:** LIS $\mathcal{O}(N \log N)$, Knapsack, Digit DP, Bitmask DP.
- **Strings & Geometria:** KMP, Z-Algorithm, Ponto 2D, Convex Hull.

---

## 📝 Licença

Este projeto está sob a licença [MIT](LICENSE). Sinta-se livre para utilizar os templates e códigos para estudos e competições.
