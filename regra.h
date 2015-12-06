/**
 * Saulo Tadashi Iguei NºUsp 7573548
 *
 * DATA entrega limite: 08/11/15
 *
 * SCC0201_01 - ICC2 _ Prof. Moacir
 *
 * Trabalho 6: Xadrez - Parte 1 (Geração de movimentos)
 */

/*
 * Biblioteca para gerenciamento de regras do jogo
 */

#ifndef __REGRA_H_
#define __REGRA_H_

#include <stdlib.h>
#include <stdio.h>
#include "integration.h"
#include "objeto.h"

//função definidora de pontuação por tipo da peça
int point (char type);

//função de separação por cor das peças
int separaCor (const void* a, const void* b);

//função de comparação para desempate
int desempate (const void* a, const void* b);

//função de comparação para ordenação de lista de movimento
int sortPlay (const void* a, const void* b);
int sortPlayConflict (const void* a, const void* b);

//preencher o tabuleiro com as peças obtidas
void fillTable (OBJETO *** table, OBJETO ** const collection, const int pieces_num);

//função irá imprimir o tabuleiro na tela
void printTable (OBJETO *** const table);

//função irá avaliar se há risco no movimento da peça contra o rei
int riscoRei (OBJETO *** const table, OBJETO * const obj, int row, int col, int turn);

//*********************** trabalho 07
PLAY inputPlay (FEN const *fen, OBJETO *** const table, int turn, int fullTurn);
//funçao verifica fim de jogo
int verifyGameState (OBJETO *** const table, OBJETO **const collection, const int pieces_num, FEN *fen);

#endif
