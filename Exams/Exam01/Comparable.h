#ifndef COMPARABLE_H
#define COMPARABLE_H

#include <iostream>

namespace dse
{
	class Comparable 
	{
		private:
		virtual size_t hash() const = 0;

		public:
		virtual ~Comparable() {}
		
		friend bool operator==(const Comparable& lhs,const Comparable& rhs)
		{
			return lhs.hash() == rhs.hash();
		}
		
		friend bool operator!=(const Comparable& lhs,const Comparable& rhs)
		{
			return lhs.hash() != rhs.hash();
		}

		friend bool operator<(const Comparable& lhs,const Comparable& rhs)
		{
			return lhs.hash() < rhs.hash();
		}

		friend bool operator<=(const Comparable& lhs,const Comparable& rhs)
		{
			return lhs.hash() <= rhs.hash();
		}

		friend bool operator>(const Comparable& lhs,const Comparable& rhs)
		{
			return lhs.hash() > rhs.hash();
		}

		friend bool operator>=(const Comparable& lhs,const Comparable& rhs)
		{
			return lhs.hash() >= rhs.hash();
		}

		friend size_t operator-(const Comparable& lhs,const Comparable& rhs)
		{
			if(lhs.hash() > rhs.hash()) {return lhs.hash() - rhs.hash();}
			return rhs.hash() - rhs.hash();
		}
	};
}

#endif
