#include "Square.h"
#include "Rectangle.h"
#include "Name.h"
#include "Age.h"
#include "Person.h"
#include "Circle.h"
#include "TextBox.h"
#include "Color.h"
#include "Speaker.h"
#include "Contact.h"

int main()
{
    dsw::Rectangle x;
    dsw::Square s, t, q = s;
    std::cout << s.side << "\n";
    s.side = 5;
    t = s; 
    s = s; 
    std::cout << t.side << "\n";

    dsw::Name n;
    dsw::Age a;

    dsw::Color col;
    std::cout << col.red << " " << col.green << " " << col.blue << "\n"; 

    dsw::Speaker sp;
    std::cout << sp.volume << " " << sp.mute << "\n"; 

    dsw::Contact ct;
    std::cout << ct.number << "\n"; 

    return 0;
}