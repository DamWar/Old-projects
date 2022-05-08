#include"GraphProject.h"

int main() {
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = al_create_display(800, 800);
	al_set_window_position(display, 1100, 200);
	al_set_window_title(display, "Graph");
	ALLEGRO_FONT* font = al_load_font("times.ttf", 36, NULL);

	Graph* a = new Graph;
	UserCommandManager man;
	GraphManager gMan;
	man.printOptions();
	UserCommand* command;
	while (true) {
		command = man.readInput(a);
		gMan.manage(a, command, display, font);
	}
	//UserCommand command(COUNT);
	//add possibility to enter command directly in code
	return 0;
}