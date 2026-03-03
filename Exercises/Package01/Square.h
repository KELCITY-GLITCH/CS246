#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <string>

namespace dsw 
{
    class Square
    {
        public:
        double side;

        Square() : side(1) {}

        Square(const Square& obj) 
        {
            side = obj.side;
        }

        Square& operator=(const Square& rhs) 
        {
            if(this != &rhs)
            {
                side = rhs.side;
            }
            return *this;
        }
        
        ~Square() {}
    }; 
}

#endif