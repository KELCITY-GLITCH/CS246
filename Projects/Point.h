#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Object.h"

namespace dsp
{
	class Point : public Object
	{
		private:
		size_t values[3];

		Point(size_t v, size_t r, size_t c) : values{v,r,c}
		{
			for(int i = 1;i < 3;i += 1)
			{
				if(values[i] == 0) {values[i] = 3;}
			}

			if(values[0] >= values[1] * values[2])
			{
				values[0] = 0;
			}
		}

		void set(size_t v) 
		{
			if(v < values[1] * values[2]) 
			{
				values[0] = v;
			}
		}

		public:
		Point() : values{0,3,3} {}

		Point(size_t r, size_t c) : values{0,r,c}
		{
			if(values[1] == 0 || values[2] == 0)
			{
				std::invalid_argument("zero invalid dimension");
			}
		}

		Point(const Point& obj)
		{
			for(int i = 0;i < 3;i += 1)
			{
				values[i] = obj.values[i];
			}
		}
		
		Point& operator=(const Point& rhs)
		{
			if(this != &rhs)
			{
				for(int i = 0;i < 3;i += 1)
				{
					values[i] = rhs.values[i];
				}
			}
			return *this;
		}

		virtual ~Point() {}

		size_t rows() const {return values[1];}

		void rows(size_t obj) 
		{
			if(obj != 0) 
			{
				values[1] = obj;
				values[0] = 0;
			}
		}

		size_t columns() const {return values[2];}

		void columns(size_t obj)
		{
			if(obj != 0) 
			{
				values[2] = obj;
				values[0] = 0;
			}
		}

		size_t row() const 
		{
			return values[0] / values[2];
		}

		void row(size_t obj) 
		{
			if(obj < rows()) 
			{
				size_t y = column();
				values[0] = obj * values[2] + y;
			}
		}

		size_t column() const 
		{
			return values[0] % values[2];
		}

		void column(size_t obj)
		{
			if(obj < columns())
			{
				size_t x = row();
				values[0] = x * values[2] + obj;
			}
		}

		void set(size_t r, size_t c)
		{
			if(r < values[1] && c < values[2])
			{
				values[0] = r * values[2] + c;
			}
		}

		size_t hash() const {return values[0];}

		Point left() const 
		{
			Point t = *this;
			size_t r = rows(), c = columns();
			size_t y = column();
			size_t v = values[0];

			if(y != 0) {t.set(v-1);}
			return t;
		}
		
		Point right() const
		{
			Point t = *this;
			size_t r = rows(), c = columns();
			size_t y = column();
			size_t v = values[0];

			if(y != c-1) {t.set(v+1);}
		       	return t;
		}
		
		Point up() const
		{
			Point t = *this;
			size_t r = rows(), c = columns();
			size_t x = row();
			size_t v = values[0];

			if(x != 0) {t.set(v-c);}
		       	return t;
		}
		
		Point down() const
		{
			Point t = *this;
			size_t r = rows(), c = columns();
			size_t x = row();
			size_t v = values[0];

			if(x != r-1) {t.set(v+c);} 
			return t;
		}

		std::string toString() const override
		{
			std::stringstream out;
			out << "(" << row() << "," << column() << ")";
			return out.str();
		}

		friend bool equal(const Point& lhs, const Point& rhs)
		{
			for(size_t i = 1;i < 3;i += 1)
			{
				if(lhs.values[i] != rhs.values[i])
				{
					return false;
				}
			}
			return true;
		}

		friend bool operator==(const Point& lhs,const Point& rhs)
		{
			if(equal(lhs,rhs))
			{
				return lhs.hash() == rhs.hash();
			}
			return false;
		}

		friend bool operator!=(const Point& lhs,const Point& rhs)
		{
			return !(lhs == rhs);
		}

	};
}

#endif
