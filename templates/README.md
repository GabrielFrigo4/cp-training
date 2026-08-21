# 📦 Competitive Programming Templates

Templates prontos e otimizados para competições e treinos rápidos.

---

## 📁 Estrutura de Templates

| Linguagem / Lib | Diretório | Descrição |
|---|---|---|
| **C++23** | [`cpp/standard/`](cpp/standard/) | Template padrão com Fast I/O e tipos 64-bit |
| **C++23 (Multi-cases)** | [`cpp/multiple-cases/`](cpp/multiple-cases/) | Loop de múltiplos casos de teste (`t--`) |
| **C++23 (Interactive)** | [`cpp/interactive/`](cpp/interactive/) | Configurado para problemas interativos com flush manual |
| **Python 3 / PyPy** | [`python/`](python/) | Template com `sys.stdin.readline` e recursion depth |
| **Rust** | [`rust/`](rust/) | Projetos com Cargo e arquivos únicos para `rustc` |
| **C** | [`c/`](c/) | Template minimalista em C |
| **AtCoder Library (ACL)** | [`atcoder_lib/`](atcoder_lib/) | Headers completos da biblioteca oficial do AtCoder |

---

## 🚀 Como Usar com a Ferramenta CLI

Para criar uma pasta de problema já com o template pronto:
```bash
# C++23 (padrão)
./tools/cp new practice/codeforces/normal/div-2/round-999 A B C D

# Python
./tools/cp new practice/atcoder/beginner/abc-350 A B C --lang py

# Rust
./tools/cp new practice/cses/introductory weird-algorithm --lang rs
```
