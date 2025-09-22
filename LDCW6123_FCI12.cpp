#include <iostream>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <string>
using namespace std;

// Function to generate random alphanumeric Order ID
string generateOrderID() {
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string orderID = "";
    int length = rand() % 2 == 0 ? 8 : 9;  // randomly choose 8 or 9 chars

    for (int i = 0; i < length; i++) {
        int randIndex = rand() % chars.size();
        orderID += chars[randIndex];
    }
    return orderID;
}

int main() {
    int categoryChoice, productChoice, courierChoice, wrapChoice;
    int paymentChoice, installmentChoice, continueChoice, patternChoice;
    string productName, courierService, wrapOption, paymentMethod;

    // Initialize random seed
    srand(time(0));

    while (true) {
        cout << "\nWelcome to E-Commerce Shopping Assistant\n";
        cout << "Choose a category:\n";
        cout << "1. Electronics\n2. Clothing\n3. Groceries\n4. Books\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> categoryChoice;

        if (categoryChoice == 5) {
            cout << "Thank you for shopping with us. Goodbye!\n";
            break;
        }

        switch(categoryChoice) {
            case 1:
                cout << "\nElectronics:\n";
                cout << "1. Smartphone\n";
                cout << "2. Laptop\n";
                cout << "3. Headphones\n";
                cout << "4. Televisions\n";
                cout << "Select a product (1-5): ";
                cin >> productChoice;
                if (productChoice == 1) productName = "Smartphone";
                else if (productChoice == 2) productName = "Laptop";
                else if (productChoice == 3) productName = "Headphones";
                else if (productChoice == 4) productName = "Televisions";
                break;
            case 2:
                cout << "\nClothing:\n";
                cout << "1. T-Shirt\n";
                cout << "2. Jeans\n";
                cout << "3. Jacket\n";
                cout << "Select a product (1-3): ";
                cin >> productChoice;
                if (productChoice == 1) productName = "T-Shirt";
                else if (productChoice == 2) productName = "Jeans";
                else if (productChoice == 3) productName = "Jacket";
                break;
            case 3:
                cout << "\nGroceries:\n";
                cout << "1. Rice (5kg)\n";
                cout << "2. Cooking Oil (2L)\n";
                cout << "3. Milk (1L)\n";
                cout << "Select a product (1-3): ";
                cin >> productChoice;
                if (productChoice == 1) productName = "Rice (5kg)";
                else if (productChoice == 2) productName = "Cooking Oil (2L)";
                else if (productChoice == 3) productName = "Milk (1L)";
                break;
            case 4:
                cout << "\nBooks:\n";
                cout << "1. Novel\n";
                cout << "2. Textbook\n";
                cout << "3. Comic\n";
                cout << "Select a product (1-3): ";
                cin >> productChoice;
                if (productChoice == 1) productName = "Novel";
                else if (productChoice == 2) productName = "Textbook";
                else if (productChoice == 3) productName = "Comic";
                break;
            default:
                cout << "Invalid choice. Returning to main menu...\n";
                continue;
        } 
    }
    return 0;
}
