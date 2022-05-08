#ifndef NODECPP
#define NODECPP

Node::Node() {
	posX = NULL;
	posY = NULL;
}
Node::Node(int positionX, int positionY) {
	posX = positionX;
	posY = positionY;
}
void Node::assignPosition(int positionX, int positionY) {
	posX = positionX;
	posY = positionY;
}
int Node::getPosition(Position axis) {
	if (axis == POSITION_X)
		return posX;
	else
		return posY;
}

#endif