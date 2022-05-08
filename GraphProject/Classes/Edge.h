#ifndef EDGE
#define EDGE
#include"../Enums/NodeIndex.h"

class Edge { //this class represents edge
	int node1, node2; //nodes that are linked by this edge
public:
	Edge(int nodeIndex1, int nodeIndex2); //constructor assigns values to node1 and node 2
	int getNodeIndex(NodeIndex index); //returns node1 or node2 based on (enum)NodeIndex
};

#endif