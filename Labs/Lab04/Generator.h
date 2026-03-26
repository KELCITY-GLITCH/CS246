#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "Object.h"

namespace dsl 
{
	class Generator : public Object
	{
		private:
		static const std::string values;
		std::string read;
		size_t md[2];

		public:
		Generator() : read(), md{0,36} {srand(time(nullptr));}

		Generator(const Generator& obj)
		{
			read = obj.read;
			for(int i = 0;i < 2;i += 1) {md[i] = obj.md[i];}
		}

		Generator& operator=(const Generator& rhs)
		{
			if(this != &rhs)
			{
				read = rhs.read;
				
				for(int i = 0;i < 2;i += 1)
				{
					md[i] = rhs.md[i];
				}
			}
			return *this;
		}

		~Generator() {}

		char next() 
		{
			char ch = values[md[0] + rand() % md[1]];
			read += ch;
			return ch;
		}

		void lettersOnly() 
		{
			read = std::string();
			md[0] = 0;
			md[1] = 26;
		}

		void digitsOnly()
		{
			read = std::string();
			md[0] = 26;
			md[1] = 10;
		}

		void bothTypes()
		{
			read = std::string();
			md[0] = 0;
			md[1] = 36;
		}

		std::string toString() const override 
		{
			std::stringstream out;

			for(size_t i = 0;i < read.size();i += 50)
			{
				out << read.substr(i,50) << "\n";
			}
			return out.str();
		}
	};

	const std::string Generator::values = "abcdefghijklmnopqrstuvwxyz0123456789"; 
}

#endif 
