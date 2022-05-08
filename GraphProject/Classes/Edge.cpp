#ifndef EDGECPP
#define EDGECPP

Edge::Edge(int nodeIndex1, int nodeIndex2) {
	node1 = nodeIndex1;
	node2 = nodeIndex2;
}
int Edge::getNodeIndex(NodeIndex index) {
	if (index == NODE_1)
		return node1;
	else
		return node2;
}

#endif