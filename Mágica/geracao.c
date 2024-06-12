// geracao.c - Sudoku Generation - Geração randômica de mapa.

#include "jogo.h"

// Gera o tabuleiro Sudoku randômico e recebe como argumento quantos deverão ser campos vazios.
void gerarSudoku(short M[N][N], short camposVazios){
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            M[i][j] = 0;

    preencherSudoku(M, 0, 0);
    apagarCampos(M, camposVazios);
}

// Apaga uma quantidade definida de campos no Sudoku.
// O argumento "camposVazios" irá nivelar a  dificuldade
// do Sudoku com base na quantidade apagada.

void apagarCampos(short M[N][N], short camposVazios){
    short cont = 0;
    while(cont < camposVazios){
        int lin = rand()%N;
        int col = rand()%N;
        if(M[lin][col] > 0){
            M[lin][col] *= -1; // valor na matriz torna-se positivo (mostrar na tela).
            ++cont;
        }
    }
}

bool posicaoValida(short M[N][N], int lin, int col, int num){
    for (int x = 0; x < N; ++x)
        if (M[lin][x] == num || M[x][col] == num)
            return false;

    int inicioLin = lin - lin % 3, inicioCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (M[i+inicioLin][j+inicioCol] == num)
                return false;

    return true;
}

bool preencherSudoku(short M[N][N], int lin, int col){
    if (lin == N - 1 && col == N)
        return true;
    if(col == N){
        ++lin;
        col = 0;
    }
    if(M[lin][col] != 0)
        return preencherSudoku(M, lin, col+1);

    int num;
    int numeros[N];
    for(int i = 0; i < N; ++i)
        numeros[i] = i+1;

    for(int i = N-1; i > 0; --i){
        int j = rand()%(i+1);
        int aux = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = aux;
    }

    for(int i = 0; i < N; ++i){
        num = numeros[i];
        if(posicaoValida(M, lin, col, num)){
            M[lin][col] = num;
            if(preencherSudoku(M, lin, col+1))
                return true;
            M[lin][col] = 0;
        }
    }
    return false;
}
