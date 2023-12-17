#include "ai.hpp"
#include "board.hpp"

#include <iostream>


int evaluate(Board board) {
    if (board.isWin(board.getBitboard()[0])) {
        return 10;
    } else if (board.isWin(board.getBitboard()[1])) {
        return -10;
    }
    return 0;
}

int minimax(Board board, int depth, int alpha, int beta, bool isMax) {
    if (depth == 0 || board.isWin(board.getBitboard()[0]) || board.isWin(board.getBitboard()[1])) {
        return evaluate(board);
    }
    if (isMax){
        for (int col : board.listMoves()) {
            board.makeMove(col);
            alpha = std::max(alpha,minimax(board, depth - 1, alpha, beta, !isMax));
            board.undoMove();
            if (beta <= alpha){
                return alpha;
            }
        }
        return alpha;
    } 
    for (int col : board.listMoves()) {
        board.makeMove(col);
        beta = std::min(beta,minimax(board, depth - 1, alpha, beta, !isMax));
        board.undoMove();
        if (beta <= alpha){
            return beta;
        }
    }
    return beta;
}
