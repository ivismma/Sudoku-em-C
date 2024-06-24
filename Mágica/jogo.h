#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include <ncurses.h>
#include <locale.h> // setlocale()..

#define N 9

typedef struct{
	short i; // Linha  (y)
	short j; // Coluna (x)
} tPos;

extern int seed;

// inputoutput.c
void lerSeed();
tPos selecionar(short *tentativa, short M1[N][N]);
void input(tPos *escolha, int tecla, bool *selecionado, short M1[N][N]);
bool verificaAcerto(short tentativa, tPos pos, short M1[N][N]);
tPos converterPos(tPos pos);
short palpitar();

// visual.c
void desenhaJogo(short M1[N][N]);
void desenhaArea();
void exibeNumeros(short M[N][N]);
void exibeAcerto(tPos pos, short num);
void areaEscolha();
void mostrarEscolha(char escolhaAtual);
void exibirSetas(tPos escolha);
void apagarSetas(tPos escolha);
void apagarSelecao(tPos atual);
void mostrarSelecao();
void mostrarInfo();
void atualizarStats(short enc, short erros);

// geracao.c

bool posicaoValida(short M[N][N], int lin, int col, int num);
bool preencherSudoku(short M[N][N], int lin, int col);
void gerarSudoku(short M[N][N], short camposVazios);
void apagarCampos(short M[N][N], short camposVazios);
void lerSeed();


// filereading.c (não mais sendo usada)

// bool lerMapa(short M1[9][9], short *encontrados);
