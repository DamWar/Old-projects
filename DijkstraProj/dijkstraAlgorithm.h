#ifndef dijkstraAlgorithm_H
#define dijkstraAlgorithm_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <limits>
typedef std::pair<int, double> adjPair;
/**
* Function that implements Dijkstra's algorithm and shows the path.\n 
* Dijkstra's algorithm (or Dijkstra's Shortest Path First) is an algorithm for finding the shortest paths between nodes in a graph.(src https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
* @param adj[] - vector of pairs of number of vertex and weight towards adjacent vertex (graph)
* @param vertices - vector of vertices
* @param findFor - index of vertex to search from
* @param adjSize - size of vector adj
* @param output - string containing shortest paths and their distances
*/
void dijkstra(std::vector<adjPair> adj[], std::vector<int>& vertices, int findFor, long long unsigned int adjSize, std::string& output);
/**
* Function that reads vertices from a file to search from and uses dijkstra function on an existing graph to write result to a file.
* @param adj[] - vector of pairs of number of vertex and weight towards adjacent vertex (graph)
* @param vertices - vector of vertices
* @param adjSize - size of vector adj
* @param sourceFileName - path to file containing vertices to search from
* @param resultFileName - path to file that should store the result
*/
bool findPathsFromVertices(std::vector<adjPair> adj[], std::vector<int>& vertices, long long unsigned int adjSize, std::string sourceFileName, std::string resultFileName);
#endif