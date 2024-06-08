#include "jogo.h"

int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	short M1[9][9]; // Matriz completa
	bool  M2[9][9]; // Matriz mapeada com valores achados e não achados.
	short encontrados, // Quantos valores já estão sendo mostrados...
		  tentativa,
		  erros = 0;
	
	if(!lerMapa(M1, M2, &encontrados)){
		printf("Falha na leitura do arquivo do mapa atual.\n");
		return 1;
	}
	
	initscr(); // screen
	keypad(stdscr, TRUE); noecho(); curs_set(0);
	desenhaArea();
	mostrarInfo();
	
	do{ // loop do jogo..
		mvprintw(25, 5, "Encontrados: %hd", encontrados);
		mvprintw(26, 5, "Erros: %hd", erros);
		exibeNumeros(M1, M2);
		tPos pos = selecionar(&tentativa, M2);
		if(tentativa == M1[pos.i][pos.j]){
			M2[pos.i][pos.j] = true;
			++encontrados;
		}
		else ++erros;
	} while(encontrados < 81);
	
	endwin();
	return 0;
}
