#ifndef GRAPHCPP
#define GRAPHCPP

void Graph::updatePosition() {
	int nNodes = nodes.size();
	int arc = 100;
	const double pi = 3.14159265358979323846;
	double angleDiff = 360 / nNodes * (pi / 180);//in radians
	double angle = 0;
	int x, y;
	r = (double)nNodes * (double)arc / (2 * pi);//to avoid overflow
	for (int i = 0; i < nNodes; ++i) {
		x = centerX + r * cos(angle);
		y = centerY + r * sin(angle);
		nodes[i].assignPosition(x, y);
		angle += angleDiff;
	}
}

void Graph::drawNode(int positionX, int positionY, int index, ALLEGRO_DISPLAY* display, ALLEGRO_FONT* font) {
	std::string indexString = std::to_string(index);
	const char* indexCharArr = indexString.c_str();
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR orange = al_map_rgb(251, 145, 1);
	al_draw_circle(positionX, positionY, 30, black, 2);
	al_draw_filled_circle(positionX, positionY, 30, orange);
	al_draw_text(font, black, positionX - 5, positionY - 20, ALLEGRO_ALIGN_CENTRE, indexCharArr);
}

void Graph::drawEdge(int xNode1, int yNode1, int xNode2, int yNode2, ALLEGRO_DISPLAY* display, ALLEGRO_FONT* font) {
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
	al_draw_line(xNode1, yNode1, xNode2, yNode2, black, 2);
}

int Graph::getNumberOfNodes() {
	return nodes.size();
}

void Graph::addNode() {
	Node obj;
	nodes.push_back(obj);//adding
}

void Graph::addEdge(int index1, int index2) {
	int nEdges = edges.size();
	for (int i = 0; i < nEdges; ++i) {//all edges connected to given node are erase
		if ((edges[i].getNodeIndex(NODE_1) == index1 && edges[i].getNodeIndex(NODE_2) == index2) || (edges[i].getNodeIndex(NODE_1) == index2 && edges[i].getNodeIndex(NODE_2) == index1)) {
			std::cout << "Such edge already exists.\n";
			return;
		}
	}
	if (index1 == index2)
		return;
	Edge obj(index1, index2);
	edges.push_back(obj);//adding
}

void Graph::removeNode(int index) {
	nodes.erase(nodes.begin() + index);
	//search through edges
	int nEdges = edges.size();
	for (int i = 0; i < nEdges; ++i) {//all edges connected to given node are erased
		if (edges[i].getNodeIndex(NODE_1) == index || edges[i].getNodeIndex(NODE_2) == index) {
			edges.erase(edges.begin() + i--);//now there is another edge on same index, hence i--
			--nEdges;
		}
	}
}

void Graph::removeEdge(int index1, int index2) {
	int nEdges = edges.size();
	bool edgeFound = false;
	for (int i = 0; i < nEdges; ++i) {//erasing
		if (edges[i].getNodeIndex(NODE_1) == index1 && edges[i].getNodeIndex(NODE_2) == index2) {
			edges.erase(edges.begin() + i);//there is only one exact edge
			edgeFound = true;
			break;//no need to continue searching
		}
	}
	if (!edgeFound)
		std::cout << "There is no such edge.\n";
}

void Graph::count() {
	std::cout << "Number of nodes : " << nodes.size() << "; Number of edges : " << edges.size() << "\n";
}

void Graph::draw(ALLEGRO_DISPLAY* display, ALLEGRO_FONT* font) {
	al_clear_to_color(al_map_rgb(255, 255, 255));
	updatePosition();
	int nodeIndex1, nodeIndex2;
	int xNode1, yNode1, xNode2, yNode2;
	for (size_t i = 0; i < edges.size(); ++i) { //edges first so they get covered by nodes
		try {
			nodeIndex1 = edges[i].getNodeIndex(NODE_1);
			nodeIndex2 = edges[i].getNodeIndex(NODE_2);
			xNode1 = nodes[nodeIndex1].getPosition(POSITION_X);
			yNode1 = nodes[nodeIndex1].getPosition(POSITION_Y);
			xNode2 = nodes[nodeIndex2].getPosition(POSITION_X);
			yNode2 = nodes[nodeIndex2].getPosition(POSITION_Y);
			drawEdge(xNode1, yNode1, xNode2, yNode2, display, font);
		}
		catch (...) {
			std::cout << "Failed to draw edge " << i << "\n";
		}
	}
	for (size_t i = 0; i < nodes.size(); ++i) {
		try {
			drawNode(nodes[i].getPosition(POSITION_X), nodes[i].getPosition(POSITION_Y), i, display, font);
		}
		catch (...) {
			std::cout << "Failed to draw node " << i << "\n";
		}
	}
	al_flip_display();
}


#endif