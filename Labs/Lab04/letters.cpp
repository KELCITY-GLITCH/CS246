#include <iostream>
#include <string>
#include <iomanip>
#include "Map.h"
#include "Generator.h"

int main()
{ 
	int n;
	std::cout << " Enter count: ";
	std::cin>> n;

	dsl:: Generator gen;
	gen.lettersOnly();

	dsl::Map<char, int> freq;

	for(int i = 0; i < n; i++)
	{
		char ch = gen.next();
		freq[ch] +=1;
	}
	
	//Header
	std::cout << "Mode: LETTERS | Set size: 26 | Generated: " << n << "\n\n";

	// All generated characters
	std::cout << gen << "\n";

	std::cout << " Frequency Table:\n";
	for(int i = 0; i < 26; i++)
	{
		char ch = 'a' + i;
		if (freq.contains(ch))
		{
			std::cout << std::setw(4) << ch << ": " << freq[ch] << "\n";
		}
	}

	std::cout << "\nDistinct characters observed: " << freq.size() << "\n";

	std::cout << "Missing characters: ";
	bool anyMissing = false;
	for(int i = 0; i < 26; i++)
	{
		char ch = 'a' + i;
		if(!freq.contains(ch))
		{
			std::cout << ch;
			anyMissing = true;
		}
	}
	if(!anyMissing) { std::cout << "none"; }
	std::cout << "\n";

	std::cout << "Full coverage: " << (freq.size() == 26 ? "yes" : "no")<< "\n";

return 0;
}
