#include "graphCreation.h"

using namespace std;

void addToGraph(vector<adjPair> adj[], vector<int>& vertices, int u, int v, double weight)
{
	if (find(vertices.begin(), vertices.end(), u) == vertices.end()) {
		vertices.push_back(u);
	}
	vector<int>::iterator vi = find(vertices.begin(), vertices.end(), v);
	if (vi == vertices.end()) {
		vertices.push_back(v);
		size_t currentIndex = vertices.size() - 1;
		adj[u].push_back(make_pair(vertices[currentIndex], weight));
	}
	else {
		size_t currentIndex = vertices.size() - 1;
		adj[u].push_back(make_pair(vertices[vi - vertices.begin()], weight));
	}
}
bool createGraphBasedOnFile(vector<adjPair> adj[], vector<int>& vertices, string sourceFileName)
{
	ifstream file(sourceFileName);
	if (file.good()) {
		cout << sourceFileName << " file opened.\n";
		string line;
		while (getline(file, line)) {
			if (line.size()) {
				stringstream ss(line);
				int p1, p2;
				string edgeType;
				string dummy;
				double w;
				if (ss >> p1 >> edgeType >> p2 >> dummy >> w) {
					if (edgeType == "->") {
						addToGraph(adj, vertices, p1, p2, w);
					}
					else if (edgeType == "-") {
						addToGraph(adj, vertices, p1, p2, w);
						addToGraph(adj, vertices, p2, p1, w);
					}
				}
			}
		}
		file.close();
		return true;
	}
	else {
		cout << "File " << sourceFileName << " could not be opened.\n";
		return false;
	}
}