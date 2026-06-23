#include"chess.h"

void draw(CELL *cells, PIECE *pieces)
{
	for(int i = 0; i < MAX_CELLS; i++)
	{
		DrawRectangleRec(cells[i].cellRectangle, cells[i].cellColor);
	}
	
	for(int i = 0; i < MAX_PIECES; i++)
	{
		DrawRectangleRec(pieces[i].pieceRectangle, BLANK);
		DrawTexture(pieces[i].texture, (int)pieces[i].pieceRectangle.x, (int)pieces[i].pieceRectangle.y, WHITE);
	}
}