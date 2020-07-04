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

	return word;
}

void game(vector<string> &v) {
	int wordLoc = rand() % 193; // 0 ~ 193 random number, for indexing in vector
	string word = v[wordLoc]; // random word
	string problem;

	problem = encode_word(word);
	
	for (int i = 0; i < 5; i++) {
		bool find = false;
		char input;
		cout << problem << endl;
		cin >> input;
		
		for (int j = 0; j < word.size(); j++) {
			if (word[j] == input && problem[j] == '-') {
				problem[j] = input;
				find = true;
			}
		}
		
		if (find) i--; // if find one letter then give one more chance (total 5 failes will be defeat)
		if (!word.compare(problem)) { // return 0 if two objects are the same.
			cout << problem << endl;
			return;
		}
	}

	cout << "Failed to complete word in 5 chances." << endl;
	cout << word << endl;
}

int main() {
	vector<string> voca;
	srand((unsigned) time(0)); // for rand

	open_file(voca);

	cout << "----------------------------------------" << endl;
	cout << "|    Let's start the Hangman game !    |" << endl;
	cout << "----------------------------------------" << endl;

	char retry;
	do {
		game(voca);
		cout << "Next(y/n)?" << endl;
		cin >> retry;
	} while (retry == 'y');

	return 0;
}