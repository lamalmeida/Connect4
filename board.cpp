#include <iostream>
#include "board.hpp"

void Board::makeMove(int col) {
    unsigned long long move = 1ULL << height[col]++; 
    bitboard[counter & 1] ^= move;  
    moves[counter++] = col;  
}

void Board::undoMove() {
    int col = moves[--counter];     
    unsigned long long move = 1ULL << --height[col]; 
    bitboard[counter & 1] ^= move;  
}

bool Board::isWin(long long bitboard) {
    int directions[] = {1, 7, 6, 8};
    unsigned long long bb;
    for(int direction : directions) {
        bb = bitboard & (bitboard >> direction);
        if ((bb & (bb >> (2 * direction))) != 0) return true;
    }
    return false;
}

std::vector<int> Board::listMoves() const {
    std::vector<int> moves;
    unsigned long long TOP = 0b1000000100000010000001000000100000010000001000000L;
    for(int col : order) {
        if ((TOP & (1ULL << height[col])) == 0) moves.push_back(col);
    }
    return moves;
}

void Board::printBoard() {
    for (int row = 5; row >= 0; row--) {
        for (int col = 0; col <= 6; col++) {
            if (height[col] % 7 > row) {
                if (bitboard[0] & (1ULL << (row + col * 7))) {
                    std::cout << "X ";
                } else if (bitboard[1] & (1ULL << (row + col * 7))) {
                    std::cout << "O ";
                } else {
                    std::cout << ". ";
                }
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}