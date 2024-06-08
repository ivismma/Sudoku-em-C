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
	refresh();
}

void exibeNumeros(short M[9][9], bool M2[9][9]){
	int i, j, k;
	// Primeira linha de células 3x3.
	for(k = 0; k < 3; ++k)
		for(i = 0; i < 3; ++i)
			for(j = 0; j < 3; ++j){
				short c = j+3*k;
				if(M2[i][c])
					mvprintw(1+i, (2+2*j)+(k*8), "%hd", M[i][c]);
				else
					mvprintw(1+i, (2+2*j)+(k*8), "-");
			}
				
	// Segunda linha de células 3x3.
	for(k = 0; k < 3; ++k)
		for(i = 0; i < 3; ++i)
			for(j = 0; j < 3; ++j){
				short l = i+3, c = j+3*k;
				if(M2[l][c])
					mvprintw(5+i, (2+2*j)+(k*8), "%hd", M[l][c]);
				else
					mvprintw(5+i, (2+2*j)+(k*8), "-");
			}
				
	// Terceira linha de células 3x3.	
	for(k = 0; k < 3; ++k)
		for(i = 0; i < 3; ++i)
			for(j = 0; j < 3; ++j){
				short l = i+6, c = j+3*k;
				if(M2[l][c])
					mvprintw(9+i, (2+2*j)+(k*8), "%hd", M[l][c]);
				else
					mvprintw(9+i, (2+2*j)+(k*8), "-");
			}
			
	refresh();
}

void areaEscolha(){
	for(int i = 0; i < 5; ++i) mvprintw(14, 10+i, "#");
	mvprintw(15, 10, "#");
	mvprintw(15, 14, "#");
	for(int i = 0; i < 5; ++i) mvprintw(16, 10+i, "#");
	//for(int i = 0; i < 3; ++i) mvprintw(15+i, 10, "#");
	//for(int i = 0; i < 3; ++i) mvprintw(15+i, 14, "#");
}

void mostrarEscolha(char escolhaAtual){
	if(escolhaAtual == '-') escolhaAtual = '?';
	mvprintw(15,12, "%c", escolhaAtual);
}

void mostrarInfo(){
	mvprintw(1, 29, "   Implementação do Sudoku pelo terminal com a biblioteca ncurses.");
	mvprintw(5, 29, ">> WIP -> 1ª iteração do jogo. Muitas coisas a ainda serem feitas... <<");
	mvprintw(12, 29, "Código por Ivis Muzi (=");
}

void mostrarSelecao(){
	mvprintw(20,4, "1 2 3 4 5 6 7 8 9");
}
