# 💻 Vim / Neovim Configuration for Competitive Programming

Configurações otimizadas para digitação ultra-rápida, auto-inserção de templates e execução em maratonas de programação.

---

## ⚡ Configuração Básica (~/.vimrc)

Adicione o seguinte conteúdo ao seu arquivo `~/.vimrc`:

```vim
" ==============================================================================
" Competitive Programming Vim Setup
" ==============================================================================

" Basic & Compatibility
set nocompatible
filetype plugin indent on
syntax on
set termguicolors

" Line Numbers & Relative Navigation
set number
set relativenumber
set cursorline

" Cursor Shapes (Bar in Insert mode, Block in Normal mode)
let &t_SI = "\<Esc>[5 q"
let &t_SR = "\<Esc>[3 q"
let &t_EI = "\<Esc>[1 q"

" Indentation & Tabs (4 spaces)
set autoindent
set smartindent
set tabstop=4
set shiftwidth=4
set softtabstop=4
set noexpandtab

" Key & Wrap behaviors
set backspace=indent,eol,start
set whichwrap+=<,>,h,l,[,]
set nowrap

" Mouse & Clipboard
set mouse=a
set clipboard^=unnamed,unnamedplus

" Encoding
set encoding=UTF-8

" Auto-load template on new C++ or Python file
autocmd BufNewFile *.cpp 0r templates/cpp/standard/main.cpp
autocmd BufNewFile *.py 0r templates/python/main.py

" Fast Compile & Run Keybindings
" F9: Compile C++23
nnoremap <F9> :w<CR>:!g++ -std=c++23 -O2 -Wall -Wextra % -o %< <CR>
" F10: Run with input.txt
nnoremap <F10> :!./%< < input.txt<CR>
```

---

## 🚀 Neovim (init.lua)

Para usuários de Neovim (`~/.config/nvim/init.lua`):

```lua
-- Line numbers & cursor
vim.opt.number = true
vim.opt.relativenumber = true
vim.opt.cursorline = true

-- Tabs & Indentation
vim.opt.tabstop = 4
vim.opt.shiftwidth = 4
vim.opt.expandtab = false

-- Clipboard
vim.opt.clipboard = "unnamedplus"

-- Keymaps
local map = vim.keymap.set
map("n", "<F9>", ":w<CR>:!g++ -std=c++23 -O2 -Wall -Wextra % -o %:r<CR>", { silent = true })
map("n", "<F10>", ":!./%:r < input.txt<CR>", { silent = true })
```
