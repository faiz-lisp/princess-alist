;; ----------------------------------------------------------------------
;; GENERAL SETTINGS
;; ----------------------------------------------------------------------

;; ;; Set the debug option to enable a backtrace when a problem occurs.
;; (setq debug-on-error t)

;; Share clipboard.
(setq x-select-enable-clipboard t)

;; Display column.
(setq column-number-mode t)

;; Show parentheses math.
(show-paren-mode t)

;; Hide toolbar.
(tool-bar-mode nil)

;; Mouse, please leave me alone!
(mouse-avoidance-mode 'animate)

;; ;; Column limit for auto-fill-mode.
;; (add-hook 'erc-mode-hook 'turn-on-auto-fill)
;; (setq-default fill-column 60)

;; Basic indentation.
(setq default-tab-width 4)

;; Convert TAB to SPACE.
(setq-default indent-tabs-mode nil)

;; ;; Font settings.
;; (set-default-font "Monaco-12")
;; (set-fontset-font (frame-parameter nil 'font)
;;   'unicode '("DejaVu Sans YuanTi Mono" . "unicode-bmp"))

;; Make `M-w' can copy a line.
(defun xiaogaozi-kill-ring-save (&optional n)
  "If region is active, copy region. Otherwise, copy line."
  (interactive "p")
  (if mark-active
      (kill-ring-save (region-beginning) (region-end))
    (if (> n 0)
        (kill-ring-save (line-beginning-position) (line-end-position n))
      (kill-ring-save (line-beginning-position n) (line-end-position)))))
(global-set-key (kbd "M-w") 'xiaogaozi-kill-ring-save)

;; ----------------------------------------------------------------------
;; SITE-LISP
;; ----------------------------------------------------------------------

(add-to-list 'load-path "~/.emacs.d/site-lisp")

;; ;; color theme
;; (load-file "/usr/share/emacs-snapshot/site-lisp/color-theme.el")
;; (require 'color-theme)
;; (color-theme-hober)

;; template
(require 'template)
(template-initialize)

;; ;; auto-header
;; (require 'auto-header)
;; (setq header-full-name "Dreamseeker"
;;       header-email-address "gaochangjian<at>gmail<dot>com"
;;       header-copyright-notice "Copyleft (c) INF, Dreamseeker"
;;       header-update-on-save '(filename modified counter copyright)
;;       header-field-list '(filename
;;                           blank
;;                           description
;;                           blank
;;                           author
;;                           created
;;                           blank
;;                           modified_by
;;                           modified
;;                           blank
;;                           status
;;                           update
;;                           blank
;;                           copyright))
;; ;; auto update the number of count
;; (global-set-key (kbd "s-h") (lambda ()
;;                               (interactive)
;;                               (if (header-exists-p)
;;                                   (header-update-count)
;;                                 (header-make t))))

;; AUCTeX
(defun auctex ()
  (add-to-list 'TeX-command-list '("XeLaTeX" "%`xelatex%(mode)%' %t; %`xelatex%(mode)%' %t" TeX-run-TeX nil t)) ;; 这里我编译了两次
    (setq TeX-command-default "XeLaTeX") ;; 设定默认编译命令为XeLaTeX
    (setq TeX-save-query nil)            ;; 保存之前不询问
    (setq TeX-show-compilation t))       ;; 在新窗口显示编译过程
(add-hook 'LaTeX-mode-hook 'auctex)

;; ;; EMMS
;; (add-to-list 'load-path "/usr/share/emacs/site-lisp/emms/")
;; (require 'emms-setup)
;; (emms-standard)
;; (emms-default-players)
;; (setq emms-repeat-playlist t
;;       emms-source-file-default-directory "/home/xiaolan/music/"
;;       emms-lyrics-coding-system nil     ;; Let Emacs to identify the encode of lyrics.
;;       emms-lyrics-dir "/home/xiaolan/music/lyrics")
;; ;; Show info at mode-line.
;; (require 'emms-mode-line)
;; (emms-mode-line 1)
;; ;; Show time of music.
;; (require 'emms-playing-time)
;; (emms-playing-time 1)
;; ;; Show lyrics.
;; (require 'emms-lyrics)
;; (emms-lyrics 1)
;; ;; Auto identify encode.
;; (require 'emms-i18n)
;; ;; Auto save and import playlist.
;; (require 'emms-history)
;; (emms-history-load)

;; ;; JDEE
;; (setq defer-loading-jde t)
;; (if defer-loading-jde
;;     (progn
;;       (autoload 'jde-mode "jde" "JDE mode." t)
;;       (setq auto-mode-alist
;;                      (append
;;                       '(("\\.java\\'" . jde-mode))
;;                       auto-mode-alist)))
;;   (require 'jde))

;; rect-mark.el
;; Support for marking a rectangle of text with highlighting.
(define-key ctl-x-map "r\C-@" 'rm-set-mark)
(define-key ctl-x-map [?r ?\C-\ ] 'rm-set-mark)
(define-key ctl-x-map "r\C-x" 'rm-exchange-point-and-mark)
(define-key ctl-x-map "r\C-w" 'rm-kill-region)
(define-key ctl-x-map "r\M-w" 'rm-kill-ring-save)
(define-key global-map [S-down-mouse-1] 'rm-mouse-drag-region)
(autoload 'rm-set-mark "rect-mark"
  "Set mark for rectangle." t)
(autoload 'rm-exchange-point-and-mark "rect-mark"
  "Exchange point and mark for rectangle." t)
(autoload 'rm-kill-region "rect-mark"
  "Kill a rectangular region and save it in the kill ring." t)
(autoload 'rm-kill-ring-save "rect-mark"
  "Copy a rectangular region to the kill ring." t)
(autoload 'rm-mouse-drag-region "rect-mark"
  "Drag out a rectangular region with the mouse." t)

;; ;; Pymacs
;; (autoload 'pymacs-apply "pymacs")
;; (autoload 'pymacs-call "pymacs")
;; (autoload 'pymacs-eval "pymacs" nil t)
;; (autoload 'pymacs-exec "pymacs" nil t)
;; (autoload 'pymacs-load "pymacs" nil t)
;; 
;; ;; Ropemacs
;; (pymacs-load "ropemacs" "rope-")

;; YASnippet
(add-to-list 'load-path
              "~/.emacs.d/site-lisp/yasnippet-0.6.1c")
(require 'yasnippet)
(yas/initialize)
(yas/load-directory "~/.emacs.d/site-lisp/yasnippet-0.6.1c/snippets")
(setq yas/prompt-functions '(yas/dropdown-prompt))

;; ;; Auto-Complete
;; (add-to-list 'load-path "/usr/share/emacs/site-lisp/auto-complete/")
;; (require 'auto-complete)
;; (require 'auto-complete-config)
;; (setq-default ac-sources '(ac-source-words-in-same-mode-buffers ac-source-yasnippet))
;; (add-hook 'emacs-lisp-mode-hook (lambda () (add-to-list 'ac-sources 'ac-source-symbols)))
;; (add-hook 'auto-complete-mode-hook (lambda () (add-to-list 'ac-sources 'ac-source-filename)))
;; (add-hook 'c++-mode-hook (lambda () (add-to-list 'ac-sources 'ac-source-c++-keywords)))
;; (add-hook 'css-mode-hook (lambda () (add-to-list 'ac-sources 'ac-source-css-keywords)))
;; (add-hook 'python-mode-hook (lambda () (add-to-list 'ac-sources 'ac-source-ropemacs)))
;; (global-auto-complete-mode t)
;; (set-face-background 'ac-candidate-face "lightgray")
;; (set-face-underline 'ac-candidate-face "darkgray")
;; (set-face-background 'ac-selection-face "steelblue")
;; (setq ac-dwim t)
;; ;; Use C-n/C-p to select candidates
;; (define-key ac-complete-mode-map "\C-n" 'ac-next)
;; (define-key ac-complete-mode-map "\C-p" 'ac-previous)

;; ----------------------------------------------------------------------
;; INDENTATION
;; ----------------------------------------------------------------------

;; C
(defun my-c-mode-hook ()
    (setq comment-start "// ")
    (setq comment-end "")
    (c-set-offset 'substatement-open 0)
    (c-set-offset 'case-label 4)
    (c-set-offset 'statement-case-open 4)
    (c-set-offset 'defun-block-intro 4)
    (c-set-offset 'brace-list-intro 4)
    (c-set-offset 'topmost-intro 2))
(add-hook 'c-mode-hook 'my-c-mode-hook)

;; C++
(defconst my-c++-style
  '((c-hanging-braces-alist . ((substatement-open after)
                               (brace-list-open)))
    (c-hanging-colons-alist . ((member-init-intro before)
                               (inher-intro)
                               (case-label after)
                               (label after)
                               (access-label after)))
    (c-cleanup-list         . (scope-operator
                               empty-defun-braces
                               defun-close-semi))
    (c-offsets-alist        . ((arglist-close . c-lineup-arglist)
                               (substatement-open . 0)
                               (topmost-intro     . 0)
                               (case-label        . 4)
                               (access-label      . -2)
                               (inline-open       . 0)
                               (member-init-intro . 4)
                               (defun-block-intro . 4)
                               (inline-close      . 0)
                               (substatement      . 4)
                               (statement-block-intro . 4)
                               (block-open        . 0)
                               (knr-argdecl-intro . -)
                               (brace-list-intro  . 4))))
  "My C++ Programming Style")
(c-add-style "PERSONAL" my-c++-style)
(defun my-c++-mode-hook ()
  (c-set-style "PERSONAL"))
(add-hook 'c++-mode-hook 'my-c++-mode-hook)

;; Java
(defun my-java-mode-hook ()
    (setq c-basic-offset 4)
    (c-set-offset 'substatement-open 0)
    (c-set-offset 'else-clause 0)
    (c-set-offset 'case-label 4)
    (c-set-offset 'arglist-cont-nonempty '(c-lineup-arglist-operators c-lineup-arglist)))
(add-hook 'java-mode-hook 'my-java-mode-hook)

;; ----------------------------------------------------------------------
;; KEYBINDINGS
;; ----------------------------------------------------------------------

;; Replace `C-@' to `C-^'.
(global-set-key (kbd "C-^") 'set-mark-command)

;; GDB
(global-set-key (kbd "<f7>") 'gdb)

;; Compile
(global-set-key (kbd "<f8>") 'compile)

;; Auto indent when Enter.
(global-set-key "\r" 'newline-and-indent)

(setq skeleton-pair-alist nil)
(setq skeleton-pair t)
(global-set-key (kbd "(") 'skeleton-pair-insert-maybe)
(global-set-key (kbd "[") 'skeleton-pair-insert-maybe)
(global-set-key (kbd "<") 'skeleton-pair-insert-maybe)
(global-set-key (kbd "\"") 'skeleton-pair-insert-maybe)
(global-set-key (kbd "'") 'skeleton-pair-insert-maybe)

;; YASnippet
(global-set-key (kbd "M-s i") 'yas/insert-snippet)
(global-set-key (kbd "M-s v") 'yas/visit-snippet-file)

;; ;; ECB
;; (global-set-key (kbd "<f11>") 'ecb-activate)
;; (global-set-key (kbd "C-<f11>") 'ecb-deactivate)
;; (global-set-key (kbd "M-s-h") 'ecb-goto-window-methods)
;; (global-set-key (kbd "M-s-l") 'ecb-goto-window-edit-last)
 
;; ;; ERC
;; (global-set-key (kbd "<f12>") 'erc)

;; ;; EMMS
;; (global-set-key (kbd "<f6>") 'emms-play-directory)
;; (global-set-key (kbd "<f5>") 'emms-playlist-mode-go)

;; ----------------------------------------------------------------------
;; CUSTOMIZE
;; ----------------------------------------------------------------------

(custom-set-variables
  ;; custom-set-variables was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 '(TeX-output-view-style (quote (("^dvi$nnnnnnn" ("^landscape$" "^pstricks$\\|^pst-\\|^psfrag$") "%(o?)dvips -t landscape %d -o && gv %f") ("^dvi$" "^pstricks$\\|^pst-\\|^psfrag$" "%(o?)dvips %d -o && gv %f") ("^dvi$" ("^a4\\(?:dutch\\|paper\\|wide\\)\\|sem-a4$" "^landscape$") "%(o?)xdvi %dS -paper a4r -s 0 %d") ("^dvi$" "^a4\\(?:dutch\\|paper\\|wide\\)\\|sem-a4$" "%(o?)xdvi %dS -paper a4 %d") ("^dvi$" ("^a5\\(?:comb\\|paper\\)$" "^landscape$") "%(o?)xdvi %dS -paper a5r -s 0 %d") ("^dvi$" "^a5\\(?:comb\\|paper\\)$" "%(o?)xdvi %dS -paper a5 %d") ("^dvi$" "^b5paper$" "%(o?)xdvi %dS -paper b5 %d") ("^dvi$" "^letterpaper$" "%(o?)xdvi %dS -paper us %d") ("^dvi$" "^legalpaper$" "%(o?)xdvi %dS -paper legal %d") ("^dvi$" "^executivepaper$" "%(o?)xdvi %dS -paper 7.25x10.5in %d") ("^dvi$" "." "%(o?)xdvi %dS %d") ("^pdf$" "." "acroread %o %(outpage)") ("^html?$" "." "netscape %o")))))
 ;; '(ecb-auto-activate t)
 ;; '(ecb-fix-window-size t)
 ;; '(ecb-layout-window-sizes (quote (("left8" (0.16774193548387098 . 0.2894736842105263) (0.16774193548387098 . 0.23684210526315788) (0.16774193548387098 . 0.2894736842105263) (0.16774193548387098 . 0.15789473684210525)))))
 ;; '(ecb-options-version "2.32")
 ;; '(ecb-tip-of-the-day nil)
 ;; '(ecb-windows-width 0.33)
 ;; '(erc-autojoin-channels-alist (quote (("freenode.net" "#ubuntu-cn" "#cuit-uif"))))
 ;; '(erc-nick "Dreamseeker")
 ;; '(erc-part-reason-various-alist (quote (("night" "Bonne Nuit :P"))))
 ;; '(erc-port 6667)
 ;; '(erc-server "irc.freenode.net")
 ;; '(erc-user-full-name "Dreamseeker")
 ;; '(jde-jdk-registry (quote (("1.6.0_06" . "/usr/lib/jvm/java-6-sun")))))
(custom-set-faces
  ;; custom-set-faces was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 )
