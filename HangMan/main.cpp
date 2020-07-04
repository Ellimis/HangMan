#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime> // for seed

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

string encode_word(string word) {
	const int MAX_HiddenWord = 2; // Max number of char to be hidden

	cout << word << endl;
	
	for (int i = 0; i < MAX_HiddenWord; i++) {
		char hide = word[rand() % word.size()];

		if (hide == '-') {
			i--;
			continue;
		}

		for (int j = 0; j < word.size(); j++) {
			if (word[j] == hide) {
				word[j] = '-';
			}
		}
	}

	cout << word << endl;
	return word;
}

void game(vector<string> &v) {
	int wordLoc = rand() % 193; // 0 ~ 193 random number, for indexing in vector
	string word = v[wordLoc]; // random word
	string problem;

	problem = encode_word(word);
	cout << problem << endl;

	//cout << "word : " << word << endl;
	//cout << "problem : " << problem << endl;
}

int main() {
	vector<string> voca;
	srand((unsigned) time(0)); // for rand

	open_file(voca);

	cout << "----------------------------------------" << endl;
	cout << "|    Let's start the Hangman game !    |" << endl;
	cout << "----------------------------------------" << endl;

	game(voca);

	//for (int i = 0; i < voca.size(); i++)
	//	cout << voca[i] << ' ' << i << endl;

	return 0;
}