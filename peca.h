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
 * Biblioteca para manipulação de peças
 */

#ifndef __PECA_H_
#define __PECA_H_

#include <stdlib.h>
#include <stdio.h>
#include "integration.h"
#include "objeto.h"

//funções buscam todos os possíveis movimentos de uma dada peça
char** movPeasant (MOV_PARAM);
char** movKnight (MOV_PARAM);
char** movBishop (MOV_PARAM);
char** movRook (MOV_PARAM);
char** movQueen (MOV_PARAM);
char** movKing (MOV_PARAM);

//funções buscam e imprimem todos os possíveis movimentos de uma dada peça
void printListMovPeasant (MOV_PARAM);
void printListMovKnight (MOV_PARAM);
void printListMovBishop (MOV_PARAM);
void printListMovRook (MOV_PARAM);
void printListMovQueen (MOV_PARAM);
void printListMovKing (MOV_PARAM);

//*********************** trabalho 07
OBJETO ** updateCollection (OBJETO ** collection, int *white_pieces, int *pieces_num, int turn);
OBJETO ** doPlay(OBJETO *** table, PLAY play, OBJETO ** collection, int white_pieces, int pieces_num, int fullTurn);

#endif
