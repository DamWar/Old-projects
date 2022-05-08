#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <limits>
#include "parametersHandlingF.h"
#include "graphCreation.h"
#include "miscellaneous.h"
#include "dijkstraAlgorithm.h"

using namespace std;

int main(int argc, char* argv[])
{
	//note: I've been told that each vertex should fit in int type
	string inGraph, inVertices, outResult;//variable that stores file names
	if (!assignIOfileNames(argc, argv, inGraph, inVertices, outResult))
		return 0;
	constexpr short unsigned int bVecSize = 1024;//size of vector at the beginning
	long long unsigned int adjSize = 0;//size of vector adj
	vector<adjPair> adj[bVecSize];//adj for adjacent
	vector<int> vertices;
	if (!createGraphBasedOnFile(adj, vertices, inGraph))
		return 0;
	adjSize = vertices.size();
	findPathsFromVertices(adj, vertices, adjSize, inVertices, outResult);

	return 0;
}