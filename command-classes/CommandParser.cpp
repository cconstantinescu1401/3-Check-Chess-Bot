#include "CommandParser.h"
#include <sstream>

CommandParser::CommandParser(){
    initCommands();
}

CommandParser::~CommandParser() {
}

void CommandParser::initCommands() {
    commandsMap.insert(pair<string, Command*>("xboard", new XboardCommand()));
    commandsMap.insert(pair<string, Command*>("feature", new FeatureCommand()));
    commandsMap.insert(pair<string, Command*>("new", new NewCommand()));
    commandsMap.insert(pair<string, Command*>("force", new ForceCommand()));
    commandsMap.insert(pair<string, Command*>("go", new GoCommand()));
    commandsMap.insert(pair<string, Command*>("quit", new QuitCommand()));

}

void CommandParser::parseCommand(Game* game, const string& commandString, ostream& logFile) {

    logFile << commandString << endl;

    //NORMAL COMMANDS
    if (commandsMap.count(commandString)) {
        commandsMap[commandString]->execute(game, logFile);
    }

    //PROTOVER COMMAND
    else {
        size_t found = commandString.find("protover");
        if(found != string::npos) {
            cout << "feature sigint=0 san=0 myname=\"Looking at the Ceiling\"" << endl;
        }

        //MOVE COMMANDS
        else if(checkIfMoveCommand(commandString)) {
            game->handleMoveCommand(commandString);
        }
    }
}

bool CommandParser::checkIfMoveCommand(string commandString) {
    if(commandString.length() == 4 && isalpha(commandString[0]) && isalpha(commandString[2]) && isdigit(commandString[1]) && isdigit(commandString[3]))
        return true;
    else if((commandString.length() == 5 && isalpha(commandString[0]) && isalpha(commandString[2]) && isalpha(commandString[4]) && isdigit(commandString[1]) && isdigit(commandString[3])))
        return true;
    return false;
}
