#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class GameDirector {
	vector<string> vocabulary; // word vocabulary

public:
	GameDirector();
	void append_word(ifstream& fin);
	string encode_word(string word);
	void game();
};

GameDirector::GameDirector() {
	cout << "----------------------------------------" << endl;
	cout << "|    Let's start the Hangman game !    |" << endl;
	cout << "----------------------------------------" << endl;
}

// 193 words
void GameDirector::append_word(ifstream& fin) { // word append from txt file to vector
	string word;

	while (getline(fin, word))
		this->vocabulary.push_back(word);

	fin.close();
}

string GameDirector::encode_word(string word) { // encode word for the game
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

void GameDirector::game() {
	string word = this->vocabulary[rand() % 193]; // 0 ~ 193 random word, for indexing in vector
	string problem;

	problem = this->encode_word(word);

	for (int i = 0; i < 5; i++) {
		bool find = false;
		char input;
		cout << problem << endl;
		cin >> input;

		// Add if the current encrypted character is the same as '-' and the user-entered character is the same as the real character
		for (int j = 0; j < word.size(); j++) {
			if (word[j] == input && problem[j] == '-') { 
				problem[j] = input;
				find = true;
			}
		}

		if (find) i--; // if find one letter then give one more chance (total 5 failes will be defeat)
		if (!word.compare(problem)) { // return 0 if two objects are the same.
			cout << "word : " << problem << endl;
			return;
		}
	}

	cout << "Failed to complete word in 5 chances." << endl;
	cout << "word : " << word << endl;
}