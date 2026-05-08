#include <iostream>
#include <string>
#include <cctype>
#include "BuildGame.h"

using namespace std;
using namespace dsl;

int main()
{
	//1
	string fileName;
	cout << "Enter the name of the game file: ";
	cin >> fileName;

	ifstream fin(fileName);

	Tnode<string>* root = loadGame(fin);
	cout << "I can guess any number you think of between 1 and 10 with at most 5 questions. Let us begin\n";
	fin.close();

	//2
	Tnode<string>* current = root;
	char answer;

	while(current != nullptr)
	{
		if(current->data() != "")
		{
			cout <<current->data() <<endl;
		}
		else
		{
			break;
		}

		cout << "Enter 'Y' for yes or 'N' for no: ";
		cin >> answer;
		answer = toupper(answer);

		if(answer == 'Y')
		{
			current = current->left();
		}

		else
		{
			current = current->right();
		}
	}

	if(answer == 'Y')
	{
		cout << "See, I told you\n";
	}
	else
	{
		cout << "You are lying\n";
	}

	return 0;
}
