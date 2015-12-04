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
 * Biblioteca para tratamento da notação FEN
 */


#ifndef __FEN_H_
#define __FEN_H_

#include <stdlib.h>
#include <stdio.h>
#include "integration.h"
#include "objeto.h"
#include "peca.h"

//função irá extrair todas as peças da notação FEN
OBJETO ** extractTableFEN (char* pieces, int *tam, int *white);

//funções para extrair coluna e linha da peça segundo notação armazenada
int getObjectColumn (OBJETO *obj);
int getObjectRow (OBJETO *obj);
int getNotationColumn (char *not);
int getNotationRow (char *not);

//função irá adicionar notação para colisão de peças caso ocorra
char* collision (OBJETO *** const table, char *notation, OBJETO *const obj, int row, int col, int turn);

//função irá adicionar notação para colisão de peças após todas as análises de peças
void conflict (OBJETO **const collection, int size);

#endif
