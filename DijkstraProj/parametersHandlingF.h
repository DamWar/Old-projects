#ifndef parametersHandling_H
#define parametersHandling_H
#include <iostream>
#include <string>
/**
* Function to assign path to file to a given string. If there is no path (nullptr), function prints error message.
* @param fName - path to a file
* @param nameVar - variable to store path if it exists
* @param erroeMessage - a message to be printed in case there is no path specified
*/
void assignOperations(char* fName, std::string& nameVar, std::string errorMessage);
/**
* Function that checks given flags and processes them accordingly.
* @param flag - variable that defines what to do with fName
* @param fName - variable that stores name of one of the files
* @param inGraph - string for graph's input file name
* @param inVertices - string for vertices's input file name
* @param outResult - string for result's output file name
*/
void checkFlag(char* flag, char* fName, std::string& inGraph, std::string& inVertices, std::string& outResult);
/**
* Function that handles program's arguments. If none are specified, it prints explanation about program's usage
* @param argc - number of arguments
* @param argv[] - array of arguments
* @param inGraph - string for graph's input file name
* @param inVertices - string for vertices's input file name
* @param outResult - string for result's output file name
*/
bool assignIOfileNames(int argc, char* argv[], std::string& inGraph, std::string& inVertices, std::string& outResult);
#endif