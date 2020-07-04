#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	const char* file_loc = "C:/words.txt";
	ifstream is(file_loc);
	if (!is) {
		cerr << "ERROR : Can't open file";
		exit(0);
	}
	string word;
	while (getline(is, word)) {

	}

	return 0;
}