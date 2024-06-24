#include "jogo.h"

#define CAMPOS_VAZIOS 52 // dificuldade media

int seed;

int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	short M1[9][9], // Matriz completa
	 	  encontrados = 81-CAMPOS_VAZIOS, 
		  tentativa,
		  erros = 0;
	
	lerSeed();
	srand(seed);
	gerarSudoku(M1, CAMPOS_VAZIOS);
	
	initscr(); // screen
	keypad(stdscr, TRUE); noecho(); curs_set(0);
	desenhaJogo(M1);
	
	do{ // loop do jogo..
	
		atualizarStats(encontrados, erros);
		tPos pos = selecionar(&tentativa, M1);
		if(tentativa != 10) // Não cancelou a inserção (Esc, backspace..)
			if(verificaAcerto(tentativa, pos, M1)) ++encontrados;
			else ++erros;
		
	} while(encontrados < 81);
	
	endwin();
	return 0;
}
