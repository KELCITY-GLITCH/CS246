#ifndef SET_H
#define SET_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "ArrayList.h"
#include "Object.h"

namespace dsl
{
    template <class T>
    class Set : public Object
    {
     private:
        dns::ArrayList<T> elements;   

    public:

    Set() : elements() {}

    //copy constructor
    Set(const Set<T>& other) : elements(other.elements) {}

    //copy assigment operator
    Set<T>& operator=(const Set<T>& other) {
        if (this != &other) {
            elements = other.elements;
        }
        return *this;
    }

    // Destructor
    ~Set() {}

//2/c


    };

}

#endif
