#include <iostream>
#include "Game.h"

using namespace std;

Game::Game() : board(new Board()), movesManager(new MovesManager()), logFile("logger.txt") {

}

Game::~Game() {
    delete board;
    delete movesManager;
    logFile.close();
}

Board *Game::getBoard() const {
    return board;
}

void Game::setBoard(Board *_board) {
    Game::board = _board;
}

bool Game::getIsRunning() const {
    return isRunning;
}

void Game::setIsRunning(bool _isRunning) {
    Game::isRunning = _isRunning;
}

bool Game::getIsPaused() const {
    return isPaused;
}

void Game::setIsPaused(bool _isPaused) {
    Game::isPaused = _isPaused;
}

bool Game::getIsWhiteTurn() const {
    return isWhiteTurn;
}

void Game::setIsWhiteTurn(bool _isWhiteTurn) {
    Game::isWhiteTurn = _isWhiteTurn;
}

bool Game::isBotWhite() const {
    return botIsWhite;
}

void Game::setBotIsWhite(bool _botIsWhite) {
    Game::botIsWhite = _botIsWhite;
}

const ofstream &Game::getLogFile() const {
    return logFile;
}

void Game::handleMoveCommand(string commandString) {

    movesManager->updateFromOpponentMove(commandString, board, isWhiteTurn);

    //LOG
    logFile << board->printBoard() << endl;

    //IF IT IS THE BOT'S TURN
    if (!getIsPaused() && (getIsWhiteTurn() == isBotWhite())) {
        movesManager->makeMove(board, botIsWhite, isWhiteTurn, logFile);
    }
}

MovesManager *Game::getMovesManager() const {
    return movesManager;
}

void Game::setMovesManager(MovesManager *_movesManager) {
    Game::movesManager = _movesManager;
}

void Game::go() {
    logFile << board->printBoard();
    movesManager->makeMove(board, botIsWhite, isWhiteTurn, logFile);
}


