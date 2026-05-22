#include <iostream>
#include <string>
#include <sstream>
#include "Point.h"
#include "Grid.h"

/*****************************************************
 *This program provide examples of using the Point and
 *Grid classes.
 *Phase 1: Grid Building
 *Phase 2: Path Marking
 ****************************************************/
int main() 
{
	//Phase 1: Grid Building
	dsp::Point p, q;
	dsp::Grid g(5,6); //Creates a 5 by 6 grid

	/*load the grid:
	 *OOXXOO 
	 *XOOXXO
	 *XOXXOO
	 *OOOXXO
	 *XXOOOO
	 ********************/
	g.load("001100100110101100000110110000");
	//Make the start position (0,5)
	p = g.start();
        p.set(0,5);
	g.start(p);

	//Make the end position (0,1)
	p = g.end();
	p.set(0,1);
	g.end(p);

	//display the grid
	std::cout << g;

	//Phase 2: Path Marking
	p = g.start();
	std::string path = "ddddllluluuu";

	//check if path will work
	//if it does mark the path
	
	if(g.path(path)) 
	{
		for(auto c : path)
		{
			if(c == 'l') {p = p.left();}
			else if(c == 'r') {p = p.right();}
			else if(c == 'u') {p = p.up();}
			else if(c == 'd') {p = p.down();}

			if(g.available(p)) 
			{
				g.mark(p);
			}
		}
	}

	std::cout << "\n" << g; 
		
	return 0;
}
