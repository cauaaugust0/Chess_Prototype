#include "chess.h"

// ---------------- AUXILIARES ----------------
int getIndex(Vector2 pos) {
    for(int i = 0; i < 64; i++) {
        if(map[i].x == pos.x && map[i].y == pos.y)
            return i;
    }
    return -1;
}

int getCol(int index) {
    return index % 8;
}

int getRow(int index) {
    return index / 8;
}

// ---------------- PEAO ----------------
void calcPawnMoves(GAME_STATE *gameState, CELL *cells) {
    int moves[8] = {-7, +7, -8, +8, -16, +16, -9, +9};
    int index = getIndex((Vector2){gameState->selectedPiece->pieceRectangle.x,
                                   gameState->selectedPiece->pieceRectangle.y});
    int col = getCol(index);
    int countMoves = 0;

    if(gameState->selectedPiece->pieceColor == WHITE_COLOR) {
        for(int i = 0; i < 8; i++) {
            int target = index + moves[i];
            if(target < 0 || target >= 64) continue;
            if(moves[i] == +8 || moves[i] == +9 || moves[i] == +16 || moves[i] == +7) continue;
            if((moves[i] == -9 && col == 0) || (moves[i] == -7 && col == 7)) continue;

            if(cells[target].cellState == EMPTY || 
               cells[target].occupiedBy != gameState->selectedPiece->pieceColor) {
                gameState->possibleMoves[countMoves++] = target;
            }
        }
    } else {
        for(int i = 0; i < 8; i++) {
            int target = index + moves[i];
            if(target < 0 || target >= 64) continue;
            if(moves[i] == -8 || moves[i] == -9 || moves[i] == -16 || moves[i] == -7) continue;
            if((moves[i] == +9 && col == 7) || (moves[i] == +7 && col == 0)) continue;

            if(cells[target].cellState == EMPTY || 
               cells[target].occupiedBy != gameState->selectedPiece->pieceColor) {
                gameState->possibleMoves[countMoves++] = target;
            }
        }
    }
}

// ---------------- BISPO ----------------
void calcBishopMoves(GAME_STATE *gameState, CELL *cells) {
    int index = getIndex((Vector2){gameState->selectedPiece->pieceRectangle.x,
                                   gameState->selectedPiece->pieceRectangle.y});
    int countMoves = 0;
    int directions[4] = {-9, -7, +7, +9};

    for(int d = 0; d < 4; d++) {
        int target = index;
        while(1) {
            target += directions[d];
            if(target < 0 || target >= 64) break;
            int colOrig = getCol(target - directions[d]);
            int colDest = getCol(target);
            if(abs(colDest - colOrig) != 1) break;

            if(cells[target].cellState == EMPTY || 
               cells[target].occupiedBy != gameState->selectedPiece->pieceColor)
                gameState->possibleMoves[countMoves++] = target;

            if(cells[target].cellState != EMPTY) break;
        }
    }
}

// ---------------- CAVALO ----------------
void calcKnightMoves(GAME_STATE *gameState, CELL *cells) {
    int index = getIndex((Vector2){gameState->selectedPiece->pieceRectangle.x,
                                   gameState->selectedPiece->pieceRectangle.y});
    int countMoves = 0;
    int moves[8] = {-17, -15, -10, -6, +6, +10, +15, +17};

    for(int i = 0; i < 8; i++) {
        int target = index + moves[i];
        if(target < 0 || target >= 64) continue;
        int colOrig = getCol(index);
        int colDest = getCol(target);
        if(abs(colDest - colOrig) > 2) continue;

        if(cells[target].cellState == EMPTY || 
           cells[target].occupiedBy != gameState->selectedPiece->pieceColor)
            gameState->possibleMoves[countMoves++] = target;
    }
}

// ---------------- TORRE ----------------
void calcRookMoves(GAME_STATE *gameState, CELL *cells) {
    int index = getIndex((Vector2){gameState->selectedPiece->pieceRectangle.x,
                                   gameState->selectedPiece->pieceRectangle.y});
    int countMoves = 0;
    int directions[4] = {-8, +8, -1, +1};

    for(int d = 0; d < 4; d++) {
        int target = index;
        while(1) {
            target += directions[d];
            if(target < 0 || target >= 64) break;
            if((directions[d] == -1 || directions[d] == +1) &&
               getRow(target) != getRow(target - directions[d])) break;

            if(cells[target].cellState == EMPTY || 
               cells[target].occupiedBy != gameState->selectedPiece->pieceColor)
                gameState->possibleMoves[countMoves++] = target;

            if(cells[target].cellState != EMPTY) break;
        }
    }
}

// ---------------- DAMA ----------------
void calcQueenMoves(GAME_STATE *gameState, CELL *cells) {
    calcRookMoves(gameState, cells);
    calcBishopMoves(gameState, cells);
}

// ---------------- REI ----------------
void calcKingMoves(GAME_STATE *gameState, CELL *cells) {
    int index = getIndex((Vector2){gameState->selectedPiece->pieceRectangle.x,
                                   gameState->selectedPiece->pieceRectangle.y});
    int countMoves = 0;
    int moves[8] = {-9, -8, -7, -1, +1, +7, +8, +9};

    for(int i = 0; i < 8; i++) {
        int target = index + moves[i];
        if(target < 0 || target >= 64) continue;
        int colOrig = getCol(index);
        int colDest = getCol(target);
        if(abs(colDest - colOrig) > 1) continue;

        if(cells[target].cellState == EMPTY || 
           cells[target].occupiedBy != gameState->selectedPiece->pieceColor)
            gameState->possibleMoves[countMoves++] = target;
    }
}

// ---------------- VERIFICAÇÕES ----------------

// verifica se uma célula está sob ataque do inimigo
int isCellAttacked(int cellIndex, PIECE_COLOR byColor, CELL *cells, PIECE *pieces) {
    for(int i = 0; i < MAX_PIECES; i++) {
        if(pieces[i].pieceColor != byColor) continue;
        GAME_STATE tmp = {0};
        tmp.selectedPiece = &pieces[i];
        getPossibleMoves(&tmp, cells);
        for(int j = 0; j < 64; j++) {
            if(tmp.possibleMoves[j] == cellIndex)
                return 1;
        }
    }
    return 0;
}

// encontra o rei de uma cor
int findKingIndex(PIECE_COLOR color, PIECE *pieces) {
    for(int i = 0; i < MAX_PIECES; i++) {
        if(pieces[i].pieceType == KING && pieces[i].pieceColor == color) {
            return getIndex((Vector2){pieces[i].pieceRectangle.x, pieces[i].pieceRectangle.y});
        }
    }
    return -1;
}

// verifica se o rei está em cheque
int isKingInCheck(PIECE_COLOR color, CELL *cells, PIECE *pieces) {
    int kingIndex = findKingIndex(color, pieces);
    PIECE_COLOR opponent = (color == WHITE_COLOR) ? BLACK_COLOR : WHITE_COLOR;
    return isCellAttacked(kingIndex, opponent, cells, pieces);
}

// verifica se é cheque-mate
int isCheckmate(PIECE_COLOR color, CELL *cells, PIECE *pieces) {
    if(!isKingInCheck(color, cells, pieces))
        return 0;

    for(int i = 0; i < MAX_PIECES; i++) {
        if(pieces[i].pieceColor != color) continue;

        GAME_STATE tmp = {0};
        tmp.selectedPiece = &pieces[i];
        getPossibleMoves(&tmp, cells);

        for(int j = 0; j < 64; j++) {
            int move = tmp.possibleMoves[j];
            if(move == 0) continue;

            Vector2 oldPos = (Vector2){pieces[i].pieceRectangle.x, pieces[i].pieceRectangle.y};
            pieces[i].pieceRectangle.x = map[move].x;
            pieces[i].pieceRectangle.y = map[move].y;

            int stillCheck = isKingInCheck(color, cells, pieces);

            pieces[i].pieceRectangle.x = oldPos.x;
            pieces[i].pieceRectangle.y = oldPos.y;

            if(!stillCheck) return 0;
        }
    }
    return 1;
}