#ifndef GRAPH
#define GRAPH
#include<vector>
#include"Node.h"
#include"Edge.h"

class Graph {
	std::vector<Node> nodes; //vector of nodes(classes)
	std::vector<Edge> edges; //vector of edges(classes)
	int centerX = 400;
	int centerY = 400;
	int r = 400*0.4;
	void updatePosition();
	void setScreenSize(int height, int width);
	void drawNode(int positionX, int positionY, int index, ALLEGRO_DISPLAY* display, ALLEGRO_FONT* font);
	void drawEdge(int xNode1, int yNode1, int xNode2, int yNode2, ALLEGRO_DISPLAY* display, ALLEGRO_FONT* font);
public:
	void setCanvas(); //sets canvas (size, color depth, etc.)
	int getNumberOfNodes();
	void addNode(); //adds node
	void addEdge(int index1, int index2); //adds edge between node of index1 and node of index2
	void removeNode(int index); //removes node of given index
	void removeEdge(int index1, int index2); //removes edge between node of index1 and node of index2
	void count(); //counts nodes and edges
	void draw(ALLEGRO_DISPLAY* display, ALLEGRO_FONT* font); //draws a graph
};

#endif