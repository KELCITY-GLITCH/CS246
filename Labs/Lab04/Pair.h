#ifndef PAIR_H
#define PAIR_H

namespace dsl 
{
	template <class K, class V>
	class Pair 
	{
		private:
		K identity;
		V content;
		
		public:

		Pair() : identity(), content() {}
		Pair(const K& key,const V& value) : identity(key), content(value) {}
		
		Pair(const Pair<K,V>& obj)  
		{
			identity = obj.identity;
			content = obj.content;
		}
		
		Pair<K,V>& operator=(const Pair<K,V>& rhs)
		{
			if(this != &rhs)
			{
				identity = rhs.identity;
				content = rhs.content;
			}
			return *this;
		}
		
		~Pair() {}
		
		K& key() {return identity;}
		const K& key() const {return identity;}
		V& value() {return content;}
		const V& value() const {return content;}
	};
}

#endif
