#ifndef USERCOMMAND
#define USERCOMMAND
#include"../Enums/CommandType.h"

class UserCommand {//this class represents user command
	CommandType type; //stores types of user command
	int nodeIndices[2]; //stores node indices needed to execute commands
public:
	UserCommand(CommandType cType); //constructor assigns type when given one argument
	UserCommand(CommandType cType, int indices[]); //constructor assigns type and required indices when given two arguments
	CommandType getType(); //returns type
	int* getIndices(); //returns *nodeIndices
};

#endif