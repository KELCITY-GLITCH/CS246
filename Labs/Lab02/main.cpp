#include <iostream>
#include <string>
#include <limits>
#include "Inventory.h"

using namespace std;
using namespace dsl;

void app(Inventory& inventory) {
    int choice;
    
    do {
        cout << "\n=== Inventory Management System ===" << endl;
        cout << "1. Get Item Count" << endl;
        cout << "2. Set Item Count" << endl;
        cout << "3. Get Low Inventory" << endl;
        cout << "4. Get Low Inventory Count" << endl;
        cout << "5. Get Total Inventory" << endl;
        cout << "6. Display All Items (toString)" << endl;
        cout << "0. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        
        switch (choice) {
            case 1: {
                int productID;
                cout << "Enter product ID (0-99): ";
                cin >> productID;
                try {
                    int count = inventory.getItemCount(productID);
                    cout << "Product " << productID << " has " << count << " items." << endl;
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            
            case 2: {
                int productID, count;
                cout << "Enter product ID (0-99): ";
                cin >> productID;
                cout << "Enter item count: ";
                cin >> count;
                inventory.setItemCount(productID, count);
                cout << "Item count updated successfully." << endl;
                break;
            }
            
            case 3: {
                int threshold;
                cout << "Enter threshold: ";
                cin >> threshold;
                string lowInventory = inventory.getLowInventory(threshold);
                cout << "Products with inventory <= " << threshold << ": ";
                if (lowInventory.empty()) {
                    cout << "None" << endl;
                } else {
                    cout << lowInventory << endl;
                }
                break;
            }
            
            case 4: {
                int threshold;
                cout << "Enter threshold: ";
                cin >> threshold;
                int count = inventory.getLowInventoryCount(threshold);
                cout << "Number of products with inventory <= " << threshold << ": " << count << endl;
                break;
            }
            
            case 5: {
                int total = inventory.getTotalInventory();
                cout << "Total inventory across all products: " << total << endl;
                break;
            }
            
            case 6: {
                cout << "\n=== Current Inventory ===" << endl;
                cout << inventory.toString();
                break;
            }
            
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    } while (choice != 0);
}

int main() {
    Inventory inventory;
    
    if (Import(inventory, "data.txt")) {
        cout << "Data loaded successfully from data.txt" << endl;
    } else {
        cout << "Warning: Could not open data.txt. Starting with empty inventory." << endl;
    }
    
    app(inventory);
    
    return 0;
}
