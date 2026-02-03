#ifndef WRDFO_H
#define WRDFO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "Multi.h"

namespace dsn 
{
	class WordBank 
	{
		private:
		std::vector<std::string> words;
		
		public:
		WordBank() 
		{
			std::fstream fin("words.txt",std::fstream::in);
			std::string str;

			if(fin.is_open())
			{
				while(fin >> str)
				{
					words.push_back(str);
				}
			}
			fin.close();
		}
		
		~WordBank() {}
		
		WordBank(const WordBank& obj) 
		{
			words = obj.words;
		}

		WordBank& operator=(const WordBank& rhs)
		{
			if(this != &rhs) 
			{
				words = rhs.words;
			}
			return *this;
		}

		std::string get() const 
		{
			return words[rand() % words.size()];
		}	
	};
}

#endif
