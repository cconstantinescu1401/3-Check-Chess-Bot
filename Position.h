#ifndef PA_CHESS_GAME_POSITION
#define PA_CHESS_GAME_POSITION

#include <string>

using namespace std;

class Position {
private:
    char column;
    int line;

public:
    Position(Position* other_position);

    Position(char column, int line);

    virtual ~Position();

    string toString() const;

    char getColumn() const;
    void setColumn(char column);

    int getLine() const;
    void setLine(int line);

};

#endif