" ----------------------------------------------------------------------
" GENERAL SETTINGS
" ----------------------------------------------------------------------

" Use Vim settings, rather then Vi settings (much better!).
" This must be first, because it changes other options as a side effect.
set nocompatible

" " For Win32 GUI: remove 't' flag from 'guioptions': no tearoff menu entries
" let &guioptions = substitute(&guioptions, "t", "", "g")

" allow backspacing over everything in insert mode
set backspace=indent,eol,start

if has("vms")
  set nobackup		" do not keep a backup file, use versions instead
else
  set backup		" keep a backup file
endif
set history=50		" keep 50 lines of command line history
set ruler		" show the cursor position all the time
set showcmd		" display incomplete commands
set incsearch		" do incremental searching

" In many terminal emulators the mouse works just fine, thus enable it.
if has('mouse')
    set mouse=a
endif

" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
    syntax on
    set hlsearch
endif

" Only do this part when compiled with support for autocommands.
if has("autocmd")

    " Enable file type detection.
    " Use the default filetype settings, so that mail gets 'tw' set to 72,
    " 'cindent' is on in C files, etc.
    " Also load indent files, to automatically do language-dependent indenting.
    filetype plugin indent on

    " Put these in an autocmd group, so that we can delete them easily.
    augroup vimrcEx
        au!

        " For all text files set 'textwidth' to 78 characters.
        autocmd FileType text setlocal textwidth=78

        " When editing a file, always jump to the last known cursor position.
        " Don't do it when the position is invalid or when inside an event handler
        " (happens when dropping a file on gvim).
        " Also don't do it when the mark is in the first line, that is the default
        " position when opening a file.
        autocmd BufReadPost *
                    \ if line("'\"") > 1 && line("'\"") <= line("$") |
                    \     exe "normal! g`\"" |
                    \ endif
    augroup END

else
    set autoindent		" always set autoindenting on
endif

" Convenient command to see the difference between the current buffer and the
" file it was loaded from, thus the changes you made.
" Only define it when not defined already.
if !exists(":DiffOrig")
    command DiffOrig vert new | set bt=nofile | r # | 0d_ | diffthis
                \ | wincmd p | diffthis
endif

set shiftwidth=4
set softtabstop=4
set tabstop=4
set cinoptions=>4,g0,h4,(0

" Options for using diff mode.
set diffopt=vertical

" Change the color cheme.
colorscheme slate

" Cancel the toolbar.
set guioptions-=T

" Convert TAB to SPACE.
set expandtab

" Set font.
set guifont=Monaco\ 11

" Template for Vim.
autocmd BufNewFile *.c 0r ~/.templates/TEMPLATE.c.tpl
autocmd BufNewFile *.sh 0r ~/.templates/TEMPLATE.sh.tpl
autocmd BufNewFile *.py 0r ~/.templates/TEMPLATE.py.tpl
autocmd BufNewFile *.cpp 0r ~/.templates/TEMPLATE.cpp.tpl
autocmd BufNewFile *.html 0r ~/.templates/TEMPLATE.html.tpl
autocmd BufNewFile Makefile 0r ~/.templates/Makefile.tpl

" ----------------------------------------------------------------------
" KEYBINDINGS
" ----------------------------------------------------------------------

noremap <F12> :make<CR>
noremap <F11> :cp<CR>  " previous error
noremap <F10> :cn<CR>  " next error
noremap <F9> <Esc><C-W>v<C-W><C-L>:copen<CR><C-W><C-K>:q<CR>

inoremap ( ()<Esc>i
inoremap [ []<Esc>i
inoremap " ""<Esc>i
inoremap ' ''<Esc>i
inoremap < <><Esc>i
inoremap <C-B> <Esc>A;

" ----------------------------------------------------------------------
" OMNI COMPLETION
" ----------------------------------------------------------------------

" Don't show the preview window.
set completeopt=menu

set tags+=~/.vim/systags,/tmp/tags

" Map <Tab> to either actually insert a <Tab> if
" the current line is currently only whitespace, or start a omni
" completion operation.
function! CleverTab()
    if strpart(getline('.'), 0, col('.')-1) =~ '^\s*$'
        return "\<Tab>"
    else
        let current_path = bufname("%")  " get name of current buffer
        let current_path = system("dirname " . current_path)
        execute "cd " . current_path
        execute "silent !ctags -R -f /tmp/tags ."
        return "\<C-X>\<C-O>"
    endif
endfunction
inoremap <Tab> <C-R>=CleverTab()<CR>

" ----------------------------------------------------------------------
" PLUGINS SETTINGS
" ----------------------------------------------------------------------

" MiniBufferExplorer
let g:miniBufExplMapWindowNavVim = 1
let g:miniBufExplMapCTabSwitchBufs = 1
