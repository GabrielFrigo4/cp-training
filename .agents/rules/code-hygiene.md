# Repository & Git Hygiene Rules

Este arquivo especifica regras rígidas de higiene do repositório para agentes de IA e colaboradores.

## 1. 🚫 Proibição de Binários e Executáveis
- **NUNCA** adicione ou faça commit de arquivos compilados:
  - `main`, `main_bin`, `test`, `sol`, `solution`, `a.out`
  - `*.exe`, `*.out`, `*.o`, `*.obj`, `*.a`, `*.so`, `*.dylib`
  - `*.class`, `*.pyc`, `__pycache__`
- Antes de commitar, sempre verifique o `git status` e rode `make clean` ou `make lint`.

## 2. 📝 Arquivos Temporários de Teste
- Arquivos gerados durante a execução de testes locais:
  - `output.txt`, `actual.txt`, `diff.txt`, `*.tmp`, `*.log`
- Não devem ser commitados no controle de versão (já ignorados no `.gitignore`).
- Sempre mantenha `input.txt` e `expected.txt` como a fonte oficial dos casos de teste.

## 3. 💬 Padrão de Mensagens de Commit (Conventional Commits)
- Todo commit deve seguir a especificação: `<tipo>(<escopo>): <descrição>`
- Tipos válidos:
  - `solution`: Adição ou refatoração de solução de problema competitivo.
  - `algo`: Novo algoritmo ou estrutura de dados em `algorithms/`.
  - `feat`: Nova funcionalidade na CLI ou na infraestrutura.
  - `fix`: Correção de bug em algoritmo, CLI ou Makefile.
  - `docs`: Atualizações no `README.md`, `HANDBOOK.md` ou `CONTRIBUTING.md`.
  - `refactor`: Refatoração sem alteração de funcionalidade.
  - `test`: Adição de casos de teste ou testes automatizados.
  - `chore`: Atualização de configurações, hooks ou dependências.
