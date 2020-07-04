#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// 193 words
void open_file(vector<string> &v) {
	const char* file_loc = "C:/words.txt";
	ifstream is(file_loc);
	string word;

	if (!is) {
		cerr << "ERROR : Can't open file";
		exit(0);
	}

	while (getline(is, word))
		v.push_back(word);

	is.close();
}

int main() {
	vector<string> voca;

	open_file(voca);

	//for (int i = 0; i < voca.size(); i++)
	//	cout << voca[i] << ' ' << i << endl;

	return 0;
}