#include <iostream>
#include <bitset>
#include <chrono>
#include "board.hpp"
#include "ai.hpp"

int main() {
    Board board;
    int choice;
    std::cout << "Enter 1 if you want to play first, 2 if you want to go second: ";
    std::cin >> choice;
    if (choice == 1) {
        while (board.getCounter() < 42) {
            int col;
            std::cout << "Enter colum number (0-6): ";
            std::cin >> col;
            while ((col > 6) | (col < 0)) {
                std::cout << "Invalid choice!\nPlease enter colum number (0-6): ";
                std::cin >> col;
            }
            board.makeMove(col);
            board.printBoard();
            if (board.isWin(board.getBitboard()[0])) {
                std::cout << "You win!" << std::endl;
                break;
            }
            std::vector<int> moves = board.listMoves();
            int ai_move = minimax(board, (42 - board.getCounter()), -100, 100, false);
            board.makeMove(ai_move);
            board.printBoard();
            if (board.isWin(board.getBitboard()[1])) {
                std::cout << "You lose!" << std::endl;
                break;
            }
        }
        if (board.getCounter() > 41){
            std::cout << "It's a draw!" << std::endl;
        }
    } else if (choice == 2) {
        while (board.getCounter() < 42) {
            int bestScore = -1000;
            int score = -100;
            int ai_move = -1;
            auto start = std::chrono::high_resolution_clock::now();
            for (int col : board.listMoves()) {
                board.makeMove(col);
                score = minimax(board, 13, -100000, 100000, false);
                board.undoMove();
                std::cout << col << ":";
                std::cout << score << std::endl;
                if (score > bestScore){
                    bestScore = score;
                    ai_move = col;
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "The code took " << diff.count() << " nanoseconds to execute." << std::endl;
            board.makeMove(ai_move);
            board.printBoard();
            if (board.isWin(board.getBitboard()[0])) {
                std::cout << "You lose!" << std::endl;
                std::cout << std::bitset<49>(board.getBitboard()[0]) << std::endl;
                break;
            }
            int col;
            std::cout << "Enter colum number (0-6): ";
            std::cin >> col;
            while ((col > 6) | (col < 0)) {
                std::cout << "Invalid choice!\nPlease enter colum number (0-6): ";
                std::cin >> col;
            }
            board.makeMove(col);
            board.printBoard();
            if (board.isWin(board.getBitboard()[1])) {
                std::cout << "You win!" << std::endl;
                std::cout << std::bitset<49>(board.getBitboard()[1]) << std::endl;
                break;
            }
        }
        if (board.getCounter() > 41){
            std::cout << "It's a draw!" << std::endl;
        }
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }
    return 0;
}