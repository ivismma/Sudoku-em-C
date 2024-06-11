// filereading.c - File Management - Leitura dos arquivos dos mapas.

#include "jogo.h"

bool lerMapa(short M1[9][9], short *encontrados){
	// 1� sudoku - teste...
	FILE *sudoku = fopen("./mapas/sudoku1.dat", "r");
	
	// Verif. abertura..
	if(sudoku == NULL) return false;
	
	short num1;
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			fscanf(sudoku, "%hd", &num1);
			M1[i][j] = num1;
			if(num1 > 0) ++*encontrados;
		}
	}
	fclose(sudoku);
	
	return true;
}

/*
O arquivo sudoku(numero).dat armazena o "mapa" completo do sudoku atual, os valores negativos s�o os campos
onde n�o dever�o ser mostrados para o jogador. Conforme o jogador encontre os valores, estes ter�o seus valores
na matriz multiplicado por (-1), transformando-o em positivo e mostrando-o na tela. (A condi��o que verifica se
o n�mero deve ser mostrado ou n�o est� na fun��o exibeNumeros).
*/
