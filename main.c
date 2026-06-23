#include<stdio.h>
#include<stdlib.h>
#include"raylib.h"
#include"chess.h"

int main()
{
	InitWindow(WINDOW_W, WINDOW_H, "chess");
	SetTargetFPS(60);
	
	CELL cells[MAX_CELLS];
	PIECE pieces[MAX_PIECES];
	GAME_STATE gameState = {0};
	
	setupGameState(&gameState);
	setupCells(cells);
	setupPieces(pieces);
	
	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		draw(cells, pieces);
		
		update(&gameState, cells, pieces);
		
		EndDrawing();
	}
	
	
	for(int i = 0; i < MAX_PIECES; i++)
	{
		printf("\nDescarregando texturas [%d]\n", i);
		endPieceTexture(&pieces[i]);
	}
	
	CloseWindow();
	
	return 0;
}
