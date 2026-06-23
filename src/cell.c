#include"chess.h"

void setCellRectangle(CELL *cell, float x, float y, Color color)
{
	cell->cellRectangle = (Rectangle){x, y, CELL_SIZE, CELL_SIZE};
	cell->cellColor = color;
}

void setOccupiedBy(CELL *cell, PIECE_COLOR pieceColor)
{
	cell->occupiedBy = pieceColor;
}

void setCellState(CELL *cell, CELL_STATE state)
{
	cell->cellState = state;
}
