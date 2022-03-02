CC = g++
FLAGS = -Wall -Wextra -g 
OP_FLAGS = -O3
EXEC = main

all: build

MAIN = main.cpp
MAIN_O = main.o
$(MAIN_O): $(MAIN)
	$(CC) -c $(MAIN) $(OP_FLAGS)

BOARD = Board.cpp
BOARD_O = Board.o
$(BOARD_O): $(BOARD)
	$(CC) -c $(BOARD) $(OP_FLAGS)

GAME = Game.cpp
GAME_O = Game.o
$(GAME_O): $(GAME)
	$(CC) -c $(GAME) $(OP_FLAGS)

MOVE = Move.cpp
MOVE_O = Move.o
$(MOVE_O): $(MOVE)
	$(CC) -c $(MOVE) $(OP_FLAGS)

MOVESMANAGER_O = MovesManager.o
MOVESMANAGER = MovesManager.cpp
$(MOVESMANAGER_O): $(MOVESMANAGER)
	$(CC) -c $(MOVESMANAGER) $(OP_FLAGS)

POSITION = Position.cpp
POSITION_O = Position.o
$(POSITION_O): $(POSITION)
	$(CC) -c $(POSITION) $(OP_FLAGS)


# COMMAND DESIGN PATTERN
COMMAND_FILE = command_classes

COMMAND = ./$(COMMAND_FILE)/Command.cpp
COMMAND_O = Command.o
$(COMMAND_O): $(COMMAND)
	$(CC) -c $(COMMAND) $(OP_FLAGS)

PARSER = ./$(COMMAND_FILE)/CommandParser.cpp
PARSER_O = CommandParser.o
$(PARSER_O): $(PARSER)
	$(CC) -c $(PARSER) $(OP_FLAGS)

FEATURE = ./$(COMMAND_FILE)/FeatureCommand.cpp
FEATURE_O = FeatureCommand.o
$(FEATURE_O): $(FEATURE)
	$(CC) -c $(FEATURE) $(OP_FLAGS)

FORCE = ./$(COMMAND_FILE)/ForceCommand.cpp
FORCE_O = ForceCommand.o
$(FORCE_O): $(FORCE)
	$(CC) -c $(FORCE) $(OP_FLAGS)

GO = ./$(COMMAND_FILE)/GoCommand.cpp
GO_O = GoCommand.o
$(GO_O): $(GO)
	$(CC) -c $(GO) $(OP_FLAGS)

NEW = ./$(COMMAND_FILE)/NewCommand.cpp
NEW_O = NewCommand.o
$(NEW_O): $(NEW)
	$(CC) -c $(NEW) $(OP_FLAGS)

QUIT = ./$(COMMAND_FILE)/QuitCommand.cpp
QUIT_O = QuitCommand.o
$(QUIT_O): $(QUIT)
	$(CC) -c $(QUIT) $(OP_FLAGS)

XBOARD = ./$(COMMAND_FILE)/XboardCommand.cpp
XBOARD_O = XboardCommand.o
$(XBOARD_O): $(XBOARD)
	$(CC) -c $(XBOARD) $(OP_FLAGS)

# PIECES CLASSES
PIECES_CLASSES = pieces_classes

BISHOP = ./$(PIECES_CLASSES)/Bishop.cpp
BISHOP_O = Bishop.o
$(BISHOP_O): $(BISHOP)
	$(CC) -c $(BISHOP) $(OP_FLAGS)

EMPTY = ./$(PIECES_CLASSES)/Empty.cpp
EMPTY_O = Empty.o
$(EMPTY_O): $(EMPTY)
	$(CC) -c $(EMPTY) $(OP_FLAGS)

KING = ./$(PIECES_CLASSES)/King.cpp
KING_O = King.o
$(KING_O): $(KING)
	$(CC) -c $(KING) $(OP_FLAGS)

KNIGHT = ./$(PIECES_CLASSES)/Knight.cpp
KNIGHT_O = Knight.o
$(KNIGHT_O): $(KNIGHT)
	$(CC) -c $(KNIGHT) $(OP_FLAGS)


PAWN = ./$(PIECES_CLASSES)/Pawn.cpp
PAWN_O = Pawn.o
$(PAWN_O): $(PAWN)
	$(CC) -c $(PAWN) $(OP_FLAGS)

PIECE = ./$(PIECES_CLASSES)/Piece.cpp
PIECE_O = Piece.o
$(PIECE_O): $(PIECE)
	$(CC) -c $(PIECE) $(OP_FLAGS)

QUEEN = ./$(PIECES_CLASSES)/Queen.cpp
QUEEN_O = Queen.o
$(QUEEN_O): $(QUEEN)
	$(CC) -c $(QUEEN) $(OP_FLAGS)

ROOK = ./$(PIECES_CLASSES)/Rook.cpp
ROOK_O = Rook.o
$(ROOK_O): $(ROOK)
	$(CC) -c $(ROOK) $(OP_FLAGS)

build: $(MAIN_O) $(MOVE_O) $(MOVESMANAGER_O) $(GAME_O) $(BOARD_O) $(POSITION_O) $(COMMAND_O) $(PARSER_O) $(FEATURE_O) $(FORCE_O) $(GO_O) $(NEW_O) $(QUIT_O) $(XBOARD_O) $(BISHOP_O) $(EMPTY_O) $(KING_O) $(KNIGHT_O) $(PAWN_O) $(PIECE_O) $(QUEEN_O) $(ROOK_O)
	$(CC) \
	$(COMMAND_O) \
	$(PARSER_O) \
	$(FEATURE_O) \
	$(FORCE_O) \
	$(GO_O) \
	$(NEW_O) \
	$(QUIT_O) \
	$(XBOARD_O) \
	$(BISHOP_O) \
	$(EMPTY_O) \
	$(KING_O) \
	$(KNIGHT_O) \
	$(PAWN_O) \
	$(PIECE_O) \
	$(QUEEN_O) \
	$(ROOK_O) \
	$(BOARD_O) \
	$(POSITION_O) \
	$(GAME_O) \
	$(MOVE_O) \
	$(MOVESMANAGER_O) \
	$(MAIN_O) \
	-o $(EXEC) $(OP_FLAGS)

run:
	./$(EXEC)

clean:
	rm -rf $(EXEC)
	rm -r *.o


	