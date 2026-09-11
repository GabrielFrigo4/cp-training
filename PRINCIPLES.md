# 📜 Princípios de Engenharia & Filosofia — Competitive Computing Hub

> _"Rule of Optimization: Prototype before polishing. Get it working before you optimize it."_<br>
> — Eric S. Raymond, _The Art of UNIX Programming_ (2003)

O **Competitive Computing Hub** é o laboratório de treinamento, biblioteca de algoritmos canônicos e centro de soluções de maratonas de programação competitiva (ICPC, OBI, Codeforces, AtCoder, Seletiva USP, CSES). O repositório alia rigor matemático e complexidade assintótica ótima a práticas de engenharia de software de alta performance, modularidade e automação via terminal Linux e FreeBSD.

> [!IMPORTANT]
> **A Regra de Ouro do Agente de IA:** Ao entrar em qualquer diretório de repositório, o agente DEVE SEMPRE ler os arquivos `AGENTS.md`, `PRINCIPLES.md` e `.agents/` daquele repositório antes de realizar qualquer alteração.

---

## 🏛️ Os 18 Princípios de Design (17 Princípios UNIX + Soberania do Usuário)

### 1. Regra da Modularidade (_Rule of Modularity_)

> _Escreva partes simples conectadas por interfaces limpas._

- A biblioteca canônica em `algorithms/` é modularizada em headers `.hpp` autocontidos com `#pragma once`. Soluções consomem algoritmos sem acoplamento de estado global.

### 2. Regra da Clareza (_Rule of Clarity_)

> _Clareza é melhor que esperteza._

- Implementações algorítmicas priorizam nomes expressivos e invariantes explícitas. Abreviações crípticas de uma única letra são restritas a índices matemáticos (`i`, `j`, `u`, `v`).

### 3. Regra da Composição (_Rule of Composition_)

> _Projete programas para serem conectados a outros programas._

- Soluções leem de `stdin` e escrevem em `stdout`. A CLI `tools/cpt` encadeia execução contra arquivos de teste (`input.txt` e `expected.txt`) e pipes para o clipboard (`wl-copy` / `xclip`).

### 4. Regra da Separação (_Rule of Separation_)

> _Separe a política do mecanismo; separe o motor da interface._

- O algoritmo puro (mecanismo) reside em `algorithms/`. A resolução do problema específico de maratona (política) instancia o algoritmo dentro de sua própria função `solve()`.

### 5. Regra da Simplicidade (_Rule of Simplicity_)

> _Projete para a simplicidade; adicione complexidade apenas onde estritamente necessário._

- Estruturas de dados complexas (Treaps, Segment Trees persistentes) são adotadas apenas quando o problema não admite soluções com árvores de Fenwick ou two-pointers.

### 6. Regra da Parcimônia (_Rule of Parsimony_)

> _Escreva um programa grande apenas quando estiver claro por demonstração que nada mais resolverá._

- Bibliotecas e templates são concisos e diretos, sem camadas excessivas de metaprogramação C++ que aumentem o tempo de compilação sem ganho de runtime.

### 7. Regra da Transparência (_Rule of Transparency_)

> _Projete para a visibilidade para tornar inspeção e depuração fáceis._

- Ferramenta CLI `tools/cpt diff` exibe diferenças entre a saída obtida e a esperada de forma visual e colorida no terminal.

### 8. Regra da Robustez (_Rule of Robustness_)

> _A robustez é filha da transparência e da simplicidade._

- **Segurança de Pilha:** Flag canônica `-Wl,-z,stack-size=268435456` (256 MB) em sistemas Linux e FreeBSD para evitar _Segmentation Fault_ por estouro de pilha em buscas DFS profundas e Euler Tour.
- **Sanitizers:** Compilação com `-fsanitize=undefined` em desenvolvimento para capturar overflows e acessos fora de limites.

### 9. Regra da Representação (_Rule of Representation_)

> _Dobre o conhecimento em dados para que a lógica do programa possa ser estúpida e robusta._

- Tabelas de pré-computação e grafos representados por listas de adjacência limpas tornam a lógica de travessia compacta.

### 10. Regra do Menor Espanto (_Rule of Least Surprise_)

> _No design de interfaces, sempre faça a coisa menos surpreendente._

- Zero poluição de namespace: NUNCA utilizar `using namespace std;` em headers da pasta `algorithms/`.

### 11. Regra do Silêncio (_Rule of Silence_)

> _Quando um programa não tem nada surpreendente a dizer, ele não deve dizer nada._

- Makefiles silenciosos (`.SILENT:`, `MAKEFLAGS += -s`). Testes e compilações emitem saída apenas quando há erros ou pedidos de relatórios (`make stats`).

### 12. Regra do Reparo (_Rule of Repair_)

> _Quando você precisar falhar, falhe ruidosamente e o mais rápido possível._

- `assert()` e checagens defensivas em runtime durante testes locais para detecção precoce de precondições inválidas.

### 13. Regra da Economia (_Rule of Economy_)

> _O tempo do programador é caro; economize-o em preferência ao tempo da máquina._

- CLI `./tools/cpt new` gera o ambiente completo de um contest com múltiplos problemas, templates e Makefiles em milissegundos.

### 14. Regra da Geração (_Rule of Generation_)

> _Evite codificação manual; escreva programas para escrever programas quando puder._

- Utilitários de _bundling_ que consolidam múltiplos headers `.hpp` em um único arquivo `.cpp` pronto para submissão nas plataformas de maratona.

### 15. Regra da Otimização (_Rule of Optimization_)

> _Prototipe antes de polir. Faça funcionar antes de otimizar._

- Primeiro provar a corretude do algoritmo e sua complexidade assintótica ($\mathcal{O}(N \log N)$); depois otimizar constantes com Fast I/O (`cin.tie(nullptr)` e `'\n'`).

### 16. Regra da Diversidade (_Rule of Diversity_)

> _Desconfie de todas as afirmações de "uma única maneira verdadeira"._

- Foco primordial em **C++23**, com suporte pragmático a Python (para automação e problemas matemáticos com inteiros gigantes) e Rust.

### 17. Regra da Extensibilidade (_Rule of Extensibility_)

> _Projete para o futuro, porque ele chegará antes do que você imagina._

- Estrutura de pastas categorizada por juiz online (`practice/codeforces/`, `practice/atcoder/`, `practice/cses/`) extensível a novas plataformas.

### 18. Regra da Soberania do Usuário (_Rule of User Sovereignty_)

> _Honre a escolha explícita e deliberada do usuário antes de impor padrões genéricos._

- O estilo de raciocínio e templates favoritos do desenvolvedor são preservados nos templates personalizados.

---

## 🧼 Princípios de Clean Code & Compilação

1. **Padrão de Linguagem:** C++23 estrito (`-std=c++23`). Compilador agnóstico `CXX ?= c++`.
2. **Fast I/O Canônico:**
    ```cpp
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ```
3. **Makefiles Silenciosos e POSIX:**
    ```makefile
    .POSIX:
    .SILENT:

    MAKEFLAGS += --no-print-directory -s
    ```
4. **Zero Binários no Versionamento:** Bloqueio mandatório de arquivos executáveis no pre-commit hook.
5. **Arquitetura de Comentários (A Tríade Sem Vazamento):**
    - Header Banner: 64 hífens (`# ----------------------------------------------------------------`).
    - Seções Estruturais: 32 caracteres (`### ================================` e `### --------------------------------`). Título $\le$ 32 caracteres.
    - Zero Comentários Narrativos no código.
