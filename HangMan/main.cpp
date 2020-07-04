#include <iostream>
#include <fstream>
#include <ctime> // for seed
#include "game_director.h"

using namespace std;

int main() {
	const char* file_loc = "C:/words.txt";
	ifstream inFile(file_loc);

	if (!inFile) {
		cerr << "ERROR : Can't open file";
		exit(0);
	}

	GameDirector director;

	director.append_word(inFile);

	srand((unsigned)time(0)); // for rand
	char retry;
	do {
		director.game();
		cout << "Next(y/n)? : ";
		cin >> retry;
	} while (retry == 'y');

	return 0;
}