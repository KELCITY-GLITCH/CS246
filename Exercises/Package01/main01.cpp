#include "Square.h"
#include "Rectangle.h"
#include "Name.h"
#include "Age.h"
#include "Person.h"
#include "Circle.h"
#include "TextBox.h"

int main()
{
    dsw::Rectangle x;
    dsw::Square s, t, q = s;
    std::cout << s.side << "\n";
    s.side = 5;
    t = s; //assignment operator
    s = s; 
    std::cout << t.side << "\n";

    dsw::Name n;
    dsw::Age a;
    return 0;
}