syntax on
filetype on
set number
set noexpandtab
set tabstop=4
set shiftwidth=4
set scrolloff=10
set autoindent

set autochdir

inoremap ( ()<left>
inoremap ' ''<left>
inoremap " ""<left>
inoremap [ []<left>
inoremap { {}<left>

function! s:InsertBrace()
	let l:last_char = getline('.')[col('.') - 2]
	if l:last_char ==# ')'
		call feedkeys("{\<left>\<CR>\<right>\<CR>}\<Esc>O\<TAB>", 'n')
	else
		call feedkeys("\<CR>", 'n')
	endif
endfunction

inoremap <CR> <C-\><C-O>:call <SID>InsertBrace()<CR>

map f :w<CR>:find**/**
map ; :

nnoremap <BS> :w<CR>:E<CR>

nnoremap <C-Up> :m-2<CR>
nnoremap <C-Down> :m+1<CR>

inoremap <C-Up> <c-o>:m-2<CR>
inoremap <C-Down> <c-o>:m+1<CR>
inoremap <C-d> <c-o>:t.<CR>
inoremap <C-z> <c-o>:u<CR>
inoremap <C-r> <c-o>:redo<CR>

inoremap ` <c-o>:w<CR><c-o>:!cc %:p:h/*.c -Wextra -Wall -Werror && %:p:h/a.out<CR>
nnoremap ` :w<CR>:!cc %:p:h/*.c -Wextra -Wall -Werror && %:p:h/a.out<CR>
