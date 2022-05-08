#include "dijkstraAlgorithm.h"
#include "miscellaneous.h"

using namespace std;

void dijkstra(vector<adjPair> adj[], vector<int>& vertices, int findFor, long long unsigned int adjSize, string& output)
{
	constexpr double inf = numeric_limits<double>::infinity();
	vector<double> distance(adjSize, inf);
	priority_queue < adjPair, vector<adjPair>, greater<adjPair> > minHeap;
	minHeap.push(make_pair(0, findFor));
	vector<int>::iterator it = find(vertices.begin(), vertices.end(), findFor);
	if (it >= vertices.end()) {
		output += "brak wierzcholka " + to_string(findFor) + " w grafie\n";
		return;
	}
	findFor = it - vertices.begin();
	distance[findFor] = 0;

	int uIndex, u;
	double v, weight;
	constexpr int maxInt = numeric_limits<int>::max();
	vector<int> prev(adjSize, maxInt);
	while (!minHeap.empty()) {
		u = minHeap.top().second;
		minHeap.pop();
		for (auto adjacent : adj[u]) {
			vector<int>::iterator ui = find(vertices.begin(), vertices.end(), u);
			uIndex = ui - vertices.begin();
			v = adjacent.first;
			double vValue = v;
			vector<int>::iterator vi = find(vertices.begin(), vertices.end(), v);
			v = vi - vertices.begin();
			weight = adjacent.second;
			if (distance[v] > distance[uIndex] + weight) {
				distance[v] = distance[uIndex] + weight;
				minHeap.push(make_pair(distance[v], vValue));
				prev[v] = u;
			}
		}
	}

	string path = "";
	for (size_t i = 0; i < adjSize; i++)
	{
		if (i == findFor)
			continue;
		size_t j = i;
		if (distance[i] != inf) {
			output += to_string(vertices[findFor]);
			path = "";
			while (prev[j] != vertices[findFor] && prev[j] != maxInt)
			{
				vector<int>::iterator it = find(vertices.begin(), vertices.end(), prev[j]);
				path += to_string(prev[j]) + " >- ";
				j = it - vertices.begin();

			}
			reverseStr(path);
			output += path;
			if (j == vertices[i])
				output += " : " + to_string(distance[i]) + "\n";
			else {
				output += " -> " + to_string(vertices[i]);
				output += " : " + to_string(distance[i]) + "\n";
			}
		}
	}
}
bool findPathsFromVertices(vector<adjPair> adj[], vector<int>& vertices, long long unsigned int adjSize, string sourceFileName, string resultFileName)
{
	ifstream vFile(sourceFileName);
	if (vFile.good()) {
		cout << "Vertices file opened.\n";
		ofstream oFile(resultFileName);
		if (oFile.good()) {
			cout << "Result file opened.\n";
			string output = "";
			int findFor;
			while (vFile >> findFor)
				dijkstra(adj, vertices, findFor, adjSize, output);
			oFile << output;
			oFile.close();
			vFile.close();
			return true;
		}
		else {
			cout << "File " << resultFileName << " could not be opened.\n";
			vFile.close();
			return false;
		}
	}
	else {
		cout << "File " << sourceFileName << " could not be opened.\n";
		return false;
	}
}