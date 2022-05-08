#ifndef USERCOMMANDMANAGERCPP
#define USERCOMMANDMANAGERCPP

void UserCommandManager::printOptions() {
	std::cout << "Program GraphProject accepts following commands:\nadd - adds node(add node) or edge(add edge node_id1 node_id2) to a graph\nremove - removes node(remove node node_id) or edge(remove edge node_id1 node_id2)\ncount - counts number of nodes and edges\n";
}
UserCommand* UserCommandManager::readInput(Graph* graph) {
	words.clear();
	while ((std::cin.peek() != '\n') && (std::cin >> input))
		words.push_back(input);
	std::cin.ignore(10, '\n');

	int nWords = words.size();
	if (nWords == 1 && words[0] == "count") {
		UserCommand* command = new UserCommand(COUNT);
		return command;
	}
	else if (nWords == 2 && words[0] == "add" && words[1] == "node") {
		UserCommand* command = new UserCommand(ADD_NODE);
		return command;
	}
	else if (nWords == 3 && words[0] == "remove" && words[1] == "node") {
		int params[2];
		try {
			params[0] = stoi(words[2]);
			if (params[0] >= graph->getNumberOfNodes()) {
				std::cout << "Node of index " << params[0] << " doesn't exist\n";
				return nullptr;
			}
			params[1] = -1;
		}
		// Standard exceptions for stoi
		catch (const std::invalid_argument& e) {
			std::cout << e.what() << "\n";
			return nullptr;
		}
		catch (const std::out_of_range& e) {
			std::cout << e.what() << "\n";
			return nullptr;
		}
		catch (...) {// and anything else
			std::cout << "Unknown error occured while handling parameters\n";
			return nullptr;
		}
		UserCommand* command = new UserCommand(REMOVE_NODE, params);
		return command;
	}
	else if (nWords == 4 && words[1] == "edge") {
		int params[2];
		try {
			params[0] = stoi(words[2]);
			params[1] = stoi(words[3]);
			if (params[0] >= graph->getNumberOfNodes() || params[1] >= graph->getNumberOfNodes()) {
				std::cout << "At least one of selected nodes doesn't exist\n";
				return nullptr;
			}
		}
		// Standard exceptions for stoi
		catch (const std::invalid_argument& e) {
			std::cout << e.what() << "\n";
			return nullptr;
		}
		catch (const std::out_of_range& e) {
			std::cout << e.what() << "\n";
			return nullptr;
		}
		catch (...) {// and anything else
			std::cout << "Unknown error occured while handling parameters\n";
			return nullptr;
		}

		if (words[0] == "add") {
			UserCommand* command = new UserCommand(ADD_EDGE, params);
			return command;
		}
		else if (words[0] == "remove") {
			UserCommand* command = new UserCommand(REMOVE_EDGE, params);
			return command;
		}
	}
	std::cout << "Unknown command\n";
	return nullptr;
}

#endif