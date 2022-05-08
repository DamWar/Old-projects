#ifndef GRAPHMANAGERCPP
#define GRAPHMANAGERCPP

void GraphManager::manage(Graph* graph, UserCommand* command, ALLEGRO_DISPLAY* display, ALLEGRO_FONT* font) {
	if (command == nullptr)
		return;
	switch (command->getType()) {
	case 0:
		graph->addNode();
		break;
	case 1:
		graph->addEdge(command->getIndices()[0], command->getIndices()[1]);
		break;
	case 2:
		graph->removeNode(command->getIndices()[0]);
		break;
	case 3:
		graph->removeEdge(command->getIndices()[0], command->getIndices()[1]);
		break;
	case 4:
		graph->count();
		break;
	}
	graph->draw(display, font);
}

#endif