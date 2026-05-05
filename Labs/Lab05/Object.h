#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>

namespace dsl
{
	class Object 
	{
		public:
		virtual std::string toString() const = 0;

		friend std::ostream& operator<<(std::ostream& out,const Object& obj)
		{
			return out << obj.toString();
		}
	};
}

#endif
