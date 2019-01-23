(global-set-key [f9] 'compile-file)
(global-set-key [f10] 'gud-gdb)
(global-set-key (kbd "C-s") 'save-buffer)
(global-set-key (kbd "C-z") 'undo)
(global-set-key (kbd "RET") 'newline-and-indent)
(global-linum-mode t)
(show-paren-mode t)
(define-key key-translation-map (kbd "C-d") (kbd "M-p M-y"))    
(global-set-key (kbd "M-p M-y") 'kill-whole-line)
(define-key key-translation-map (kbd "C-a") (kbd "C-x h"))
(setq c-default-style "awk")
;;;考场必备
(ido-mode t)

(setq default-frame-alist
             '((vertical-scroll-bars)
               (top . 25)
               (left . 45)
               (width . 120)
               (height . 40)
               (background-color . "grey15")
               (foreground-color . "grey")
               (cursor-color . "gold1")
               (mouse-color . "gold1")
               (tool-bar-lines . 0)
               (menu-bar-lines . 1)
               (scroll-bar-lines . 0)
               (right-fringe)
               (left-fringe)))



(global-hl-line-mode 1)

(set-face-background 'highlight "gray5")
(set-face-foreground 'region "cyan")
(set-face-background 'region "blue")
(set-face-foreground 'secondary-selection "skyblue")
(set-face-background 'secondary-selection "darkblue")

;;;;;设置org模式
(setq org-startup-indented t)
;(setq org-log-done 'time)
;(s.etq org-log-done 'note)
;

;;;无关紧要
(set-cursor-color "wheat")
(set-mouse-color "wheat")
(global-font-lock-mode t);;高亮
;;;;;设置编译信息
(defun compile-file ()
  (interactive)
  (compile (format "g++ -o '%s' '%s' -g -lm -Wall -std=c++11"  (file-name-sans-extension (buffer-name))(buffer-name))))
;;(global-set-key (kbd "<f9>") 'compile-file)
;;;;;设置一键调试
;;;;;改变emacs标题栏的标题
(setq frame-title-format "%b by GZY")
;;;;;允许emacs和外部其他程序的粘贴
(setq x-select-enable-clipboard t)
;; 显示列号
(setq column-number-mode t)
;;设置tab为2个空格的宽度
(setq default-tab-width 4)
(setq c-basic-offset 4)
;;;;;启用时间显示设置，在minibuffer上面的那个杠上（忘了叫什么来着）
(display-time-mode 1)
;;;;;时间使用24小时制
(setq display-time-24hr-format t)
;;;;;时间显示包括日期和具体时间
(setq display-time-day-and-date t)
;;;;;时间的变化频率，单位多少来着？
(setq display-time-interval 10)
;;;;;是用滚轴鼠标
(mouse-wheel-mode t)
;;;;;备份设置
;;;;;emacs还有一个自动保存功能，默认在~/.emacs.d/auto-save-list里，这个非常有用，我这里没有改动，具体可以参见Sams teach yourself emacs in 24hours(我简称为sams24)
;;;;;备份设置方法，直接拷贝
(setq backup-by-copying t)
;; 自动存盘
(setq auto-save-mode t)
;;;;;去掉烦人的警告铃声
(setq visible-bell nil)
(setq ring-bell-function 'ignore)
;;;;;指针不要闪，我得眼睛花了
(blink-cursor-mode -1)
;;;;;滚动页面时比较舒服，不要整页的滚动
(setq scroll-step 1
        scroll-margin 3
        scroll-conservatively 10000)
;;;;;设定删除保存记录为200，可以方便以后无限恢复
(setq kill-ring-max 200)
;;;;;修改透明度
(set-frame-parameter (selected-frame) 'alpha (list 90 80))
(add-to-list 'default-frame-alist (cons 'alpha (list 90 80)))
(setq-default cursor-type 'bar)

(show-paren-mode 1);;括号匹配
(fset 'yes-or-no-p 'y-or-n-p);;酱油的
(setq make-backup-files nil)
(global-auto-revert-mode t);自动reload文件





(global-set-key (kbd "<f8>") 'gdb-many-windows)


(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(blink-cursor-mode nil)
 '(column-number-mode t)
 '(cua-mode t nil (cua-base))
 '(display-time-mode t)
 '(inhibit-startup-screen t)
 '(show-paren-mode t))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:family "Ubuntu Mono" :foundry "DAMA" :slant normal :weight normal :height 151 :width normal)))))
