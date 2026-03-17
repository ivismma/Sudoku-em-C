Sudoku em linguagem C utilizando biblioteca ncurses.<br>
Geração randômica do Sudoku utilizando semente via input para a geração aleatória
do tabuleiro.<br>
<br>
<b>Miniprojeto feito lá em 2024, desprovido de algumas boas práticas de programação, releve.</b>
<br><br>

> Seed: Inserida do usuário (inteiro de até 8 dígitos).

Utilize as setas do teclado e o ENTER para jogar, Backspace e Esc cancelam<br>
a escolha.<br>
Além disso, ao selecionar um campo vazio é possível inserir números diretamente do teclado,<br>
teclando de 1 a 9 caso não queira selecionar os números manualmente com as setas. <br>


<h3>Para compilar no Linux:</h3>
1. Instale os pacotes <b>ncurses</b> e <b>ncursesw</b>:
<br>
<b>sudo apt install libncurses5-dev libncursesw5-dev</b>
<br><br>
2. Compile:<br>
<b>gcc main.c visual.c inputoutput.c geracao.c</b>
<br><br>
Obs.: Na compilação, acrescente a flag <b>-lncurses</b>, ou <b>-lncursesw</b>, (para UTF-8)
<br><br>
3. Antes de executar, aumente/maximize a tela do seu terminal, 
ncurses é problemático com window resizing.

Se preferir, acrescente otimização -O1 ou -O2.
