#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <cstring>
#include <bits/stdc++.h>
#include "MovesManager.h"

void MovesManager::makeMove(Board *board, bool &botIsWhite, bool &isWhiteTurn,
                            ostream &logFile) {
    vector<Piece *> currentPieces;

    if (board->getKing(botIsWhite)->isInCheck(board->getBoardMatrix())) {
        logFile << "KING IS IN CHECK!!!!!!!!" << endl;
    }

    //TODO MINIMAX AND DELETE TREE CA SA MAI AVEM RAM PE PC
    cout << "Before minimax" << endl;
    Move *bestMove = miniMaxroot(board, 3, isWhiteTurn, botIsWhite);
    logFile << board->printBoard() << endl;
    if (!bestMove) {
        logFile << "Nu mai sunt mutari" << endl;
        cout << "resign" << endl;
        return;
    }

    Position *oldPos = bestMove->getOldPos();
    Position *newPos = bestMove->getNewPos();

    cout << "move " << oldPos->toString() << newPos->toString();
    int promoteCheck = board->updateBoard(oldPos, newPos, 0);

    switch (promoteCheck) {
        case 0: {
            cout << "q";
            break;
        }
        case 1: {
            cout << "b";
            break;
        }
        case 2: {
            cout << "n";
            break;
        }
        case 3: {
            cout << "r";
            break;
        }
    }

    cout << endl;

    

    isWhiteTurn = !isWhiteTurn;

}

void MovesManager::updateFromOpponentMove(string &commandString, Board *board,
                                          bool &isWhiteTurn) {
    stringstream strOldPosLine;
    strOldPosLine << commandString[1];
    int oldPosLine;
    strOldPosLine >> oldPosLine;

    stringstream strNewPosLine;
    strNewPosLine << commandString[3];
    int newPosLine;
    strNewPosLine >> newPosLine;

    char updatePromoteRead = 'z';
    if (commandString.length() == 5) updatePromoteRead = commandString[4];

    int updatePromote = -1;

    switch (updatePromoteRead) {
        case 'q' : {
            updatePromote = 0;
            break;
        }
        case 'b' : {
            updatePromote = 1;
            break;
        }
        case 'n' : {
            updatePromote = 2;
            break;
        }
        case 'r' : {
            updatePromote = 3;
            break;
        }
    }

    board->updateBoard(new Position(commandString[0], oldPosLine),
                       new Position(commandString[2], newPosLine),
                       updatePromote);

    isWhiteTurn = !isWhiteTurn;
}

void MovesManager::removeIllegalMoves(Board *board,
                                      vector<Position *> &possibleMoves,
                                      Piece *toBeMovedPiece) {
    King *allyKing = board->getKing(toBeMovedPiece->getIsWhite());
    Position *currentPos = toBeMovedPiece->getCurrentPos();

    for (size_t i = 0; i < possibleMoves.size(); i++) {
        vector<vector<Piece *>> newBoardMatrix(board->getBoardMatrix());

        Position *oldPosition =
                new Position(currentPos->getColumn(), currentPos->getLine());
        Position *newPosition = possibleMoves[i];

        int oldLine = oldPosition->getLine() - 1;
        int oldColumn = oldPosition->getColumn() - 'a';
        int newLine = newPosition->getLine() - 1;
        int newColumn = newPosition->getColumn() - 'a';

        //check if it tries to take the enemy king
        if (newBoardMatrix[newLine][newColumn]->getType() == "KING") {
            possibleMoves.erase(possibleMoves.begin() + i);
            i--;
            continue;
        }

        //check if by doing the move the ally king will be in check

        //update piece postion
        toBeMovedPiece->setCurrentPos(newPosition);

        //update board position
        newBoardMatrix[oldLine][oldColumn] = new Empty(oldPosition);
        newBoardMatrix[newLine][newColumn] = toBeMovedPiece;

        //check if king is in check after doing the move
        if (allyKing->isInCheck(newBoardMatrix)) {
            possibleMoves.erase(possibleMoves.begin() + i);
            i--;
        }

        //revert piece postion
        toBeMovedPiece->setCurrentPos(oldPosition);
    }
}

double MovesManager::evaluate(Board *board, bool isBotWhite) {
    double white_score = (double)0;
    double black_score = (double)0;
    vector<Piece *> white_pieces = board->getWhitePiecesList();
    vector<Piece *> black_pieces = board->getBlackPiecesList();

    if (isCheckMate(board, isBotWhite))
        return MIN_MAX;
    if (isCheckMate(board, !isBotWhite))
        return -MIN_MAX;
   
   for (auto w : white_pieces) {
        white_score += w->getPositionScore(true);
    }

    for (auto b : black_pieces) {
        black_score += b->getPositionScore(false);
    }
    double eval = isBotWhite ? white_score - black_score : black_score - white_score;
    giveCheckBonus(eval, board, isBotWhite);
    return eval;
}

double MovesManager::miniMax(Board *board, int depth, bool isWhiteTurn,
                             bool isBotWhite, double alpha, double beta) {
    if (depth == 0) {
        return evaluate(board, isBotWhite);
    }

    vector<Piece *> piecesList = board->getPiecesList(isWhiteTurn);
    vector<Move *> all_moves;

    double maxeval = MIN_MAX;
    double mineval = -MIN_MAX;
    Board *copy_board;
    double eval;

    for (auto piece : piecesList) {
        vector<Position *> newPositions =
                piece->getAvailableMoves(board->getBoardMatrix());
        removeIllegalMoves(board, newPositions, piece);
        for (auto newPos : newPositions) {
            all_moves.push_back(new Move(new Position(piece->getCurrentPos()),
                                         new Position(newPos)));
        }
    }

    // sort moves
     multimap<double, Move *, greater<>> eval_moves;

     Move* copy_move;
     for (auto move : all_moves) {
         //TODO FREE SOME MORE MEMORY
         copy_board = new Board(board);
         copy_move = new Move(move);
         copy_board->updateBoard(copy_move->getOldPos(), copy_move->getNewPos(), 0);
         eval = evaluate(copy_board, isBotWhite);
         delete(copy_board);
         eval_moves.insert(make_pair(eval, move));
     }
     all_moves.clear();
     for (auto eval_move : eval_moves) {
         all_moves.push_back(eval_move.second);
     }
     eval_moves.clear();

    if (isWhiteTurn == isBotWhite) {
        //TODO FINISH WHEN KING IS IN CHECKMATE ETC
        if (all_moves.empty()) {
            return MIN_MAX;
        }
        for (auto move : all_moves) {
            copy_board = new Board(board);
            copy_board->updateBoard(move->getOldPos(), move->getNewPos(), 0);

            eval = miniMax(copy_board, depth - 1, !isWhiteTurn, isBotWhite,
                           alpha, beta);
            giveCheckBonus(eval, copy_board, isBotWhite);
            if (eval > maxeval)
                maxeval = eval;

            delete (copy_board);

            if (alpha <= eval)
                alpha = eval;
            if (beta <= alpha)
                break;
        }
        return maxeval;
    } else {
        if (all_moves.empty()) {
            return -MIN_MAX;
        }
        for (auto move : all_moves) {
            copy_board = new Board(board);
            copy_board->updateBoard(move->getOldPos(), move->getNewPos(), 0);

            eval = miniMax(copy_board, depth - 1, !isWhiteTurn, isBotWhite,
                           alpha, beta);
            giveCheckBonus(eval, copy_board, isBotWhite);
            if (eval < mineval)
                mineval = eval;
            delete (copy_board);

            if (beta >= eval)
                beta = eval;
            if (beta <= alpha)
                break;
        }
        return mineval;
    }
}

Move *MovesManager::miniMaxroot(Board *board, int depth, bool isWhiteTurn,
                                bool isBotWhite) {
    Move *bestmove = nullptr;
    double maxeval = MIN_MAX;
    vector<Piece *> piecesList = board->getPiecesList(isBotWhite);
    vector<Move *> all_moves;

    for (auto piece : piecesList) {
        vector<Position *> newPositions =
                piece->getAvailableMoves(board->getBoardMatrix());
        removeIllegalMoves(board, newPositions, piece);
        for (auto newPos : newPositions) {
            all_moves.push_back(new Move(new Position(piece->getCurrentPos()), new Position(newPos)));
        }
    }

    double eval;
    for (auto move : all_moves) {
        Board *copy_board = new Board(board);
        copy_board->updateBoard(move->getOldPos(), move->getNewPos(), 0);

        eval = miniMax(copy_board, depth - 1, !isWhiteTurn, isBotWhite,
                       MIN_MAX, -MIN_MAX);
        giveCheckBonus(eval, copy_board, isBotWhite);
        if (eval > maxeval) {
            maxeval = eval;
            bestmove = move;
        }
    }
    return bestmove;
}

bool MovesManager::isCheckMate(Board *board, bool kingIsWhite) {
    vector<Piece *> piecesList = kingIsWhite ? board->getWhitePiecesList() : 
                                               board->getBlackPiecesList();
    for (auto piece : piecesList) {
        vector<Position *> newPositions =
                piece->getAvailableMoves(board->getBoardMatrix());
        removeIllegalMoves(board, newPositions, piece);
        if (!newPositions.empty())
            return false;
    }
    return true;
}

void MovesManager::giveCheckBonus(double &eval, Board *copy_board, bool isBotWhite) {
    King *black_king = copy_board->getKing(false);
    King *white_king = copy_board->getKing(true);
    double bonus_white_score = 0.0, bonus_black_score = 0.0;
    if (black_king->isInCheck(copy_board->getBoardMatrix())) {
        if (black_king->times_in_check == 1)
            bonus_white_score += 444.0;
        if (black_king->times_in_check == 2)
            bonus_white_score += 2425.0;
        if (black_king->times_in_check >= 3) {
            bonus_white_score = 999999;
            bonus_black_score = 0.0;
        }
    }
    if (white_king->isInCheck(copy_board->getBoardMatrix())) {
        if (white_king->times_in_check == 1)
            bonus_black_score += 444.0;
        if (white_king->times_in_check == 2)
            bonus_black_score += 2425.0;
        if (white_king->times_in_check >= 3) {
            bonus_black_score = 999999;
            bonus_white_score = 0.0;
        }
    }
    double bonus_score;
    if (isBotWhite)
        bonus_score = bonus_white_score - bonus_black_score;
    else
        bonus_score = bonus_black_score - bonus_white_score;
    if (bonus_score == MIN_MAX || bonus_score == -MIN_MAX)
        eval = bonus_score;
    else
        eval += bonus_score;
}
