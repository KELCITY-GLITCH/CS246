#ifndef MULTI_H
#define MULTI_H

#include "Object.h"
#include <sstream>

namespace dsn 
{
	/*
	 *Class: Multi 
	 *Description: Multi-player Game Interface
	 */
	class Multi : public Object
	{
		public:
		virtual ~Multi() {}

		//Method: intro()
		//Description: provides name, 
		//descriptions, and instructions for 
		//the game   
		virtual std::string intro() const = 0;

		//Method: move(str) 
		//Dscription: validates move input 
		//and performs move for the current 
		//player  
		virtual bool move(std::string) = 0;

		//Method: playable()
		//Description: checks if the game is
		//playable
		virtual bool playable() const = 0;

		//Method: won() 
		//Description: checks if the current 
		//player won the game
		virtual bool won() const = 0;

		//Method: next()
		//Description: changes the current 
		//player 
		virtual void next() = 0;

		//Method: current()
		//Dscription: retrieve the identification 
		//of the current player 
		virtual std::string current() const = 0;
	};
}

#endif
