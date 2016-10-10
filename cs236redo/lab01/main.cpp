#include <iostream>
#include <fstream>
#include <string>
#include "Scanner.h"

using namespace std;

int main(int argc, char * argv[]) {
	Scanner scan;
	string filename;
	filename = argv[1];
	scan.begin_scan(filename);
	scan.print_tokens();

	return 0;
}
