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

    double price = 0;

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
                cout << "1. Smartphone (RM 1200)\n";
                cout << "2. Laptop (RM 3500)\n";
                cout << "3. Headphones (RM 250)\n";
                cout << "4. Televisions (RM 2200)\n";
                cout << "Select a product (1-4): ";
                cin >> productChoice;
                if (productChoice == 1) { productName = "Smartphone"; price += 1200.00; }
                else if (productChoice == 2) { productName = "Laptop"; price += 3500.00; }
                else if (productChoice == 3) { productName = "Headphones"; price += 250.00; }
                else if (productChoice == 4) { productName = "Televisions"; price += 2200.00; }
                break;

            case 2:
                cout << "\nClothing:\n";
                cout << "1. T-Shirt (RM 50)\n";
                cout << "2. Jeans (RM 120)\n";
                cout << "3. Jacket (RM 200)\n";
                cout << "Select a product (1-3): ";
                cin >> productChoice;
                if (productChoice == 1) { productName = "T-Shirt"; price += 50.00; }
                else if (productChoice == 2) { productName = "Jeans"; price += 120.00; }
                else if (productChoice == 3) { productName = "Jacket"; price += 200.00; }
                break;

            case 3:
                cout << "\nGroceries:\n";
                cout << "1. Rice (5kg) (RM 25)\n";
                cout << "2. Cooking Oil (2L) (RM 18)\n";
                cout << "3. Milk (1L) (RM 6)\n";
                cout << "Select a product (1-3): ";
                cin >> productChoice;
                if (productChoice == 1) { productName = "Rice (5kg)"; price += 25.00; }
                else if (productChoice == 2) { productName = "Cooking Oil (2L)"; price += 18.00; }
                else if (productChoice == 3) { productName = "Milk (1L)"; price += 6.00; }
                break;

            case 4:
                cout << "\nBooks:\n";
                cout << "1. Novel (RM 35)\n";
                cout << "2. Textbook (RM 120)\n";
                cout << "3. Comic (RM 15)\n";
                cout << "Select a product (1-3): ";
                cin >> productChoice;
                if (productChoice == 1) { productName = "Novel"; price += 35.00; }
                else if (productChoice == 2) { productName = "Textbook"; price += 120.00; }
                else if (productChoice == 3) { productName = "Comic"; price += 15.00; }
                break;

            default:
                cout << "Invalid choice. Returning to main menu...\n";
                continue;
        }
        
        cout << "\nDo you want to continue shopping?\n";
        cout << "1. Yes\n2. No (Proceed to payment)\n";
        cout << "Enter your choice: ";
        cin >> continueChoice;

        if (continueChoice == 2) {
            // Gift Wrapping
            cout << "\nDo you want gift wrapping? (Extra RM 5)\n";
            cout << "1. Yes\n2. No\n";
            cout << "Enter your choice: ";
            cin >> wrapChoice;
            if (wrapChoice == 1) { wrapOption = "Yes"; price += 5.00; }
            else if (wrapChoice == 2) { wrapOption = "No"; }
            else { cout << "Invalid choice. Defaulting to No.\n"; wrapOption = "No"; }

            // Courier
            cout << "\nChoose Courier Service:\n";
            cout << "1. J&T\n2. DHL\n3. PosLaju\n";
            cout << "Enter your choice: ";
            cin >> courierChoice;
            if (courierChoice == 1) courierService = "J&T";
            else if (courierChoice == 2) courierService = "DHL";
            else if (courierChoice == 3) courierService = "PosLaju";
            else { cout << "Invalid choice. Defaulting to J&T.\n"; courierService = "J&T"; }

            // Payment Method
            cout << "\nChoose Payment Method:\n";
            cout << "1. Online Banking\n2. Credit Card\n3. E-Wallet\n";
            cout << "Enter your choice: ";
            cin >> paymentChoice;
            if (paymentChoice == 1) paymentMethod = "Online Banking";
            else if (paymentChoice == 2) paymentMethod = "Credit Card";
            else if (paymentChoice == 3) paymentMethod = "E-Wallet";
            else { cout << "Invalid choice. Defaulting to Online Banking.\n"; paymentMethod = "Online Banking"; }

            // Generate Order ID
            string orderID = generateOrderID();

            // Print Receipt
            cout << "\n===== Order Summary =====\n";
            cout << "Order ID      : " << orderID << endl;
            cout << "Product       : " << productName << endl;
            cout << "Courier       : " << courierService << endl;
            cout << "Gift Wrapping : " << wrapOption << endl;
            cout << "Total Price   : RM " << price << endl;
            cout << "Payment Method: " << paymentMethod << endl;
            cout << "=========================\n";
            cout << "Thank you for your purchase!\n";
            break;
        }
    }
    return 0;
}
