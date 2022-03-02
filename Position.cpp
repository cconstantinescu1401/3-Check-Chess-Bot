#include "Position.h"

Position::Position(char _column, int _line) : column(_column), line(_line) {}

std::string Position::toString() const {
    string s;
    s += column;
    s+= (char)(line + '0');
    return s;
}

char Position::getColumn() const {
    return column;
}

void Position::setColumn(char _column) {
    Position::column = _column;
}

int Position::getLine() const {
    return line;
}

void Position::setLine(int _line) {
    Position::line = _line;
}

Position::Position(Position *other_position) : Position(other_position->column, other_position->line){
}

Position::~Position() {

}
