#include <iostream>
#include <windows.h>

using namespace std;

const char* ESC = "\x1b";
const char* CSI = "\x1b[";

const char* TITLE = "\x1b[5;20H";
const char* INDENT = "\x1b[5C";
const char* YELLOW = "\x1b[93m";
const char* MAGENTA = "\x1b[95m";
const char* RESET_COLOR = "\x1b[0m";
const char* SAVE_CURSOR_POS = "\x1b[s";
const char* RESTORE_CURSOR_POS = "\x1b[u";

void main()
{
	// Set output mode to handle cirtual terminal sequences
	DWORD dwMode = 0;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);


	int height = 0;
	char firstLetterOfName = 0;

	int avatarHP = 0;

	cout << TITLE << MAGENTA << "Welcome to ZORP!" << RESET_COLOR << endl;
	cout << INDENT << "ZORP is a game of adventure, danger, and low cunning." << endl;
	cout << INDENT << "It is definitely not related to any other text-based adventure game." << endl << endl;

	cout << INDENT << "First, some questions..." << endl;

	// Save Cursor Position
	cout << SAVE_CURSOR_POS;
	cout << INDENT << "How tall are you, in centimeters? " << INDENT << YELLOW;

	
	// Getting height input
	cin >> height;
	cout << RESET_COLOR << endl;

	// Error check (Making sure user entered numbers only)
	if (cin.fail())
		cout << INDENT << "You have failed the first challenge and are eaten by a grue." << endl;
	else
		cout << INDENT << "You entered " << height << endl;

	// Clearing the Input Buffer
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	// Move Cursor to the start of the 1st question
	cout << RESTORE_CURSOR_POS;
	// Delete the next 4 lines
	cout << CSI << "4M";

	cout << INDENT << "What is the first letter of your name? " << INDENT << YELLOW;
	cin >> firstLetterOfName;
	cout << RESET_COLOR << endl;

	// Error check (Making sure they entered a letter)
	if (cin.fail() || !isalpha(firstLetterOfName))
		cout << INDENT << "You have failed the second challenge and are eaten by a grue." << endl;
	else
		cout << INDENT << "You entered " << firstLetterOfName << endl;

	// Clearing the Input Buffer
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();

	// Move the cursor to the start of the 1st question
	cout << RESTORE_CURSOR_POS;
	cout << CSI << "A"; // Cursor up 1
	cout << CSI << "4M"; // Delete the next 4 lines

	// Calculating Players Health
	if (firstLetterOfName != 0)
		avatarHP = (float)height / (firstLetterOfName * 0.02f);
	else
		avatarHP = 0;


	cout << INDENT << "Using a complex deterministic algorithm, it has been calculated that you have " << avatarHP << " hit point(s)." << endl;


	cout << endl << INDENT << "Press 'Enter' to exit the program!" << endl;
	cin.get();
	return;
}