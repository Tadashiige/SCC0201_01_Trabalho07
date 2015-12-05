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
 * Arquivo Principal - main
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "FEN.h"
#include "objeto.h"
#include "peca.h"
#include "regra.h"

//todo fazer interface para chamada de função updateFEN e interface de interação com o usuário

int main (int argc, char* argv[])
{
	//declaração de variáveis da notação FEN
	FEN *fen = (FEN*) malloc(sizeof(FEN));

	//recepção dos valores da notação FEN
	fscanf(stdin, "%s ", fen->pieces);
	fscanf(stdin, "%c ", &(fen->turn));
	fscanf(stdin, "%s ", fen->rock);
	fscanf(stdin, "%s ", fen->pass);
	fscanf(stdin, "%d ", &(fen->halfTurn));
	fscanf(stdin, "%d", &(fen->fullTurn));

	//extrair todos as peças da notação FEN
	int pieces_num = 0;
	int white_pieces = 0;
	OBJETO **collection = extractTableFEN (fen->pieces, &pieces_num, &white_pieces);

	//ordenar por cor, os brancos vem primeiro
	qsort(collection, pieces_num, sizeof(OBJETO*), &separaCor);

	//ordenar por critério de desempate e apenas as peças do turno
	if(fen->turn == 'w')
		qsort(collection, white_pieces, sizeof(OBJETO*), &desempate);
	else
		qsort(collection + white_pieces, pieces_num - white_pieces, sizeof(OBJETO*), &desempate);

	//construir o tabuleiro
	OBJETO ***table = (OBJETO***)malloc(sizeof(OBJETO**)*TABLE_ROWS);
	int i;
	for(i = 0; i < TABLE_ROWS; i++)
		table[i] = (OBJETO**)malloc(sizeof(OBJETO*)*TABLE_COLS);

	//preencher o tabuleiro
	fillTable (table, collection, pieces_num);

	//todo para apagar
	//printCollectionObject (collection, pieces_num);
	//printTable(table);

	//	 imprimir lista de movimentos para cada peça
	int total;
	OBJETO **collection_list;

	//as primeiras n primeiras posições são ocupadas por peças brancas, e as posteriores por pretas
	if(fen->turn == 'w')
	{
		total = white_pieces;
		collection_list = collection;
	}
	else
	{
		total = pieces_num - white_pieces;
		collection_list = collection + white_pieces;
	}

	char **list;

	//executar as listagem de movimentos para cada peça
	for(i = 0; i < total; i++)
	{
		funcPtr funcType;
		funcType = getFunctionMov(collection_list[i]);
		OBJETO *obj = collection_list[i];
		char white = getType(obj) - (getType(obj) >= 'a')*32;
		char black = getType(obj) + (getType(obj) < 'a')*32;
		//printf("peca %dº - %c[%d][%d]\n", i, getType(obj), getObjectRow(obj), getObjectColumn(obj));
		list = funcType(MOV_VALUE);
	}

	//tratar jogadas coincidentes
	conflict (collection_list, total);

	//imprimir as jogadas possíveis para o turno
	printCollectionPlay(collection_list, total);

	//eliminar todos os objetos alocados
	for(i = 0; i < pieces_num; i++)
	{
		deleteObject(&(collection[i]));
	}
	if(collection != NULL)
		free(collection);

	//as peças dentro do tabuleiro já foram liberado por coleção, então basta liberar o tabuleiro
	if(table != NULL)
	{
		for(i = 0; i < TABLE_ROWS; i++)
		{
			if(table[i] != NULL)
			{
				free(table[i]);
			}
		}
		free(table);
	}

	deleteFEN(&fen);

	return 0;
}
