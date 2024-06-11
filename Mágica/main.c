#include "jogo.h"

int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	short M1[9][9]; // Matriz completa
	short encontrados, // Quantos valores já estão sendo mostrados...
		  tentativa,
		  erros = 0;
	
	if(!lerMapa(M1, &encontrados)){
		printf("Falha na leitura do arquivo do mapa atual.\n\n");
		system("pause");
		return 1;
	}
	
	initscr(); // screen
	keypad(stdscr, TRUE); noecho(); curs_set(0);
	desenhaJogo(M1);
	
	do{ // loop do jogo..
	
		atualizarStats(encontrados, erros);
		tPos pos = selecionar(&tentativa, M1);
		if(tentativa != 10) // Não cancelou a inserção (Esc, backspace..)
			if(verificaAcerto(tentativa, pos, M1))
				++encontrados;
			else ++erros;
	} while(encontrados < 81);
	
	endwin();
	return 0;
}









/*
int main(void){
	
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	short M1[9][9]; // Matriz completa
	bool  M2[9][9]; // Matriz mapeada com valores achados e não achados.
	
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			M2[i][j] = true;
		}
	}
	
	short encontrados, // Quantos valores já estão sendo mostrados...
		  tentativa,
		  erros = 0;
	
	gerar_sudoku(M1,M2);
	
	initscr(); // screen
	keypad(stdscr, TRUE); noecho(); curs_set(0);
	desenhaArea();
	mostrarInfo();
	
	do{ // loop do jogo..
		atualizarStats(encontrados, erros);
		exibeNumeros(M1, M2);
		tPos pos = selecionar(&tentativa, M2);
		if(tentativa != 10) // 10 = Backspace <-> Cancelou a seleção...
			if(tentativa == M1[pos.i][pos.j]){
				M2[pos.i][pos.j] = true;
				++encontrados;
			}
			else ++erros;
	} while(encontrados < 81);
	
	endwin();
	
	return 0;
}
*/
