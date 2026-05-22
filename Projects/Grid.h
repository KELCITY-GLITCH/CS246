#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include "Point.h"

namespace dsp
{
	class Grid : public Object
	{
		private:
		std::string bd;
		Point ends[2];

		bool validate(const std::string& str)
		{
			if(str.size() == bd.size())
			{
				for(auto i : str)
				{
					if(i != '0' && i != '1')
					{
						return false;
					}
				}
				bd = str;
				return true;
			}
			return false;
		}
		
		bool valid(const Point& p) const
		{
			if(equal(ends[0],p))
			{
				size_t i = p.hash();
				size_t s = ends[0].hash();
				size_t e = ends[1].hash();
				bool es = (i == s || i == e);
				return es || bd[i] != '1';
			}
			return false;
		}

		public:
		Grid()  
		{
			bd = std::string(16,'0');

			for(size_t i = 0;i < 2;i += 1)
			{
				ends[i] = Point(4,4);
				ends[i].set(3*i,3*i);
			}
		}

		Grid(size_t r, size_t c) 
		{
			if(r > 20 || c > 20 || r * c <= 1) 
			{
				throw std::invalid_argument("invalid inputs");
			}
			bd = std::string(r*c,'0');

			for(size_t i = 0;i < 2;i += 1)
			{
				ends[i] = Point(r,c);
				ends[i].set((r-1)*i,(c-1)*i);
			}
		}

		Grid(const Grid& obj)
		{
			bd = obj.bd;

			for(size_t i = 0;i < 2;i += 1)
			{
				ends[i] = obj.ends[i];
			}
		}
		
		Grid& operator=(const Grid& rhs)
		{
			if(this != &rhs)
			{
				bd = rhs.bd;

				for(size_t i = 0;i < 2;i += 1)
				{
					ends[i] = rhs.ends[i];
				}
			}
			return *this;
		}

		virtual ~Grid() {}

		size_t rows() const {return ends[0].rows();}

		size_t columns() const {return ends[0].columns();}

		void start(const Point& p) 
		{
			if(equal(p,ends[0]) && p != ends[1])
			{
				ends[0] = p;
			}
		}

		void end(const Point& p) 
		{
			if(equal(p,ends[0]) && p != ends[0])
			{
				ends[1] = p;
			}
		}

		Point start() const {return ends[0];}

		Point end() const {return ends[1];}

		void mark(const Point& p)
		{
			if(equal(ends[0],p))
			{
				size_t s = ends[0].hash();
				size_t e = ends[1].hash();
				size_t i = p.hash();
				char t = bd[i];

				if(i != s && i != e && t != '1') 
				{
					bd[i] = '+';
				}
			}
		}
		
		bool load(const std::string& str) 
		{
			return validate(str);
		}
		
		bool available(const Point& p) const
		{
			if(equal(ends[0],p) && p != ends[0])
			{
				size_t i = p.hash();
				return p == ends[1] || bd[i] == '0';
			}
			return false;
		}

		void reset() 
		{
			for(size_t i = 0;i < bd.size();i += 1)
			{
				if(bd[i] == '+') {bd[i] = '0';}
			}
		}

		bool path(const std::string& str) const
		{
			Point p = ends[0], q;
			char s;

			for(auto c : str)
			{
				s = tolower(c);
				q = p;
				if(s == 'l') {p = p.left();}
				else if(s == 'r') {p = p.right();}
				else if(s == 'u') {p = p.up();}
				else if(s == 'd') {p = p.down();}
				else {return false;}

				if(q == p || !valid(p)) 
				{
					return false;
				}
			}
			return p == ends[1];
		}

		std::string toString() const override
		{
			std::stringstream out;
			size_t s = ends[0].hash();
			size_t e = ends[1].hash();
			size_t c = ends[0].columns();
			
			for(size_t i = 0;i < bd.size();i += 1)
			{
				if(s == i) {out << 'S';}
				else if(e == i) {out << 'E';}
				else if(bd[i] == '0') {out << " ";}
				else if(bd[i] == '1') {out << "X";}
				else {out << bd[i];}

				if((i + 1) % c == 0) {out << "\n";}
			}	
			return out.str();
		}

		friend std::istream& operator>>(std::istream& ii,Grid& obj)
		{
			std::string str;
			ii >> str;
			obj.validate(str);
			return ii;
		}
	};
}

#endif
