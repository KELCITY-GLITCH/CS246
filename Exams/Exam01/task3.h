#ifndef TASK3_H
#define TASK3_H

#include <string>
#include <vector>
#include <stdexcept>

const int MIN_CAPACITY = 3;

template<typename ItemType>
class Player {
    static int playerCount;
    std::string id;
    int capacity;
    std::vector<ItemType> items;

public:
    //A constructor that provides an identification and uses the minimum capacity.
    Player(const std::string& identification)
    : id(identification), capacity(MIN_CAPACITY), items(MIN_CAPACITY) {}

    //A constructor that provides a capacity and uses the default identification.
    Player(int cap)
    : id("player " + std::to_string(++playerCount)), capacity(cap < MIN_CAPACITY ? MIN_CAPACITY : cap), items(capacity) {}

    //A constructor that provides an identification and a capacity.
    Player(const std::string& identification, int cap)
    : id(identification), capacity(cap <MIN_CAPACITY ?MIN_CAPACITY : cap), items(capacity) {}
    
    //A getter method for both the identification and the capacity.
    std::string getId() const { return id; }
    int getCapacity() const { return capacity; }

    //A getter/setter method for the elements of the collection that are accessed with an index.
    ItemType getItem(int index) const {
        if (index < 0 || index >= capacity) throw std::out_of_range("Index out of range");
        return items[index]; 
    }

    void setItem(int index, const ItemType& item) {
        if (index < 0 || index >= capacity) throw std::out_of_range("Index out of range");
        items[index] = item;
    }
};

template<typename ItemType>
int Player<ItemType>::playerCount = 0;


#endif