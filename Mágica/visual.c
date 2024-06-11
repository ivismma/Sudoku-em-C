// visual.c - HUD/Texto do jogo - Funções que gerenciam impressões na tela, refresh() etc.

#include "jogo.h"

void desenhaArea(){
	// Paredes externas horizontais
	for(int i = 0; i < 25; i+=2)
		mvprintw(0, i, "#");
	for(int i = 2; i < 25; i+=2)
		mvprintw(12, i, "#");
	// Paredes externas verticais:
	for(int i = 1; i < 13; ++i)
		mvprintw(i, 0, "#");
	for(int i = 1; i < 12; ++i)
		mvprintw(i, 24, "#");
	/*
	// Divisões internas:
	for(int i = 0; i < 23; ++i)
		mvprintw(4, i+1, "#");
	for(int i = 1; i < 24; ++i)
		mvprintw(8, i, "#");
	for(int i = 1; i < 13; ++i)
		mvprintw(i, 8, "#");
	for(int i = 1; i < 13; ++i)
		mvprintw(i, 16, "#");
	*/
	areaEscolha();
}

void exibeNumeros(short M[9][9]){
	int i, j, k;
	// Primeira linha de células 3x3.
	for(k = 0; k < 3; ++k)
		for(i = 0; i < 3; ++i)
			for(j = 0; j < 3; ++j){
				short c = j+3*k;
				if(M[i][c] > 0)
					mvprintw(1+i, (2+2*j)+(k*8), "%hd", M[i][c]);
				else
					mvprintw(1+i, (2+2*j)+(k*8), "-");
			}
				
	// Segunda linha de células 3x3.
	for(k = 0; k < 3; ++k)
		for(i = 0; i < 3; ++i)
			for(j = 0; j < 3; ++j){
				short l = i+3, c = j+3*k;
				if(M[l][c] > 0)
					mvprintw(5+i, (2+2*j)+(k*8), "%hd", M[l][c]);
				else
					mvprintw(5+i, (2+2*j)+(k*8), "-");
			}
				
	// Terceira linha de células 3x3.	
	for(k = 0; k < 3; ++k)
		for(i = 0; i < 3; ++i)
			for(j = 0; j < 3; ++j){
				short l = i+6, c = j+3*k;
				if(M[l][c] > 0)
					mvprintw(9+i, (2+2*j)+(k*8), "%hd", M[l][c]);
				else
					mvprintw(9+i, (2+2*j)+(k*8), "-");
			}
}

void exibeAcerto(tPos pos, short num){
	pos.i = (pos.i < 3)? pos.i+1 : (pos.i < 6)? pos.i+2 : pos.i+3;
	pos.j = (pos.j < 3)? pos.j*2+2 : (pos.j < 6)? pos.j*2 + 4 : pos.j*2 + 6; 
	mvprintw(pos.i, pos.j, "%hd", num);
}

void areaEscolha(){
	for(int i = 0; i < 5; ++i) mvprintw(14, 10+i, "#");
	mvprintw(15, 10, "#");
	mvprintw(15, 14, "#");
	for(int i = 0; i < 5; ++i) mvprintw(16, 10+i, "#");
}

void mostrarEscolha(char escolhaAtual){
	if(escolhaAtual == '-') escolhaAtual = '?';
	mvprintw(15,12, "%c", escolhaAtual);
}

void mostrarInfo(){
	mvprintw(0, 29, "   Implementação do Sudoku pelo terminal com a biblioteca ncurses.");
	mvprintw(2, 29, ">> WIP -> 1ª iteração do jogo. Muitas coisas a ainda serem feitas... <<");
	mvprintw(4, 29, "-----------------------------------------------------------------------");
	mvprintw(23, 5, "Faltam:");
	mvprintw(24, 5, "Erros:");
	mvprintw(6, 29, "Teclas do jogo:");
	mvprintw(8, 29,  "Setas         -> Mover");
	mvprintw(9, 29,  "ENTER         -> Confirmar");
	mvprintw(10, 29, "BACKSPACE/Esc -> Cancelar ");
	mvprintw(12, 29, "Obs: É possível inserir números teclando diretamente o número desejado.");
	mvprintw(27, 5, "Código por Ivis Muzi (=");
}

void atualizarStats(short enc, short erros){
	mvprintw(23, 16, "%hd", 81-enc);
	mvprintw(24, 16, "%hd", erros);
}

void mostrarSelecao(){
	mvprintw(20,4, "1 2 3 4 5 6 7 8 9");
}

void apagarSelecao(tPos atual){
	move(20,3);
	clrtoeol();
	move(18,4);
	clrtoeol();
}

void apagarSetas(tPos pos){
	mvprintw(pos.i, pos.j-1, " ");
    mvprintw(pos.i, pos.j+1, " ");
}

void exibirSetas(tPos pos){
	mvprintw(pos.i, pos.j-1, ">");
    mvprintw(pos.i, pos.j+1, "<");
}

void desenhaJogo(short M1[9][9]){
	desenhaArea();
	exibeNumeros(M1);
	mostrarInfo();
}
