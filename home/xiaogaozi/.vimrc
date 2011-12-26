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

set fileencodings=ucs-bom,utf-8,cp936,gb18030,default,latin1

" Options for using diff mode.
set diffopt=vertical

" Change the color cheme.
if has("gui_running")
    colorscheme slate
endif

" Cancel the toolbar.
set guioptions-=T

" Convert TAB to SPACE.
set expandtab

" Set font.
if has("gui_running")
    set guifont=Menlo\ 12
endif

" Turn on persistent undo.
if v:version >= 703
    set undofile
endif

" Extended "%" matching
source $VIMRUNTIME/macros/matchit.vim

" Template for Vim.
autocmd BufNewFile *.c 0r ~/.templates/TEMPLATE.c.tpl
autocmd BufNewFile *.h 0r ~/.templates/TEMPLATE.h.tpl
autocmd BufNewFile *.sh 0r ~/.templates/TEMPLATE.sh.tpl
autocmd BufNewFile *.py 0r ~/.templates/TEMPLATE.py.tpl
autocmd BufNewFile *.cpp 0r ~/.templates/TEMPLATE.cpp.tpl
autocmd BufNewFile *.gyp 0r ~/.templates/TEMPLATE.gyp.tpl
autocmd BufNewFile *.html 0r ~/.templates/TEMPLATE.html.tpl
autocmd BufNewFile Makefile 0r ~/.templates/Makefile.tpl
autocmd BufNewFile CMakeLists.txt 0r ~/.templates/CMakeLists.txt.tpl

" ----------------------------------------------------------------------
" KEYBINDINGS
" ----------------------------------------------------------------------

noremap <Leader>Q <Esc><C-W>v<C-W><C-L>:copen<CR><C-W><C-K>:q<CR>
noremap <Leader>W :make<CR>
noremap <C-_> :cp<CR>  " previous error
noremap <C-\> :cn<CR>  " next error

noremap <Leader>T :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR>

" cscope
if has("cscope")
	set cscopequickfix=s-,c-,d-,i-,t-,e-
    set nocsverb
    " add any database in current directory
    if filereadable("cscope.out")
        cs add cscope.out
    " else add database pointed to by environment
    elseif $CSCOPE_DB != ""
        cs add $CSCOPE_DB
    endif
    set csverb
endif
noremap <Leader>C :!cscope -Rbkq<CR>
noremap <C-_>s :cs find s <C-R>=expand("<cword>")<CR><CR>
noremap <C-_>g :cs find g <C-R>=expand("<cword>")<CR><CR>
noremap <C-_>c :cs find c <C-R>=expand("<cword>")<CR><CR>
noremap <C-_>t :cs find t <C-R>=expand("<cword>")<CR><CR>
noremap <C-_>e :cs find e <C-R>=expand("<cword>")<CR><CR>
noremap <C-_>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
noremap <C-_>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
noremap <C-_>d :cs find d <C-R>=expand("<cword>")<CR><CR>

inoremap ( ()<Esc>i
inoremap [ []<Esc>i
inoremap " ""<Esc>i
inoremap ' ''<Esc>i
inoremap < <><Esc>i
inoremap <C-B> <Esc>A;

" ----------------------------------------------------------------------
" OMNI COMPLETION
" ----------------------------------------------------------------------

" " Don't show the preview window.
" set completeopt=menu

set tags+=~/.vim/tags/systags  " /usr/include
set tags+=~/.vim/tags/cpptags  " http://www.vim.org/scripts/script.php?script_id=2358

" " Map <Tab> to either actually insert a <Tab> if
" " the current line is currently only whitespace, or start a omni
" " completion operation.
" function! CleverTab()
"     if strpart(getline('.'), 0, col('.')-1) =~ '^\s*$'
"         return "\<Tab>"
"     else
"         let current_path = bufname("%")  " get name of current buffer
"         let current_path = system("dirname " . current_path)
"         execute "cd " . current_path
"         execute "silent !ctags -R -f /tmp/tags ."
"         return "\<C-X>\<C-O>"
"     endif
" endfunction
" inoremap <Tab> <C-R>=CleverTab()<CR>

" ----------------------------------------------------------------------
" PLUGINS SETTINGS
" ----------------------------------------------------------------------

" pathogen.vim (http://www.vim.org/scripts/script.php?script_id=2332)
call pathogen#infect()

" MiniBufferExplorer (http://www.vim.org/scripts/script.php?script_id=159)
let g:miniBufExplMapWindowNavVim = 1
let g:miniBufExplMapCTabSwitchBufs = 1

" SuperTab (http://www.vim.org/scripts/script.php?script_id=1643)
let g:SuperTabDefaultCompletionType = "context"

" OmniCppComplete (http://www.vim.org/scripts/script.php?script_id=1520)
let OmniCpp_SelectFirstItem = 1
" autocmd CursorMovedI * if pumvisible() == 0|pclose|endif
" autocmd InsertLeave * if pumvisible() == 0|pclose|endif
