#include"chess.h"

void setPieceTexture(PIECE *piece)
{
	if(piece->pieceColor == WHITE_COLOR)
	{
		switch(piece->pieceType)
		{
			case KING:
			{
				piece->pieceptr = malloc(sizeof(KING_PIECE));
				if(piece->pieceptr != NULL)
				{
					piece->texture = LoadTexture(WHITE_KING_PATH);
					((KING_PIECE*)piece->pieceptr)->hasMoved = 0;
					((KING_PIECE*)piece->pieceptr)->ksCastle = 1;
					((KING_PIECE*)piece->pieceptr)->qsCastle = 1;
					((KING_PIECE*)piece->pieceptr)->check = 0;
					((KING_PIECE*)piece->pieceptr)->checkMate = 0;
				}
				break;
			}
			case QUEEN:
			{
				piece->texture = LoadTexture(WHITE_QUEEN_PATH);
				piece->pieceptr = NULL;
				break;
			}
			case ROOK:
			{
				piece->pieceptr = malloc(sizeof(ROOK_PIECE));
				if(piece->pieceptr != NULL)
				{
					piece->texture = LoadTexture(WHITE_ROOK_PATH);
					((ROOK_PIECE*)piece->pieceptr)->hasMoved = 0;
				}
				break;
			}
			case KNIGHT:
			{
				piece->texture = LoadTexture(WHITE_KNIGHT_PATH);
				piece->pieceptr = NULL;
				break;
			}
			case BISHOP:
			{
				piece->texture = LoadTexture(WHITE_BISHOP_PATH);
				piece->pieceptr = NULL;
				break;
			}
			case PAWN:
			{
				piece->pieceptr = malloc(sizeof(PAWN_PIECE));
				if(piece->pieceptr != NULL)
				{
					piece->texture = LoadTexture(WHITE_PAWN_PATH);
					((PAWN_PIECE*)piece->pieceptr)->hasMoved = 0;
					((PAWN_PIECE*)piece->pieceptr)->enPassant = 0;
				}
				break;
			}
		}
	}
	else
	{
		switch(piece->pieceType)
		{
			case KING:
			{
				piece->pieceptr = malloc(sizeof(KING_PIECE));
				if(piece->pieceptr != NULL)
				{
					piece->texture = LoadTexture(BLACK_KING_PATH);
					((KING_PIECE*)piece->pieceptr)->hasMoved = 0;
					((KING_PIECE*)piece->pieceptr)->ksCastle = 1;
					((KING_PIECE*)piece->pieceptr)->qsCastle = 1;
					((KING_PIECE*)piece->pieceptr)->check = 0;
					((KING_PIECE*)piece->pieceptr)->checkMate = 0;
				}
				break;
			}
			case QUEEN:
			{
				piece->texture = LoadTexture(BLACK_QUEEN_PATH);
				piece->pieceptr = NULL;
				break;
			}
			case ROOK:
			{
				piece->pieceptr = malloc(sizeof(ROOK_PIECE));
				if(piece->pieceptr != NULL)
				{
					piece->texture = LoadTexture(BLACK_ROOK_PATH);
					((ROOK_PIECE*)piece->pieceptr)->hasMoved = 0;
				}
				break;
			}
			case KNIGHT:
			{
				piece->texture = LoadTexture(BLACK_KNIGHT_PATH);
				piece->pieceptr = NULL;
				break;
			}
			case BISHOP:
			{
				piece->texture = LoadTexture(BLACK_BISHOP_PATH);
				piece->pieceptr = NULL;
				break;
			}
			case PAWN:
			{
				piece->pieceptr = malloc(sizeof(PAWN_PIECE));
				if(piece->pieceptr != NULL)
				{
					piece->texture = LoadTexture(BLACK_PAWN_PATH);
					((PAWN_PIECE*)piece->pieceptr)->hasMoved = 0;
					((PAWN_PIECE*)piece->pieceptr)->enPassant = 0;
				}
				break;
			}
		}
	}
}

void setPieceRectangle(PIECE *piece, float x, float y, PIECE_COLOR color, PIECE_TYPE type)
{
	piece->pieceRectangle = (Rectangle){x, y, CELL_SIZE, CELL_SIZE};
	piece->pieceColor = color;
	piece->pieceType = type;
}

void setPiecePos(PIECE *piece, float x, float y)
{
	piece->pieceRectangle.x = x;
	piece->pieceRectangle.y = y;
}

void endPieceTexture(PIECE *piece)
{
	UnloadTexture(piece->texture);

	if(piece->pieceptr != NULL)
	{
		free(piece->pieceptr);
		piece->pieceptr = NULL;	
	}
}