#include "NxSquare.h"
#include "NxRectangle.h"
#include "NxCircle.h"
#include "NxAge.h"
#include "NxName.h"
#include "NxPerson.h"
#include "NxTextBox.h"
#include <iostream>
#include "NxColor.h"
#include "NxSpeaker.h"
#include "NxContact.h"

int main()
{
    // NxSquare
    dsw::NxSquare sq;
    std::cout << sq.getSide() << "\n";   
    sq.setSide(5);
    std::cout << sq.getSide() << "\n";   
    sq.setSide(-1);                       
    std::cout << sq.getSide() << "\n";   

    // NxRectangle
    dsw::NxRectangle rect;
    rect.setLength(4);
    rect.setWidth(2);
    std::cout << rect.getLength() << " " << rect.getWidth() << "\n"; 

    // NxCircle
    dsw::NxCircle c;
    c.setRadius(3);
    std::cout << c.getRadius() << "\n";         
    std::cout << dsw::NxCircle::getPI() << "\n";

    // NxAge
    dsw::NxAge a;
    a.setCount(25);
    std::cout << a.getCount() << "\n"; 
    a.setCount(-5);                     
    std::cout << a.getCount() << "\n"; 

    // NxName
    dsw::NxName n;
    std::cout << n.getFirstName() << " " << n.getLastName() << "\n"; 
    n.setFirstName("Alice");
    n.setLastName("Smith");
    std::cout << n.getFirstName() << " " << n.getLastName() << "\n"; 


    dsw::NxPerson p;
    std::cout << p.getName().getFirstName() << "\n"; 


    dsw::NxTextBox tb;
    std::cout << tb.getName() << "\n";    
    std::cout << tb.getContent() << "\n"; 
    tb.setName("MyBox");
    tb.setContent("Hello World");
    std::cout << tb.getName() << "\n";   
    std::cout << tb.getContent() << "\n"; 

    // NxColor
    dsw::NxColor col;
    col.setRed(255);
    col.setGreen(128);
    col.setBlue(300);  
    std::cout << col.getRed() << " " << col.getGreen() << " " << col.getBlue() << "\n"; 

    // NxSpeaker
    dsw::NxSpeaker sp;
    sp.setVolume(50);
    sp.setMute(true);
    std::cout << sp.getVolume() << " " << sp.getMute() << "\n"; 
    sp.setVolume(200); 
    std::cout << sp.getVolume() << "\n"; 

    // NxContact
    dsw::NxContact ct;
    std::cout << ct.getNumber() << "\n"; 
    ct.setNumber("5551234567");
    std::cout << ct.getNumber() << "\n"; 
    ct.setNumber("abc");                 
    std::cout << ct.getNumber() << "\n"; 

    return 0;
}
