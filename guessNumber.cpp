#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;
int main() {
	srand(time(0));
	char replay{ 'y' };
	while (replay == 'y') {
		cout << "\033[2J\033[1;1H";
		int diffLvl{};
		int maxRange{};
		int nb{};
		int tries{};
		cout << "choose a difficulty\n1 for easy\t 2 for medium\t 3 for hard\n";
		while (!(cin >> diffLvl)|| diffLvl>3||diffLvl<1) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "enter a nb between 1 and 3\n";
		}
		switch (diffLvl) {
		case 1:
			maxRange = 10;
			nb = (rand() % maxRange) + 1;
			tries = 3;
			break;
		case 2:
			maxRange = 50;
			nb = (rand() % maxRange) + 1;
			tries = 5;
			break;
		case 3:
			maxRange = 100;
			nb = (rand() % maxRange) + 1;
			tries = 7;
			break;
		}
		cout << "guess a number between 1-" << maxRange << "\n";
		while (tries > 0) {
			int luckNb{};
			cout << right << setw(80) << tries << " trie(s) left\n";
			/*cout << nb;*/
			cin >> luckNb;
			if (luckNb == nb) {
				cout << "\033[32mu won\033[0m\n";
				tries = 0;
			}
			else {
				tries--;
				if (tries > 0) {
					cout << "try again, ";
					(luckNb > nb) ? cout << "aim lower \n" : cout << "aim higher\n";
				}
				else if (tries <= 0) {
					cout << "\033[31mu lost, the real nb was " << nb << "\033[0m\n";
				}
			}
		}
		cout << "wanna replay?\n";
		while (!(cin >> replay)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "enter something valid\n";
		}
		replay = tolower(replay);
	}

}
