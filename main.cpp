#include "tests.h"
#include <string>
#include <fstream>
using std::string;
#define MAX_LINE 256


int main(int argc, char** argv) {
	test_linked_list();
}


////* return false if input is invalid *//
//bool get_input(string file_name) {
//	char line[MAX_LINE];
//	std::ifstream inFile(file_name);
//
//	do {
//		inFile.getline(line, MAX_LINE);
//
//
//	}
//
//	while (!inFile.eof());
//}
//
