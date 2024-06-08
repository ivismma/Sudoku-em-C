#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <ncurses.h>
#include <locale.h> // setlocale..

typedef struct{
	short i; // Linha  (y)
	short j; // Coluna (x)
} tPos;

//extern short M1[9][9];
//extern bool M2[9][9];
//extern short encontrados;

// inputoutput.c
tPos selecionar(short *tentativa, bool M2[9][9]);
void input(tPos *escolha, int tecla, bool *selecionado, bool M2[9][9]);
void exibirSetas(tPos escolha);
void apagarSetas(tPos escolha);
tPos converterPos(tPos pos);
short palpitar();

// visual.c
void desenhaArea();
void exibeNumeros(short M[9][9], bool M2[9][9]);
void areaEscolha();
void mostrarEscolha(char escolhaAtual);
void mostrarSelecao();
void mostrarInfo();

// filereading.c
bool lerMapa(short M1[9][9], bool M2[9][9], short *encontrados);
