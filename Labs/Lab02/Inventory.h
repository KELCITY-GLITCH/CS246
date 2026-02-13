#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "Array.h"
#include "Object.h"

//Task 1
namespace dsl
{
    class Inventory : public dsn::Object
    {
        private:
            dsn::Array<int> items;

        public:    
          Inventory() : items(100)
          {
for (size_t i = 0; i <100; ++i)
  {
    items[i] = 0;
  }
    }

    virtual ~Inventory() {}

    int getItemCount(int productID) const
    {
        if (productID < 0 || productID >= 100)
        {
            throw std::invalid_argument("Invalid product ID");
        }
        return items[productID];
    }
//a public void method

    void setItemCount(int productID, int count)
    {
        if (productID >= 0 && productID < 100 && count >=0)
        {
            items[productID] = count;
        }
    }

 //a public string constant method
    std::string getLowInventory(int threshold) const
    {
        if (threshold < 0)
        {
            return "";
        }

        std::ostringstream oss;
        for (size_t i = 0; i < 100; ++i)
        {
            if (items[i] <= threshold)
            {
                oss <<std::setw(2) << std::setfill('0') << i << " ";
            }
        }

        std::string result = oss.str();
        if (!result.empty() && result.back() == ' ')
        {
            result.pop_back();
        }

        return result;
    }

    int getLowInventoryCount(int threshold) const 
    {
        if (threshold < 0)
        {
            return 0;
        }

        int count = 0;
        for (size_t i = 0; i < 100; ++i)
        {
            if (items[i] <= threshold)
            {
                count++;
            }
        }
        return count;
    }

    int getTotalInventory() const
    {
        int total = 0;
        for (size_t i = 0; i < 100; ++i)
        {
            total += items[i];
        }
        return total;
    }

    virtual std::string toString() const
    {
        std::ostringstream oss;
        for (size_t i = 0; i < 100; ++i)
        {
            oss << std::setw(2) << std::setfill('0') << i << " : " << items[i] << "\n";
        }
        return oss.str();
    }
        
    };    
    
    bool Import(Inventory& inventory, const std::string& filename) {
        std::ifstream file(filename);
        
        if (!file.is_open()) {
            return false;
        }
        
        int productID, count;
        while (file >> productID >> count) {
            if (productID >= 0 && productID < 100 && count >= 0) {
                inventory.setItemCount(productID, count);
            }
        }
        
        file.close();
        return true;
    }
}
#endif