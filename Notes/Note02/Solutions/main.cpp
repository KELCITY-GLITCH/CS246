#include <iostream>
#include <string>
#include "Multi.h"
#include "WrdFo.h"
#include "TiTaTo.h"

void play(dsn::Multi& game) 
{
	std::string str;
	std::cout << game.intro();

	while(game.playable())
	{
		while(true) 
		{
			std::cout << "\n" << game << "\n";
			std::cout << "Enter: ";
			std::getline(std::cin,str);
			if(game.move(str)) {break;}
		}

		if(game.won()) 
		{
			std::cout << game << "\n" << game.current() << " won\n";
		    return;
		}
		else {game.next();}
	}

	if(!game.won()) 
	{
		std::cout << "game ended without a winner\n";
	}			
}

int main()
{
	dsn::TicTacToe t;
	play(t);
	return 0;
}
