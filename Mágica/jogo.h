#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include <ncurses.h>
#include <locale.h> // setlocale..

typedef struct{
	short i; // Linha  (y)
	short j; // Coluna (x)
} tPos;

// inputoutput.c
tPos selecionar(short *tentativa, short M1[9][9]);
void input(tPos *escolha, int tecla, bool *selecionado, short M1[9][9]);
bool verificaAcerto(short tentativa, tPos pos, short M1[9][9]);
tPos converterPos(tPos pos);
short palpitar();

// visual.c
void desenhaJogo(short M1[9][9]);
void desenhaArea();
void exibeNumeros(short M[9][9]);
void exibeAcerto(tPos pos, short num);
void areaEscolha();
void mostrarEscolha(char escolhaAtual);
void exibirSetas(tPos escolha);
void apagarSetas(tPos escolha);
void apagarSelecao(tPos atual);
void mostrarSelecao();
void mostrarInfo();
void atualizarStats(short enc, short erros);

// filereading.c
bool lerMapa(short M1[9][9], short *encontrados);
