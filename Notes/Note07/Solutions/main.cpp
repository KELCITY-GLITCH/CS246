#include <iostream>
#include "List.h"
#include "Node.h"
#include <fstream> //ifstream
#include <cstdlib> //srand(), rand()
#include <ctime> //time() 
#include <string>
#include <cctype> //

class Player 
{
	private:
	static size_t count;
	std::string name;
	std::string word;
	std::string display;
	std::string guessed;

	public: 
	Player() : word(""), display(""), guessed("") 
	{
		name = "Player " + std::to_string(count);
		count += 1;
	}

	Player(std::string w) : word(w), guessed("") 
	{
		for(int i = 0;i < word.size();i += 1)
		{
			word[i] = tolower(word[i]);
		}
		display = std::string(word.size(),'_');
		name = "Player " + std::to_string(count);
		count += 1;
	}

	Player(const Player& obj) 
	{
		name = obj.name;
		word = obj.word;
		diplay = obj.display;
		guessed = obj.guessed;
	}

	Player& operator=(const Player& rhs)
	{
		if(this != &rhs) 
		{
			name = rhs.name;
			word = rhs.word;
			display = 




};
int main()
{
    dsn::List<int> h;
    dsn::Iterator<int> s(h);
    return 0;
}
