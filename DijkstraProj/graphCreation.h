#ifndef graphCreation_H
#define graphCreation_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
typedef std::pair<int, double> adjPair;
/**
* Function to add vertices and edges to a graph.
* @param adj[] - vector of pairs of number of vertex and weight towards adjacent vertex (graph)
* @param vertices - vector of vertices
* @param u - first vertex
* @param v - second vertex
* @param weight - edge weight first -> second
*/
void addToGraph(std::vector<adjPair> adj[], std::vector<int>& vertices, int u, int v, double weight);
/**
* Function to create graph based on a given file.
* @param adj[] - vector of pairs of number of vertex and weight towards adjacent vertex (graph)
* @param vertices - vector of vertices
* @param sourceFileName - path to file that is used to generate a graph
*/
bool createGraphBasedOnFile(std::vector<adjPair> adj[], std::vector<int>& vertices, std::string sourceFileName);
#endif