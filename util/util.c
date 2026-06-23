#include"chess.h"

int getColValue(int index)
{
	int col = index % 8;
	return col;
}

int getIndex(Vector2 position)
{
	for(int i = 0; i < 64; i++)
	{
		if(Vector2Equals(map[i], position))
		{
			return i;
			break;
		}
	}
	return -1;
}