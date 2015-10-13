#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"

using namespace std;

int main(int argc, char * argv[])
{
	string filename = argv[1];
	Parser parse(filename);
	parse.begin();
}
