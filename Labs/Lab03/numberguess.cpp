#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Set.h"

int main()
{
	srand(time(nullptr));
	int x, y;

	std::cout << "Enter the first endpoint: ";
	std::cin >> x;
	std::cout << "Enter the second endpoint: ";
	std::cin >> y;
	game(x,y);
	return 0;
}
