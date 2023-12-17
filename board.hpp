#pragma once
#include <array>
#include <vector>

class Board {
    private:
        int counter = 0;
        std::array<unsigned long long, 2> bitboard = {0, 0};
        std::array<int, 42> moves = {0};
        std::array<int, 7> height = {0, 7, 14, 21, 28, 35, 42};
        std::array<int, 7> order = {3,2,4,1,5,0,6};
    public:
        void makeMove(int col);
        void undoMove();
        bool isWin(long long bitboard);
        std::vector<int> listMoves() const;

        void printBoard();

        int getCounter() const {return counter;};
        std::array<unsigned long long, 2> getBitboard() const {return bitboard;};
        std::array<int, 42> getMoves() const {return moves;};
        std::array<int, 7> getHeight() const {return height;};
};