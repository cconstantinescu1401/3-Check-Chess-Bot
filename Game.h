#ifndef PROIECT_GAME_H
#define PROIECT_GAME_H

#include <fstream>
#include "Board.h"
#include "MovesManager.h"

class Game {
private:
    Board* board = nullptr;
    MovesManager* movesManager = nullptr;

    bool isRunning = false;
    bool isPaused = false;
    bool isWhiteTurn = true;
    bool botIsWhite = false;

    ofstream logFile;

public:
    Game();
    virtual ~Game();

    Board *getBoard() const;
    void setBoard(Board *board);

    MovesManager *getMovesManager() const;
    void setMovesManager(MovesManager *movesManager);

    bool getIsRunning() const;
    void setIsRunning(bool isRunning);

    bool getIsPaused() const;
    void setIsPaused(bool isPaused);

    bool getIsWhiteTurn() const;
    void setIsWhiteTurn(bool isWhiteTurn);

    bool isBotWhite() const;
    void setBotIsWhite(bool _botIsWhite);

    const ofstream &getLogFile() const;

    void handleMoveCommand(string commandString);

    void go();
};

#endif //PROIECT_GAME_H
