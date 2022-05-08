#ifndef NODE
#define NODE
#include"../Enums/Position.h"

class Node { //this class represents a node
	int posX, posY; //position (x,y) of node's center 
	static const unsigned int radius = 30;//node's radius
public:
	Node();
	Node(int positionX, int positionY); //constructor assigns values to posX and posY
	void assignPosition(int positionX, int positionY);
	int getPosition(Position axis); //returns posX or posY based on (enum)Position
};

#endif