.POSIX:
.SILENT:

MAKEFLAGS += --no-print-directory -s

# ----------------------------------------------------------------
# Makefile: Competitive Computing Hub
# ----------------------------------------------------------------

CXX        ?= c++
CXXFLAGS   ?= -std=c++23 -O2 -Wall -Wextra
STACK_FLAG ?= -Wl,-z,stack-size=268435456
PYTHON     ?= python3

.PHONY: all help setup setup-hooks test test-tool test-algorithms lint stats clean check-binaries

all: help

### ================================
### HELP & DOCUMENTATION
### ================================
help:
	echo "Competitive Programming Hub — Centralized Automation"
	echo ""
	echo "Comandos disponíveis:"
	echo "  make setup            - Configura hooks do Git, permissões e valida dependências"
	echo "  make setup-hooks      - Ativa o diretório .githooks no git local"
	echo "  make test             - Executa toda a suíte de testes (CLI + Algoritmos)"
	echo "  make test-tool        - Executa testes unitários do CLI (tools/cp_tool.py)"
	echo "  make test-algorithms  - Compila e valida todos os componentes de algorithms/ em C++23"
	echo "  make lint             - Verifica sintaxe Python e integridade do repositório"
	echo "  make stats            - Exibe as estatísticas consolidadas do repositório"
	echo "  make clean            - Remove executáveis, binários compilados e arquivos temporários"
	echo ""

### ================================
### SETUP & ENVIRONMENT
### ================================
setup: setup-hooks
	echo "Verificando ferramentas do sistema..."
	command -v $(CXX) > "/dev/null" 2>&1 && echo "  [OK] Compilador C++: $$($(CXX) --version | head -n 1)" || echo "  [AVISO] Compilador $(CXX) não encontrado!"
	command -v $(PYTHON) > "/dev/null" 2>&1 && echo "  [OK] Interpretador Python: $$($(PYTHON) --version)" || echo "  [AVISO] Python 3 não encontrado!"
	chmod 0755 tools/cpt tools/cptool 2> "/dev/null" || true
	echo "Setup do repositório concluído com sucesso!"

setup-hooks:
	echo "Configurando hooks do Git..."
	chmod 0755 .githooks/*
	git config core.hooksPath .githooks
	echo "core.hooksPath configurado para .githooks"

### ================================
### TESTING & VERIFICATION
### ================================
test: test-tool test-algorithms
	echo "Todos os testes foram concluídos com êxito!"

test-tool:
	echo "Executando testes unitários do CLI..."
	$(PYTHON) tests/test_cp_tool.py

test-algorithms:
	echo "Compilando e testando biblioteca de algoritmos (C++23)..."
	$(CXX) $(CXXFLAGS) tests/test_algorithms.cpp -o tests/test_algos_bin
	./tests/test_algos_bin
	rm -f tests/test_algos_bin

lint: check-binaries
	echo "Verificando sintaxe de scripts Python..."
	$(PYTHON) -m py_compile tools/cp_tool.py tests/test_cp_tool.py
	echo "Sintaxe Python validada!"

check-binaries:
	echo "Verificando se há binários compilados rastreados pelo Git..."
	TRACKED_BINS=$$(git ls-files | grep -E '\.(exe|out|app|bin|o|obj|a|so|dylib)$$' || true); \
	if [ -n "$$TRACKED_BINS" ]; then \
		echo "ERRO: Binários rastreados encontrados: $$TRACKED_BINS" >&2; \
		exit 1; \
	fi
	echo "Nenhum binário indevido rastreado no repositório."

stats:
	$(PYTHON) tools/cp_tool.py stats

### ================================
### CLEANUP
### ================================
clean:
	echo "Removendo arquivos temporários e binários compilados..."
	rm -f tests/test_algos_bin
	find . -type f \( -name "main_bin" -o -name "*.exe" -o -name "*.out" -o -name "a.out" -o -name "output.txt" -o -name "actual.txt" -o -name "diff.txt" \) -exec rm -f {} +
	find . -type d -name "__pycache__" -exec rm -rf {} + 2> "/dev/null" || true
	echo "Limpeza concluída."
