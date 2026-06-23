#include"chess.h"

void update(GAME_STATE *gameState, CELL *cells, PIECE *pieces)
{	
	Vector2 mousePos = GetMousePosition();

	if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if(gameState->selectionState == 0)
		{
			for(int i = 0; i < MAX_PIECES; i++)
			{
				if(CheckCollisionPointRec(mousePos, pieces[i].pieceRectangle))
				{
					printf("\nCLICOU NA PEÇA\n");
					
					gameState->selectedPiece = &pieces[i];
					gameState->selectionState = 1;
					
					break;
				}
				
			}
			
		}
		else
		{
			for(int i = 0; i < MAX_CELLS; i++)
			{
				if(CheckCollisionPointRec(mousePos, cells[i].cellRectangle))
				{
					printf("\nCLICOU NA CELULA\n");
					
					setPiecePos(gameState->selectedPiece, map[i].x, map[i].y);
					
					gameState->selectedPiece = NULL;
					gameState->selectionState = 0;
					
					break;
				}
				
			}
			
		}
		
	}
	
}


void getPossibleMoves(GAME_STATE *gameState, CELL *cells)
{
	switch(gameState->selectedPiece->pieceType)
	{
		case PAWN:
		{
			calcPawnMoves(gameState, cells);
		}
		case BISHOP:
		{
			calcBishopMoves(gameState, cells);
		}
		case KNIGHT:
		{
			calcKnightMoves(gameState, cells);
		}
		case ROOK:
		{
			calcRookMoves(gameState, cells);
		}
		case QUEEN:
		{
			calcQueenMoves(gameState, cells);
		}
		case KING:
		{
			calcKingMoves(gameState, cells);
		}
	}
}
