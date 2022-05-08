#include "parametersHandlingF.h"

using namespace std;

void assignOperations(char* fName, string& nameVar, string errorMessage)
{
	if (fName == nullptr)
		cout << errorMessage;
	else
		nameVar = fName;
}
void checkFlag(char* flag, char* fName, string& inGraph, string& inVertices, string& outResult)
{
	string flagS = flag;
	if (flagS == "-g")
		assignOperations(fName, inGraph, "Invalid graph input file name.\n");
	else if (flagS == "-w")
		assignOperations(fName, inVertices, "Invalid vertices input file name.\n");
	else if (flagS == "-o")
		assignOperations(fName, outResult, "Invalid output file name.\n");
	else
		cout << "Unknown flag \"" << flagS << "\".";
}
bool assignIOfileNames(int argc, char* argv[], string& inGraph, string& inVertices, string& outResult)
{
	if (argc == 1) {
		cout << "Program accepts following parameters in any order:\n-g \"graph input file name\"\n-w \"vertices input file name\"\n-o \"output file name\"\n";
		return false;
	}
	for (short int i = 1; i < argc; i += 2)
	{
		checkFlag(argv[i], argv[i + 1], inGraph, inVertices, outResult);
	}
	return true;
}