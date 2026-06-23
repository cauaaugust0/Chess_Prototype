#include"chess.h"

void setupCells(CELL *cells)
{
	// iniciando celulas
	int index = 0;
	
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{	
			if((i + j) % 2 == 0)
			{
				setCellRectangle(&cells[index], (float)map[index].x, (float)map[index].y, LIGHTGRAY);
			}
			else
			{
				setCellRectangle(&cells[index], (float)map[index].x, (float)map[index].y, DARKBROWN);
			}
			
			index++;
		}
	}
	
	for(int i = 8; i < 15; i++)
	{
		setOccupiedBy(&cells[i], BLACK_COLOR);
	}
	setOccupiedBy(&cells[2], BLACK_COLOR);
	setOccupiedBy(&cells[5], BLACK_COLOR);
	
	setOccupiedBy(&cells[1], BLACK_COLOR);
	setOccupiedBy(&cells[6], BLACK_COLOR);
	
	setOccupiedBy(&cells[0], BLACK_COLOR);
	setOccupiedBy(&cells[7], BLACK_COLOR);
	
	setOccupiedBy(&cells[3], BLACK_COLOR);
	setOccupiedBy(&cells[4], BLACK_COLOR);

	for(int i = 48; i < 56; i++)
	{
		setOccupiedBy(&cells[i], WHITE_COLOR);
	}
	setOccupiedBy(&cells[58], WHITE_COLOR);
	setOccupiedBy(&cells[61], WHITE_COLOR);

	setOccupiedBy(&cells[57], WHITE_COLOR);
	setOccupiedBy(&cells[62], WHITE_COLOR);
	
	setOccupiedBy(&cells[56], WHITE_COLOR);
	setOccupiedBy(&cells[63], WHITE_COLOR);
	
	setOccupiedBy(&cells[59], WHITE_COLOR);
	setOccupiedBy(&cells[60], WHITE_COLOR);
}

void setupPieces(PIECE *pieces)
{
	// iniciando peças
	int pawnIndex = 8;
	for(int i = 0; i < 8; i++)
	{
		setPieceRectangle(&pieces[i], (float)map[pawnIndex].x, (float)map[pawnIndex].y, BLACK_COLOR, PAWN);
		pawnIndex++;
	}
	
	setPieceRectangle(&pieces[8], (float)map[2].x, map[2].y, BLACK_COLOR, BISHOP);
	setPieceRectangle(&pieces[9], (float)map[5].x, map[5].y, BLACK_COLOR, BISHOP);
	
	setPieceRectangle(&pieces[10], (float)map[1].x, map[1].y, BLACK_COLOR, KNIGHT);
	setPieceRectangle(&pieces[11], (float)map[6].x, map[6].y, BLACK_COLOR, KNIGHT);

	setPieceRectangle(&pieces[12], (float)map[0].x, map[0].y, BLACK_COLOR, ROOK);
	setPieceRectangle(&pieces[13], (float)map[7].x, map[7].y, BLACK_COLOR, ROOK);
	
	setPieceRectangle(&pieces[14], (float)map[3].x, map[3].y, BLACK_COLOR, QUEEN);
	setPieceRectangle(&pieces[15], (float)map[4].x, map[4].y, BLACK_COLOR, KING);
	
	pawnIndex = 48;
	for(int i = 16; i < 24; i++)
	{
		setPieceRectangle(&pieces[i], (float)map[pawnIndex].x, (float)map[pawnIndex].y, WHITE_COLOR, PAWN);
		pawnIndex++;
	}

	setPieceRectangle(&pieces[24], (float)map[58].x, map[58].y, WHITE_COLOR, BISHOP);
	setPieceRectangle(&pieces[25], (float)map[61].x, map[61].y, WHITE_COLOR, BISHOP);
	
	setPieceRectangle(&pieces[26], (float)map[57].x, map[57].y, WHITE_COLOR, KNIGHT);
	setPieceRectangle(&pieces[27], (float)map[62].x, map[62].y, WHITE_COLOR, KNIGHT);

	setPieceRectangle(&pieces[28], (float)map[56].x, map[56].y, WHITE_COLOR, ROOK);
	setPieceRectangle(&pieces[29], (float)map[63].x, map[63].y, WHITE_COLOR, ROOK);
	
	setPieceRectangle(&pieces[30], (float)map[59].x, map[59].y, WHITE_COLOR, QUEEN);
	setPieceRectangle(&pieces[31], (float)map[60].x, map[60].y, WHITE_COLOR, KING);

	for(int i = 0; i < MAX_PIECES; i++)
	{
		setPieceTexture(&pieces[i]);
	}
}

void setupGameState(GAME_STATE *gameState)
{
	gameState->selectionState = 0;
	gameState->selectedPiece = NULL;
}