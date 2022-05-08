#ifndef USERCOMMANDMANAGER
#define USERCOMMANDMANAGER
#include<string>
#include<vector>
#include"UserCommand.h"
#include"Graph.h"

class UserCommandManager { //manages communication with user
	std::string input; //stores user's input(from console)
	std::vector<std::string> words; //stores parts of user's input - separated by " "
public:
	void printOptions(); //prints options that user can decide to use
	UserCommand* readInput(Graph* graph); //reads user's input and decides what UserCommand to return
};

#endif