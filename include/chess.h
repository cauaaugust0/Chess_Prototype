#ifndef CHESS_H
#define CHESS_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"raylib.h"
#include"raymath.h"

#define WINDOW_W 800
#define WINDOW_H 600

#define CELL_SIZE 70

#define NAME_CELL_SIZE 4
#define MAX_CELLS 64
#define MAX_PIECES 32

static const char* WHITE_PAWN_PATH = "assets/w_pawn.png";
static const char* WHITE_BISHOP_PATH = "assets/w_bishop.png";
static const char* WHITE_KNIGHT_PATH = "assets/w_knight.png";
static const char* WHITE_ROOK_PATH = "assets/w_rook.png";
static const char* WHITE_QUEEN_PATH = "assets/w_queen.png";
static const char* WHITE_KING_PATH = "assets/w_king.png";
static const char* BLACK_PAWN_PATH = "assets/b_pawn.png";
static const char* BLACK_BISHOP_PATH = "assets/b_bishop.png";
static const char* BLACK_KNIGHT_PATH = "assets/b_knight.png";
static const char* BLACK_ROOK_PATH = "assets/b_rook.png";
static const char* BLACK_QUEEN_PATH = "assets/b_queen.png";
static const char* BLACK_KING_PATH = "assets/b_king.png";

static const Vector2 map[] = {
	{120,  20}, {190,  20}, {260, 20}, {330, 20}, {400, 20}, {470, 20}, {540, 20}, {610, 20},
	{120,  90}, {190,  90}, {260, 90}, {330, 90}, {400, 90}, {470, 90}, {540, 90}, {610, 90},
	{120, 160}, {190, 160}, {260, 160}, {330, 160}, {400, 160}, {470, 160}, {540, 160}, {610, 160},
	{120, 230}, {190, 230}, {260, 230}, {330, 230}, {400, 230}, {470, 230}, {540, 230}, {610, 230},
	{120, 300}, {190, 300}, {260, 300}, {330, 300}, {400, 300}, {470, 300}, {540, 300}, {610, 300},
	{120, 370}, {190, 370}, {260, 370}, {330, 370}, {400, 370}, {470, 370}, {540, 370}, {610, 370},
	{120, 440}, {190, 440}, {260, 440}, {330, 440}, {400, 440}, {470, 440}, {540, 440}, {610, 440},
	{120, 510}, {190, 510}, {260, 510}, {330, 510}, {400, 510}, {470, 510}, {540, 510}, {610, 510}
};

typedef enum
{
	KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
}PIECE_TYPE;

typedef enum
{
	WHITE_COLOR,
	BLACK_COLOR
}PIECE_COLOR;

typedef enum
{
	EMPTY, NOTEMPTY
}CELL_STATE;

// CELL //
typedef struct
{
	Rectangle cellRectangle;
	Color cellColor;
	
	CELL_STATE cellState;
	PIECE_COLOR occupiedBy;
}CELL;

void setCellRectangle(CELL *cell, float x, float y, Color color);
void setOccupiedBy(CELL *cell, PIECE_COLOR pieceColor);
void setCellState(CELL *cell, CELL_STATE state);

// PIECE //
typedef struct
{
	Texture2D texture;
	Rectangle pieceRectangle;
	PIECE_COLOR pieceColor;
	PIECE_TYPE pieceType;
	
	void *pieceptr;
}PIECE;

void setPieceTexture(PIECE *piece);
void setPieceRectangle(PIECE *piece, float x, float y, PIECE_COLOR color, PIECE_TYPE type);
void setPiecePos(PIECE *piece, float x, float y);
void endPieceTexture(PIECE *piece);

// src_pieces //
typedef struct
{
	int hasMoved;
	int enPassant;
}PAWN_PIECE;

typedef struct
{
	int hasMoved;
}ROOK_PIECE;

typedef struct
{
	int hasMoved;
	int ksCastle;
	int qsCastle;
	int check;
	int checkMate;
}KING_PIECE;

// src_logic //
typedef struct
{
	int selectionState;
	PIECE *selectedPiece;
	int possibleMoves[64];
	PIECE_COLOR turn;
}GAME_STATE;

// setup //
void setupCells(CELL *cells);
void setupPieces(PIECE *pieces);
void setupGameState(GAME_STATE *gameState);
// draw //
void draw(CELL *cells, PIECE *pieces);
// upddate //
void update(GAME_STATE *gameState, CELL *cells, PIECE *pieces);

void getPossibleMoves(GAME_STATE *gameState, CELL *cells);

//utils
int getIndex(Vector2 pos);
int getCol(int index);
int getRow(int index);

// piece_rules //
void calcPawnMoves(GAME_STATE *gameState, CELL *cells);
void calcBishopMoves(GAME_STATE *gameState, CELL *cells);
void calcKnightMoves(GAME_STATE *gameState, CELL *cells);
void calcRookMoves(GAME_STATE *gameState, CELL *cells);
void calcQueenMoves(GAME_STATE *gameState, CELL *cells);
void calcKingMoves(GAME_STATE *gameState, CELL *cells);

int isCellAttacked(int cellIndex, PIECE_COLOR byColor, CELL *cells, PIECE *pieces);
int findKingIndex(PIECE_COLOR color, PIECE *pieces);
int isKingInCheck(PIECE_COLOR color, CELL *cells, PIECE *pieces);
int isCheckmate(PIECE_COLOR color, CELL *cells, PIECE *pieces);

#endif