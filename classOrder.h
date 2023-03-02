/* Class definitions for Pizza and Pasta, which are going to be used for templated queue. 
A customer can only order either pizza or pasta. */
/* TODO: 
- Input for crust and toppings
- Print order name, phone, drink, total;
- Subclass PastaOrder and its functions
*/

#ifndef CLASSORDER_H
#define CLASSORDER_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
enum PizzaType { Margherita = 12, Pepperoni = 13, Cheese = 14, Vegetarian = 13, BBQChicken = 16 };
enum CrustType { thin = 0, thick = 1, stuffed = 2};
using namespace std;

// Parent abstract class Order
class Order {
    protected:
        string name;
        string phone;
        bool drink;
        double total;
    public:
        Order(); // default constructor
        // Order(string name, string phone, string drink, double total) // full constructor
        //     : name(name), phone(phone), drink(drink), total(total) {}
        virtual void printOrder() = 0; // pure virtual function to print order details
        // accessor functions
        double getTotal() const { return total; }
        string getName() const { return name; }
        string getPhone() const { return phone; }
        bool getDrink() const { return drink; }
        // modifier functions
        void setName(const string& newName) { name = newName; }
        void setPhone(const string& newPhone) { phone = newPhone; }
        void setTotal(int newTotal) { total = newTotal; }
        // other functions
        bool phoneValidation(const string& phone);
};
// Constructor for Order 
Order::Order() {
    cin.ignore();
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your phone number: ";
    getline(cin, phone);
    while (!phoneValidation(phone)) {
        cout << "Invalid format. Please re-enter your phone: ";
        getline(cin, phone);
    }
    cout << "Nice to meet you, " << name << "!" << endl;
    cout << "Would you like a fountain drink (y/n)?: ";
    string choice;
    getline(cin, choice);
    if (choice == "y") {
        drink = 1;
    } else if (choice == "n") {
        drink = 0;
    }
    while (choice != "y" && choice != "n") {
        cout << "Invalid choice. Please enter 'y' or 'n': ";
        cin >> choice;
        if (choice == "y") {
        drink = 1;
        } else if (choice == "n") {
            drink = 0;
        }
    }
    total = 0;
}

bool Order::phoneValidation(const string& phone) {
    // check the length of the string
    if (phone.length() != 10 && phone.length() != 12) {
        return false;
    }
    
    int count = 0;

    // loop through the string and check each character
    for (int i = 0; i < phone.length(); i++) {
        char ch = phone[i];
        if (isdigit(ch)) {
            count++;
        }
        else if (ch != '-' && ch != '.'&& !(isdigit(ch))) {
            return false;
        }
        // check the positions of the hyphens and dots
        if (i == 3 || i == 7) {
            if (ch != '-' && ch != '.' && !(isdigit(ch))) {
                return false;
            }
        }
    }
    // check the number of digits
    if (count != 10) {
        return false;
    }
    
    return true;
}

// Derived class of Order: Pizza
class PizzaOrder : public Order {
    private:
        PizzaType type;
        int size;
        CrustType crust;
        // vector<string> toppings;
    public:
        PizzaOrder();
        PizzaType getType() const { return type; }
        int getSize() const { return size; }
        CrustType getCrust() const { return crust; }
        // void getToppings();
        virtual void printOrder() override;
};

// Constructor for PizzaOrder
PizzaOrder::PizzaOrder() : Order() {
    // inputting pizza type
    bool valid = 0;
    while (!valid) {
        cout << endl;
        cout << "Choose pizza type:" << endl;
        cout << "1. Margherita ($12)" << endl;
        cout << "2. Pepperoni ($13)" << endl;
        cout << "3. Cheese ($14)" << endl;
        cout << "4. Vegeterian ($13)" << endl;
        cout << "5. BBQ Chicken ($16)" << endl;
        cout << endl;
        char pizzaChoice;
        cout << "Enter your choice: ";
        cin >> pizzaChoice;
        switch (pizzaChoice) {
            case '1':   total += Margherita;
                        type = Margherita;
                        valid = 1;
                        break;
            case '2':   total += Pepperoni;
                        type = Pepperoni;
                        valid = 1;
                        break;
            case '3':   total += Cheese;
                        type = Cheese;
                        valid = 1;
                        break;
            case '4':   total += Vegetarian;
                        type = Vegetarian;
                        valid = 1;
                        break;
            case '5':   total += BBQChicken;
                        type = BBQChicken;
                        valid = 1;
                        break;
            default:    cout << "Invalid choice. Please try again. " << endl;
                        break;
        }
    }
    cout << endl;
    cout << "Wonderful choice, " << name << "!" << endl;
    // inputting size
    valid = 0;
    while (!valid) {
        cout << endl;
        cout << "Let's choose the size:" << endl;
        cout << "1. 14\" (+$0)" << endl;
        cout << "2. 16\" (+$2)" << endl;
        cout << "3. 18\" (+$4)" << endl;
        cout << endl;
        char sizeChoice;
        cout << "Enter your choice: ";
        cin >> sizeChoice;
        switch (sizeChoice) {
            case '1':   size = 14;
                        valid = 1;
                        break;
            case '2':   size = 16;
                        total += 2.0;
                        valid = 1;
                        break;
            case '3':   size = 18;
                        total += 4.0;
                        valid = 1;
                        break;
            default:    cout << "Invalid choice. Please try again. " << endl;
                        break;
        }
    }
    cout << endl;
    cout << "Great choice, " << name << "!" << endl;
    // inputting crust
    valid = 0;
    while (!valid) {
        cout << endl;
        cout << "Now, choose the crust:" << endl;
        cout << "1. Thin (+$0)" << endl;
        cout << "2. Thick (+$1)" << endl;
        cout << "3. Stuffed (+$2)" << endl;
        cout << endl;
        char crustChoice;
        cout << "Enter your choice: ";
        cin >> crustChoice;
        switch (crustChoice) {
            case '1':   crust = thin;
                        valid = 1;
                        break;
            case '2':   size = thick;
                        total += thick;
                        valid = 1;
                        break;
            case '3':   size = stuffed;
                        total += stuffed;
                        valid = 1;
                        break;
            default:    cout << "Invalid choice. Please try again. " << endl;
                        break;
        }
    }
    cout << endl;
    cout << "You're all set! Thanks for your order!" << endl;
}

// Function to print the pizza order, overrides the function in the parent class
void PizzaOrder::printOrder() {
    cout << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Drink: ";
    if (drink == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << "Pizza Type: " << type << endl;
    cout << "Size: " << size << endl;
    cout << "Crust: " << crust << endl;
    cout << "Total: $" << total << endl;
    // cout << "Toppings: "; getToppings(); cout << endl; 
}

// Pasta Type Enumeration
enum PastaType {Spaghetti = 10, Fettuccine = 12, Penne = 11, Linguine = 13, Alfredo = 15, Carbonara = 16};

// Derived class of Order: Pasta
class PastaOrder : public Order {
    private:
        PastaType type;
        bool withChicken;
        bool withShrimp;
        bool withMushroom;
    public:
        PastaOrder();
        PastaType getType() const { return type; }
        bool hasChicken() const { return withChicken; }
        bool hasShrimp() const { return withShrimp; }
        bool hasMushroom() const { return withMushroom; }
        virtual void printOrder() override;
};

// Constructor for PastaOrder
PastaOrder::PastaOrder() : Order() {
    // inputting pasta type
    bool valid = 0;
    while (!valid) {
        cout << endl;
        cout << "Choose pasta type:" << endl;
        cout << "1. Spaghetti ($10)" << endl;
        cout << "2. Fettuccine ($12)" << endl;
        cout << "3. Penne ($11)" << endl;
        cout << "4. Linguine ($13)" << endl;
        cout << endl;
        char pastaChoice;
        cout << "Enter your choice: ";
        cin >> pastaChoice;
        switch (pastaChoice) {
            case '1':   total += Spaghetti;
                        type = Spaghetti;
                        valid = 1;
                        break;
            case '2':   total += Fettuccine;
                        type = Fettuccine;
                        valid = 1;
                        break;
            case '3':   total += Penne;
                        type = Penne;
                        valid = 1;
                        break;
            case '4':   total += Linguine;
                        type = Linguine;
                        valid = 1;
                        break;
            default:    cout << "Invalid choice. Please try again. " << endl;
                        break;
        }
    }
    cout << endl;
    cout << "Good choice, " << name << "!" << endl;
    // inputting extras
    withChicken = false;
    withShrimp = false;
    withMushroom = false;
    valid = 0;
    while (!valid) {
        cout << endl;
        cout << "Would you like extras in your pasta?" << endl;
        cout << "1. Chicken (+$3)" << endl;
        cout << "2. Shrimp (+$4)" << endl;
        cout << "3. Mushroom (+$2)" << endl;
        cout << "4. None" << endl;
        cout << endl;
        char extraChoice;
        cout << "Enter your choice: ";
        cin >> extraChoice;
        switch (extraChoice) {
            case '1':   total += 3.0;
                        withChicken = true;
                        valid = 1;
                        break;
            case '2':   total += 4.0;
                        withShrimp = true;
                        valid = 1;
                        break;
            case '3':   total += 2.0;
                        withMushroom = true;
                        valid = 1;
                        break;
            case '4':   valid = 1;
                        break;
            default:    cout << "Invalid choice. Please try again. " << endl;
                        break;
        }
    }
    cout << endl;
}

// Function to print the pizza order, overrides the function in the parent class
void PastaOrder::printOrder() {
    cout << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Drink: ";
    if (drink == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << "Pasta Type: " << type << endl;
    cout << "Extras: ";
    if (withChicken) {
        cout << "Chicken" << endl;
    } else if (withShrimp) {
        cout << "Shrimp" << endl;
    } else if (withMushroom) {
        cout << "Mushrooms" << endl;
    } else {
        cout << "None" << endl;
    }
    cout << "Total: $" << total << endl;
}

#endif