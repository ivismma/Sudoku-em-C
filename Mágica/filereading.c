// filereading.c - File Management - Leitura dos arquivos dos mapas.

#include "jogo.h"

bool lerMapa(short M1[9][9], bool M2[9][9], short *encontrados){
	// 1º sudoku - teste...
	FILE *sudoku = fopen("./mapas/sudoku1a.dat", "r");
	FILE *mostrar = fopen("./mapas/sudoku1b.dat", "r");
	
	// Verif. abertura..
	if(sudoku == NULL || mostrar == NULL) return false;
	
	short num1, num2;
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			fscanf(sudoku, "%hd", &num1);
			fscanf(mostrar, "%hd", &num2);
			M1[i][j] = num1;
			if(num1 == num2){
				M2[i][j] = true;
				++*encontrados;
			}
			else M2[i][j] = false;
		}
	}
	fclose(sudoku);
	fclose(mostrar);
	
	return true;
}

// O arquivo a armazena todas as respostas do Sudoku atual, passando-as para matriz M1...
// O arquivo b armazena quais devem ser mostradas na tela, passando-os para a matriz M2 (como booleanos)...
/// a var. "encontrados" armazena quantos já estão sendo mostrados, o jogo termina com 81 (venceu o Sudoku).
