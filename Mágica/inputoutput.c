// inputoutput.c - Input Management - Funções que gerenciam I/O do jogo e afins..
#include "jogo.h"

// Coordenada da linha que contém a mensagem de inserir palpite:
#define X_INPUT 5
#define Y_INPUT 18

tPos selecionar(short *tentativa, bool M2[9][9]){
	tPos escolha = {6, 12}; // Meio da tela
	int tecla;
	char atual; // Qual número está sendo selecionado? Obtido pela func. mvinch()
	bool selecionado = false;
	
	exibirSetas(escolha);
	while(atual = mvinch(escolha.i, escolha.j), !selecionado){
		tPos anterior = escolha;
		mostrarEscolha(atual);
		
		tecla = getch();
		input(&escolha, tecla, &selecionado, M2);
		
        mostrarEscolha(atual);
        apagarSetas(anterior);
        exibirSetas(escolha);
	
	}
	mostrarSelecao();
	*tentativa = palpitar();
	apagarSetas(escolha);
	
	// Converter para M[i][j] --> descobrir i e j atual da matriz.
	return converterPos(escolha);
}

void input(tPos *escolha, int tecla, bool *selecionado, bool M2[9][9]){
	tPos aux;
	switch (tecla){
        case KEY_UP:
        	if(escolha->i == 1) break; // Limite da área do jogo...
			--escolha->i;
        	if(escolha->i == 4 || escolha->i == 8) --escolha->i;
			break;
        case KEY_DOWN:
        	if(escolha->i == 11) break; // Limite da área do jogo...
			++escolha->i;
        	if(escolha->i == 4 || escolha->i == 8) ++escolha->i;
			break;
        case KEY_LEFT:
        	if(escolha->j == 2) break; // Limite da área do jogo...
			escolha->j -= 2;
        	if(escolha->j == 8 || escolha->j == 16) escolha->j -= 2;
        	break;
        case KEY_RIGHT:
        	if(escolha->j == 22) break; // Limite da área do jogo...
			escolha->j += 2;
        	if(escolha->j == 8 || escolha->j == 16) escolha->j += 2;
        	break;
        case '\n': // ENTER
        	aux = converterPos(*escolha);
			if(M2[aux.i][aux.j] == true) break;
        	*selecionado = true;
        	break;
    }
}

short palpitar(){
	tPos atual = {20, 12}, anterior; // Começar no centro
	mvprintw(18,5,"Inserir número:");
	exibirSetas(atual);
	int tecla = KEY_LEFT;
	short escolha = 0;
	
	while(tecla = getch()){
		anterior = atual;
		switch(tecla){
			case KEY_LEFT:
				if(atual.j > 4) atual.j -= 2;
				break;
			case KEY_RIGHT:
				if(atual.j < 20) atual.j += 2;
				break;
			case '\n':
				escolha = (atual.j/2)-1; // Número escolhido.
				break;
			default: // Possibilitar escolha teclando o número no teclado:
				if(tecla >= '1' && tecla <= '9'){
					char c = tecla;
					escolha = (short) atoi(&c);
				}
				break;
		}
		if(escolha){
			apagarSelecao(atual);
			return escolha;
		}
		apagarSetas(anterior);
		exibirSetas(atual);
	}
}

void apagarSelecao(tPos atual){
	move(20,4);
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

tPos converterPos(tPos pos){
	// Converter a coordenada na janela do ncurses para a matriz ([i][j])
	pos.i = (pos.i <= 4)? pos.i-1 : (pos.i <= 7)? pos.i-2 : pos.i-3;
	pos.j = (pos.j <= 6)? (pos.j-2)/2 : (pos.j <= 15)? (pos.j-4)/2 : (pos.j-6)/2;
	return pos;
}
