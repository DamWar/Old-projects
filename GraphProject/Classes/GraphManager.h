#ifndef GRAPHMANAGER
#define GRAPHMANAGER
#include"UserCommand.h"
#include"Graph.h"

class GraphManager {
public:
	void manage(Graph* graph, UserCommand* command, ALLEGRO_DISPLAY* display, ALLEGRO_FONT* font); //calls appropraite graph methods(on given graph object) based on given user's command
};

#endif