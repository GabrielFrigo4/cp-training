# 🐂 Emacs Configuration for Competitive Programming

Configuração minimalista e rápida para o Emacs (`~/.emacs` ou `~/.emacs.d/init.el`).

---

## ⚡ Configuração Básica (~/.emacs)

```elisp
;; ==============================================================================
;; Competitive Programming Emacs Setup
;; ==============================================================================

;; Initial setup & Performance
(setq initial-major-mode 'fundamental-mode)
(setq initial-scratch-message nil)
(setq inhibit-startup-screen t)

;; Visuals & Line Numbers
(custom-set-variables
 '(column-number-mode t)
 '(global-display-line-numbers-mode t)
 '(display-line-numbers-type 'relative)
 '(custom-enabled-themes '(tsdh-dark))
 '(menu-bar-mode nil)
 '(tool-bar-mode nil)
 '(scroll-bar-mode nil))

;; Auto template insertion
(auto-insert-mode t)
(setq auto-insert-query nil)
(setq auto-insert-directory "~")

(define-auto-insert "\\.cpp\\'" "templates/cpp/standard/main.cpp")
(define-auto-insert "\\.py\\'" "templates/python/main.py")

;; Fast compile keybinding (F9)
(global-set-key (kbd "<f9>") 'compile)
```
