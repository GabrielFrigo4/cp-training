# ==============================================================================
# Competitive Programming Hub - Centralized Makefile
# ==============================================================================

CXX ?= g++
CXXFLAGS ?= -std=c++23 -O2 -Wall -Wextra
STACK_FLAG ?= -Wl,-z,stack-size=268435456
PYTHON ?= python3

# Colors for terminal output
BOLD := \033[1m
GREEN := \033[32m
CYAN := \033[36m
YELLOW := \033[33m
RED := \033[31m
RESET := \033[0m

.PHONY: all help setup setup-hooks test test-tool test-algorithms lint stats clean check-binaries

all: help

## help: Exibe os comandos disponíveis neste Makefile
help:
	@echo ""
	@echo "$(BOLD)$(CYAN)⚡ Competitive Programming Hub - Centralized Makefile$(RESET)"
	@echo "$(BOLD)Comandos disponíveis:$(RESET)"
	@echo "  $(GREEN)make setup$(RESET)             Configura hooks do Git, permissões e valida dependências"
	@echo "  $(GREEN)make setup-hooks$(RESET)       Ativa o diretório .githooks no git local"
	@echo "  $(GREEN)make test$(RESET)              Executa toda a suíte de testes (CLI + Algoritmos)"
	@echo "  $(GREEN)make test-tool$(RESET)         Executa testes unitários do CLI (tools/cp_tool.py)"
	@echo "  $(GREEN)make test-algorithms$(RESET)   Compila e valida todos os componentes de algorithms/ em C++23"
	@echo "  $(GREEN)make lint$(RESET)              Verifica sintaxe Python e integridade do repositório"
	@echo "  $(GREEN)make stats$(RESET)             Exibe as estatísticas consolidadas do repositório"
	@echo "  $(GREEN)make clean$(RESET)             Remove executáveis, binários compilados e arquivos temporários"
	@echo ""

## setup: Configura hooks do git, permissões e dependências de ambiente
setup: setup-hooks
	@echo "$(CYAN)[setup] Verificando ferramentas do sistema...$(RESET)"
	@which $(CXX) >/dev/null 2>&1 && echo "  $(GREEN)✔$(RESET) Compilador C++: $$($(CXX) --version | head -n 1)" || echo "  $(YELLOW)⚠$(RESET) Compilador $(CXX) não encontrado!"
	@which $(PYTHON) >/dev/null 2>&1 && echo "  $(GREEN)✔$(RESET) Interpretador Python: $$($(PYTHON) --version)" || echo "  $(YELLOW)⚠$(RESET) Python 3 não encontrado!"
	@chmod +x tools/cpt tools/cptool 2>/dev/null || true
	@echo "$(GREEN)✔ Setup do repositório concluído com sucesso!$(RESET)"

## setup-hooks: Ativa os githooks versionados no git local
setup-hooks:
	@echo "$(CYAN)[setup-hooks] Configurando hooks do Git...$(RESET)"
	@chmod +x .githooks/*
	@git config core.hooksPath .githooks
	@echo "$(GREEN)✔ core.hooksPath configurado para .githooks$(RESET)"

## test: Roda todos os testes (CLI e compilação de algoritmos)
test: test-tool test-algorithms
	@echo ""
	@echo "$(BOLD)$(GREEN)✔ Todos os testes foram concluídos com êxito!$(RESET)"

## test-tool: Roda os testes unitários do CLI cpt
test-tool:
	@echo "$(CYAN)[test] Executando testes unitários do CLI...$(RESET)"
	@$(PYTHON) tests/test_cp_tool.py

## test-algorithms: Compila e valida todos os algoritmos em C++23
test-algorithms:
	@echo "$(CYAN)[test] Compilando e testando biblioteca de algoritmos (C++23)...$(RESET)"
	@$(CXX) $(CXXFLAGS) tests/test_algorithms.cpp -o tests/test_algos_bin
	@./tests/test_algos_bin
	@rm -f tests/test_algos_bin

## lint: Valida sintaxe e higiene do repositório
lint: check-binaries
	@echo "$(CYAN)[lint] Verificando sintaxe de scripts Python...$(RESET)"
	@$(PYTHON) -m py_compile tools/cp_tool.py tests/test_cp_tool.py
	@echo "$(GREEN)✔ Sintaxe Python validada!$(RESET)"

## check-binaries: Assegura que nenhum binário está rastreado pelo Git
check-binaries:
	@echo "$(CYAN)[lint] Verificando se há binários compilados rastreados pelo Git...$(RESET)"
	@TRACKED_BINS=$$(git ls-files | grep -E '\.(exe|out|app|bin|o|obj|a|so|dylib)$$' || true); \
	if [ -n "$$TRACKED_BINS" ]; then \
		echo "$(RED)[ERRO] Binários rastreados encontrados:$$TRACKED_BINS$(RESET)"; \
		exit 1; \
	fi
	@echo "$(GREEN)✔ Nenhum binário indevido rastreado no repositório.$(RESET)"

## stats: Exibe estatísticas de problemas resolvidos e categorias
stats:
	@$(PYTHON) tools/cp_tool.py stats

## clean: Remove binários e saídas temporárias
clean:
	@echo "$(CYAN)[clean] Removendo arquivos temporários e binários compilados...$(RESET)"
	@rm -f tests/test_algos_bin
	@find . -type f \( -name "main_bin" -o -name "*.exe" -o -name "*.out" -o -name "a.out" -o -name "output.txt" -o -name "actual.txt" -o -name "diff.txt" \) -delete
	@find . -type d -name "__pycache__" -exec rm -rf {} + 2>/dev/null || true
	@echo "$(GREEN)✔ Limpeza concluída.$(RESET)"
