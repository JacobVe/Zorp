#include <iostream>

using namespace std;

void main()
{
	int height = 0;
	char firstLetterOfName = 0;

	int avatarHP = 0;

	cout << "Welcome to ZORP!" << endl;
	cout << "ZORP is a game of adventure, danger, and low cunning." << endl;
	cout << "It is definitely not related to any other text-based adventure game." << endl << endl;

	cout << "First, some questions..." << endl;

	cout << "How tall are you, in centimeters? " << endl;

	// Getting height input
	cin >> height;

	// Error check (Making sure user entered numbers only)
	if (cin.fail())
		cout << "You have failed the first challenge and are eaten by a grue." << endl;
	else
		cout << "You entered " << height << endl;

	// Clearing the Input Buffer
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	cout << "What is the first letter of your name? " << endl;
	cin >> firstLetterOfName;

	// Error check (Making sure they entered a letter)
	if (cin.fail() || !isalpha(firstLetterOfName))
		cout << "You have failed the second challenge and are eaten by a grue." << endl;
	else
		cout << "You entered " << firstLetterOfName << endl;

	// Clearing the Input Buffer
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	// Calculating Players Health
	if (firstLetterOfName != 0)
		avatarHP = (float)height / (firstLetterOfName * 0.02f);
	else
		avatarHP = 0;


	cout << endl << "Using a complex deterministic algorithm, it has been calculated that you have " << avatarHP << " hit point(s)." << endl;


	cout << endl << "Press 'Enter' to exit the program!" << endl;
	cin.get();
	return;
}