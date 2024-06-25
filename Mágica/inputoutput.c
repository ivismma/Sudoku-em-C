// inputoutput.c - Input Management - Funções que gerenciam I/O do jogo e afins..
#include "jogo.h"

// Coordenada da linha que contém a mensagem de inserir palpite:
#define X_INPUT 5
#define Y_INPUT 18
#define SEED_DIGS 8 // Quantidade de dígitos da seed - Obs: seed é um (int).

// Retorna true se acertou, false caso contrário.
// Libera a exibição do número, caso o usuário acerte.
bool verificaAcerto(short tentativa, tPos pos, short M1[N][N]){
		if(tentativa == -M1[pos.i][pos.j]){
			M1[pos.i][pos.j] *= -1;
			exibeAcerto(pos, tentativa);
			return true;
		} return false;
}

tPos selecionar(short *tentativa, short M1[N][N]){
	static tPos escolha = {6, 12}; // Meio da tela
	int tecla;
	char atual; // Qual número está sendo selecionado? Obtido pela func. mvinch()
	bool selecionado = false;
	
	exibirSetas(escolha);
	
	while(atual = mvinch(escolha.i, escolha.j), !selecionado){
		tPos anterior = escolha;
		mostrarEscolha(atual);
		
		tecla = getch();
		input(&escolha, tecla, &selecionado, M1);
		
        mostrarEscolha(atual);
        apagarSetas(anterior);
        exibirSetas(escolha);
	}
	mostrarSelecao();
	*tentativa = palpitar();
	
	// Converter para M[i][j] --> descobrir i e j atual da matriz.
	return converterPos(escolha);
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
			// Confirmar:
			case KEY_ENTER: // ENTER
			case 10:        // ENTER
				escolha = (atual.j/2)-1; // Número escolhido.
				break;
			// Cancelar:
			case 27:            // ESC
			case KEY_BACKSPACE: // BACKSPACE
			case '\b':          // BACKSPACE
			case 127:           // BACKSPACE
				escolha = 10;
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

void input(tPos *escolha, int tecla, bool *selecionado, short M1[N][N]){
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
       	case 10:        // ENTER
	    case KEY_ENTER: // ENTER
        	aux = converterPos(*escolha);
			if(M1[aux.i][aux.j] > 0) break;
        	*selecionado = true;
        	break;
    }
}

tPos converterPos(tPos pos){
	// Converter a coordenada na janela do ncurses para a matriz ([i][j])
	pos.i = (pos.i <= 4)? pos.i-1 : (pos.i <= 7)? pos.i-2 : pos.i-3;
	pos.j = (pos.j <= 6)? (pos.j-2)/2 : (pos.j <= 15)? (pos.j-4)/2 : (pos.j-6)/2;
	return pos;
}

void lerSeed(){
	char c, buffer[SEED_DIGS+1];
	bool seedValida; // Se não contém letras/simbolos/etc..
	int i = 0;
	do{
		seedValida = true;
		printf("Digite a seed de até 8 dígitos para a geração do Sudoku (somente números):\n--> ");
		for(i = 0; i < SEED_DIGS; ++i){
			c = getchar();
			if(c == '\n') break;
			else if(c < '0' || c > '9'){
				seedValida = false;
				printf("Seed inválida\n");
				break;
			}
			else buffer[i] = c; // OK.
		}
	} while(!seedValida);
	buffer[i] = '\0';
	seed = atoi(buffer);
}
